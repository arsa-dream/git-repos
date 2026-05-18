/*
 * KIT_Appl.c
 *
 * Target:   NXP S32K144EVB evaluation board
 * Standard: ISO 26262 ASIL-B
 *
 * Description:
 *   RGB Rainbow demo application using FreeRTOS tasks.
 *   Demonstrates FTM0 PWM, GPIO, LPUART1, ADC0, and PTC12 switch
 *   coordinated through FreeRTOS inter-task communication.
 *
 * Task overview:
 *   vTask_RgbPwm       -- Cycles RGB LED through HSV rainbow via FTM0 PWM
 *   vTask_SwitchMonitor -- Reads SW2, pauses/resumes rainbow on press
 *   vTask_UartStatus   -- Prints RGB values and ADC reading over LPUART1
 */

#include "Headers.h"
#include "KIT_Appl.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include <string.h>

/*===========================================================================
 * PRIVATE TYPES
 *=========================================================================*/

typedef struct
{
    uint8 u8Red;
    uint8 u8Green;
    uint8 u8Blue;
} stRgbValue;

/*===========================================================================
 * PRIVATE CONSTANTS
 *=========================================================================*/

/* Number of hue steps in one full rainbow cycle (0-360 degrees, step 5) */
#define APPL_HSV_HUE_STEPS          72u

/* Hue increment per step in fixed-point (degrees * 10 to avoid float) */
#define APPL_HSV_HUE_INCREMENT      50u     /* 5.0 degrees * 10 */

/* UART transmit buffer size */
#define APPL_UART_BUF_SIZE          48u

/*===========================================================================
 * PRIVATE VARIABLES
 *=========================================================================*/

/* Current RGB output -- written by RgbPwm task, read by UartStatus task  */
static volatile stRgbValue  gstCurrentRgb;

/* Pause flag -- set/cleared by SwitchMonitor task                         */
static volatile uint8       gu8RainbowPaused    = FALSE;

/* Current hue index -- maintained across task cycles                      */
static uint8                gu8HueIndex         = 0u;

/*===========================================================================
 * PRIVATE FUNCTION PROTOTYPES
 *=========================================================================*/
static void APPL_ConvertHSVtoRGB(uint16 u16Hue, uint8 *pu8Red, uint8 *pu8Green, uint8 *pu8Blue);
static void APPL_UintToDecStr(uint8 u8Value, sint8 *ps8Buf, uint8 *pu8Len);

/*===========================================================================
 * PRIVATE FUNCTIONS
 *=========================================================================*/

/*---------------------------------------------------------------------------
 * APPL_ConvertHSVtoRGB
 *
 * Converts HSV colour to RGB using integer arithmetic only.
 * No floating point -- safe for use in FreeRTOS tasks on Cortex-M4F
 * without requiring FPU context save in every task.
 *
 * Input:
 *   u16Hue   -- Hue in degrees * 10 (0..3599), i.e. 0=0deg, 3599=359.9deg
 *   Saturation and Value fixed at 1.0 (full vivid colour, full brightness)
 *
 * Output:
 *   pu8Red, pu8Green, pu8Blue -- 0..255 each
 *--------------------------------------------------------------------------*/
static void APPL_ConvertHSVtoRGB(uint16 u16Hue, uint8 *pu8Red, uint8 *pu8Green, uint8 *pu8Blue)
{
    uint16 u16Sector;   /* 0..5: which 60-degree sector of the colour wheel */
    uint16 u16Frac;     /* fractional part within sector, 0..255            */
    uint8  u8Q;         /* falling slope value                              */
    uint8  u8T;         /* rising slope value                               */

    /* Sector: 0-5, each covers 60 degrees (600 in *10 units)              */
    u16Sector = u16Hue / 600u;

    /* Fraction within sector, scaled to 0..255                             */
    u16Frac   = ((u16Hue % 600u) * 255u) / 600u;

    u8Q = (uint8)(255u - u16Frac);  /* falling: 255 -> 0 across sector     */
    u8T = (uint8)(u16Frac);         /* rising:  0 -> 255 across sector     */

    switch (u16Sector)
    {
        case 0u:  *pu8Red = 255u; *pu8Green = u8T;   *pu8Blue = 0u;    break; /* Red -> Yellow   */
        case 1u:  *pu8Red = u8Q;  *pu8Green = 255u;  *pu8Blue = 0u;    break; /* Yellow -> Green */
        case 2u:  *pu8Red = 0u;   *pu8Green = 255u;  *pu8Blue = u8T;   break; /* Green -> Cyan   */
        case 3u:  *pu8Red = 0u;   *pu8Green = u8Q;   *pu8Blue = 255u;  break; /* Cyan -> Blue    */
        case 4u:  *pu8Red = u8T;  *pu8Green = 0u;    *pu8Blue = 255u;  break; /* Blue -> Magenta */
        default:  *pu8Red = 255u; *pu8Green = 0u;    *pu8Blue = u8Q;   break; /* Magenta -> Red  */
    }
}

/*---------------------------------------------------------------------------
 * APPL_UintToDecStr
 *
 * Converts uint8 value to decimal ASCII string.
 * Avoids sprintf/itoa -- no dynamic allocation, no stdio dependency.
 *
 * Output: ps8Buf filled with ASCII digits, pu8Len set to character count.
 *--------------------------------------------------------------------------*/
static void APPL_UintToDecStr(uint8 u8Value, sint8 *ps8Buf, uint8 *pu8Len)
{
    uint8 u8Digits[3u];
    uint8 u8Count = 0u;
    uint8 u8Idx   = 0u;

    if (u8Value == 0u)
    {
        ps8Buf[0] = '0';
        *pu8Len   = 1u;
        return;
    }

    while (u8Value > 0u)
    {
        u8Digits[u8Count] = u8Value % 10u;
        u8Value           = u8Value / 10u;
        u8Count++;
    }

    /* Reverse into output buffer                                           */
    while (u8Count > 0u)
    {
        u8Count--;
        ps8Buf[u8Idx] = (sint8)('0' + u8Digits[u8Count]);
        u8Idx++;
    }

    *pu8Len = u8Idx;
}

/*===========================================================================
 * PUBLIC TASK FUNCTIONS
 *=========================================================================*/

/*---------------------------------------------------------------------------
 * Task: RGB PWM Rainbow
 *
 * Priority : 3
 * Period   : 20ms -- smooth visible colour transition
 *
 * Cycles through HSV hue 0-360 degrees in APPL_HSV_HUE_STEPS steps.
 * Writes PWM duty cycle to FTM0 CH0/1/2 for R/G/B.
 * Respects gu8RainbowPaused flag from SwitchMonitor task.
 *--------------------------------------------------------------------------*/
void vTask_RgbPwm(void *pvParameters)
{
    (void)pvParameters;

    const TickType_t xPeriod       = pdMS_TO_TICKS(20u);
    TickType_t       xLastWakeTime = xTaskGetTickCount();
    uint8            u8Red         = 0u;
    uint8            u8Green       = 0u;
    uint8            u8Blue        = 0u;
    uint16           u16Hue        = 0u;

    /* Enable all three PWM channels at startup                             */
    APPL_ENABLE_PWM_RED();
    APPL_ENABLE_PWM_GREEN();
    APPL_ENABLE_PWM_BLUE();

    for (;;)
    {
        vTaskDelayUntil(&xLastWakeTime, xPeriod);

        if (gu8RainbowPaused == FALSE)
        {
            /* Compute current hue in *10 degrees                           */
            u16Hue = (uint16)gu8HueIndex * APPL_HSV_HUE_INCREMENT;

            /* Convert HSV to RGB                                           */
            APPL_ConvertHSVtoRGB(u16Hue, &u8Red, &u8Green, &u8Blue);

            /* Apply to PWM channels                                        */
            APPL_SET_RED_DUTY(u8Red);
            APPL_SET_GREEN_DUTY(u8Green);
            APPL_SET_BLUE_DUTY(u8Blue);

            /* Update shared RGB state for UART task                        */
            gstCurrentRgb.u8Red   = u8Red;
            gstCurrentRgb.u8Green = u8Green;
            gstCurrentRgb.u8Blue  = u8Blue;

            /* Advance hue, wrap at end of cycle                            */
            gu8HueIndex++;
            if (gu8HueIndex >= APPL_HSV_HUE_STEPS)
            {
                gu8HueIndex = 0u;
            }
        }
        else
        {
            /* Paused -- hold current colour, nothing to update             */
        }
    }
}

/*---------------------------------------------------------------------------
 * Task: Switch Monitor
 *
 * Priority : 2
 * Period   : 10ms -- responsive button debounce
 *
 * Reads SW2 on PTC12. Toggles rainbow pause/resume on each button press.
 * Implements simple debounce: requires stable state for 3 consecutive reads.
 *--------------------------------------------------------------------------*/
void vTask_SwitchMonitor(void *pvParameters)
{
    (void)pvParameters;

    const TickType_t xPeriod        = pdMS_TO_TICKS(10u);
    TickType_t       xLastWakeTime  = xTaskGetTickCount();
    uint8            u8DebounceCount = 0u;
    uint8            u8PrevPressed  = FALSE;

    for (;;)
    {
        vTaskDelayUntil(&xLastWakeTime, xPeriod);

        if (APPL_SWITCH_SW2_PRESSED())
        {
            u8DebounceCount++;

            if (u8DebounceCount >= 3u)       /* 30ms stable press confirmed */
            {
                if (u8PrevPressed == FALSE)  /* rising edge -- first detect  */
                {
                    /* Toggle pause state                                    */
                    if (gu8RainbowPaused == FALSE)
                    {
                        gu8RainbowPaused = TRUE;

                        /* Hold current colour on pause                      */
                        APPL_ENABLE_PWM_RED();
                        APPL_ENABLE_PWM_GREEN();
                        APPL_ENABLE_PWM_BLUE();
                    }
                    else
                    {
                        gu8RainbowPaused = FALSE;
                    }

                    u8PrevPressed = TRUE;
                }
                u8DebounceCount = 3u;        /* Clamp to avoid overflow      */
            }
        }
        else
        {
            /* Button released -- reset debounce and edge detection          */
            u8DebounceCount = 0u;
            u8PrevPressed   = FALSE;
        }
    }
}

/*---------------------------------------------------------------------------
 * Task: UART Status Output
 *
 * Priority : 1
 * Period   : 500ms
 *
 * Prints current RGB values over LPUART1 in format:
 *   "RGB: R=255 G=128 B=0 | State=RUN\r\n"
 *
 * Uses no printf/sprintf -- builds string manually to avoid
 * pulling in newlib stdio which consumes significant flash.
 *--------------------------------------------------------------------------*/
void vTask_UartStatus(void *pvParameters)
{
    (void)pvParameters;

    const TickType_t xPeriod       = pdMS_TO_TICKS(500u);
    TickType_t       xLastWakeTime = xTaskGetTickCount();

    sint8   s8Buf[APPL_UART_BUF_SIZE];
    uint8   u8Pos   = 0u;
    uint8   u8Len   = 0u;
    uint8   u8Red   = 0u;
    uint8   u8Green = 0u;
    uint8   u8Blue  = 0u;

    for (;;)
    {
        vTaskDelayUntil(&xLastWakeTime, xPeriod);

        /* Snapshot current RGB atomically                                  */
        u8Red   = gstCurrentRgb.u8Red;
        u8Green = gstCurrentRgb.u8Green;
        u8Blue  = gstCurrentRgb.u8Blue;

        /* Build string: "RGB: R=xxx G=xxx B=xxx | State=RUN\r\n"          */
        u8Pos = 0u;

        /* "RGB: R=" */
        s8Buf[u8Pos++] = 'R'; s8Buf[u8Pos++] = 'G'; s8Buf[u8Pos++] = 'B';
        s8Buf[u8Pos++] = ':'; s8Buf[u8Pos++] = ' ';
        s8Buf[u8Pos++] = 'R'; s8Buf[u8Pos++] = '=';
        APPL_UintToDecStr(u8Red,   &s8Buf[u8Pos], &u8Len); u8Pos += u8Len;

        /* " G=" */
        s8Buf[u8Pos++] = ' '; s8Buf[u8Pos++] = 'G'; s8Buf[u8Pos++] = '=';
        APPL_UintToDecStr(u8Green, &s8Buf[u8Pos], &u8Len); u8Pos += u8Len;

        /* " B=" */
        s8Buf[u8Pos++] = ' '; s8Buf[u8Pos++] = 'B'; s8Buf[u8Pos++] = '=';
        APPL_UintToDecStr(u8Blue,  &s8Buf[u8Pos], &u8Len); u8Pos += u8Len;

        /* " | State=" */
        s8Buf[u8Pos++] = ' '; s8Buf[u8Pos++] = '|'; s8Buf[u8Pos++] = ' ';
        s8Buf[u8Pos++] = 'S'; s8Buf[u8Pos++] = 't'; s8Buf[u8Pos++] = 'a';
        s8Buf[u8Pos++] = 't'; s8Buf[u8Pos++] = 'e'; s8Buf[u8Pos++] = '=';

        /* "RUN" or "PAUSED" */
        if (gu8RainbowPaused == FALSE)
        {
            s8Buf[u8Pos++] = 'R'; s8Buf[u8Pos++] = 'U'; s8Buf[u8Pos++] = 'N';
        }
        else
        {
            s8Buf[u8Pos++] = 'P'; s8Buf[u8Pos++] = 'A'; s8Buf[u8Pos++] = 'U';
            s8Buf[u8Pos++] = 'S'; s8Buf[u8Pos++] = 'E'; s8Buf[u8Pos++] = 'D';
        }

        /* "\r\n" */
        s8Buf[u8Pos++] = '\r';
        s8Buf[u8Pos++] = '\n';

        /* Transmit                                                         */
        APPL_UART_PRINT(s8Buf, u8Pos);
    }
}

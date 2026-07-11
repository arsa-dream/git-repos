/*
 * KIT_Appl.c
 *
 * Target:   NXP S32K144EVB evaluation board
 * Standard: ISO 26262 ASIL-B
 *
 * Description:
 *   RGB sequential ramp demo using FreeRTOS tasks.
 *   Red ramps 0->100->0, then Green, then Blue, repeating.
 *
 * Task overview:
 *   vTask_RgbPwm       -- Steps RGB LED through R/G/B ramp sequence via FTM0 PWM
 *   vTask_SwitchMonitor -- Reads SW2, pauses/resumes sequence on press
 *   vTask_UartStatus   -- Prints RGB values over LPUART1
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

typedef enum
{
    APPL_PHASE_RED_UP   = 0u,
    APPL_PHASE_RED_DOWN = 1u,
    APPL_PHASE_GRN_UP   = 2u,
    APPL_PHASE_GRN_DOWN = 3u,
    APPL_PHASE_BLU_UP   = 4u,
    APPL_PHASE_BLU_DOWN = 5u
} teRgbPhase;

/*===========================================================================
 * PRIVATE CONSTANTS
 *=========================================================================*/

/* Duty step per 10 ms tick: 0->255 in 255 steps (~2.5 s per ramp direction) */
#define APPL_RGB_STEP           6553u

#define APPL_RGB_MAX            65530u

/* UART transmit buffer size */
#define APPL_UART_BUF_SIZE      48u

/*===========================================================================
 * PRIVATE VARIABLES
 *=========================================================================*/

/* Current RGB output -- written by RgbPwm task, read by UartStatus task  */
static volatile stRgbValue  gstCurrentRgb;

/* Pause flag -- set/cleared by SwitchMonitor task                         */
static volatile uint8       gu8Paused = FALSE;

/*===========================================================================
 * PRIVATE FUNCTION PROTOTYPES
 *=========================================================================*/
static void APPL_UintToDecStr(uint8 u8Value, sint8 *ps8Buf, uint8 *pu8Len);

/*===========================================================================
 * PRIVATE FUNCTIONS
 *=========================================================================*/

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
 * Task: RGB PWM Ramp
 *
 * Priority : 3
 * Period   : 10ms
 *
 * Sequences through: Red 0->255->0, Green 0->255->0, Blue 0->255->0, repeat.
 * Each ramp direction takes ~2.5 s (255 steps x 10 ms).
 * Writes PWM duty to FTM0 CH0/1/2 for R/G/B.
 * Respects gu8Paused flag from SwitchMonitor task.
 *--------------------------------------------------------------------------*/
void vTask_RgbPwm(void *pvParameters)
{
    (void)pvParameters;

    const TickType_t xPeriod       = pdMS_TO_TICKS(10u);
    TickType_t       xLastWakeTime = xTaskGetTickCount();
//    static teRgbPhase   ePhase        = APPL_PHASE_RED_UP;
//    static uint32       u32level      = 0u;
//    static uint32       u32Red        = 0u;
//    static uint32       u32Green      = 0u;
//    static uint32       u32Blue       = 0u;

    for (;;)
    {
		vTaskDelayUntil(&xLastWakeTime, xPeriod);

		APPL_DISABLE_PWM_RED();
		APPL_ENABLE_PWM_RED();
		APPL_SET_RED_DUTY(10000u);

//		if (gu8Paused == TRUE)
//		{
//			u32Red   = 0u;
//			u32Green = 0u;
//			u32Blue  = 0u;
//
//			switch (ePhase)
//			{
//				case APPL_PHASE_RED_UP:
//					u32level += APPL_RGB_STEP;
//
//					APPL_DISABLE_PWM_RED();
//					APPL_DISABLE_PWM_GREEN();
//					APPL_DISABLE_PWM_BLUE();
//
//					if (u32level >= APPL_RGB_MAX)
//					{
//						u32level = APPL_RGB_MAX;
//						ePhase  = APPL_PHASE_RED_DOWN;
//					}
//
//					APPL_ENABLE_PWM_RED();
//					APPL_SET_RED_DUTY(u32level);
//					APPL_DISABLE_PWM_GREEN();
//					APPL_DISABLE_PWM_BLUE();
//
//					u32Red = u32level;
//					break;
//
//				case APPL_PHASE_RED_DOWN:
//
//
//					APPL_DISABLE_PWM_RED();
//					APPL_DISABLE_PWM_GREEN();
//					APPL_DISABLE_PWM_BLUE();
//
//					if (u32level <= APPL_RGB_STEP)
//					{
//						/* Transition: start Green in same tick -- no dark gap */
//						u32level = APPL_RGB_STEP;
//						ePhase  = APPL_PHASE_GRN_UP;
//						u32Green = u32level;
//					}
//					else
//					{
//						u32level -= APPL_RGB_STEP;
//						u32Red    = u32level;
//					}
//
//					APPL_ENABLE_PWM_RED();
//					APPL_SET_RED_DUTY(u32level);
//					APPL_DISABLE_PWM_GREEN();
//					APPL_DISABLE_PWM_BLUE();
//
//					break;
//
//				case APPL_PHASE_GRN_UP:
//
//					APPL_DISABLE_PWM_RED();
//					APPL_DISABLE_PWM_GREEN();
//					APPL_DISABLE_PWM_BLUE();
//
//					u32level += APPL_RGB_STEP;
//					if (u32level >= APPL_RGB_MAX)
//					{
//						u32level = APPL_RGB_MAX;
//						ePhase  = APPL_PHASE_GRN_DOWN;
//					}
//
//					APPL_ENABLE_PWM_GREEN();
//					APPL_SET_GREEN_DUTY(u32level);
//					APPL_DISABLE_PWM_RED();
//					APPL_DISABLE_PWM_BLUE();
//
//					u32Green = u32level;
//					break;
//
//				case APPL_PHASE_GRN_DOWN:
//
//					APPL_DISABLE_PWM_RED();
//					APPL_DISABLE_PWM_GREEN();
//					APPL_DISABLE_PWM_BLUE();
//
//					if (u32level <= APPL_RGB_STEP)
//					{
//						/* Transition: start Blue in same tick -- no dark gap  */
//						u32level = APPL_RGB_STEP;
//						ePhase  = APPL_PHASE_BLU_UP;
//						u32Blue  = u32level;
//					}
//					else
//					{
//						u32level -= APPL_RGB_STEP;
//						u32Green  = u32level;
//					}
//
//					APPL_ENABLE_PWM_GREEN();
//					APPL_SET_GREEN_DUTY(u32level);
//					APPL_DISABLE_PWM_RED();
//					APPL_DISABLE_PWM_BLUE();
//
//					break;
//
//				case APPL_PHASE_BLU_UP:
//
//					APPL_DISABLE_PWM_RED();
//					APPL_DISABLE_PWM_GREEN();
//					APPL_DISABLE_PWM_BLUE();
//
//					u32level += APPL_RGB_STEP;
//					if (u32level >= APPL_RGB_MAX)
//					{
//						u32level = APPL_RGB_MAX;
//						ePhase  = APPL_PHASE_BLU_DOWN;
//					}
//
//					APPL_ENABLE_PWM_BLUE();
//					APPL_SET_BLUE_DUTY(u32level);
//					APPL_DISABLE_PWM_RED();
//					APPL_DISABLE_PWM_BLUE();
//
//
//					u32Blue = u32level;
//					break;
//
//				case APPL_PHASE_BLU_DOWN:
//
//					APPL_DISABLE_PWM_RED();
//					APPL_DISABLE_PWM_GREEN();
//					APPL_DISABLE_PWM_BLUE();
//
//					if (u32level <= APPL_RGB_STEP)
//					{
//						/* Transition: start Red in same tick -- no dark gap   */
//						u32level = APPL_RGB_STEP;
//						ePhase = APPL_PHASE_RED_UP;
//						u32Red = u32level;
//					}
//					else
//					{
//						u32level -= APPL_RGB_STEP;
//						u32Blue   = u32level;
//					}
//
//					APPL_ENABLE_PWM_BLUE();
//					APPL_SET_BLUE_DUTY(u32level);
//					APPL_DISABLE_PWM_RED();
//					APPL_DISABLE_PWM_BLUE();
//
//					break;
//
//				default:
//					ePhase  = APPL_PHASE_RED_UP;
//					u32level = 0u;
//					break;
//			}
//
//			gstCurrentRgb.u8Red   = (u32Red*100u)/APPL_RGB_MAX;
//			gstCurrentRgb.u8Green = (u32Green*100u)/APPL_RGB_MAX;
//			gstCurrentRgb.u8Blue  = (u32Blue*100u)/APPL_RGB_MAX;
//
//		}
    }
}

/*---------------------------------------------------------------------------
 * Task: Switch Monitor
 *
 * Priority : 2
 * Period   : 10ms -- responsive button debounce
 *
 * Reads SW2 on PTC12. Toggles sequence pause/resume on each button press.
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
                    gu8Paused = (gu8Paused == FALSE) ? TRUE : FALSE;
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

    const TickType_t xPeriod       = pdMS_TO_TICKS(10u);
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
        if (gu8Paused == FALSE)
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

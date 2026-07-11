/*
 * KIT_Appl.h
 *
 * Target:   NXP S32K144EVB evaluation board
 * Standard: ISO 26262 ASIL-B
 *
 * Description:
 *   Application layer interface for the RGB sequential ramp demo.
 *   Demonstrates FTM0 PWM, GPIO, LPUART1, ADC0, PTC12 switch
 *   and FreeRTOS task coordination.
 *
 * Board resources used:
 *   PTD15  -- Red   LED (FTM0 CH0 PWM, Active Low)
 *   PTD16  -- Green LED (FTM0 CH1 PWM, Active Low)
 *   PTD0   -- Blue  LED (FTM0 CH2 PWM, Active Low)
 *   PTC12  -- Switch SW2 (Active Low, pull-up)
 *   LPUART1 -- Debug UART output
 *   ADC0 CH0 -- Analog input
 */

#ifndef APPL_H_
#define APPL_H_

#include "Headers.h"

/*---------------------------------------------------------------------------
 * LED GPIO macros
 * Note: LEDs are Active Low -- SET = LED ON, CLR = LED OFF
 *--------------------------------------------------------------------------*/
#define APPL_SET_RED_LED()          GPIO_CLR_OUTPUT(PTD, 15u)   /* Active Low */
#define APPL_SET_GREEN_LED()        GPIO_CLR_OUTPUT(PTD, 16u)   /* Active Low */
#define APPL_SET_BLUE_LED()         GPIO_CLR_OUTPUT(PTD, 0u)    /* Active Low */

#define APPL_CLR_RED_LED()          GPIO_SET_OUTPUT(PTD, 15u)   /* Active Low */
#define APPL_CLR_GREEN_LED()        GPIO_SET_OUTPUT(PTD, 16u)   /* Active Low */
#define APPL_CLR_BLUE_LED()         GPIO_SET_OUTPUT(PTD, 0u)    /* Active Low */

#define APPL_TOG_RED_LED()          GPIO_TOGGLE(PTD, 15u)
#define APPL_TOG_GREEN_LED()        GPIO_TOGGLE(PTD, 16u)
#define APPL_TOG_BLUE_LED()         GPIO_TOGGLE(PTD, 0u)

/*---------------------------------------------------------------------------
 * Switch macro
 * SW2 on PTC12: returns 0 when pressed (Active Low with pull-up)
 *--------------------------------------------------------------------------*/
#define APPL_SWITCH_SW2_PRESSED()   (GPIO_READ_INPUT(PTC, 12u) == 0u)

/*---------------------------------------------------------------------------
 * PWM channel enable / disable
 * FTM0: CH0 = Red, CH1 = Green, CH2 = Blue
 *--------------------------------------------------------------------------*/
#define APPL_ENABLE_PWM_RED()       FTMn_ENABLE_CH0(FTM0)
#define APPL_ENABLE_PWM_GREEN()     FTMn_ENABLE_CH1(FTM0)
#define APPL_ENABLE_PWM_BLUE()      FTMn_ENABLE_CH2(FTM0)

#define APPL_DISABLE_PWM_RED()      FTMn_DISABLE_CH0(FTM0)
#define APPL_DISABLE_PWM_GREEN()    FTMn_DISABLE_CH1(FTM0)
#define APPL_DISABLE_PWM_BLUE()     FTMn_DISABLE_CH2(FTM0)

/*---------------------------------------------------------------------------
 * PWM duty cycle macros
 * Input: duty 0-255 (8-bit RGB scale)
 * Formula: compare count = (duty / 255) * FTM0_CHx_MODULO_VAL
 * FTM0_CHx_MODULO_VAL is defined in FTMn_Cfg.h
 *--------------------------------------------------------------------------*/
/* LEDs are Active Low: duty=0 -> CnV=0 -> output LOW -> LED ON (inverted).  *
 * Invert here so callers use natural 0=off, 255=full brightness.            */
//#define APPL_SET_RED_DUTY(duty)     FTMn_CHn_SET_CHANNEL_DUTYCNT(FTM0, 0u, ((uint32)(255u - (duty)) * FTM0_CHx_MODULO_VAL) / 255u)
//#define APPL_SET_GREEN_DUTY(duty)   FTMn_CHn_SET_CHANNEL_DUTYCNT(FTM0, 1u, ((uint32)(255u - (duty)) * FTM0_CHx_MODULO_VAL) / 255u)
//#define APPL_SET_BLUE_DUTY(duty)    FTMn_CHn_SET_CHANNEL_DUTYCNT(FTM0, 2u, ((uint32)(255u - (duty)) * FTM0_CHx_MODULO_VAL) / 255u)

#define APPL_SET_RED_DUTY(duty)     FTMn_CHn_SET_CHANNEL_DUTYCNT(FTM0, 0u, duty)
#define APPL_SET_GREEN_DUTY(duty)   FTMn_CHn_SET_CHANNEL_DUTYCNT(FTM0, 1u, duty)
#define APPL_SET_BLUE_DUTY(duty)    FTMn_CHn_SET_CHANNEL_DUTYCNT(FTM0, 2u, duty)


/*---------------------------------------------------------------------------
 * UART output macro
 * Wraps LPUART1 transmit -- caller passes (sint8*, uint8)
 *--------------------------------------------------------------------------*/
#define APPL_UART_PRINT(str, len)   LPUart1_TransmitString((sint8*)(str), (uint8)(len))

/*---------------------------------------------------------------------------
 * Public task functions -- called from main.c task creation
 *--------------------------------------------------------------------------*/
extern void vTask_RgbPwm(void *pvParameters);
extern void vTask_SwitchMonitor(void *pvParameters);
extern void vTask_UartStatus(void *pvParameters);

#endif /* APPL_H_ */

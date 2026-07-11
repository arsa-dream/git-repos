/*
 * PORT_Cfg.h
 *
 * Target:   NXP S32K144EVB evaluation board
 * Standard: ISO 26262 ASIL-B
 *
 * Description:
 *   PIN configuration table for PORT MCAL driver.
 *   Each entry in gkastPortPinCfg[] configures one pin.
 *   Port_Init() in PORT_Core.c iterates this table at startup.
 *
 *   To add or modify a pin:
 *     1. Add/edit one row in the table below
 *     2. No changes to PORT_Core.c are needed
 *
 * Table column order:
 *   { pstPort, pstGpio, u8Pin, u8Mux, u8IrqC,
 *     u8Direction, u8DriveStr, u8PassiveFil, u8PullEn, u8PullSel, u8LockReg }
 *
 * S32K144EVB board pin assignments used in this table:
 *   PTD15   -- Red   LED (FTM0 CH0 PWM, ALT2)
 *   PTD16   -- Green LED (FTM0 CH1 PWM, ALT2)
 *   PTD0    -- Blue  LED (FTM0 CH2 PWM, ALT2)
 *   PTC12   -- SW2 input (GPIO, Active Low, pull-up)
 *   PTC13   -- SW3 input (GPIO, Active Low, pull-up)
 *   PTB0    -- LPUART1 RX (ALT2)
 *   PTB1    -- LPUART1 TX (ALT2)
 *
 * Ref: S32K144 Reference Manual, Chapter 12 (PORT), pages 215-237
 */

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

#include "PORT_Core.h"

/*===========================================================================
 * PIN CONFIGURATION TABLE
 *
 * Only pins that are actually used are listed here.
 * Unlisted pins remain at reset default (analog, input, no pull).
 * This replaces the previous 3000-line per-pin expansion.
 *
 * PORT_PIN_NOTUSED pins are skipped by Port_Init() -- safe to leave in
 * for documentation purposes without any code size impact.
 *=========================================================================*/

static const stPortPinCfg gkastPortPinCfg[] =
{
    /*------------------------------------------------------------------------
     * PORT B -- LPUART0 communication
     *----------------------------------------------------------------------*/

    /* PTB0 -- LPUART0 RX
     * ALT2 = LPUART0_RX, no pull, no interrupt                             */
    { PORTB, PTB, 0u,  PORT_MUX_ALT2, PORT_IRQC_DISABLED,
      PORT_PIN_INPUT,  FALSE, FALSE, FALSE, FALSE, FALSE },

    /* PTB1 -- LPUART0 TX
     * ALT2 = LPUART0_TX, high drive strength for signal integrity           */
    { PORTB, PTB, 1u,  PORT_MUX_ALT2, PORT_IRQC_DISABLED,
      PORT_PIN_OUTPUT, TRUE,  FALSE, FALSE, FALSE, FALSE },
    /*------------------------------------------------------------------------
     * PORT C -- LPUART1 communication
     *----------------------------------------------------------------------*/

    /* PTC6 -- LPUART1 RX
     * ALT2 = LPUART1_RX, no pull, no interrupt                             */
    { PORTC, PTC, 6u,  PORT_MUX_ALT2, PORT_IRQC_DISABLED,
      PORT_PIN_INPUT,  FALSE, FALSE, FALSE, FALSE, FALSE },

    /* PTC7 -- LPUART1 TX
     * ALT2 = LPUART1_TX, high drive strength for signal integrity           */
    { PORTC, PTC, 7u,  PORT_MUX_ALT2, PORT_IRQC_DISABLED,
      PORT_PIN_OUTPUT, TRUE,  FALSE, FALSE, FALSE, FALSE },
    /*------------------------------------------------------------------------
     * PORT C -- Switch inputs SW2, SW3
     *----------------------------------------------------------------------*/

    /* PTC12 -- SW2 (S32K144EVB user switch 2)
     * GPIO input, Active Low, internal pull-up enabled
     * Ref. Manual: SW2 connected to PTC12 with external pull-up             */
    { PORTC, PTC, 12u, PORT_MUX_GPIO, PORT_IRQC_DISABLED,
      PORT_PIN_INPUT,  FALSE, FALSE, TRUE,  TRUE,  FALSE },

    /* PTC13 -- SW3 (S32K144EVB user switch 3)
     * GPIO input, Active Low, internal pull-up enabled                      */
    { PORTC, PTC, 13u, PORT_MUX_GPIO, PORT_IRQC_DISABLED,
      PORT_PIN_INPUT,  FALSE, FALSE, TRUE,  TRUE,  FALSE },

    /*------------------------------------------------------------------------
     * PORT D -- RGB LED outputs (FTM0 PWM)
     *----------------------------------------------------------------------*/

    /* PTD0 -- Blue LED (Active Low)
     * ALT2 = FTM0_CH2 PWM output, high drive strength                      */
    { PORTD, PTD, 0u,  PORT_MUX_ALT2, PORT_IRQC_DISABLED,
      PORT_PIN_OUTPUT, TRUE,  FALSE, FALSE, FALSE, FALSE },

    /* PTD15 -- Red LED (Active Low)
     * ALT2 = FTM0_CH0 PWM output, high drive strength                      */
    { PORTD, PTD, 15u, PORT_MUX_ALT2, PORT_IRQC_DISABLED,
      PORT_PIN_OUTPUT, TRUE,  FALSE, FALSE, FALSE, FALSE },

    /* PTD16 -- Green LED (Active Low)
     * ALT2 = FTM0_CH1 PWM output, high drive strength                      */
    { PORTD, PTD, 16u, PORT_MUX_ALT2, PORT_IRQC_DISABLED,
      PORT_PIN_OUTPUT, TRUE,  FALSE, FALSE, FALSE, FALSE },
};

/* Number of pins in the config table -- used by Port_Init() loop           */
#define PORT_PIN_CFG_COUNT  (sizeof(gkastPortPinCfg) / sizeof(gkastPortPinCfg[0u]))

/*===========================================================================
 * PORT CLOCK ENABLE FLAGS
 * Set TRUE for each port that has at least one pin in the table above.
 * Port_Init() enables PCC clock only for ports listed as TRUE.
 *=========================================================================*/
#define PORT_CFG_ENABLE_PORTA   FALSE
#define PORT_CFG_ENABLE_PORTB   TRUE
#define PORT_CFG_ENABLE_PORTC   TRUE
#define PORT_CFG_ENABLE_PORTD   TRUE
#define PORT_CFG_ENABLE_PORTE   FALSE

#endif /* PORT_CFG_H_ */

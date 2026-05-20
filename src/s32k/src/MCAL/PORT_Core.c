/*
 * PORT_Core.c
 *
 * Target:   NXP S32K144 (CPU_S32K144HFT0VLLT)
 * Standard: ISO 26262 ASIL-B
 *
 * Description:
 *   PORT MCAL driver implementation.
 *   Port_Init() iterates the gkastPortPinCfg[] table defined in PORT_Cfg.h
 *   and applies PCR and direction settings for each pin in a single loop.
 *
 *   Previous implementation: ~3000 lines of per-pin expansion with
 *   copy-paste bugs (wrong pin numbers on PORTA pins 2/3/4/6/7/8).
 *   This implementation: ~80 lines, zero copy-paste risk, table-driven.
 *
 * Ref: S32K144 Reference Manual, Chapter 12 (PORT), pages 215-237
 */

#include "Headers.h"
#include "PORT_Core.h"
#include "PORT_Cfg.h"

/*===========================================================================
 * PRIVATE FUNCTION PROTOTYPES
 *=========================================================================*/
static void PORT_EnableClocks(void);

/*===========================================================================
 * PRIVATE FUNCTIONS
 *=========================================================================*/

/*---------------------------------------------------------------------------
 * PORT_EnableClocks
 *
 * Enables PCC peripheral clock for each port configured in PORT_Cfg.h.
 * Clock must be enabled before any PCR register write.
 * Ref. Manual page 958 -- PCC_PORTx registers.
 *--------------------------------------------------------------------------*/
static void PORT_EnableClocks(void)
{
#if(PORT_CFG_ENABLE_PORTA == TRUE)
    PCC->PCCn[PCC_PORTA_INDEX] |= PCC_PCCn_CGC_MASK;   /* Enable clock to PORTA */
#endif

#if(PORT_CFG_ENABLE_PORTB == TRUE)
    PCC->PCCn[PCC_PORTB_INDEX] |= PCC_PCCn_CGC_MASK;   /* Enable clock to PORTB */
#endif

#if(PORT_CFG_ENABLE_PORTC == TRUE)
    PCC->PCCn[PCC_PORTC_INDEX] |= PCC_PCCn_CGC_MASK;   /* Enable clock to PORTC */
#endif

#if(PORT_CFG_ENABLE_PORTD == TRUE)
    PCC->PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC_MASK;   /* Enable clock to PORTD */
#endif

#if(PORT_CFG_ENABLE_PORTE == TRUE)
    PCC->PCCn[PCC_PORTE_INDEX] |= PCC_PCCn_CGC_MASK;   /* Enable clock to PORTE */
#endif
}

/*===========================================================================
 * PUBLIC FUNCTIONS
 *=========================================================================*/

/*---------------------------------------------------------------------------
 * Port_Init
 *
 * Initializes all pins listed in gkastPortPinCfg[] (PORT_Cfg.h).
 * Called once at startup from main.c before NVIC_init_IRQs().
 *
 * Steps per pin:
 *   1. Write PCR register (MUX, IRQC, DSE, PFE, PE, PS, LK)
 *   2. Set GPIO direction (PDDR) if MUX is GPIO and direction is not NOTUSED
 *
 * Pins with u8Direction == PORT_PIN_NOTUSED are skipped entirely.
 * Pins with non-GPIO MUX have direction set by the peripheral (FTM, LPUART).
 *--------------------------------------------------------------------------*/
void Port_Init(void)
{
    uint8 u8Idx = 0u;
    const stPortPinCfg *pstPin = NULL;

    /* Step 1 -- Enable peripheral clocks for all configured ports          */
    PORT_EnableClocks();

    /* Step 2 -- Iterate pin config table and apply each pin's settings     */
    for (u8Idx = 0u; u8Idx < PORT_PIN_CFG_COUNT; u8Idx++)
    {
        pstPin = &gkastPortPinCfg[u8Idx];

        /* Skip pins marked as not used                                     */
        if (pstPin->u8Direction == PORT_PIN_NOTUSED)
        {
            continue;
        }

        /* Write PCR register -- single write covers all fields             */
        PORT_PCR_WRITE(pstPin->pstPort,
                       pstPin->u8Pin,
                       pstPin->u8IrqC,
                       pstPin->u8LockReg,
                       pstPin->u8Mux,
                       pstPin->u8DriveStr,
                       pstPin->u8PassiveFil,
                       pstPin->u8PullEn,
                       pstPin->u8PullSel);

        /* Set GPIO direction -- only applies when MUX is set to GPIO       */
        if (pstPin->u8Mux == PORT_MUX_GPIO)
        {
            if (pstPin->u8Direction == PORT_PIN_OUTPUT)
            {
                PORT_SET_OUTPUT(pstPin->pstGpio, pstPin->u8Pin);
                /* PDDR bit set to 1: output, Ref. Manual page 237          */
            }
            else
            {
                PORT_SET_INPUT(pstPin->pstGpio, pstPin->u8Pin);
                /* PDDR bit cleared to 0: input, Ref. Manual page 237       */
            }
        }
        /* For non-GPIO MUX (ALT2..ALT7), peripheral controls the pin      */
        /* direction -- no PDDR write needed                                */
    }
}

/*===========================================================================
 * INTERRUPT HANDLERS
 *=========================================================================*/

/*---------------------------------------------------------------------------
 * PORTC_IRQHandler
 *
 * Handles PORT C pin interrupt flags.
 * ISF flag must be cleared by software after handling.
 * Ref. Manual page 216 -- PORT_PCR[ISF]
 *
 * Dev Note: Function name from interrupt vector table:
 *           Project_Settings/Startup_Code/startup_S32K144.S
 *--------------------------------------------------------------------------*/
void INTERRUPT_ PORTC_IRQHandler(void)
{
    /* SW2 -- PTC12, S32K144EVB user switch 2                               */
    if (TRUE == PORT_READ_ISF(PORTC, 12u))
    {
        PORT_CLEAR_ISF(PORTC, 12u);
        /* TODO: Add SW2 press handling or set a flag for task notification */
    }

    /* SW3 -- PTC13, S32K144EVB user switch 3                               */
    if (TRUE == PORT_READ_ISF(PORTC, 13u))
    {
        PORT_CLEAR_ISF(PORTC, 13u);
        /* TODO: Add SW3 press handling or set a flag for task notification */
    }
}

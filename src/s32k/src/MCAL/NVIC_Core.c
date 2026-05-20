/*
 * NVIC_Core.c
 *
 * Target:   NXP S32K144 (CPU_S32K144HFT0VLLT)
 * Standard: ISO 26262 ASIL-B
 *
 * Description:
 *   NVIC MCAL driver implementation.
 *   Configures interrupt priorities and enables IRQs for all active
 *   peripherals using a data-driven IRQ table.
 *
 * FreeRTOS interrupt priority rules (enforced here):
 *   Priorities 0..4  -- safety-critical ISRs, MUST NOT call FreeRTOS API
 *   Priorities 5..15 -- can use FreeRTOS fromISR() API safely
 *   configMAX_SYSCALL_INTERRUPT_PRIORITY = 5 (0x50 shifted)
 *
 * Ref: S32K144 Reference Manual, Chapter 9 (NVIC), pages 241-247.
 */

#include "Headers.h"
#include "NVIC_Core.h"

/*===========================================================================
 * PRIVATE TYPES
 *=========================================================================*/

typedef struct
{
    IRQn_Type   eIrqNum;        /* IRQ number from S32K144 device header    */
    uint8       u8Priority;     /* Priority 0x00..0xF0 (4-bit, left-shifted)*/
} stNvicIrqCfg;

/*===========================================================================
 * PRIVATE CONSTANTS -- IRQ configuration table
 *
 * Sequence: always CLEAR_PENDING before ENABLE to prevent spurious ISR
 * on startup if a flag was left set from a previous reset.
 *
 * Priority assignment rationale:
 *   LPUART1    0x00 -- UART Rx/Tx must not be missed, safety-critical comm
 *   ADC0/1     0x00 -- ADC conversions time-critical
 *   FTM0/1     0xA0 -- PWM/timer overflow, normal priority
 *
 * NOTE: LPUART1 and ADC ISRs at priority 0x00 MUST NOT call any FreeRTOS
 * API. If FreeRTOS notification is needed from these ISRs, raise their
 * priority to >= 0x50 (NVIC_PRIORITY_5).
 *=========================================================================*/
static const stNvicIrqCfg gkastNvicIrqCfg[] =
{
    /* FTM0 CH2/CH3 compare match interrupt                                 */
    { FTM0_Ch2_Ch3_IRQn,        NVIC_PRIORITY_10 },

    /* FTM0 overflow / reload interrupt -- 1ms base timer                   */
    { FTM0_Ovf_Reload_IRQn,     NVIC_PRIORITY_10 },

    /* FTM1 overflow / reload interrupt -- 1ms software timer tick          */
    { FTM1_Ovf_Reload_IRQn,     NVIC_PRIORITY_10 },

    /* LPUART1 Rx/Tx interrupt                                              */
    { LPUART1_RxTx_IRQn,        NVIC_PRIORITY_0  },

    /* ADC0 conversion complete interrupt                                   */
    { ADC0_IRQn,                NVIC_PRIORITY_0  },

    /* ADC1 conversion complete interrupt                                   */
    { ADC1_IRQn,                NVIC_PRIORITY_0  },
};

#define NVIC_IRQ_CFG_COUNT  (sizeof(gkastNvicIrqCfg) / sizeof(gkastNvicIrqCfg[0u]))

/*===========================================================================
 * PUBLIC FUNCTIONS
 *=========================================================================*/

/*---------------------------------------------------------------------------
 * NVIC_init_IRQs
 *
 * Configures and enables all IRQs listed in gkastNvicIrqCfg[].
 * Called once at startup from main.c as the last step before
 * vTaskStartScheduler().
 *
 * Sequence per IRQ:
 *   1. Set priority
 *   2. Clear any pending flag (prevents spurious ISR on first enable)
 *   3. Enable IRQ
 *--------------------------------------------------------------------------*/
void NVIC_init_IRQs(void)
{
    uint8 u8Idx = 0u;

    for (u8Idx = 0u; u8Idx < NVIC_IRQ_CFG_COUNT; u8Idx++)
    {
        /* Set priority before enabling -- avoids priority inversion        */
        NVIC_SET_PRIORITY(gkastNvicIrqCfg[u8Idx].eIrqNum,
                          gkastNvicIrqCfg[u8Idx].u8Priority);

        /* Clear any pending flag from previous reset cycle                 */
        NVIC_CLEAR_PENDING(gkastNvicIrqCfg[u8Idx].eIrqNum);

        /* Enable the interrupt                                             */
        NVIC_ENABLE(gkastNvicIrqCfg[u8Idx].eIrqNum);
    }
}

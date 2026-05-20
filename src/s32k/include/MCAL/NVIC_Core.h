/*
 * NVIC_Core.h
 *
 * Target:   NXP S32K144 (CPU_S32K144HFT0VLLT)
 * Standard: ISO 26262 ASIL-B
 *
 * Description:
 *   NVIC MCAL driver interface.
 *   Provides macros for clearing pending IRQs, enabling IRQs, and
 *   setting interrupt priorities via the S32_NVIC registers.
 *
 * Priority model (FreeRTOS-aware):
 *   S32K144 uses 4-bit priority (0..15, lower number = higher priority).
 *   FreeRTOS configMAX_SYSCALL_INTERRUPT_PRIORITY = 5 (shifted to 0x50).
 *   ISRs that call FreeRTOS API:  priority 5..15 (0x50..0xF0)
 *   ISRs that do NOT call FreeRTOS API: priority 0..4 (0x00..0x40)
 *   NEVER call FreeRTOS API from an ISR with priority 0..4.
 *
 * Ref: S32K144 Reference Manual, Chapter 9 (NVIC), Cortex-M4 TRM.
 */

#ifndef MCAL_NVIC_CORE_H_
#define MCAL_NVIC_CORE_H_

#include "Headers.h"

/*===========================================================================
 * PRIORITY CONSTANTS
 * 4-bit priority field, shifted left to occupy bits [7:4] of the IP register
 * Ref: Cortex-M4 TRM -- NVIC_IPRx register format
 *=========================================================================*/
#define NVIC_PRIORITY_0         0x00u   /* Highest -- safety-critical ISR   */
#define NVIC_PRIORITY_5         0x50u   /* FreeRTOS syscall boundary        */
#define NVIC_PRIORITY_10        0xA0u   /* Normal peripheral ISR            */
#define NVIC_PRIORITY_15        0xF0u   /* Lowest -- background ISR         */

/*===========================================================================
 * NVIC OPERATION MACROS
 *
 * Formula for register index and bit position:
 *   Register index = IRQn / 32
 *   Bit position   = IRQn % 32
 *
 * ICPR (Interrupt Clear Pending Register):
 *   Write 1 to clear pending state before enabling -- prevents spurious ISR
 *   Ref. Manual page 243
 *
 * ISER (Interrupt Set Enable Register):
 *   Write 1 to enable the interrupt
 *   Ref. Manual page 241
 *
 * IP (Interrupt Priority Register):
 *   8-bit field per IRQ, priority in bits [7:4]
 *   Ref. Manual page 247
 *=========================================================================*/

/* Clear any pending interrupt before enabling -- always call before NVIC_ENABLE */
#define NVIC_CLEAR_PENDING(IRQn) \
    (S32_NVIC->ICPR[(uint32)(IRQn) / 32u] = (1u << ((uint32)(IRQn) % 32u)))

/* Enable interrupt                                                         */
#define NVIC_ENABLE(IRQn) \
    (S32_NVIC->ISER[(uint32)(IRQn) / 32u] = (1u << ((uint32)(IRQn) % 32u)))

/* Set interrupt priority -- priority in bits [7:4], bits [3:0] reserved   */
#define NVIC_SET_PRIORITY(IRQn, Priority) \
    (S32_NVIC->IP[(uint32)(IRQn)] = (uint8)(Priority))

/*===========================================================================
 * PUBLIC FUNCTION DECLARATIONS
 *=========================================================================*/
extern void NVIC_init_IRQs(void);

#endif /* MCAL_NVIC_CORE_H_ */

/*
 * PORT_Core.h
 *
 * Target:   NXP S32K144 (CPU_S32K144HFT0VLLT)
 * Standard: ISO 26262 ASIL-B
 *
 * Description:
 *   PORT MCAL driver interface.
 *   Provides data-driven pin configuration using a compile-time
 *   const table of stPortPinCfg structs. Port_Init() iterates the
 *   table and applies each pin's PCR and direction in a single loop,
 *   replacing the previous 3000-line per-pin expansion.
 *
 * Register references: S32K144 Reference Manual, Chapter 12 (PORT).
 */

#ifndef PORT_CORE_H_
#define PORT_CORE_H_

#include "Headers.h"

/*===========================================================================
 * CONSTANTS -- Pin direction values
 * Used in stPortPinCfg.u8Direction field and PORT_Cfg.h
 *=========================================================================*/
#define PORT_PIN_INPUT          0u      /* PDDR bit cleared -- input        */
#define PORT_PIN_OUTPUT         1u      /* PDDR bit set -- output           */
#define PORT_PIN_NOTUSED        2u      /* Pin not configured, skip         */

/*===========================================================================
 * CONSTANTS -- MUX values
 * Ref. Manual page 217 -- PCR[MUX] field
 *=========================================================================*/
#define PORT_MUX_ANALOG         0b000   /* Disabled / analog input          */
#define PORT_MUX_GPIO           0b001   /* GPIO                             */
#define PORT_MUX_ALT2           0b010   /* Chip-specific alternate 2        */
#define PORT_MUX_ALT3           0b011   /* Chip-specific alternate 3        */
#define PORT_MUX_ALT4           0b100   /* Chip-specific alternate 4        */
#define PORT_MUX_ALT5           0b101   /* Chip-specific alternate 5        */
#define PORT_MUX_ALT6           0b110   /* Chip-specific alternate 6        */
#define PORT_MUX_ALT7           0b111   /* Chip-specific alternate 7        */

/*===========================================================================
 * CONSTANTS -- Interrupt/DMA trigger values
 * Ref. Manual page 216 -- PCR[IRQC] field
 * Only listed and allowed values -- reserved values have no effect.
 *=========================================================================*/
#define PORT_IRQC_DISABLED      0b0000  /* ISF flag disabled                */
#define PORT_IRQC_DMA_RISING    0b0001  /* DMA request on rising edge       */
#define PORT_IRQC_DMA_FALLING   0b0010  /* DMA request on falling edge      */
#define PORT_IRQC_DMA_EITHER    0b0011  /* DMA request on either edge       */
#define PORT_IRQC_IRQ_LOW       0b1000  /* IRQ when logic 0                 */
#define PORT_IRQC_IRQ_RISING    0b1001  /* IRQ on rising edge               */
#define PORT_IRQC_IRQ_FALLING   0b1010  /* IRQ on falling edge              */
#define PORT_IRQC_IRQ_EITHER    0b1011  /* IRQ on either edge               */
#define PORT_IRQC_IRQ_HIGH      0b1100  /* IRQ when logic 1                 */

/*===========================================================================
 * PIN CONFIG STRUCT
 *
 * One entry per pin. Stored as const in flash.
 * Port_Init() iterates the table from PORT_Cfg.h.
 *
 * Fields:
 *   pstPort      -- Port base address (PORTA, PORTB, PORTC, PORTD, PORTE)
 *   pstGpio      -- GPIO base address (PTA, PTB, PTC, PTD, PTE)
 *   u8Pin        -- Pin number 0..31
 *   u8Mux        -- PCR MUX field (PORT_MUX_xxx)
 *   u8IrqC       -- PCR IRQC field (PORT_IRQC_xxx)
 *   u8Direction  -- PORT_PIN_INPUT, PORT_PIN_OUTPUT, PORT_PIN_NOTUSED
 *   u8DriveStr   -- PCR DSE: 0=low drive, 1=high drive strength
 *   u8PassiveFil -- PCR PFE: 0=passive filter disabled, 1=enabled
 *   u8PullEn     -- PCR PE:  0=pull resistor disabled, 1=enabled
 *   u8PullSel    -- PCR PS:  0=pull down, 1=pull up (only if u8PullEn=1)
 *   u8LockReg    -- PCR LK:  0=not locked, 1=PCR locked until reset
 *=========================================================================*/
typedef struct
{
    PORT_Type   *pstPort;
    GPIO_Type   *pstGpio;
    uint8        u8Pin;
    uint8        u8Mux;
    uint8        u8IrqC;
    uint8        u8Direction;
    uint8        u8DriveStr;
    uint8        u8PassiveFil;
    uint8        u8PullEn;
    uint8        u8PullSel;
    uint8        u8LockReg;
} stPortPinCfg;

/*===========================================================================
 * MACROS -- PCR register write
 * Ref. Manual page 215
 *=========================================================================*/

/* Write all PCR fields in a single register write                          */
#define PORT_PCR_WRITE(pstPort, u8Pin, u8IrqC, u8Lk, u8Mux, u8Dse, u8Pfe, u8Pe, u8Ps) \
    ((pstPort)->PCR[(u8Pin)] =  PORT_PCR_IRQC(u8IrqC)  |   \
                                PORT_PCR_LK(u8Lk)       |   \
                                PORT_PCR_MUX(u8Mux)     |   \
                                PORT_PCR_DSE(u8Dse)     |   \
                                PORT_PCR_PFE(u8Pfe)     |   \
                                PORT_PCR_PE(u8Pe)        |   \
                                PORT_PCR_PS(u8Ps))

/* Clear all PCR fields for a pin (reset to default)                        */
#define PORT_PCR_CLEAR(pstPort, u8Pin) \
    ((pstPort)->PCR[(u8Pin)] = 0u)

/* Set pin direction -- input: PDDR bit cleared, Ref. Manual page 237       */
#define PORT_SET_INPUT(pstGpio, u8Pin) \
    ((pstGpio)->PDDR &= ~(1u << (u8Pin)))

/* Set pin direction -- output: PDDR bit set, Ref. Manual page 237          */
#define PORT_SET_OUTPUT(pstGpio, u8Pin) \
    ((pstGpio)->PDDR |= (1u << (u8Pin)))

/* Read interrupt status flag for a pin                                     */
#define PORT_READ_ISF(pstPort, u8Pin) \
    (((pstPort)->PCR[(u8Pin)] & PORT_PCR_ISF_MASK) >> PORT_PCR_ISF_SHIFT)

/* Clear interrupt status flag for a pin                                    */
#define PORT_CLEAR_ISF(pstPort, u8Pin) \
    ((pstPort)->PCR[(u8Pin)] |= PORT_PCR_ISF_MASK)

/*===========================================================================
 * PUBLIC FUNCTION DECLARATIONS
 *=========================================================================*/
extern void Port_Init(void);

#endif /* PORT_CORE_H_ */

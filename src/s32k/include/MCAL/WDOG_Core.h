/*
 * WDOG_Core.h
 *
 * Target:   NXP S32K144 (CPU_S32K144HFT0VLLT)
 * Standard: ISO 26262 ASIL-B
 *
 * Description:
 *   Watchdog (WDOG) MCAL driver interface.
 *   Provides WDOG_Init() for configuration and WDOG_Refresh() for
 *   periodic service. Configuration parameters are in WDOG_Cfg.h.
 *
 * Clock source: LPO (128 kHz), 256x prescaler
 *   WDOG tick period = 1 / (128000 / 256) = 2ms per count
 *   Formula in WDOG_CAL_TIMEOUT_VAL: counts = seconds * 500
 *   Ref: WDOG_Cfg.h comment -- DevHelp: CLK_CRITICAL
 *
 * Unlock sequence:
 *   Write 0xD928C520 to WDOG->CNT -- unlocks for one bus clock cycle
 *   Must complete within 128 bus cycles or lock re-engages
 *   Ref. Manual page 503 -- WDOG_CNT register
 *
 * Refresh sequence (interrupt-safe):
 *   Disable interrupts -> write 0xB480A602 -> re-enable interrupts
 *   Ref. Manual page 503 -- WDOG_CNT register
 *
 * Safety constraints (ISO 26262):
 *   WDOG_Refresh() is called from vTask_WdogRefresh at highest FreeRTOS
 *   priority (configMAX_PRIORITIES-1). If the scheduler stops running,
 *   this task misses its deadline and the WDOG resets the MCU.
 *   Do NOT call WDOG_Refresh() from any other context.
 */

#ifndef WDOG_CORE_H_
#define WDOG_CORE_H_

#include "Headers.h"
#include "WDOG_Cfg.h"

/*===========================================================================
 * REGISTER OPERATION MACROS
 * Ref: S32K144 Reference Manual, Chapter 26 (WDOG), pages 499-519
 *=========================================================================*/

/* Unlock WDOG registers -- write magic value to CNT register
 * Must be followed immediately by configuration writes
 * Ref. Manual page 503                                                     */
#define WDOG_UNLOCK_REGS()          (WDOG->CNT = 0xD928C520u)

/* Refresh WDOG -- write magic value to reset the timeout counter
 * Must be called within WDOG_TIMEOUT_VAL seconds
 * Ref. Manual page 503                                                     */
#define WDOG_REFRESH_SET()          (WDOG->CNT = 0xB480A602u)

/* Read unlock status -- bit 11 (ULK) of CS register
 * Returns non-zero when registers are unlocked and ready to write
 * Ref. Manual page 505                                                     */
#define WDOG_READ_ULK_STAT()        (WDOG->CS & 0x0800u)

/* Read reconfiguration status -- bit 10 (RCS) of CS register
 * Returns non-zero when new configuration has taken effect
 * Ref. Manual page 505                                                     */
#define WDOG_READ_RCS_STAT()        (WDOG->CS & 0x0400u)

/* Write total timeout value to TOVAL register
 * Ref. Manual page 510                                                     */
#define WDOG_WRITE_TOTAL_VAL(val)   (WDOG->TOVAL = (val))

/* Write window value to WIN register (only used when WIN mode is enabled)
 * Window value must be less than timeout value
 * Ref. Manual page 511                                                     */
#define WDOG_WRITE_WINDOW_VAL(val)  (WDOG->WIN = (val))

/* Calculate WDOG counter value from timeout in seconds
 * Formula: counts = seconds * (ClkHz / Prescaler)
 *        = seconds * (128000 / 256) = seconds * 500
 * Ref. Manual page 499 -- clock source and prescaler configuration         */
#define WDOG_CAL_TIMEOUT_VAL(sec)   ((sec) * 500u)

/* Write WDOG control/status register in one atomic write
 * All fields must be written together after unlock
 * Ref. Manual page 505                                                     */
#define WDOG_CS_REG(WinMode, Cmd32en, ClkSrc, ReConfig, IntrptCfg,         \
                    TestMode, DebugMode, WaitMode, StopMode, Enable, PreScale) \
    (WDOG->CS = (WDOG_CS_WIN(WinMode)       |                               \
                 WDOG_CS_CMD32EN(Cmd32en)   |                               \
                 WDOG_CS_CLK(ClkSrc)        |                               \
                 WDOG_CS_UPDATE(ReConfig)   |                               \
                 WDOG_CS_INT(IntrptCfg)     |                               \
                 WDOG_CS_TST(TestMode)      |                               \
                 WDOG_CS_DBG(DebugMode)     |                               \
                 WDOG_CS_WAIT(WaitMode)     |                               \
                 WDOG_CS_STOP(StopMode)     |                               \
                 WDOG_CS_EN(Enable)         |                               \
                 WDOG_CS_PRES(PreScale)))

/*===========================================================================
 * CLOCK SOURCE CONSTANTS
 * Ref. Manual page 507 -- WDOG_CS[CLK] field
 *=========================================================================*/
#define WDOG_BUS_CLK            0b00    /* Bus clock                        */
#define WDOG_INTRLPO_CLK        0b01    /* LPO 128 kHz -- used in this proj */
#define WDOG_INTRL_CLK          0b10    /* Internal clock                   */
#define WDOG_EXT_CLK            0b11    /* External clock                   */

/*===========================================================================
 * TEST MODE CONSTANTS
 * Ref. Manual page 507 -- WDOG_CS[TST] field
 *=========================================================================*/
#define WDOG_TEST_DISABLE       0b00    /* Normal operation, test disabled  */
#define WDOG_TEST_ENABLE        0b01    /* User mode test enabled           */
#define WDOG_TEST_LOWBYTE       0b10    /* Test low byte of counter         */
#define WDOG_TEST_HIGHBYTE      0b11    /* Test high byte of counter        */

/*===========================================================================
 * COMPILE-TIME SAFETY CHECKS
 *
 * Window value check only applies when window mode is enabled.
 * WDOG_WINDOW_VAL is a raw counter value (hex), not seconds -- it is not
 * comparable to WDOG_TIMEOUT_VAL (seconds) directly.
 * Window mode is DISABLE in this project so no check is needed here.
 * The timeout range check uses the seconds value directly.
 *=========================================================================*/
#if(WDOG_WIN_MODE == ENABLE)
    #if(WDOG_WIN_VAL >= WDOG_CAL_TIMEOUT_VAL(WDOG_TIMEOUT_VAL))
        #error "WDOG_WIN_VAL (counter) must be less than WDOG_CAL_TIMEOUT_VAL. Ref. Manual page 510."
    #endif
#endif

#if(WDOG_TIMEOUT_VAL >= 131u)
    #error "WDOG_TIMEOUT_VAL must be less than 131 seconds (max counter value at LPO/256)."
#endif

/*===========================================================================
 * PUBLIC FUNCTION DECLARATIONS
 *=========================================================================*/
extern void WDOG_Init(void);
extern void WDOG_Refresh(void);

#endif /* WDOG_CORE_H_ */

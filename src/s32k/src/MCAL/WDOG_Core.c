/*
 * WDOG_Core.c
 *
 * Target:   NXP S32K144 (CPU_S32K144HFT0VLLT)
 * Standard: ISO 26262 ASIL-B
 *
 * Description:
 *   Watchdog (WDOG) MCAL driver implementation.
 *   Configures WDOG on startup and provides interrupt-safe refresh.
 *
 * Ref: S32K144 Reference Manual, Chapter 26 (WDOG), pages 499-519.
 */

#include "Headers.h"
#include "WDOG_Core.h"

/*===========================================================================
 * PUBLIC FUNCTIONS
 *=========================================================================*/

/*---------------------------------------------------------------------------
 * WDOG_Init
 *
 * Configures the watchdog using parameters from WDOG_Cfg.h.
 * Must be called before any other peripheral initialization.
 *
 * Sequence:
 *   1. Unlock registers -- write magic value to WDOG->CNT
 *   2. Wait for unlock status bit to confirm
 *   3. Write timeout value to TOVAL
 *   4. Optionally write window value to WIN
 *   5. Write all CS fields in a single atomic write
 *   6. Wait for reconfiguration status bit to confirm effect
 *
 * CAUTION: Steps 1-6 must complete within 128 bus clock cycles after
 * unlock or the WDOG re-locks. Do not add delays between unlock and config.
 * Ref. Manual page 503.
 *--------------------------------------------------------------------------*/
void WDOG_Init(void)
{
    volatile uint32 u32TimeoutCounts = 0u;

    /* Calculate counter value from configured timeout in seconds           */
    u32TimeoutCounts = WDOG_CAL_TIMEOUT_VAL(WDOG_TIMEOUT_VAL);

    /* Unlock WDOG registers -- write magic value 0xD928C520                */
    WDOG_UNLOCK_REGS();

    /* Wait until registers are confirmed unlocked (ULK bit set)            */
    while (WDOG_READ_ULK_STAT() == 0u)
    {
        /* Ref. Manual page 505 -- CS[ULK] set when registers writable      */
    }

    /* Write timeout value -- must be done before CS write                  */
    WDOG_WRITE_TOTAL_VAL(u32TimeoutCounts);

    /* Write window value if window mode is enabled                         */
#if(WDOG_WIN_MODE == ENABLE)
    WDOG_WRITE_WINDOW_VAL(WDOG_WIN_VAL);
    /* Window value must be < timeout value -- enforced by WDOG_Core.h      */
#endif

    /* Write control/status register -- all fields in one atomic write      */
    WDOG_CS_REG(WDOG_WIN_MODE,      /* WIN:    window mode enable/disable   */
                WDOG_CMD32EN,       /* CMD32EN: 32-bit command word enable  */
                WDOG_CLK_SRC,       /* CLK:    clock source selection       */
                WDOG_RECONFIG,      /* UPDATE: allow reconfiguration        */
                WDOG_INRPT_CFG,     /* INT:    interrupt before reset       */
                WDOG_TEST_MODE,     /* TST:    test mode selection          */
                WDOG_DEBUG_MODE,    /* DBG:    run in debug mode            */
                WDOG_WAIT_MODE,     /* WAIT:   run in wait mode             */
                WDOG_STOP_MODE,     /* STOP:   run in stop mode             */
                WDOG_STATUS_CFG,    /* EN:     watchdog enable              */
                WDOG_PRESCALE);     /* PRES:   256x prescaler enable        */

    /* Wait until new configuration has taken effect (RCS bit set)          */
    while (WDOG_READ_RCS_STAT() == 0u)
    {
        /* Ref. Manual page 505 -- CS[RCS] set when reconfiguration complete*/
    }
}

/*---------------------------------------------------------------------------
 * WDOG_Refresh
 *
 * Services the watchdog to prevent reset.
 * Must be called periodically within WDOG_TIMEOUT_VAL seconds.
 *
 * Called from vTask_WdogRefresh in main.c every 500ms.
 * WDOG timeout is configured to 4s in WDOG_Cfg.h -- safe margin.
 *
 * Interrupt-safe: disables global interrupts during the refresh write
 * to prevent the 2-write sequence from being interrupted.
 * Ref. Manual page 503 -- CNT register refresh sequence.
 *
 * ISO 26262 Note:
 *   This function must only be called from the dedicated WdogRefresh task.
 *   Calling from multiple contexts risks corrupting the refresh sequence.
 *--------------------------------------------------------------------------*/
void WDOG_Refresh(void)
{
    DISABLE_INTERRUPTS();

    WDOG_REFRESH_SET();     /* Write magic value 0xB480A602 to WDOG->CNT    */

    ENABLE_INTERRUPTS();
}

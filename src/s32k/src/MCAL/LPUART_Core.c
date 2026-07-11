/*
 * LPUART_Core.c
 *
 * Target:   NXP S32K144 (CPU_S32K144HFT0VLLT)
 * Standard: ISO 26262 ASIL-B
 *
 * Description:
 *   LPUART MCAL driver implementation.
 *   Supports LPUART0, LPUART1, LPUART2 modules.
 *   Interrupt-driven Tx with state machine, polling and ISR Rx.
 *
 * Clock:
 *   PCC_PCCn_PCS(0b001) selects SOSCDIV2 (8 MHz crystal) as UART clock source.
 *   Baud rate = ClkHz / ((OSR+1) * SBR)
 *   LPUART1 @ 115200: 8MHz / ((9+1) * 7) = 114286 baud (-0.79%)
 *
 * Tx state machine (LPUART1):
 *   LPUart1_TransmitString() arms the buffer and enables Tx interrupt.
 *   LPUART1_RxTx_IRQHandler() sends byte-by-byte until null terminator.
 *   bTxStatusFlag semaphore prevents re-entry during transmission.
 *
 * Known bugs fixed in this version:
 *   1. LPUART2_RxTx_IRQHandler was copying to LPUART0 instead of LPUART2
 *   2. LPUart1_TransmitString was defined twice (under LPUART_1 and LPUART_2)
 *      -- renamed LPUART_2 version to LPUart2_TransmitString
 *
 * Ref: S32K144 Reference Manual, Chapter 47 (LPUART), pages 1695-1735.
 */

#include "Headers.h"

/*===========================================================================
 * PRIVATE VARIABLES
 *=========================================================================*/

/* Rx ring buffers -- one per UART instance                                 */
static stLPUARTRxBuf gstLPUARTRxBuf[3u];

/* Tx buffers -- one per UART instance                                      */
static stLPUARTRxBuf gstLPUARTTxBuf[3u];

/* Tx busy flag for LPUART1 interrupt-driven transmission
 * TRUE  = transmitter idle, ready to accept new string
 * FALSE = transmission in progress, caller must wait                       */
static uint8 gu8TxStatusFlag = TRUE;

/*===========================================================================
 * PUBLIC FUNCTIONS -- Initialization
 *=========================================================================*/

/*---------------------------------------------------------------------------
 * LPUART_Init
 *
 * Top-level LPUART initialization. Calls instance init functions
 * based on compile-time enable flags in LPUARTn_Cfg.h.
 * Called from main.c during MCAL initialization sequence.
 *--------------------------------------------------------------------------*/
void LPUART_Init(void)
{
#if(LPUART_0 == ENABLE)
    LPUart0_Init();
#endif

#if(LPUART_1 == ENABLE)
    LPUart1_Init();
#endif

#if(LPUART_2 == ENABLE)
    LPUart2_Init();
#endif
}

/*---------------------------------------------------------------------------
 * LPUart0_Init
 *
 * Initializes LPUART0 with parameters from LPUARTn_Cfg.h.
 * Note: Clock index uses PCC_LPUART0_INDEX for LPUART0.
 *--------------------------------------------------------------------------*/
#if(LPUART_0 == ENABLE)

void LPUart0_Init(void)
{
    /* Enable PCC clock with SIRCDIV2 (8 MHz) as source                    */
    PCC->PCCn[PCC_LPUART0_INDEX] &= ~PCC_PCCn_CGC_MASK;    /* Disable clock to change PCS */
    PCC->PCCn[PCC_LPUART0_INDEX] |=  PCC_PCCn_PCS(0b010)   /* Clock Src=2: SIRCDIV2       */
                                  |  PCC_PCCn_CGC_MASK;     /* Enable clock                */

    /* Configure baud rate register                                         */
    LPUART_n_SET_BAUD_RATE(LPUART0,
                           LPUART_0_BAUD_MATCHMD1,
                           LPUART_0_BAUD_MATCHMD2,
                           LPUART_0_BAUD_TENBITMD,
                           LPUART_0_BAUD_OVRSAMPRATIO,
                           LPUART_0_BAUD_TXDMA,
                           LPUART_0_BAUD_RXDMA,
                           LPUART_0_BAUD_RXIDLEDMA,
                           LPUART_0_BAUD_MATCHCFG,
                           LPUART_0_BAUD_BOTHEDGEEN,
                           LPUART_0_BAUD_RESYNC,
                           LPUART_0_BAUD_LINBRKINTRP,
                           LPUART_0_BAUD_RXACTEDGEINT,
                           LPUART_0_BAUD_NOOFSTOPBITS,
                           LPUART_0_BAUD_BAUDRATEMOD);

    /* Configure control register                                           */
    LPUART_n_SET_CTRL_REG(LPUART0,
                          LPUART_0_CTRL_RX8TX9,
                          LPUART_0_CTRL_RX9TX8,
                          LPUART_0_CTRL_SINGWIRE,
                          LPUART_0_CTRL_TXDATAINV,
                          LPUART_0_CTRL_OVRRUNINPT,
                          LPUART_0_CTRL_NOISEINTP,
                          LPUART_0_CTRL_FRMEERRINTP,
                          LPUART_0_CTRL_PARIERRINTP,
                          LPUART_0_CTRL_TXINTP,
                          LPUART_0_CTRL_TXCOMPINTP,
                          LPUART_0_CTRL_RXINTP,
                          LPUART_0_CTRL_IDLLINEINTP,
                          LPUART_0_CTRL_TXEN,
                          LPUART_0_CTRL_RXEN,
                          LPUART_0_CTRL_RXWAKEUPCTRL,
                          LPUART_0_CTRL_SNDBRK,
                          LPUART_0_CTRL_MATCH1INTP,
                          LPUART_0_CTRL_MATCH2INTP,
                          LPUART_0_CTRL_7BITMODE,
                          LPUART_0_CTRL_IDLECFG,
                          LPUART_0_CTRL_LOOPMODE,
                          LPUART_0_CTRL_DOZE,
                          LPUART_0_CTRL_RXSRCSEL,
                          LPUART_0_CTRL_9BIT8BITMODE,
                          LPUART_0_CTRL_RXWAKEUPMETH,
                          LPUART_0_CTRL_IDLELINETYPE,
                          LPUART_0_CTRL_PARITYEN,
                          LPUART_0_CTRL_PARITYTYPE);
}

#endif /* LPUART_0 */

/*---------------------------------------------------------------------------
 * LPUart1_Init
 *
 * Initializes LPUART1 with parameters from LPUARTn_Cfg.h.
 * LPUART1 is the primary debug/status UART on S32K144EVB.
 * Uses interrupt-driven Tx state machine.
 *--------------------------------------------------------------------------*/
#if(LPUART_1 == ENABLE)

void LPUart1_Init(void)
{
    /* Enable PCC clock with SOSCDIV2 (8 MHz crystal) as source            */
    PCC->PCCn[PCC_LPUART1_INDEX] &= ~PCC_PCCn_CGC_MASK;    /* Disable clock to change PCS */
    PCC->PCCn[PCC_LPUART1_INDEX] |=  PCC_PCCn_PCS(0b001)   /* Clock Src=1: SOSCDIV2       */
                                  |  PCC_PCCn_CGC_MASK;     /* Enable clock                */

    /* Configure baud rate register                                         */
    LPUART_n_SET_BAUD_RATE(LPUART1,
                           LPUART_1_BAUD_MATCHMD1,
                           LPUART_1_BAUD_MATCHMD2,
                           LPUART_1_BAUD_TENBITMD,
                           LPUART_1_BAUD_OVRSAMPRATIO,
                           LPUART_1_BAUD_TXDMA,
                           LPUART_1_BAUD_RXDMA,
                           LPUART_1_BAUD_RXIDLEDMA,
                           LPUART_1_BAUD_MATCHCFG,
                           LPUART_1_BAUD_BOTHEDGEEN,
                           LPUART_1_BAUD_RESYNC,
                           LPUART_1_BAUD_LINBRKINTRP,
                           LPUART_1_BAUD_RXACTEDGEINT,
                           LPUART_1_BAUD_NOOFSTOPBITS,
                           LPUART_1_BAUD_BAUDRATEMOD);

    /* Configure control register                                           */
    LPUART_n_SET_CTRL_REG(LPUART1,
                          LPUART_1_CTRL_RX8TX9,
                          LPUART_1_CTRL_RX9TX8,
                          LPUART_1_CTRL_SINGWIRE,
                          LPUART_1_CTRL_TXDATAINV,
                          LPUART_1_CTRL_OVRRUNINPT,
                          LPUART_1_CTRL_NOISEINTP,
                          LPUART_1_CTRL_FRMEERRINTP,
                          LPUART_1_CTRL_PARIERRINTP,
                          LPUART_1_CTRL_TXINTP,
                          LPUART_1_CTRL_TXCOMPINTP,
                          LPUART_1_CTRL_RXINTP,
                          LPUART_1_CTRL_IDLLINEINTP,
                          LPUART_1_CTRL_TXEN,
                          LPUART_1_CTRL_RXEN,
                          LPUART_1_CTRL_RXWAKEUPCTRL,
                          LPUART_1_CTRL_SNDBRK,
                          LPUART_1_CTRL_MATCH1INTP,
                          LPUART_1_CTRL_MATCH2INTP,
                          LPUART_1_CTRL_7BITMODE,
                          LPUART_1_CTRL_IDLECFG,
                          LPUART_1_CTRL_LOOPMODE,
                          LPUART_1_CTRL_DOZE,
                          LPUART_1_CTRL_RXSRCSEL,
                          LPUART_1_CTRL_9BIT8BITMODE,
                          LPUART_1_CTRL_RXWAKEUPMETH,
                          LPUART_1_CTRL_IDLELINETYPE,
                          LPUART_1_CTRL_PARITYEN,
                          LPUART_1_CTRL_PARITYTYPE);

    /* Configure watermark register (Tx/Rx FIFO thresholds)                */
    LPUART_n_SET_WATER_REG(LPUART1,
                           LPUART_1_WATER_TXCOUNT,
                           LPUART_1_WATER_RXCOUNT);
}

#endif /* LPUART_1 */

/*---------------------------------------------------------------------------
 * LPUart2_Init
 *--------------------------------------------------------------------------*/
#if(LPUART_2 == ENABLE)

void LPUart2_Init(void)
{
    /* Enable PCC clock with SIRCDIV2 (8 MHz) as source                    */
    PCC->PCCn[PCC_LPUART2_INDEX] &= ~PCC_PCCn_CGC_MASK;    /* Disable clock to change PCS */
    PCC->PCCn[PCC_LPUART2_INDEX] |=  PCC_PCCn_PCS(0b010)   /* Clock Src=2: SIRCDIV2       */
                                  |  PCC_PCCn_CGC_MASK;     /* Enable clock                */

    /* Configure baud rate register                                         */
    LPUART_n_SET_BAUD_RATE(LPUART2,
                           LPUART_2_BAUD_MATCHMD1,
                           LPUART_2_BAUD_MATCHMD2,
                           LPUART_2_BAUD_TENBITMD,
                           LPUART_2_BAUD_OVRSAMPRATIO,
                           LPUART_2_BAUD_TXDMA,
                           LPUART_2_BAUD_RXDMA,
                           LPUART_2_BAUD_RXIDLEDMA,
                           LPUART_2_BAUD_MATCHCFG,
                           LPUART_2_BAUD_BOTHEDGEEN,
                           LPUART_2_BAUD_RESYNC,
                           LPUART_2_BAUD_LINBRKINTRP,
                           LPUART_2_BAUD_RXACTEDGEINT,
                           LPUART_2_BAUD_NOOFSTOPBITS,
                           LPUART_2_BAUD_BAUDRATEMOD);

    /* Configure control register                                           */
    LPUART_n_SET_CTRL_REG(LPUART2,
                          LPUART_2_CTRL_RX8TX9,
                          LPUART_2_CTRL_RX9TX8,
                          LPUART_2_CTRL_SINGWIRE,
                          LPUART_2_CTRL_TXDATAINV,
                          LPUART_2_CTRL_OVRRUNINPT,
                          LPUART_2_CTRL_NOISEINTP,
                          LPUART_2_CTRL_FRMEERRINTP,
                          LPUART_2_CTRL_PARIERRINTP,
                          LPUART_2_CTRL_TXINTP,
                          LPUART_2_CTRL_TXCOMPINTP,
                          LPUART_2_CTRL_RXINTP,
                          LPUART_2_CTRL_IDLLINEINTP,
                          LPUART_2_CTRL_TXEN,
                          LPUART_2_CTRL_RXEN,
                          LPUART_2_CTRL_RXWAKEUPCTRL,
                          LPUART_2_CTRL_SNDBRK,
                          LPUART_2_CTRL_MATCH1INTP,
                          LPUART_2_CTRL_MATCH2INTP,
                          LPUART_2_CTRL_7BITMODE,
                          LPUART_2_CTRL_IDLECFG,
                          LPUART_2_CTRL_LOOPMODE,
                          LPUART_2_CTRL_DOZE,
                          LPUART_2_CTRL_RXSRCSEL,
                          LPUART_2_CTRL_9BIT8BITMODE,
                          LPUART_2_CTRL_RXWAKEUPMETH,
                          LPUART_2_CTRL_IDLELINETYPE,
                          LPUART_2_CTRL_PARITYEN,
                          LPUART_2_CTRL_PARITYTYPE);
}

#endif /* LPUART_2 */

/*===========================================================================
 * PUBLIC FUNCTIONS -- Transmit
 *=========================================================================*/

/*---------------------------------------------------------------------------
 * LPUart0_TransmitChar
 *
 * Blocking single character transmit on LPUART0.
 * Polls TDRE flag until transmit buffer is empty then sends.
 * Use only for debug/init sequences where blocking is acceptable.
 * Ref. Manual page 1705 -- STAT[TDRE]
 *--------------------------------------------------------------------------*/
#if(LPUART_0 == ENABLE)

void LPUart0_TransmitChar(sint8 s8Word)
{
    while (LPUART_x_READTDREFLAG(LPUART0) == 0u);  /* Wait for Tx buffer empty */
    LPUART_x_SENDWORD(LPUART0, s8Word);
}

void LPUart0_TransmitString(sint8 *s8DataBuf, uint8 u8Size)
{
    uint8 u8Index = 0u;

    for (u8Index = 0u; u8Index < u8Size; u8Index++)
    {
        LPUart0_TransmitChar(s8DataBuf[u8Index]);
    }
}

#endif /* LPUART_0 */

/*---------------------------------------------------------------------------
 * LPUart1_TransmitString
 *
 * Non-blocking interrupt-driven string transmit on LPUART1.
 * Arms the Tx buffer and enables Tx interrupt -- actual transmission
 * happens byte-by-byte in LPUART1_RxTx_IRQHandler().
 *
 * Returns STD_OK if buffer armed successfully.
 * Returns STD_NOK if transmission already in progress (gu8TxStatusFlag=FALSE).
 * Caller must retry if STD_NOK is returned.
 *
 * String must be null-terminated -- ISR uses null as end-of-transmission marker.
 * Ref. Manual page 1709 -- CTRL[TIE] Tx interrupt enable
 *--------------------------------------------------------------------------*/
#if(LPUART_1 == ENABLE)

STD_FsmStates LPUart1_TransmitString(sint8 *s8DataBuf, uint8 u8Size)
{
    STD_FsmStates eRetval = STD_NOK;
    uint8         u8Idx   = 0u;

    if (s8DataBuf == NULLPTR)
    {
        return STD_NOK;
    }

    if (gu8TxStatusFlag == TRUE)
    {
        /* Copy data into Tx buffer                                         */
        for (u8Idx = 0u; u8Idx < u8Size; u8Idx++)
        {
            gstLPUARTTxBuf[eLPUART_1].s8Buffer[u8Idx] = s8DataBuf[u8Idx];
        }

        /* Null-terminate -- ISR uses this as end-of-transmission marker    */
        gstLPUARTTxBuf[eLPUART_1].s8Buffer[u8Idx] = 0;
        gstLPUARTTxBuf[eLPUART_1].u8IndexPos      = 0u;

        /* Mark transmitter busy before enabling interrupt                  */
        gu8TxStatusFlag = FALSE;

        /* Enable TC interrupt -- TC=1 in idle state fires ISR immediately,
         * which loads the first byte. Subsequent bytes sent on each TC.   */
        LPUART_n_ENABLE_CTRL_TXCOMPLETEINTP(LPUART1);
        LPUART_n_DISABLE_CTRL_RXINTP(LPUART1);

        eRetval = STD_OK;
    }

    return eRetval;
}

#endif /* LPUART_1 */

/*---------------------------------------------------------------------------
 * LPUart2_TransmitChar / LPUart2_TransmitString
 *
 * Blocking transmit on LPUART2 (same pattern as LPUART0).
 *--------------------------------------------------------------------------*/
#if(LPUART_2 == ENABLE)

void LPUart2_TransmitChar(sint8 s8Word)
{
    while (LPUART_x_READTDREFLAG(LPUART2) == 0u);
    LPUART_x_SENDWORD(LPUART2, s8Word);
}

void LPUart2_TransmitString(sint8 *s8DataBuf, uint8 u8Size)
{
    uint8 u8Index = 0u;

    for (u8Index = 0u; u8Index < u8Size; u8Index++)
    {
        LPUart2_TransmitChar(s8DataBuf[u8Index]);
    }
}

#endif /* LPUART_2 */

/*===========================================================================
 * PUBLIC FUNCTIONS -- Receive (polling)
 *=========================================================================*/

#if(LPUART_0 == ENABLE)

void LPUart0_Receive(void)
{
    if (TRUE == LPUART_x_STAT_RECIVE_ACTIVE(LPUART0))
    {
        /* Wait for Rx data register full flag                              */
        while (FALSE == LPUARTn_READ_RXDATAREGFULL(LPUART0));

        LPUARTn_COPY_RX_WORD(LPUART0,
            gstLPUARTRxBuf[eLPUART_0].s8Buffer[gstLPUARTRxBuf[eLPUART_0].u8IndexPos]);

        gstLPUARTRxBuf[eLPUART_0].u8IndexPos++;

        /* Wrap ring buffer index                                           */
        if (LPUART_0_MAXRXBUFSIZE == gstLPUARTRxBuf[eLPUART_0].u8IndexPos)
        {
            gstLPUARTRxBuf[eLPUART_0].u8IndexPos = 0u;
        }
    }
}

#endif /* LPUART_0 */

#if(LPUART_1 == ENABLE)

void LPUart1_Receive(void)
{
    if (TRUE == LPUART_x_STAT_RECIVE_ACTIVE(LPUART1))
    {
        while (FALSE == LPUARTn_READ_RXDATAREGFULL(LPUART1));

        LPUARTn_COPY_RX_WORD(LPUART1,
            gstLPUARTRxBuf[eLPUART_1].s8Buffer[gstLPUARTRxBuf[eLPUART_1].u8IndexPos]);

        gstLPUARTRxBuf[eLPUART_1].u8IndexPos++;

        if (LPUART_1_MAXRXBUFSIZE == gstLPUARTRxBuf[eLPUART_1].u8IndexPos)
        {
            gstLPUARTRxBuf[eLPUART_1].u8IndexPos = 0u;
        }
    }
}

#endif /* LPUART_1 */

#if(LPUART_2 == ENABLE)

void LPUart2_Receive(void)
{
    if (TRUE == LPUART_x_STAT_RECIVE_ACTIVE(LPUART2))
    {
        while (FALSE == LPUARTn_READ_RXDATAREGFULL(LPUART2));

        LPUARTn_COPY_RX_WORD(LPUART2,
            gstLPUARTRxBuf[eLPUART_2].s8Buffer[gstLPUARTRxBuf[eLPUART_2].u8IndexPos]);

        gstLPUARTRxBuf[eLPUART_2].u8IndexPos++;

        if (LPUART_2_MAXRXBUFSIZE == gstLPUARTRxBuf[eLPUART_2].u8IndexPos)
        {
            gstLPUARTRxBuf[eLPUART_2].u8IndexPos = 0u;
        }
    }
}

#endif /* LPUART_2 */

/*===========================================================================
 * INTERRUPT HANDLERS
 *=========================================================================*/

/*---------------------------------------------------------------------------
 * LPUART0_RxTx_IRQHandler
 *
 * Handles LPUART0 Rx interrupt.
 * Copies received byte into ring buffer, wraps on overflow.
 * Dev Note: Function name from IV table -- startup_S32K144.S
 *--------------------------------------------------------------------------*/
#if(LPUART_0 == ENABLE)

void INTERRUPT_ LPUART0_RxTx_IRQHandler(void)
{
    if (TRUE == LPUARTn_READ_RXINRTFLG(LPUART0))
    {
        LPUARTn_COPY_RX_WORD(LPUART0,
            gstLPUARTRxBuf[eLPUART_0].s8Buffer[gstLPUARTRxBuf[eLPUART_0].u8IndexPos]);

        gstLPUARTRxBuf[eLPUART_0].u8IndexPos++;

        if (LPUART_0_MAXRXBUFSIZE == gstLPUARTRxBuf[eLPUART_0].u8IndexPos)
        {
            gstLPUARTRxBuf[eLPUART_0].u8IndexPos = 0u;
        }
    }
}

#endif /* LPUART_0 */

/*---------------------------------------------------------------------------
 * LPUART1_RxTx_IRQHandler
 *
 * Handles LPUART1 Rx and Tx interrupts.
 *
 * Rx path: RDRF flag set -- copy byte to ring buffer, wrap on overflow
 * Tx path: TC flag set -- send next byte from Tx buffer
 *          On null terminator or buffer end: disable Tx interrupt,
 *          mark transmitter idle, re-enable Rx interrupt
 *
 * Dev Note: Function name from IV table -- startup_S32K144.S
 *--------------------------------------------------------------------------*/
#if(LPUART_1 == ENABLE)

void INTERRUPT_ LPUART1_RxTx_IRQHandler(void)
{
    /* Handle Rx active edge interrupt (baud rate edge detection)           */
    if (TRUE == LPUARTn_READ_RXINRTFLG(LPUART1))
    {
        LPUART_n_DISABLE_BAUD_RXEDGEINTRP(LPUART1);
    }

    /* Handle Rx data register full -- byte received                        */
    if (TRUE == LPUARTn_READ_RXDATAREGFULL(LPUART1))
    {
        LPUARTn_COPY_RX_WORD(LPUART1,
            gstLPUARTRxBuf[eLPUART_1].s8Buffer[gstLPUARTRxBuf[eLPUART_1].u8IndexPos]);

        gstLPUARTRxBuf[eLPUART_1].u8IndexPos++;

        if (LPUART_1_MAXRXBUFSIZE == gstLPUARTRxBuf[eLPUART_1].u8IndexPos)
        {
            gstLPUARTRxBuf[eLPUART_1].u8IndexPos = 0u;
        }
    }

    /* Handle Tx complete -- only when TX is armed (gu8TxStatusFlag=FALSE)  */
    if ((gu8TxStatusFlag == FALSE) && (TRUE == LPUART_n_FETCH_TxCOMPLETE(LPUART1)))
    {
        LPUARTn_COPY_TX_WORD(LPUART1,
            gstLPUARTTxBuf[eLPUART_1].s8Buffer[gstLPUARTTxBuf[eLPUART_1].u8IndexPos]);

        gstLPUARTTxBuf[eLPUART_1].u8IndexPos++;

        /* Check for null terminator or buffer overflow -- end transmission */
        if ((0 == gstLPUARTTxBuf[eLPUART_1].s8Buffer[gstLPUARTTxBuf[eLPUART_1].u8IndexPos]) ||
            (gstLPUARTTxBuf[eLPUART_1].u8IndexPos >= LPUARTn_MAXRXBUFSIZE))
        {
            LPUART_n_DISABLE_CTRL_TXINTRP(LPUART1);
            LPUART_n_DISABLE_CTRL_TXCOMPLETEINTP(LPUART1);

            gstLPUARTTxBuf[eLPUART_1].u8IndexPos = 0u;
            gu8TxStatusFlag = TRUE;             /* Mark transmitter idle    */

            LPUART_n_ENABLE_CTRL_RXINTP(LPUART1);
        }
    }
}

#endif /* LPUART_1 */

/*---------------------------------------------------------------------------
 * LPUART2_RxTx_IRQHandler
 *
 * Bug fixed: was copying to LPUART0 instead of LPUART2.
 * Dev Note: Function name from IV table -- startup_S32K144.S
 *--------------------------------------------------------------------------*/
#if(LPUART_2 == ENABLE)

void INTERRUPT_ LPUART2_RxTx_IRQHandler(void)
{
    if (TRUE == LPUARTn_READ_RXINRTFLG(LPUART2))
    {
        /* FIX: was incorrectly using LPUART0 here -- corrected to LPUART2  */
        LPUARTn_COPY_RX_WORD(LPUART2,
            gstLPUARTRxBuf[eLPUART_2].s8Buffer[gstLPUARTRxBuf[eLPUART_2].u8IndexPos]);

        gstLPUARTRxBuf[eLPUART_2].u8IndexPos++;

        if (LPUART_2_MAXRXBUFSIZE == gstLPUARTRxBuf[eLPUART_2].u8IndexPos)
        {
            gstLPUARTRxBuf[eLPUART_2].u8IndexPos = 0u;
        }
    }
}

#endif /* LPUART_2 */

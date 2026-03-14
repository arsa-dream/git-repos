///*
// * LUART_Core.c
// *
// *  Created on: 10-Nov-2020
// *      Author: HP
// */
//
//
//#include "Headers.h"
//
//
//// Cfg.h
//
//
//
//#define		LPUART_0													ENABLE
//#define 	LPUART_1													DISABLE
//#define 	LPUART_2													DISABLE
//
//#define 	LPUART_0_TRGSEL_CFG											LPUART_x_TRGSEL_INPUT_TRIG_DISABLE /*Allowed values  LPUART_x_TRGSEL_INPUT_TRIG_DISABLE| LPUART_x_TRGSEL_INPUT_TRIG_EN_INSTEAD_RXD|
// 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 LPUART_x_TRGSEL_INPUT_TRIG_EN_INSTEAD_CTSB| LPUART_x_TRGSEL_INPUT_TRIG_MODULATE_TXD: Ref Note 9*/
//#define 	LPUART_1_TRGSEL_CFG											LPUART_x_TRGSEL_INPUT_TRIG_DISABLE /*Allowed values  LPUART_x_TRGSEL_INPUT_TRIG_DISABLE| LPUART_x_TRGSEL_INPUT_TRIG_EN_INSTEAD_RXD|
// 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 LPUART_x_TRGSEL_INPUT_TRIG_EN_INSTEAD_CTSB| LPUART_x_TRGSEL_INPUT_TRIG_MODULATE_TXD: Ref Note 9*/
//#define 	LPUART_2_TRGSEL_CFG											LPUART_x_TRGSEL_INPUT_TRIG_DISABLE /*Allowed values  LPUART_x_TRGSEL_INPUT_TRIG_DISABLE| LPUART_x_TRGSEL_INPUT_TRIG_EN_INSTEAD_RXD|
// 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 LPUART_x_TRGSEL_INPUT_TRIG_EN_INSTEAD_CTSB| LPUART_x_TRGSEL_INPUT_TRIG_MODULATE_TXD: Ref Note 9*/
//
//
//
//// Core.h
//
//#define 	LPUART_0_READ_VER_NO()										(LPUART0 -> VERID)/* Reads version Id  Ref. Manual page: 1698*/
//#define 	LPUART_1_READ_VER_NO()										(LPUART1 -> VERID)/* Reads version Id  Ref. Manual page: 1698*/
//#define 	LPUART_2_READ_VER_NO()										(LPUART2 -> VERID)/* Reads version Id  Ref. Manual page: 1698*/
//
//#define 	LPUART_0_PARAM_CONFIG()										(LPUART0 -> PARAM)/* Reads TX(0-7)- RX(8-15) Buffer size Ref. Manual page: 1700*/
//#define 	LPUART_1_PARAM_CONFIG()										(LPUART1 -> PARAM)/* Reads TX(0-7)- RX(8-15) Buffer size Ref. Manual page: 1700*/
//#define 	LPUART_2_PARAM_CONFIG()										(LPUART2 -> PARAM)/* Reads TX(0-7)- RX(8-15) Buffer size Ref. Manual page: 1700*/
//
//#define 	LPUART_0_RESET_REGS()										(LPUART0 -> GLOBAL = LPUART_GLOBAL_RST(1u))/* Clears all the UART Registers Ref. Manual page: 1700*/
//#define 	LPUART_1_RESET_REGS()										(LPUART1 -> GLOBAL = LPUART_GLOBAL_RST(1u))/* Clears all the UART Registers Ref. Manual page: 1700*/
//#define 	LPUART_2_RESET_REGS()										(LPUART2 -> GLOBAL = LPUART_GLOBAL_RST(1u))/* Clears all the UART Registers Ref. Manual page: 1700*/
//
//#define 	LPUART_0_TRGSEL(TriggerSelOption)							(LPUART0 -> PINCFG = LPUART_PINCFG_TRGSEL(TriggerSelOption))
//#define 	LPUART_1_TRGSEL(TriggerSelOption)							(LPUART1 -> PINCFG = LPUART_PINCFG_TRGSEL(TriggerSelOption))
//#define 	LPUART_2_TRGSEL(TriggerSelOption)							(LPUART2 -> PINCFG = LPUART_PINCFG_TRGSEL(TriggerSelOption))


/* Headers here*/
#include	"Headers.h"

/* Global variables here	*/

static	stLPUARTRxBuf	gstLPUARTRxBuf[3u];
static	stLPUARTRxBuf	gstLPUARTTxBuf[3u];

unsigned char bTxStatusFlag = TRUE;
unsigned char bRxFlag = FALSE;
/* Function bodies from here*/

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

#if(LPUART_0 == ENABLE)

void LPUart0_Init(void)
{
	PCC->PCCn[PCC_LPUART1_INDEX] &= ~PCC_PCCn_CGC_MASK;    /* Ensure clk disabled for config */
	PCC->PCCn[PCC_LPUART1_INDEX] |= PCC_PCCn_PCS(0b010)    /* Clock Src = 2 (SIRCDIV2_CLK) */
                            	 |  PCC_PCCn_CGC_MASK;     /* Enable clock for LPUART1 regs */
														   /* 8 mhz */

	LPUART_n_SET_BAUD_RATE(	   LPUART0,						\
							   LPUART_0_BAUD_MATCHMD1,		\
							   LPUART_0_BAUD_MATCHMD2,		\
							   LPUART_0_BAUD_TENBITMD,		\
							   LPUART_0_BAUD_OVRSAMPRATIO,	\
							   LPUART_0_BAUD_TXDMA,			\
							   LPUART_0_BAUD_RXDMA,			\
							   LPUART_0_BAUD_RXIDLEDMA,		\
							   LPUART_0_BAUD_MATCHCFG,		\
							   LPUART_0_BAUD_BOTHEDGEEN,	\
							   LPUART_0_BAUD_RESYNC,		\
							   LPUART_0_BAUD_LINBRKINTRP,	\
							   LPUART_0_BAUD_RXACTEDGEINT,	\
							   LPUART_0_BAUD_NOOFSTOPBITS,	\
							   LPUART_0_BAUD_BAUDRATEMOD);

	LPUART_n_SET_CTRL_REG(	   LPUART0,						\
								LPUART_0_CTRL_RX8TX9,		\
								LPUART_0_CTRL_RX9TX8,		\
								LPUART_0_CTRL_SINGWIRE,		\
								LPUART_0_CTRL_TXDATAINV,	\
								LPUART_0_CTRL_OVRRUNINPT,	\
								LPUART_0_CTRL_NOISEINTP,	\
								LPUART_0_CTRL_FRMEERRINTP,	\
								LPUART_0_CTRL_PARIERRINTP,	\
								LPUART_0_CTRL_TXINTP,		\
								LPUART_0_CTRL_TXCOMPINTP,	\
								LPUART_0_CTRL_RXINTP,		\
								LPUART_0_CTRL_IDLLINEINTP,	\
								LPUART_0_CTRL_TXEN,			\
								LPUART_0_CTRL_RXEN,			\
								LPUART_0_CTRL_RXWAKEUPCTRL, \
								LPUART_0_CTRL_SNDBRK,		\
								LPUART_0_CTRL_MATCH1INTP,	\
								LPUART_0_CTRL_MATCH2INTP,	\
								LPUART_0_CTRL_7BITMODE,		\
								LPUART_0_CTRL_IDLECFG,		\
								LPUART_0_CTRL_LOOPMODE,		\
								LPUART_0_CTRL_DOZE,			\
								LPUART_0_CTRL_RXSRCSEL,		\
								LPUART_0_CTRL_9BIT8BITMODE, \
								LPUART_0_CTRL_RXWAKEUPMETH, \
								LPUART_0_CTRL_IDLELINETYPE,	\
								LPUART_0_CTRL_PARITYEN,		\
								LPUART_0_CTRL_PARITYTYPE);


}

#endif

#if(LPUART_1 == ENABLE)

void LPUart1_Init(void)
{
	PCC->PCCn[PCC_LPUART1_INDEX] &= ~PCC_PCCn_CGC_MASK;    /* Ensure clk disabled for config */
	PCC->PCCn[PCC_LPUART1_INDEX] |= PCC_PCCn_PCS(0b010)    /* Clock Src = 2 (SIRCDIV2_CLK) */
                            	 |  PCC_PCCn_CGC_MASK;     /* Enable clock for LPUART1 regs */

	LPUART_n_SET_BAUD_RATE(	   LPUART1,						\
							   LPUART_1_BAUD_MATCHMD1,		\
							   LPUART_1_BAUD_MATCHMD2,		\
							   LPUART_1_BAUD_TENBITMD,		\
							   LPUART_1_BAUD_OVRSAMPRATIO,	\
							   LPUART_1_BAUD_TXDMA,			\
							   LPUART_1_BAUD_RXDMA,			\
							   LPUART_1_BAUD_RXIDLEDMA,		\
							   LPUART_1_BAUD_MATCHCFG,		\
							   LPUART_1_BAUD_BOTHEDGEEN,	\
							   LPUART_1_BAUD_RESYNC,		\
							   LPUART_1_BAUD_LINBRKINTRP,	\
							   LPUART_1_BAUD_RXACTEDGEINT,	\
							   LPUART_1_BAUD_NOOFSTOPBITS,	\
							   LPUART_1_BAUD_BAUDRATEMOD);


	LPUART_n_SET_CTRL_REG(	   LPUART1,						\
								LPUART_1_CTRL_RX8TX9,		\
								LPUART_1_CTRL_RX9TX8,		\
								LPUART_1_CTRL_SINGWIRE,		\
								LPUART_1_CTRL_TXDATAINV,	\
								LPUART_1_CTRL_OVRRUNINPT,	\
								LPUART_1_CTRL_NOISEINTP,	\
								LPUART_1_CTRL_FRMEERRINTP,	\
								LPUART_1_CTRL_PARIERRINTP,	\
								LPUART_1_CTRL_TXINTP,		\
								LPUART_1_CTRL_TXCOMPINTP,	\
								LPUART_1_CTRL_RXINTP,		\
								LPUART_1_CTRL_IDLLINEINTP,	\
								LPUART_1_CTRL_TXEN,			\
								LPUART_1_CTRL_RXEN,			\
								LPUART_1_CTRL_RXWAKEUPCTRL, \
								LPUART_1_CTRL_SNDBRK,		\
								LPUART_1_CTRL_MATCH1INTP,	\
								LPUART_1_CTRL_MATCH2INTP,	\
								LPUART_1_CTRL_7BITMODE,		\
								LPUART_1_CTRL_IDLECFG,		\
								LPUART_1_CTRL_LOOPMODE,		\
								LPUART_1_CTRL_DOZE,			\
								LPUART_1_CTRL_RXSRCSEL,		\
								LPUART_1_CTRL_9BIT8BITMODE, \
								LPUART_1_CTRL_RXWAKEUPMETH, \
								LPUART_1_CTRL_IDLELINETYPE,	\
								LPUART_1_CTRL_PARITYEN,		\
								LPUART_1_CTRL_PARITYTYPE);

	LPUART_n_SET_WATER_REG(		LPUART1,					\
								LPUART_1_WATER_TXCOUNT,		\
								LPUART_1_WATER_RXCOUNT		);
}

#endif

#if(LPUART_2 == ENABLE)

void LPUart2_Init(void)
{
	PCC->PCCn[PCC_LPUART2_INDEX] &= ~PCC_PCCn_CGC_MASK;    /* Ensure clk disabled for config */
	PCC->PCCn[PCC_LPUART2_INDEX] |= PCC_PCCn_PCS(0b010)    /* Clock Src = 2 (SIRCDIV2_CLK) */
                            	 |  PCC_PCCn_CGC_MASK;     /* Enable clock for LPUART2 regs */
														   /* 8 mhz */

	LPUART_n_SET_BAUD_RATE(	   LPUART2,						\
							   LPUART2_BAUD_MATCHMD1,		\
							   LPUART2_BAUD_MATCHMD2,		\
							   LPUART2_BAUD_TENBITMD,		\
							   LPUART2_BAUD_OVRSAMPRATIO,	\
							   LPUART2_BAUD_TXDMA,			\
							   LPUART2_BAUD_RXDMA,			\
							   LPUART2_BAUD_RXIDLEDMA,		\
							   LPUART2_BAUD_MATCHCFG,		\
							   LPUART2_BAUD_BOTHEDGEEN,	\
							   LPUART2_BAUD_RESYNC,		\
							   LPUART2_BAUD_LINBRKINTRP,	\
							   LPUART2_BAUD_RXACTEDGEINT,	\
							   LPUART2_BAUD_NOOFSTOPBITS,	\
							   LPUART2_BAUD_BAUDRATEMOD);

	LPUART_n_SET_CTRL_REG(	   LPUART2,						\
								LPUART2_CTRL_RX8TX9,		\
								LPUART2_CTRL_RX9TX8,		\
								LPUART2_CTRL_SINGWIRE,		\
								LPUART2_CTRL_TXDATAINV,	\
								LPUART2_CTRL_OVRRUNINPT,	\
								LPUART2_CTRL_NOISEINTP,	\
								LPUART2_CTRL_FRMEERRINTP,	\
								LPUART2_CTRL_PARIERRINTP,	\
								LPUART2_CTRL_TXINTP,		\
								LPUART2_CTRL_TXCOMPINTP,	\
								LPUART2_CTRL_RXINTP,		\
								LPUART2_CTRL_IDLLINEINTP,	\
								LPUART2_CTRL_TXEN,			\
								LPUART2_CTRL_RXEN,			\
								LPUART2_CTRL_RXWAKEUPCTRL, \
								LPUART2_CTRL_SNDBRK,		\
								LPUART2_CTRL_MATCH1INTP,	\
								LPUART2_CTRL_MATCH2INTP,	\
								LPUART2_CTRL_7BITMODE,		\
								LPUART2_CTRL_IDLECFG,		\
								LPUART2_CTRL_LOOPMODE,		\
								LPUART2_CTRL_DOZE,			\
								LPUART2_CTRL_RXSRCSEL,		\
								LPUART2_CTRL_9BIT8BITMODE, \
								LPUART2_CTRL_RXWAKEUPMETH, \
								LPUART2_CTRL_IDLELINETYPE,	\
								LPUART2_CTRL_PARITYEN,		\
								LPUART2_CTRL_PARITYTYPE);

}

#endif


#if(LPUART_0 == ENABLE)

void LPUart0_TransmitChar(sint8	s8Word)
{
	/* Wait for transmit buffer to be empty */
	while(LPUART_x_READTDREFLAG(LPUART0)	==	0);

	/* Send data */
	LPUART_x_SENDWORD(LPUART0,	s8Word);

}

void LPUart0_TransmitString(sint8	*s8DataBuf,		uint8	u8Size)
{
	uint8 u8Index	=	0;

	for( u8Index	=	0;	 u8Index	<	u8Size;		u8Index++)
	{
		LPUart0_TransmitChar(s8DataBuf[u8Index]);
	}

}


#endif

#if(LPUART_1 == ENABLE)

STD_FsmStates	LPUart1_TransmitString(sint8	*s8DataBuf,		uint8	u8Size)
{
	STD_FsmStates eRetval =	STD_NOK;
	uint8 u8Idx = 0u;

	if(NULLPTR	!=	s8DataBuf)
	{
		if(TRUE	==	bTxStatusFlag)
		{

			for( u8Idx =	0;  u8Idx	<	u8Size;		u8Idx++)
			{
				gstLPUARTTxBuf[eLPUART_1].s8Buffer[u8Idx] = s8DataBuf[u8Idx];
			}

			 /*Null char should be used as termination character*/
			gstLPUARTTxBuf[eLPUART_1].s8Buffer[u8Idx] = 0;

			/*Enable Tx Interrupt control	*/
			LPUART_n_ENABLE_CTRL_TXINTRP(LPUART1);
			LPUART_n_DISABLE_CTRL_RXINTP(LPUART1);

//			gstLPUARTTxBuf[eLPUART_1].u8IndexPos = 0;

			bTxStatusFlag = FALSE;

			eRetval =	STD_OK;


		}
		else
		{
			eRetval =	STD_NOK;
		}
	}
	else
	{
		/* Do nothing*/
	}

	return eRetval;

}

#endif

#if(LPUART_2 == ENABLE)

void LPUart2_TransmitChar(sint8	s8Word)
{
	/* Wait for transmit buffer to be empty */
	while(LPUART_x_READTDREFLAG(LPUART2)	==	0);

	/* Send data */
	LPUART_x_SENDWORD(LPUART2,	s8Word);

}

void LPUart1_TransmitString(sint8	*s8DataBuf,		uint8	u8Size)
{
	uint8 u8Index	=	0;

	for( u8Index	=	0;	 u8Index	<	u8Size;		u8Index++)
	{
		LPUart2_TransmitChar(s8DataBuf[u8Index]);
	}

}

#endif



/* LPUART _ Reciever	*/

#if(LPUART_0 == ENABLE)

void LPUart0_Recieve(void)
{

	if(TRUE	==	LPUART_x_STAT_RECIVE_ACTIVE(LPUART0))
	{
		while(FALSE == LPUARTn_READ_RXDATAREGFULL(LPUART0));
		/* Wait for received buffer to be full */
		LPUARTn_COPY_RX_WORD(LPUART0,	gstLPUARTRxBuf[eLPUART_0].s8Buffer[gstLPUARTRxBuf[eLPUART_0].u8IndexPos]	);

		gstLPUARTRxBuf[eLPUART_0].u8IndexPos++;

		if(LPUART_0_MAXRXBUFSIZE == (gstLPUARTRxBuf[eLPUART_0].u8IndexPos)	)
		{
			gstLPUARTRxBuf[eLPUART_0].u8IndexPos = 0;
		}
		else
		{
			/* Do Nothing*/
		}
	}

}

#endif

#if(LPUART_1 == ENABLE)

void LPUart1_Recieve(void)
{

	if(TRUE	==	LPUART_x_STAT_RECIVE_ACTIVE(LPUART1))
	{
		while(FALSE == LPUARTn_READ_RXDATAREGFULL(LPUART1));
		/* Wait for received buffer to be full */
		LPUARTn_COPY_RX_WORD(LPUART1,	gstLPUARTRxBuf[eLPUART_1].s8Buffer[gstLPUARTRxBuf[eLPUART_1].u8IndexPos]	);

		gstLPUARTRxBuf[eLPUART_1].u8IndexPos++;

		if(LPUART_1_MAXRXBUFSIZE == (gstLPUARTRxBuf[eLPUART_1].u8IndexPos)	)
		{
			gstLPUARTRxBuf[eLPUART_1].u8IndexPos = 0;
		}
		else
		{
			/* Do Nothing*/
		}
	}

}

#endif

#if(LPUART_2 == ENABLE)

void LPUart1_Recieve(void)
{

	if(TRUE	==	LPUART_x_STAT_RECIVE_ACTIVE(LPUART2))
	{
		while(FALSE == LPUARTn_READ_RXDATAREGFULL(LPUART2));
		/* Wait for received buffer to be full */
		LPUARTn_COPY_RX_WORD(LPUART2,	gstLPUARTRxBuf[eLPUART_2].s8Buffer[gstLPUARTRxBuf[eLPUART_2].u8IndexPos]	);

		gstLPUARTRxBuf[eLPUART_2].u8IndexPos++;

		if(LPUART_2_MAXRXBUFSIZE == (gstLPUARTRxBuf[eLPUART_2].u8IndexPos)	)
		{
			gstLPUARTRxBuf[eLPUART_2].u8IndexPos = 0;
		}
		else
		{
			/* Do Nothing*/
		}
	}

}

#endif




#if(LPUART_0 == ENABLE)

void	INTERRUPT_	LPUART0_RxTx_IRQHandler(void)
{
	if(TRUE	==	LPUARTn_READ_RXINRTFLG(LPUART0))
	{
		/*Copy Data*/
		LPUARTn_COPY_RX_WORD(LPUART0,	gstLPUARTRxBuf[eLPUART_0].s8Buffer[gstLPUARTRxBuf[eLPUART_0].u8IndexPos]	);

		gstLPUARTRxBuf[eLPUART_0].u8IndexPos++;

		if(LPUART_0_MAXRXBUFSIZE == (gstLPUARTRxBuf[eLPUART_0].u8IndexPos)	)
		{
			gstLPUARTRxBuf[eLPUART_0].u8IndexPos = 0;
		}
		else
		{

		}

	}
	else
	{

	}


}

#endif



#if(LPUART_1 == ENABLE)

void	INTERRUPT_	LPUART1_RxTx_IRQHandler(void)
{


	if(TRUE == LPUARTn_READ_RXINRTFLG(LPUART1))
	{
		LPUART_n_DISABLE_BAUD_RXEDGEINTRP(LPUART1);


	}
	else
	{

	}




	/*Rx Data*/
	if(TRUE == LPUARTn_READ_RXDATAREGFULL(LPUART1))
	{

		LPUARTn_COPY_RX_WORD(LPUART1,	gstLPUARTRxBuf[eLPUART_1].s8Buffer[gstLPUARTRxBuf[eLPUART_1].u8IndexPos]);

		gstLPUARTRxBuf[eLPUART_1].u8IndexPos++;

		if(LPUART_1_MAXRXBUFSIZE == (gstLPUARTRxBuf[eLPUART_1].u8IndexPos)	)
		{
			gstLPUARTRxBuf[eLPUART_1].u8IndexPos = 0u;
		}
		else
		{
			/* Do Nothing */
		}


	}
	else
	{
		/* Do Nothing */
	}

	/* Tx State */
	if(TRUE == LPUART_n_FETCH_TxCOMPLETE(LPUART1))
	{

		LPUARTn_COPY_TX_WORD(LPUART1,	gstLPUARTTxBuf[eLPUART_1].s8Buffer[gstLPUARTTxBuf[eLPUART_1].u8IndexPos]);

		gstLPUARTTxBuf[eLPUART_1].u8IndexPos++;

		if((0 == gstLPUARTTxBuf[eLPUART_1].s8Buffer[gstLPUARTTxBuf[eLPUART_1].u8IndexPos]) ||
		   (gstLPUARTTxBuf[eLPUART_1].u8IndexPos >= LPUARTn_MAXRXBUFSIZE))
		{

			LPUART_n_DISABLE_CTRL_TXINTRP(LPUART1);

			bTxStatusFlag = TRUE;

			gstLPUARTTxBuf[eLPUART_1].u8IndexPos = 0u;

			LPUART_n_DISABLE_CTRL_TXCOMPLETEINTP(LPUART1);

			LPUART_n_ENABLE_CTRL_RXINTP(LPUART1);

		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		/* Do Nothing */
	}


}

#endif

#if(LPUART_2 == ENABLE)

void	INTERRUPT_	LPUART2_RxTx_IRQHandler(void)
{
	if(TRUE	==	LPUARTn_READ_RXINRTFLG(LPUART2))
	{
		/*Copy Data*/
		LPUARTn_COPY_RX_WORD(LPUART0,	gstLPUARTRxBuf[eLPUART_2].s8Buffer[gstLPUARTRxBuf[eLPUART_2].u8IndexPos]	);

		gstLPUARTRxBuf[eLPUART_2].u8IndexPos++;

		if(LPUART_2_MAXRXBUFSIZE == (gstLPUARTRxBuf[eLPUART_2].u8IndexPos)	)
		{
			gstLPUARTRxBuf[eLPUART_2].u8IndexPos = 0;
		}
		else
		{

		}

	}
	else
	{

	}


}

#endif










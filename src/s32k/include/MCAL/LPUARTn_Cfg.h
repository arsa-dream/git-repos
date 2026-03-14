/*
 * LPUARTn_Cfg.h
 *
 *  Created on: 21-Nov-2020
 *      Author: HP
 */

#ifndef MCAL_LPUARTN_CFG_H_
#define MCAL_LPUARTN_CFG_H_

#define		LPUART_0														DISABLE
#define		LPUART_1														ENABLE
#define		LPUART_2														DISABLE


#define		LPUARTn_CTRL_IDLECHAR1											0b000
#define		LPUARTn_CTRL_IDLECHAR2											0b001
#define		LPUARTn_CTRL_IDLECHAR4											0b010
#define		LPUARTn_CTRL_IDLECHAR8											0b011
#define		LPUARTn_CTRL_IDLECHAR16											0b100
#define		LPUARTn_CTRL_IDLECHAR32											0b101
#define		LPUARTn_CTRL_IDLECHAR64											0b110
#define		LPUARTn_CTRL_IDLECHAR128										0b111

#define		LPUARTn_CTRL_PARITYEVEN											0u
#define		LPUARTn_CTRL_PARITYODD											1u

#if(ENABLE == LPUART_0)

	#define		LPUART_0_MAXRXBUFSIZE										8u

	#define		LPUART_0_BAUD_MATCHMD1										ENABLE
	#define		LPUART_0_BAUD_MATCHMD2										ENABLE
	#define		LPUART_0_BAUD_TENBITMD										DISABLE
	#define		LPUART_0_BAUD_OVRSAMPRATIO									LPUARTn_OVERSAMPLERATIO_8			/* For Baud rate 115200 */
	#define		LPUART_0_BAUD_MATCHCFG										LPUART_x_MATCH_CFG_ADDR_WAKE_UP
	#define		LPUART_0_BAUD_RESYNCDIS										DISABLE
	#define		LPUART_0_BAUD_LINBRKINTRP									DISABLE
	#define		LPUART_0_BAUD_RXACTEDGEINT									ENABLE
	#define		LPUART_0_BAUD_NOOFSTOPBITS									LPUART_x_BAUD_ONESTOPBIT
	#define		LPUART_0_BAUD_BAUDRATEMOD									625u      							/* For Baud rate 115200 */
	#define		LPUART_0_BAUD_BOTHEDGEEN									DISABLE
	#define		LPUART_0_BAUD_RXDMA											DISABLE
	#define		LPUART_0_BAUD_TXDMA											DISABLE
	#define		LPUART_0_BAUD_RESYNC										DISABLE
	#define		LPUART_0_BAUD_RXIDLEDMA										DISABLE

	#define		LPUART_0_CTRL_RX8TX9										DISABLE
	#define		LPUART_0_CTRL_RX9TX8										DISABLE
	#define		LPUART_0_CTRL_SINGWIRE										DISABLE
	#define		LPUART_0_CTRL_TXDATAINV										DISABLE
	#define		LPUART_0_CTRL_OVRRUNINPT									ENABLE
	#define		LPUART_0_CTRL_NOISEINTP										ENABLE
	#define		LPUART_0_CTRL_FRMEERRINTP									ENABLE
	#define		LPUART_0_CTRL_PARIERRINTP									ENABLE
	#define		LPUART_0_CTRL_TXINTP										ENABLE
	#define		LPUART_0_CTRL_TXCOMPINTP									ENABLE
	#define		LPUART_0_CTRL_RXINTP										ENABLE
	#define		LPUART_0_CTRL_IDLLINEINTP									ENABLE
	#define		LPUART_0_CTRL_TXEN											ENABLE
	#define		LPUART_0_CTRL_RXEN											ENABLE
	#define		LPUART_0_CTRL_RXWAKEUPCTRL									ENABLE
	#define		LPUART_0_CTRL_SNDBRK										ENABLE
	#define		LPUART_0_CTRL_MATCH1INTP									DISABLE
	#define		LPUART_0_CTRL_MATCH2INTP									DISABLE
	#define		LPUART_0_CTRL_7BITMODE										DISABLE
	#define		LPUART_0_CTRL_IDLECFG										LPUARTn_CTRL_IDLECHAR1
	#define		LPUART_0_CTRL_LOOPMODE										DISABLE
	#define		LPUART_0_CTRL_DOZE											DISABLE
	#define		LPUART_0_CTRL_RXSRCSEL										0u /* Currently no use until Loops mode is set Ref page: 1712*/
	#define		LPUART_0_CTRL_9BIT8BITMODE									0u	/* 8Bit mode*/
	#define		LPUART_0_CTRL_RXWAKEUPMETH									0u /* Currently no use as Rx wake is not enabled Ref page 1712*/
	#define		LPUART_0_CTRL_IDLELINETYPE									0u /* Idle charecter starts at Start bit Ref page 1712*/
	#define		LPUART_0_CTRL_PARITYEN										ENABLE
	#define		LPUART_0_CTRL_PARITYTYPE									LPUARTn_CTRL_PARITYEVEN

#endif

#if(ENABLE == LPUART_1)

	#define		LPUART_1_MAXRXBUFSIZE										8u

	#define		LPUART_1_BAUD_MATCHMD1										DISABLE
	#define		LPUART_1_BAUD_MATCHMD2										DISABLE
	#define		LPUART_1_BAUD_TENBITMD										DISABLE
	#define		LPUART_1_BAUD_OVRSAMPRATIO									LPUARTn_OVERSAMPLERATIO_4_BOTHEDGE			/* For Baud rate 115200 */
	#define		LPUART_1_BAUD_MATCHCFG										LPUART_x_MATCH_CFG_ADDR_WAKE_UP
	#define		LPUART_1_BAUD_RESYNCDIS										DISABLE
	#define		LPUART_1_BAUD_LINBRKINTRP									DISABLE
	#define		LPUART_1_BAUD_RXACTEDGEINT									DISABLE
	#define		LPUART_1_BAUD_NOOFSTOPBITS									LPUART_x_BAUD_ONESTOPBIT
	#define		LPUART_1_BAUD_BAUDRATEMOD									17u      			//11.9				/* For Baud rate 115200 */
	#define		LPUART_1_BAUD_BOTHEDGEEN									DISABLE
	#define		LPUART_1_BAUD_RXDMA											DISABLE
	#define		LPUART_1_BAUD_TXDMA											DISABLE
	#define		LPUART_1_BAUD_RESYNC										DISABLE
	#define		LPUART_1_BAUD_RXIDLEDMA										DISABLE

	#define		LPUART_1_CTRL_RX8TX9										DISABLE
	#define		LPUART_1_CTRL_RX9TX8										DISABLE
	#define		LPUART_1_CTRL_SINGWIRE										DISABLE
	#define		LPUART_1_CTRL_TXDATAINV										DISABLE
	#define		LPUART_1_CTRL_OVRRUNINPT									DISABLE
	#define		LPUART_1_CTRL_NOISEINTP										DISABLE
	#define		LPUART_1_CTRL_FRMEERRINTP									DISABLE
	#define		LPUART_1_CTRL_PARIERRINTP									DISABLE
	#define		LPUART_1_CTRL_TXINTP										DISABLE
	#define		LPUART_1_CTRL_TXCOMPINTP									DISABLE
	#define		LPUART_1_CTRL_RXINTP										DISABLE
	#define		LPUART_1_CTRL_IDLLINEINTP									DISABLE
	#define		LPUART_1_CTRL_TXEN											ENABLE
	#define		LPUART_1_CTRL_RXEN											ENABLE
	#define		LPUART_1_CTRL_RXWAKEUPCTRL									DISABLE
	#define		LPUART_1_CTRL_SNDBRK										DISABLE
	#define		LPUART_1_CTRL_MATCH1INTP									DISABLE
	#define		LPUART_1_CTRL_MATCH2INTP									DISABLE
	#define		LPUART_1_CTRL_7BITMODE										DISABLE
	#define		LPUART_1_CTRL_IDLECFG										LPUARTn_CTRL_IDLECHAR1
	#define		LPUART_1_CTRL_LOOPMODE										DISABLE
	#define		LPUART_1_CTRL_DOZE											DISABLE
	#define		LPUART_1_CTRL_RXSRCSEL										0u 			/* Currently no use until Loops mode is set Ref page: 1712*/
	#define		LPUART_1_CTRL_9BIT8BITMODE									0u			/* 8Bit mode*/
	#define		LPUART_1_CTRL_RXWAKEUPMETH									0u 			/* Currently no use as Rx wake is not enabled Ref page 1712*/
	#define		LPUART_1_CTRL_IDLELINETYPE									0u 			/* Idle charecter starts at Start bit Ref page 1712*/
	#define		LPUART_1_CTRL_PARITYEN										DISABLE
	#define		LPUART_1_CTRL_PARITYTYPE									LPUARTn_CTRL_PARITYEVEN

	#define		LPUART_1_WATER_RXCOUNT										0u
	#define		LPUART_1_WATER_TXCOUNT										0u


#endif


#if(ENABLE == LPUART_2)

	#define		LPUART_2_MAXRXBUFSIZE										8u

	#define		LPUART_2_BAUD_MATCHMD1										ENABLE
	#define		LPUART_2_BAUD_MATCHMD2										ENABLE
	#define		LPUART_2_BAUD_TENBITMD										DISABLE
	#define		LPUART_2_BAUD_OVRSAMPRATIO									LPUARTn_OVERSAMPLERATIO_8			/* For Baud rate 115200 */
	#define		LPUART_2_BAUD_MATCHCFG										LPUART_x_MATCH_CFG_ADDR_WAKE_UP
	#define		LPUART_2_BAUD_RESYNCDIS										DISABLE
	#define		LPUART_2_BAUD_LINBRKINTRP									DISABLE
	#define		LPUART_2_BAUD_RXACTEDGEINT									ENABLE
	#define		LPUART_2_BAUD_NOOFSTOPBITS									LPUART_x_BAUD_ONESTOPBIT
	#define		LPUART_2_BAUD_BAUDRATEMOD									625u      							/* For Baud rate 115200 */
	#define		LPUART_2_BAUD_BOTHEDGEEN									DISABLE
	#define		LPUART_2_BAUD_RXDMA											DISABLE
	#define		LPUART_2_BAUD_TXDMA											DISABLE
	#define		LPUART_2_BAUD_RESYNC										DISABLE
	#define		LPUART_2_BAUD_RXIDLEDMA										DISABLE

	#define		LPUART_2_CTRL_RX8TX9										DISABLE
	#define		LPUART_2_CTRL_RX9TX8										DISABLE
	#define		LPUART_2_CTRL_SINGWIRE										DISABLE
	#define		LPUART_2_CTRL_TXDATAINV										DISABLE
	#define		LPUART_2_CTRL_OVRRUNINPT									ENABLE
	#define		LPUART_2_CTRL_NOISEINTP										ENABLE
	#define		LPUART_2_CTRL_FRMEERRINTP									ENABLE
	#define		LPUART_2_CTRL_PARIERRINTP									ENABLE
	#define		LPUART_2_CTRL_TXINTP										ENABLE
	#define		LPUART_2_CTRL_TXCOMPINTP									ENABLE
	#define		LPUART_2_CTRL_RXINTP										ENABLE
	#define		LPUART_2_CTRL_IDLLINEINTP									ENABLE
	#define		LPUART_2_CTRL_TXEN											ENABLE
	#define		LPUART_2_CTRL_RXEN											ENABLE
	#define		LPUART_2_CTRL_RXWAKEUPCTRL									ENABLE
	#define		LPUART_2_CTRL_SNDBRK										ENABLE
	#define		LPUART_2_CTRL_MATCH1INTP									DISABLE
	#define		LPUART_2_CTRL_MATCH2INTP									DISABLE
	#define		LPUART_2_CTRL_7BITMODE										DISABLE
	#define		LPUART_2_CTRL_IDLECFG										LPUARTn_CTRL_IDLECHAR1
	#define		LPUART_2_CTRL_LOOPMODE										DISABLE
	#define		LPUART_2_CTRL_DOZE											DISABLE
	#define		LPUART_2_CTRL_RXSRCSEL										0u /* Currently no use until Loops mode is set Ref page: 1712*/
	#define		LPUART_2_CTRL_9BIT8BITMODE									0u	/* 8Bit mode*/
	#define		LPUART_2_CTRL_RXWAKEUPMETH									0u /* Currently no use as Rx wake is not enabled Ref page 1712*/
	#define		LPUART_2_CTRL_IDLELINETYPE									0u /* Idle charecter starts at Start bit Ref page 1712*/
	#define		LPUART_2_CTRL_PARITYEN										ENABLE
	#define		LPUART_2_CTRL_PARITYTYPE									LPUARTn_CTRL_PARITYEVEN

#endif

#endif /* MCAL_LPUARTN_CFG_H_ */

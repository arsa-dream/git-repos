/*
 * NVIC_Core.c
 *
 *  Created on: 16-Nov-2020
 *      Author: HP
 */

#include "Headers.h"



void NVIC_init_IRQs(void)
{
	/* Port C Interrupt */

//	S32_NVIC->ICPR[1u] = 1 << (PORTC_IRQn % 32);  					/* IRQ62 - PORTC ch0: clear any pending IRQ*/
//	S32_NVIC->ISER[1u] = 1 << (PORTC_IRQn % 32);  					/* IRQ62 - PORTC ch0: enable IRQ */
//	S32_NVIC->IP[PORTC_IRQn] = 0xA;                					/* IRQ62 - PORTC ch0: priority 10 of 0-15*/

//	S32_NVIC->ICPR[3u] = 1 << (FTM0_Ch0_Ch1_IRQn % 32); 			 /* IRQ99 - FTM0 ch0,1: clear any pending IRQ*/
//	S32_NVIC->ISER[3u] = 1 << (FTM0_Ch0_Ch1_IRQn % 32);  			 /* IRQ99 - FTM0 ch0,1: enable IRQ */
//	S32_NVIC->IP[FTM0_Ch0_Ch1_IRQn] = 0x0A;              			 /* IRQ99 - FTM0 ch0,1: priority 0 of 0-15*/

	S32_NVIC->ICPR[3u] = 1 << (FTM0_Ch2_Ch3_IRQn % 32); 			 /* IRQ99 - FTM0 ch0,1: clear any pending IRQ*/
	S32_NVIC->ISER[3u] = 1 << (FTM0_Ch2_Ch3_IRQn % 32);  			 /* IRQ99 - FTM0 ch0,1: enable IRQ */
	S32_NVIC->IP[FTM0_Ch2_Ch3_IRQn] = 0x0A;              			 /* IRQ99 - FTM0 ch0,1: priority 0 of 0-15*/

	S32_NVIC->ICPR[3u] = 1 << (FTM0_Ovf_Reload_IRQn % 32); 			 /* IRQ99 - FTM1 ch0,1: clear any pending IRQ*/
	S32_NVIC->ISER[3u] = 1 << (FTM0_Ovf_Reload_IRQn % 32);  		 /* IRQ99 - FTM1 ch0,1: enable IRQ */
	S32_NVIC->IP[FTM0_Ovf_Reload_IRQn] = 0x0A;

	S32_NVIC->ICPR[3u] = 1 << (FTM1_Ovf_Reload_IRQn % 32); 			 /* IRQ99 - FTM1 ch0,1: clear any pending IRQ*/
	S32_NVIC->ISER[3u] = 1 << (FTM1_Ovf_Reload_IRQn % 32);  		 /* IRQ99 - FTM1 ch0,1: enable IRQ */
	S32_NVIC->IP[FTM1_Ovf_Reload_IRQn] = 0x0A;						 /* IRQ99 - FTM1 ch0,1: priority 0 of 0-15*/

	S32_NVIC->ICPR[1u] = 1 << (LPUART1_RxTx_IRQn % 32); 			 /* IRQ99 - LPUART  clear any pending IRQ*/
	S32_NVIC->ISER[1u] = 1 << (LPUART1_RxTx_IRQn % 32);  			 /* IRQ99 - LPUART  enable IRQ */
	S32_NVIC->IP[LPUART1_RxTx_IRQn] = 0x00;							 /* IRQ99 - LPUART  priority 0 of 0-15*/

	S32_NVIC->ICPR[1u] = 1 << (ADC0_IRQn % 32); 			 		/* IRQ99 - ADC0  clear any pending IRQ*/
	S32_NVIC->ISER[1u] = 1 << (ADC0_IRQn % 32);  			 		/* IRQ99 - ADC0 enable IRQ */
	S32_NVIC->IP[ADC0_IRQn] = 0x00;									/* IRQ99 - ADC0 priority 0 of 0-15*/

	S32_NVIC->ICPR[1u] = 1 << (ADC1_IRQn % 32); 					 /* IRQ99 - ADC1 clear any pending IRQ*/
	S32_NVIC->ISER[1u] = 1 << (ADC1_IRQn % 32);  			 		 /* IRQ99 - ADC1 enable IRQ */
	S32_NVIC->IP[ADC1_IRQn] = 0x00;

}







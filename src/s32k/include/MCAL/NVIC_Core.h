/*
 * NVIC_Cfg.h
 *
 *  Created on: 16-Nov-2020
 *      Author: HP
 */

#ifndef 	MCAL_NVIC_CORE_H_
#define 	MCAL_NVIC_CORE_H_

#include 	"Headers.h"


#define 	NVIC_CLR_PENDING_INTERRUPT(PeripheralIndex)									S32_NVIC->ICPR[PeripheralIndex % 32] = 1 << (PeripheralIndex % 32)
#define 	NVIC_ENABLE_INTERRUPT(PeripheralIndex)										S32_NVIC->ISER[PeripheralIndex % 32] = 1 << (PeripheralIndex % 32)
#define 	NVIC_SETPRIORITY_INTERRUPT(PeripheralIndex,		Priority)					S32_NVIC->ICPR[PeripheralIndex % 32] = 1 << (PeripheralIndex % 32)



extern		void	NVIC_init_IRQs(void);

#endif /* MCAL_NVIC_CORE_H_ */

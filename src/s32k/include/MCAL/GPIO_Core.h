/*
 * GPIO_Core.h
 *
 *  Created on: 20-Nov-2020
 *      Author: HP
 */

#ifndef MCAL_GPIO_CORE_H_
#define MCAL_GPIO_CORE_H_

#include	"Headers.h"



#define		GPIO_TOGGLE(PortBaseAddr,	PortPin)									(PortBaseAddr->PTOR |= (1<<PortPin))
																					/* Formula: The Port's specific PTTO has been set to 1b Ref. Manual page 235*/
#define		GPIO_READ_INPUT(PortBaseAddr,	PortPin)								(PortBaseAddr->PDIR & (1<<PortPin))
																					/* Formula: The Port's specific PTTO has been Read Ref. Manual page 236*/
#define		GPIO_CLR_OUTPUT(PortBaseAddr,	PortPin)								(PortBaseAddr->PCOR |= (1<<PortPin))
																					/* Formula: The Port's specific PTTO has been Read Ref. Manual page 236*/
#define		GPIO_SET_OUTPUT(PortBaseAddr,	PortPin)								(PortBaseAddr->PSOR |= (1<<PortPin))
																					/* Formula: The Port's specific PTTO has been Read Ref. Manual page 236*/
#define		GPIO_FETCH_OUTPUT_STATE(PortBaseAddr,	PortPin)						((PortBaseAddr->PDOR & (1<<PortPin)) >> PortPin)
																					/* Formula: The Port's specific PTTO has been Read Ref. Manual page 236*/
#endif /* MCAL_GPIO_CORE_H_ */

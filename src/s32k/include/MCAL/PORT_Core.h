/*
 * Gpio_Core.h
 *
 *  Created on: 01-Nov-2020
 *      Author: HP
 */

#ifndef PORT_CORE_H_
#define PORT_CORE_H_

#include "Headers.h"


#define		INPUT																	0u
#define 	OUTPUT																	1u
#define		NOTUSED																	2u

#define		ENABLE																	TRUE
#define		DISABLE																	FALSE

#define 	PULL_UP																	TRUE
#define		PULL_DWN																FALSE



#define 	PORT_PCR(PortBaseAddr, n, IRQC, LK, MUX, DSE, PFE, PE, PS)				(PortBaseAddr->PCR[n] = 	  (PORT_PCR_IRQC(IRQC))|	\
																								  	  	  	  (PORT_PCR_LK(LK))|	\
																											  (PORT_PCR_MUX(MUX))|    \
																											  (PORT_PCR_DSE(DSE))|    \
																											  (PORT_PCR_PFE(PFE))|    \
																											  (PORT_PCR_PE(PE))|		\
																											  (PORT_PCR_PS(PS)) )

/* Dev. Note 1: The following table are the listed and only allowed values for the interrupt configuration service for a Port pin,
 * Ref. Manual page 216
 * Rest of the values are reserved and has no effect
 */
#define 	INRTP_STATUS_FLG_ISF_DISABLED											0b0000

#define 	ISF_FLG_UPON_DMA_RISING_EDGE											0b0001
#define 	ISF_FLG_UPON_DMA_FALLNG_EDGE											0b0010
#define 	ISF_FLG_UPON_DMA_BOTH_EDGES												0b0010

#define 	ISF_FLG_UPON_INTRPT_LOGIC_0												0b1000
#define 	ISF_FLG_UPON_INTRPT_RISING_EDGE											0b1001
#define 	ISF_FLG_UPON_INTRPT_FALLNG_EDGE											0b1010
#define 	ISF_FLG_UPON_INTRPT_BOTH_EDGES											0b1011
#define 	ISF_FLG_UPON_INTRPT_LOGIC_1												0b1100

/* Dev. Note 2: The following table are the listed and only allowed values for the PCS MUX configuration for a Port pin,
 * Ref. Manual page 217
 * Rest of the values are reserved and has no effect
 */


#define 	ANALOG																	0b000   /* TBD: Improvement, Query: What is Disable and alternative 0?*/
#define 	GPIO																	0b001
#define 	CHIPSPECIFIC_1															0b010
#define 	CHIPSPECIFIC_2															0b011
#define 	CHIPSPECIFIC_3															0b100
#define 	CHIPSPECIFIC_4															0b101
#define 	CHIPSPECIFIC_5															0b110
#define 	CHIPSPECIFIC_6															0b111

#define		SET_PIN_DIRECTION_INPUT(PortBaseAddr,	PortPin)						(PortBaseAddr->PDDR &= ~(1<<PortPin))
																					/* Formula: The Port's specific PDDR has been cleared to 0b Ref. Manual page 237*/
#define 	SET_PIN_DIRECTION_OUTPUT(PortBaseAddr,	PortPin)						(PortBaseAddr->PDDR |= (1<<PortPin))
	                                                                				/* Formula: The Port's specific PDDR has been cleared to 1b Ref. Manual page 237*/


#define 	PORT_PCR_CLR_INTRPT(PortBaseAddr, n)									PortBaseAddr->PCR[n] |= PORT_PCR_ISF(0u) /*Clear Interrupt Flag	*/
#define 	PORT_PCR_READ_INTRPT(PortBaseAddr, n)									((PortBaseAddr->PCR[n] & PORT_PCR_ISF(1u))>>PORT_PCR_ISF_SHIFT) // Read Interrupt Flag as Enable/Disable

extern void Port_Init(void);

inline void Port_Initialize_PortA(void);
inline void Port_Initialize_PortB(void);
inline void Port_Initialize_PortC(void);
inline void Port_Initialize_PortD(void);
inline void Port_Initialize_PortE(void);


inline void Port_Clear_PortA(void);
inline void Port_Clear_PortC(void);
inline void Port_Clear_PortD(void);
inline void Port_Clear_PortE(void);

#endif /* PORT_CORE_H_ */

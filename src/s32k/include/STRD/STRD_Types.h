/*
 * StdTypes.h
 *
 *  Created on: 01-Nov-2020
 *      Author: HP
 */

#ifndef STDTYPES_H_
#define STDTYPES_H_


typedef enum{
	STD_NOK = 0u,
	STD_OK,
	STD_PENDING,
	STD_Limit
}STD_FsmStates;


typedef unsigned char 					uint8;
typedef unsigned short					uint16;
typedef unsigned int					uint32;
typedef	unsigned long long				uint64;

typedef	signed char						sint8;
typedef	signed short					sint16;
typedef	signed int						sint32;
typedef signed long long				sint64;

typedef	float							float32;
typedef	double							double64;


#define		STRD_FIXED_LEFTOFFSET(Arg,	BitSize)				(Arg << BitSize)

#define 	TRUE											1u
#define 	FALSE 											0u


#define		OK												TRUE
#define		NOK												FALSE

#define		NULLPTR											0u


#define		DEBUG_MODE										TRUE /*This Flag Enables/disables all the Debugging related functionality*/
#define 	INTERRUPT_											 /* This dummy flag used for SW design for differentiating normal functions from Interrupt functions*/



#endif /* STDTYPES_H_ */

///*
// * Bldc.c
// *
// *  Created on: 03-Nov-2025
// *      Author: HP
// */
//
//#define	BLDC_U_PHASE_DUTY(in_duty)	FTM0_CHANNEL_XX(in_duty)
//#define	BLDC_V_PHASE_DUTY(in_duty)	FTM0_CHANNEL_XX(in_duty)
//#define	BLDC_W_PHASE_DUTY(in_duty)	FTM0_CHANNEL_XX(in_duty)
//
//#define	BLDC_U_PHASE_ENABLE			FTM0_ENABLE_XX
//#define	BLDC_V_PHASE_ENABLE			FTM0_ENABLE_XX
//#define	BLDC_W_PHASE_ENABLE			FTM0_ENABLE_XX
//
//#define	BLDC_U_PHASE_DISABLE		FTM0_DISABLE_XX
//#define	BLDC_V_PHASE_DISABLE		FTM0_DISABLE_XX
//#define	BLDC_W_PHASE_DISABLE		FTM0_DISABLE_XX
//
//#define	BLDC_U_N_PHASE_CHANNEL(in_state)		DIO_PTA_XX(in_state)
//#define	BLDC_V_N_PHASE_CHANNEL(in_state)		DIO_PTA_XX(in_state)
//#define	BLDC_W_N_PHASE_CHANNEL(in_state)		DIO_PTA_XX(in_state)
//
//
//typedef	enum{
//	bldc_init = 0,
//	bldc_run,				//for 0 to max rpm
//	bldc_fault
//}bldc_state_table;
//
//static 	bldc_state_table bldc_state = bldc_init;
//static	uint8	bldc_position = 0;
//static	uint16	bldc_duty = 0;
//
//void bldc_rotate(void)
//{
//	switch(bldc_state)
//	{
//		case bldc_init:
//		{
//			boolean bldc_startup = false;
//
//			bldc_startup &=	bldc_startup_check();
//			bldc_startup &= bldc_position_read(&bldc_position);
//
//			if(bldc_startup ==true)
//			{
//				bldc_state = bldc_run;
//			}
//
//			break;
//		}
//
//		case bldc_run:
//		{
//			boolean	bstate = bldc_reverse_request();
//			bldc_duty_read(&bldc_duty);
//			bldc_position_read(&bldc_position);
//
//			switch(bstate)
//			{
//				case true:
//				{
//					//reverse rotate
//					switch(bldc_position)
//					{
//						case	1:
//						{
//							//60 degrees
//							bldc_disable_all_channels();
//
//							BLDC_U_PHASE_ENABLE;
//							BLDC_U_PHASE_CHANNEL(bldc_duty);
//							BLDC_W_N_PHASE_CHANNEL(true);
//
//#if(MOTOR_POSITION_SIMULATION == TRUE)
//							bldc_position = 2;
//#endif
//							break;
//						}
//						case	2:
//						{
//							//120 degrees
//							bldc_disable_all_channels();
//
//							BLDC_W_PHASE_ENABLE;
//							BLDC_W_PHASE_CHANNEL(bldc_duty);
//							BLDC_U_N_PHASE_CHANNEL(true);
//
//#if(MOTOR_POSITION_SIMULATION == TRUE)
//							bldc_position = 3;
//#endif
//
//							break;
//						}
//						case	3:
//						{
//
//							//180 degrees
//							bldc_disable_all_channels();
//
//							BLDC_V_PHASE_ENABLE;
//							BLDC_V_PHASE_CHANNEL(bldc_duty);
//							BLDC_W_N_PHASE_CHANNEL(true);
//
//#if(MOTOR_POSITION_SIMULATION == TRUE)
//							bldc_position = 4;
//#endif
//							break;
//						}
//						case	4:
//						{
//							//240 degrees
//							bldc_disable_all_channels();
//
//							BLDC_W_PHASE_ENABLE;
//							BLDC_W_PHASE_CHANNEL(bldc_duty);
//							BLDC_V_N_PHASE_CHANNEL(true);
//
//#if(MOTOR_POSITION_SIMULATION == TRUE)
//							bldc_position = 5;
//#endif
//							break;
//						}
//						case	5:
//						{
//							//300 degrees
//							bldc_disable_all_channels();
//
//							BLDC_V_PHASE_ENABLE;
//							BLDC_V_PHASE_CHANNEL(bldc_duty);
//							BLDC_U_N_PHASE_CHANNEL(true);
//
//#if(MOTOR_POSITION_SIMULATION == TRUE)
//							bldc_position = 6;
//#endif
//							break;
//						}
//						case	6:
//						{
//							//300 degrees
//							bldc_disable_all_channels();
//
//							BLDC_U_PHASE_ENABLE;
//							BLDC_U_PHASE_CHANNEL(bldc_duty);
//							BLDC_V_N_PHASE_CHANNEL(true);
//
//#if(MOTOR_POSITION_SIMULATION == TRUE)
//							bldc_position = 1;
//#endif
//							break;
//						}
//
//						case	0:
//						default:
//						{
//							bldc_state = bldc_fault;
//							break;
//						}
//					}
//					break;
//				}
//				case false:
//				{
//					//forward rotate
//
//					//tbd
//					break;
//				}
//
//				default:
//					break;
//			}
//		}
//		case bldc_fault:
//		{
//
//			break;
//		}
//
//		default:
//			break;
//
//	}
//}
//
//
//static	inline	boolean	bldc_position_read(uint8*	bldc_pos_inout)
//{
//	//dummy code
//	*bldc_pos_inout = true;
//	return true;
//}
//
//static	inline	boolean bldc_duty_read(uint16*	bldc_duty_inout)
//{
//	//dummy code
//	*bldc_duty_inout = 32765; // 50.00%
//	return true;
//}
//
//
//static inline boolean bldc_reverse_request(void)
//{
//	//dummy code
//	return false;
//}
//
//
//static	inline	boolean bldc_disable_all_channels(void)
//{
//	BLDC_U_N_PHASE_CHANNEL(false);
//	BLDC_V_N_PHASE_CHANNEL(false);
//	BLDC_W_N_PHASE_CHANNEL(false);
//
//	BLDC_U_PHASE_DISABLE;
//	BLDC_V_PHASE_DISABLE;
//	BLDC_W_PHASE_DISABLE;
//}

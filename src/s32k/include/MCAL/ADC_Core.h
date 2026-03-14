/*
 * ADC_Core.h
 *
 *  Created on: 07-Dec-2020
 *      Author: HP
 */

#ifndef MCAL_ADC_CORE_H_
#define MCAL_ADC_CORE_H_


//ADC_core.h

#define		ADCn_CFG1_ADIV_DIV1									0b00
#define		ADCn_CFG1_ADIV_DIV2									0b01
#define		ADCn_CFG1_ADIV_DIV4									0b10
#define		ADCn_CFG1_ADIV_DIV8									0b11
															/* refer manual	page: 1227*/

#define		ADCn_CFG1_MODE_8BIT									0b00
#define		ADCn_CFG1_MODE_12BIT								0b01
#define		ADCn_CFG1_MODE_10BIT								0b10
#define		ADCn_CFG1_MODE_RESRV								0b11
															/* refer manual	page: 1227*/

#define		ADCn_CFG1_ADICLK_1									0b00
#define		ADCn_CFG1_ADICLK_2									0b01
#define		ADCn_CFG1_ADICLK_3									0b10
#define		ADCn_CFG1_ADICLK_4									0b11
															/* refer manual	page: 1227*/

#define		ADCn_SC1_ADCH_EXTCH0ASINPUT							0b000000
#define		ADCn_SC1_ADCH_EXTCH1ASINPUT							0b000001
#define		ADCn_SC1_ADCH_EXTCH2ASINPUT							0b000010
#define		ADCn_SC1_ADCH_EXTCH3ASINPUT							0b000011
#define		ADCn_SC1_ADCH_EXTCH4ASINPUT							0b000100
#define		ADCn_SC1_ADCH_EXTCH5ASINPUT							0b000101
#define		ADCn_SC1_ADCH_EXTCH6ASINPUT							0b000110
#define		ADCn_SC1_ADCH_EXTCH7ASINPUT							0b000111
#define		ADCn_SC1_ADCH_EXTCH8ASINPUT							0b001000
#define		ADCn_SC1_ADCH_EXTCH9ASINPUT							0b001001
#define		ADCn_SC1_ADCH_EXTCH10ASINPUT						0b001010
#define		ADCn_SC1_ADCH_EXTCH11ASINPUT						0b001011
#define		ADCn_SC1_ADCH_EXTCH12ASINPUT						0b001100
#define		ADCn_SC1_ADCH_EXTCH13ASINPUT						0b001101
#define		ADCn_SC1_ADCH_EXTCH14ASINPUT						0b001110
#define		ADCn_SC1_ADCH_EXTCH15ASINPUT						0b001111
#define		ADCn_SC1_ADCH_INTCH0ASINPUT							0b010101
#define		ADCn_SC1_ADCH_INTCH1ASINPUT							0b010110
#define		ADCn_SC1_ADCH_INTCH2ASINPUT							0b010111
#define		ADCn_SC1_ADCH_BANDGAP								0b011011
#define		ADCn_SC1_ADCH_INTCH3ASINPUT							0b011100
#define		ADCn_SC1_ADCH_VREFSHASINPUT							0b011101	/* Note See SC2[REFSEL] in RM*/
#define		ADCn_SC1_ADCH_VREFSLASINPUT							0b011110
#define		ADCn_SC1_ADCH_EXTCH16ASINPUT						0b100000
#define		ADCn_SC1_ADCH_EXTCH17ASINPUT						0b100001
#define		ADCn_SC1_ADCH_EXTCH18ASINPUT						0b100010
#define		ADCn_SC1_ADCH_EXTCH19ASINPUT						0b100011
#define		ADCn_SC1_ADCH_EXTCH20ASINPUT						0b100100
#define		ADCn_SC1_ADCH_EXTCH21ASINPUT						0b100101
#define		ADCn_SC1_ADCH_EXTCH22ASINPUT						0b100110
#define		ADCn_SC1_ADCH_EXTCH23ASINPUT						0b100111
#define		ADCn_SC1_ADCH_EXTCH24ASINPUT						0b101000
#define		ADCn_SC1_ADCH_EXTCH25ASINPUT						0b101001
#define		ADCn_SC1_ADCH_EXTCH26ASINPUT						0b101010
#define		ADCn_SC1_ADCH_EXTCH27ASINPUT						0b101011
#define		ADCn_SC1_ADCH_EXTCH28ASINPUT						0b101100
#define		ADCn_SC1_ADCH_EXTCH29ASINPUT						0b101101
#define		ADCn_SC1_ADCH_EXTCH30ASINPUT						0b101110
#define		ADCn_SC1_ADCH_EXTCH31ASINPUT						0b101111
																/* refer manual	page: 1225*/

#define		ADCn_SC2_CONVTRIGSW									0b0
#define		ADCn_SC2_CONVTRIGHW									0b1


#define		ADCn_SC2_REF_SELDEFAULT								0b00
#define		ADCn_SC2_REF_SELALTREFVTG							0b01
																/* refer manual	page: 1234*/

#define		ADCn_SC3_HWAVGBY4SAMPLES							0b00
#define		ADCn_SC3_HWAVGBY8SAMPLES							0b01
#define		ADCn_SC3_HWAVGBY16SAMPLES							0b10
#define		ADCn_SC3_HWAVGBY32SAMPLES							0b11

#define		ADCn_CFG1(AdcModNo,	\
						Adiv,	\
						Mode,	\
						AdiClk	)									(	AdcModNo	->	CFG1	|=	(	ADC_CFG1_ADICLK(AdiClk)		|		\
																										ADC_CFG1_MODE(Mode)			|		\
																										ADC_CFG1_ADIV(Adiv)		)	)

#define		ADCn_CFG1_SETCLRTRIG(AdcModNo)							(	AdcModNo	->	CFG1	|=	ADC_CFG1_CLRLTRG_MASK	)


#define		ADCn_CFG2(AdcModNo,			\
						SampleRate		)							(	AdcModNo	->	CFG2	|=	(	ADC_CFG2_SMPLTS(SampleRate)	)	)

#define		ADCn_SC1_CHx(AdcModNo,		\
							ChnlNo,		\
							Aien,		\
							Adch		)							(	AdcModNo	->	SC1[ChnlNo]		|=	(	ADC_SC1_AIEN(Aien)	|		\
																												ADC_SC1_ADCH(Adch)	)	)

#define		ADCn_SC2_CHx(AdcModNo,		\
							TrigSel,	\
							Comp,		\
							CompGrt,	\
							CompRng,	\
							DmaEn,		\
							VtgRefSel	)							(	AdcModNo	->	SC2		|=	(	ADC_SC2_REFSEL(VtgRefSel)	|	\
																										ADC_SC2_DMAEN(DmaEn)		|	\
																										ADC_SC2_ACREN(CompRng)		|	\
																										ADC_SC2_ACFGT(CompGrt)		|	\
																										ADC_SC2_ACFE(Comp)			|	\
																										ADC_SC2_ADTRG(TrigSel)		)	)

#define		ADCn_SC3_CHx(AdcModNo,	\
							ContiConv,	\
							HwAvg,	\
							HwAvgSel	)							(	AdcModNo	->	SC3	|=	(	ADC_SC3_AVGS(HwAvgSel)			|	\
																									ADC_SC3_AVGE(HwAvg)				|	\
																									ADC_SC3_ADCO(ContiConv)		)	)

#define		ADCn_SC3_CALIB_SET(AdcModNo)							(	AdcModNo	->	SC3	|=		ADC_SC3_CAL_MASK)

extern	void	ADC_Init(void);
		void	ADC0_Init(void);
		void	ADC1_Init(void);

#endif /* MCAL_ADC_CORE_H_ */

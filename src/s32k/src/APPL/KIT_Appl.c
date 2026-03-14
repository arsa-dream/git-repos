/*
 * Appl.c
 *
 *  Created on: 03-Nov-2020
 *      Author: HP
 */

#include	"Headers.h"
#include	<string.h>
#include 	<signal.h>
#include 	<stdlib.h>
#include 	<math.h>


#define		APPL_INTENSITYDELAY_CHNGE								100000u
#define		APPL_SENSITIVITY											1u
#define		DUTY_MAX												5u
#define		TX_LEN													30u

const	uint8	RedStr[]	=	"\nRed : ";
const	uint8	OrangeStr[]	=	"\nOrange : ";
const	uint8	YellowStr[]	=	"\nyellow : ";
const	uint8	GreenStr[]	=	"\nGreen : ";
const	uint8	CyanStr[]	=	"\nCyan : ";
const	uint8	BlueStr[]	=	"\nblue : ";
const	uint8	VioletStr[]	=	"\nviolet : ";

static	sint8	TxBuf[TX_LEN];

static	char* 	itoa(int num, char* str, int base);
static	char *	my_strcat(char *dest, const char *src) ;
static	void 	reverse(char str[], int length);

//static	void	APPL_GlowRedOnly(uint8 	u8duty);
//static	void	APPL_GlowGreenOnly(uint8 	u8duty);
//static	void	APPL_GlowBlueOnly(uint8 	u8duty);
//static	void	APPL_GlowOrangeOnly(uint8 	u8duty);
//static	void	APPL_GlowYellowOnly(uint8 	u8duty);
//static	void	APPL_GlowCyanOnly(uint8 	u8duty);
//static	void	APPL_GlowVioletOnly(uint8 	u8duty);
//static	void	APPL_GlowYellowOnly(uint8 	u8duty);
//static	void	APPL_SendRGBInfo(uint8	u8duty, const	uint8	*Data);
//static	void 	APPL_ClrTx(void);
//static	void 	APPL_Rainbow(void);
static	void ConvertHSVtoRGB(float hue, float saturation, float value, int *red, int *green, int *blue);


void APPL_main(void)
{
    int red=0, green=0, blue=0;
    float hue, saturation = 1.0, value = 1.0; // Full saturation and brightness for vivid colors

    // Generate colors with varying hue (0 to 360 degrees)
    for (hue = 0; hue < 360; hue += 15) {
        ConvertHSVtoRGB(hue, saturation, value, &red, &green, &blue);

        // Insert APIs - user code

    	APPL_DISABLE_PWM_RED();
    	APPL_DISABLE_PWM_GREEN();
    	APPL_DISABLE_PWM_BLUE();

    	APPL_SetRedDuty(red);
    	APPL_SetBlueDuty(blue);
    	APPL_SetGreenDuty(green);
    }

}

void ConvertHSVtoRGB(float hue, float saturation, float value, int *red, int *green, int *blue) {
    float chroma = value * saturation;
    float intermediate_value = chroma * (1 - fabs(fmod(hue / 60.0, 2) - 1));
    float match_value = value - chroma;
    float r, g, b;

    if (hue >= 0 && hue < 60) {
        r = chroma; g = intermediate_value; b = 0;
    } else if (hue >= 60 && hue < 120) {
        r = intermediate_value; g = chroma; b = 0;
    } else if (hue >= 120 && hue < 180) {
        r = 0; g = chroma; b = intermediate_value;
    } else if (hue >= 180 && hue < 240) {
        r = 0; g = intermediate_value; b = chroma;
    } else if (hue >= 240 && hue < 300) {
        r = intermediate_value; g = 0; b = chroma;
    } else {
        r = chroma; g = 0; b = intermediate_value;
    }

    *red = (r + match_value) * 255;
    *green = (g + match_value) * 255;
    *blue = (b + match_value) * 255;

}
/* chat gpt code */

char *	my_strcat(char *dest, const char *src) {
    // Find the end of the destination string
    char *dest_ptr = dest;
    while (*dest_ptr != '\0') {
        dest_ptr++;
    }

    // Copy characters from the source to the end of the destination
    while (*src != '\0') {
        *dest_ptr = *src;
        dest_ptr++;
        src++;
    }

    // Add the null terminator at the end
    *dest_ptr = '\0';

    // Return the original destination pointer
    return dest;
}

void reverse(char str[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

char* itoa(int num, char* str, int base) {
    int i = 0;
    int is_negative = 0;

    // Handle 0 explicitly, otherwise the empty string is returned
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // Handle negative numbers only if base is 10
    if (num < 0 && base == 10) {
        is_negative = 1;
        num = -num;
    }

    // Process each digit and store it in the string
    while (num != 0) {
        int remainder = num % base;
        str[i++] = (remainder > 9) ? (remainder - 10) + 'a' : remainder + '0';
        num = num / base;
    }

    // Append minus sign if the number is negative
    if (is_negative) {
        str[i++] = '-';
    }

    str[i] = '\0';  // Null-terminate the string

    // Reverse the string to get the correct result
    reverse(str, i);

    return str;
}

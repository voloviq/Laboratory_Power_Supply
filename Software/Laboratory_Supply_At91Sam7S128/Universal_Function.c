/*
	Module include all most common function
	like converter digits and etc.

	Compiler: Gnu Gcc

	Language: Ansi C

	Ide: Eclipse

	Author: Michal Wolowik

	Date: Rzeszow listopad 2008
*/





#include "Universal_Function.h"






// Array use to storage a convertered strings with number
char string_comunicat[STRING_SIZE];





unsigned char Bcd2Hex(unsigned char bcd_val)
{
	unsigned char hex_val = 0x00;

	if(bcd_val<0x10)
	{
		hex_val = bcd_val;
	}
	else if(bcd_val >= 0x10 && bcd_val < 0x20)
	{
		hex_val += 10;
		hex_val += bcd_val - 0x10;
	}
	else if(bcd_val >= 0x20 && bcd_val < 0x30)
	{
		hex_val += 20;
		hex_val += bcd_val - 0x20;
	}
	else if(bcd_val >= 0x30 && bcd_val < 0x40)
	{
		hex_val += 30;
		hex_val += bcd_val - 0x30;
	}
	else if(bcd_val >= 0x40 && bcd_val < 0x50)
	{
		hex_val += 40;
		hex_val += bcd_val - 0x40;
	}
	else if(bcd_val >= 0x50 && bcd_val < 0x60)
	{
		hex_val += 50;
		hex_val += bcd_val - 0x50;
	}
	else if(bcd_val >= 0x60 && bcd_val < 0x70)
	{
		hex_val += 60;
		hex_val += bcd_val - 0x60;
	}
	else if(bcd_val >= 0x70 && bcd_val < 0x80)
	{
		hex_val += 70;
		hex_val += bcd_val - 0x70;
	}
	else if(bcd_val >= 0x80 && bcd_val < 0x90)
	{
		hex_val += 80;
		hex_val += bcd_val - 0x80;
	}
	else if(bcd_val >= 0x90 && bcd_val <= 0x9F)
	{
		hex_val += 90;
		hex_val += bcd_val - 0x90;
	}

	return hex_val;
}






unsigned char Hex2Bcd2(unsigned char hex_val)
{
	unsigned char bcd_val = 0x00;
	unsigned char th = 0x00, tl = 0x00;

	Hex2Dec(hex_val, &th, &tl);
	bcd_val |= (th<<4)|(tl);

	return bcd_val;
}






void Hex2Dec	(
					unsigned char hex_val,
					unsigned char *hex_value_high,
					unsigned char *hex_value_low
				)
{
	unsigned char tmp_1 = 0x00;

	tmp_1 = hex_val/100;

	*hex_value_high = (hex_val - tmp_1*100)/10;
	*hex_value_low = hex_val - tmp_1*100 - (*hex_value_high)*10;
}






char* Connect_2String_With_Value	(
									char *string_1,
									unsigned int value,
									char *string_2
								)
{
	unsigned int i = 0, j = 0;
	unsigned int temp = 0;
	unsigned long tab_value[7] = {1000000, 100000, 10000, 1000, 100, 10};
	unsigned int znaleziono = 0;


	// Clear string information
	for(i=0; i<STRING_SIZE; i++)
		string_comunicat[i] = 0;

	// Clear i variable
	i = 0;


	// Copy input string to string
	while(*string_1)
	{

		// Execute until reached maximum size of string
		if(i<STRING_SIZE)
			string_comunicat[i++] = *string_1;
		else
			break;
		string_1++;

	}

	for(j=0; j<6; j++)
	{
		temp = value/(tab_value[j]);

		if(temp < 10)
		{
			if(znaleziono == 0 && temp > 0)
				znaleziono = 1;

			if(znaleziono == 1)
			{
				value -= (temp*tab_value[j]);

				if(i<STRING_SIZE)
					string_comunicat[i++] += temp+0x30;
				else
					break;
			}
		}
	}

	temp = value%10;

	if(i<STRING_SIZE)
		string_comunicat[i++] += temp+0x30;


	// Copy input string_2 to string
	while(*string_2)
	{

		// Execute until reached maximum size of string
		if(i<STRING_SIZE)
			string_comunicat[i++] = *string_2;
		else
			break;
		string_2++;
	}

	// Execute until reached maximum size of string
	for(i=i; i<STRING_SIZE; i++)
		string_comunicat[i] = 0x20; // space char

	// This is necessary to end of actual string
	string_comunicat[i-1] = '\0'; // end of string


	return(string_comunicat);
}






unsigned int ConvHex2mV( unsigned int valueToConvert )
{
    return( (ADC_VREF * valueToConvert)/0x3FF);
}


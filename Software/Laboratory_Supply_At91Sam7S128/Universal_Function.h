/*
	Module include all most common function
	like converter digits and etc.

	Compiler: Gnu Gcc

	Language: Ansi C

	Ide: Eclipse

	Author: Michal Wolowik

	Date: Rzeszow listopad 2008
*/





#ifndef UNIVERSAL_FUNCTION_H_
#define UNIVERSAL_FUNCTION_H_





// Maximum chars in string
#define STRING_SIZE 15






// ADC referential voltage definition
#define ADC_VREF       3500  // 3.5 * 1000






/*
Function Name	:	Bcd2Hex
Description		:	Function convert digits from
					Bcd to Hex

Input		 	:	bcd_val:	bcd_val value

Output			:   None
Function Return	:	unsigned char: convertered hex value
*/
unsigned char Bcd2Hex(unsigned char bcd_val);





/*
Function Name	:	Hex2Bcd2
Description		:	Function Coding to digits to
					one char value

Input		 	:	hex_val:	hex value to bcd

Output			:   None
Function Return	:	unsigned char: convertered bcd value
*/
unsigned char Hex2Bcd2(unsigned char hex_val);





/*
Function Name	:	Hex2Dec
Description		:	Function Convert one hex digit to
					one 2 dec values

Input		 	:	hex_val:	hex value to bcd
Input		 	:	*hex_value_high:	hex value high
Input		 	:	*hex_value_low:		hex value low

Output			:   None
Function Return	:	None
*/
void Hex2Dec	(
					unsigned char hex_val,
					unsigned char *hex_value_high,
					unsigned char *hex_value_low
				);






/*
Function Name	:	Connect_2String_With_Value
Description		:	Function connect 2 input string
					with decimal value and return
					one string to display

Input		 	:	string_1: 1	string to display
Input		 	:	value:	to display with string
Input		 	:	string_2: 2	string to display


Output			:   None
Function Return	:	None
*/
char* Connect_2String_With_Value	(
									char *string_1,
									unsigned int value,
									char *string_2
								);






/*
Function Name	:	ConvHex2mV
Description		:	Function convert value from HEX cast
					to decimal value using VREF value

Input		 	:	valueToConvert: value which should be configure

Output			:   None
Function Return	:	unsigned int: converted value
*/
unsigned int ConvHex2mV( unsigned int valueToConvert );

#endif

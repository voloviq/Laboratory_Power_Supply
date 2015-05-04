/*
	Laboratory Supply Project
	pheriperial configurate, and
	low level startup. In this module
	are located all function to drive
	each necessary pheriperial like
	port drive, SPI Flash drive etc.

	Compiler: Gnu Gcc

	Language: Ansi C

	Ide: Eclipse

	Author: Michal Wolowik

	Date: Rzeszow may 2010
*/

#ifndef BOARD_LOWLEVEL_H_
#define BOARD_LOWLEVEL_H_





#include <pwmc/pwmc.h>
#include <adc/adc.h>
#include <pit/pit.h>
#include <pio/pio.h>
#include "../delay.h" // ../ means go to up word directory
#include "../Universal_Function.h"





/*
Function Name	:	PWM_Configure
Description		:	Function configure PWM channel in
					At91sam7s128 microcontroller.
					Each configure aspects are described
					in C module.

Input		 	:	None

Output			:   None
Function Return	:	None
*/
void PWM_Configure(void);






/*
Function Name	:	ADC_Configure
Description		:	Function configure ADC channel in
					At91sam7s128 microcontroller.
					Each configure aspects are described
					in C module.

Input		 	:	None

Output			:   None
Function Return	:	None
*/
void ADC_Configure(void);






/*
Function Name	:	Make_ADC_Measurements
Description		:	Function made once measurement
					for each selected before channel.
					This function was
					especialy wrote for current project.
					In furer uses shall be changed

Input		 	:	None

Output			:   None
Function Return	:	None
*/
void Make_ADC_Measurements(void);






/*
Function Name	:	Obtain_ADC_Conversion_Result
Description		:	Function obtain ADC conversion result
					from channel 0 to 7. This function was
					especialy wrote for current project.
					In furer uses shall be changed

Input		 	:	idx_channel: type 0 obtain result from channel 0
								 type 1 obtain result from channel 1
								 type 2 obtain result from channel 2
								 type 3 obtain result from channel 3
								 etc. up to 7

Output			:   None
Function Return	:	None
*/
unsigned int Obtain_ADC_Conversion_Result(unsigned char idx_channel);






/*
Function Name	:	ConfigurePit
Description		:	Configure the periodic interval timer to generate
					an interrupt every millisecond.

Input		 	:	None

Output			:   None
Function Return	:	None
*/
void ConfigurePit(void);






/*
Function Name	:	GPIO_Configure
Description		:	Configure all necessary access to port PIO

Input		 	:	None

Output			:   None
Function Return	:	None
*/
void GPIO_Configure(void);





/*
Function Name	:	Read_Selected_Pin
Description		:	Read button state on S1 to S5

Input		 	:	idx_button: possible value 1 - 5

Output			:   None
Function Return	:	unsigned char: if 0 button no click else 1
*/
unsigned char Read_Selected_Pin(unsigned char idx_button);






/*
Function Name	:	PWR_Led_State
Description		:	Light on/off of Power Led diode. If type 0 turn off
					if 1 turn on.

Input		 	:	None

Output			:   None
Function Return	:	None
*/
void PWR_Led_State(unsigned char state);






#endif /* BOARD_LOWLEVEL_H_ */


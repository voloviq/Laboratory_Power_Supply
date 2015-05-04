/*
	Laboratory Supply Project
	version V1_0

	Compiler: Gnu Gcc

	Language: Ansi C

	Ide: Eclipse

	Author: Michal Wolowik

	Date: Rzeszow may 2010
*/







#include <board.h>
#include <tc/tc.h>
#include <dbgu/dbgu.h>
#include <utility/trace.h>
#include <stdio.h>
#include "delay.h"
#include <board_lowlevel.h>







int main(void)
{

	volatile unsigned short i = 0;
	unsigned char fade_in_out = 1;
	volatile unsigned int result = 0;


	// PIO controller configure
	GPIO_Configure();



    // Periodic time interval startup
    ConfigurePit();



    // PWM channel configure
    PWM_Configure();



    // ADC channel configure
    ADC_Configure();





    // Infinite loop
    while (1)
    {


        PWMC_SetDutyCycle(VOLTAGE_REGULAOR_PWM_CHANNEL, i); // Fade in/out Voltage
        PWMC_SetDutyCycle(CURRENT_LIMIT_PWM_CHANNEL, i); // Fade in/out Current
        PWMC_SetDutyCycle(BRIGHTNESS_PWM_CHANNEL, i); // Fade in/out Current


        // Drive Power Led Diode
        if ( Read_Selected_Pin(5) )
        	PWR_Led_State(0);
        else
        	PWR_Led_State(1);


        // Make a measurements
        Make_ADC_Measurements();

        // Obtain ADC result from channel 5
        result = Obtain_ADC_Conversion_Result(5);


    	UTIL_WaitTimeInUs(BOARD_MCK, 300);


        if(fade_in_out != 0)
        {
        	i++;
        	if(i == 511)
        		fade_in_out ^= 1;

        }
        else
        {
        	i--;
        	if(i == 1)
        		fade_in_out ^= 1;
        }

    }
}


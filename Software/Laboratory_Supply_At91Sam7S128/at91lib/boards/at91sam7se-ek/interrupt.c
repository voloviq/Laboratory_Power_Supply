/*
	Interrupt module. This module consist of
	all exist interrupt routines of AT91sam7s128.

	Compiler: Gnu Gcc

	Language: Ansi C

	Ide: Eclipse

	Author: Michal Wolowik

	Date: Rzeszow may 2010
*/






#include "interrupt.h"
#include "board.h"







void ISR_Pwmc(void)
{

    static unsigned int count = 0;
    static unsigned int duty = MIN_DUTY_CYCLE;
    static unsigned char fadeIn = 1;

    // Interrupt on channel #1
    if ((AT91C_BASE_PWMC->PWMC_ISR & AT91C_PWMC_CHID1) == AT91C_PWMC_CHID1) {

        count++;

        // Fade in/out
        if (count == (PWM_FREQUENCY / (MAX_DUTY_CYCLE - MIN_DUTY_CYCLE))) {

            // Fade in
            if (fadeIn) {

                duty++;
                if (duty == MAX_DUTY_CYCLE) {

                    fadeIn = 0;
                }
            }
            // Fade out
            else {

                duty--;
                if (duty == MIN_DUTY_CYCLE) {

                    fadeIn = 1;
                }
            }

            // Set new duty cycle
            count = 0;
            //xxxPWMC_SetDutyCycle(CHANNEL_PWM_LED0, duty);
            //xxxPWMC_SetDutyCycle(CHANNEL_PWM_LED1, duty);
        }
    }

}






//------------------------------------------------------------------------------
/// Handler for PIT interrupt. Increments the timestamp counter.
//------------------------------------------------------------------------------
void ISR_Pit(void)
{
	static volatile unsigned int timestamp = 0;
    unsigned int status;
    static char i = 0;

    i ^= 1;


   //xxx if(i != 0)
    //xxx	PIO_Clear(pins+2);
    //xxxelse
        //xxxPIO_Set(pins+2);


    // Read the PIT status register
    status = PIT_GetStatus() & AT91C_PITC_PITS;
    if (status != 0) {

        // Read the PIVR to acknowledge interrupt and get number of ticks
        timestamp += (PIT_GetPIVR() >> 20);
    }
}

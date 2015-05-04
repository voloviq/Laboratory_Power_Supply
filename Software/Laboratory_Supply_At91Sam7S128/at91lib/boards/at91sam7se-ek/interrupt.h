/*
	Interrupt module. This module consist of
	all exist interrupt routines of AT91sam7s128.

	Compiler: Gnu Gcc

	Language: Ansi C

	Ide: Eclipse

	Author: Michal Wolowik

	Date: Rzeszow may 2010
*/

#ifndef INTERRUPT_H_
#define INTERRUPT_H_






#include "pwmc/pwmc.h"
#include <pit/pit.h>
#include <aic/aic.h>





/*
Function Name	:	ISR_Pwmc
Description		:	Interrupt routine of PWM. If any interrupt
					occuren due to PWM operation will be invoke
					in this funtion

Input		 	:	None

Output			:   None
Function Return	:	None
*/
void ISR_Pwmc(void);






/*
Function Name	:	ISR_Pit
Description		:	Interrupt routine of Periodic interval time.

Input		 	:	None

Output			:   None
Function Return	:	None
*/
void ISR_Pit(void);


#endif

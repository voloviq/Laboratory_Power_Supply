/*
	Delay modules.

	Compiler: Gnu Gcc

	Language: Ansi C

	Ide: Eclipse

	Author: Michal Wolowik

	Date: Rzeszow may 2010
*/






#include "delay.h"






//------------------------------------------------------------------------------
/// Wait time in ms
//------------------------------------------------------------------------------
void UTIL_Loop(volatile unsigned int loop)
{
    while(loop--)
    {
    	asm volatile ("nop");
    }
}







void UTIL_WaitTimeInMs(unsigned int mck, unsigned int time_ms)
{
    register unsigned int i = 0;
    i = (mck / 1000) * time_ms;
    i = i / 3;
    UTIL_Loop(i);
}







//------------------------------------------------------------------------------
/// Wait time in us
//------------------------------------------------------------------------------
void UTIL_WaitTimeInUs(unsigned int mck, unsigned int time_us)
{
    volatile unsigned int i = 0;
    i = (mck / 1000000) * time_us;
    i = i / 3;
    UTIL_Loop(i);
}

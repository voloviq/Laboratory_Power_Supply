/*
	Delay modules.

	Compiler: Gnu Gcc

	Language: Ansi C

	Ide: Eclipse

	Author: Michal Wolowik

	Date: Rzeszow may 2010
*/

#ifndef DELAY_H_
#define DELAY_H_






void UTIL_Loop(volatile unsigned int loop);







void UTIL_WaitTimeInMs(unsigned int mck, unsigned int time_ms);







void UTIL_WaitTimeInUs(unsigned int mck, unsigned int time_us);





#endif

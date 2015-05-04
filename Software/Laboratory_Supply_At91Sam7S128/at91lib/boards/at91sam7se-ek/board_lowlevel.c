/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

//------------------------------------------------------------------------------
/// \unit
///
/// !Purpose
///
/// Provides the low-level initialization function that gets called on chip
/// startup.
///
/// !Usage
///
/// LowLevelInit() is called in #board_cstartup.S#.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include "board.h"
#include <board_memories.h>
#include "board_lowlevel.h"
#include "interrupt.h"
#include <pmc/pmc.h>








/// Pio pins to configure.
static const Pin pins[] = {
	BRIGHTNESS_PWM,
	CURRENT_LIMIT_PWM,
	VOLTAGE_REGULATOR_PWM,
	N_D0, // 3 // Wrong Solder !
	N_D1, // 4 // Tested work perfectly
	N_D2, // 5 // Tested work perfectly
	N_D3, // 6 // Tested work perfectly
	N_D4, // 7 // Tested work perfectly
	N_D5, // 8 // Tested work perfectly
	N_D6, // 9 // Tested work perfectly
	N_D7, // 10 // Tested work perfectly
	N_RDX, // 11 // Tested work perfectly
	N_WRX, // 12 // Wrong Solder !
	N_RESX, // 13 Tested work perfectly
	N_CSX, // 14 Tested work perfectly
	N_D_CX, // 15 Tested work perfectly
	N_Pin31, // 16 Tested work perfectly
	N_Pin32, // 17 Tested work perfectly
	CONV_DIR_2, // 18 Tested work perfectly
	CONV_OE, // 19 Tested work perfectly
	POWER_LED, // 20 Tested work perfectly
	CONV_DIR_1, // 21 Tested work perfectly
	BUTTON_S1, // 22 Button number 1
	BUTTON_S2, // 23 Button number 2
	BUTTON_S3, // 24 Button number 3
	BUTTON_S4, // 25 Button number 4
	BUTTON_S5 // 26 Button number 4
};





// Result of ADC conversion for 4 channel
volatile unsigned int conv_result[8];





//------------------------------------------------------------------------------
//         Internal definitions
//------------------------------------------------------------------------------
// Startup time of main oscillator (in number of slow clock ticks).
#define BOARD_OSCOUNT           (AT91C_CKGR_OSCOUNT & (0x40 << 8))

// USB PLL divisor value to obtain a 48MHz clock.
#define BOARD_USBDIV            AT91C_CKGR_USBDIV_1

// PLL frequency range.
#define BOARD_CKGR_PLL          AT91C_CKGR_OUT_0

// PLL startup time (in number of slow clock ticks).
#define BOARD_PLLCOUNT          (16 << 8)

// PLL MUL value.
#define BOARD_MUL               (AT91C_CKGR_MUL & (72 << 16))

// PLL DIV value.
#define BOARD_DIV               (AT91C_CKGR_DIV & 14)

// Master clock prescaler value.
#define BOARD_PRESCALER         AT91C_PMC_PRES_CLK_2

//------------------------------------------------------------------------------
//         Internal functions
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/// Default spurious interrupt handler. Infinite loop.
//------------------------------------------------------------------------------
void defaultSpuriousHandler( void )
{
    while (1);
}

//------------------------------------------------------------------------------
/// Default handler for fast interrupt requests. Infinite loop.
//------------------------------------------------------------------------------
void defaultFiqHandler( void )
{
    while (1);
}

//------------------------------------------------------------------------------
/// Default handler for standard interrupt requests. Infinite loop.
//------------------------------------------------------------------------------
void defaultIrqHandler( void )
{
    while (1);
}


//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Performs the low-level initialization of the chip. This includes EFC, master
/// clock, AIC & watchdog configuration, as well as memory remapping.
//------------------------------------------------------------------------------
void LowLevelInit( void )
{
    unsigned char i;

    BOARD_ConfigureFlash48MHz();

//#if !defined(sdram)
    /* Initialize main oscillator
     ****************************/
    AT91C_BASE_PMC->PMC_MOR = BOARD_OSCOUNT | AT91C_CKGR_MOSCEN;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MOSCS));

    /* Initialize PLL at 96MHz (96.109) and USB clock to 48MHz */
    AT91C_BASE_PMC->PMC_PLLR = BOARD_USBDIV | BOARD_CKGR_PLL | BOARD_PLLCOUNT
                               | BOARD_MUL | BOARD_DIV;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_LOCK));

    /* Wait for the master clock if it was already initialized */
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));

    /* Switch to fast clock
     **********************/
    /* Switch to slow clock + prescaler */
    AT91C_BASE_PMC->PMC_MCKR = BOARD_PRESCALER;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));

    /* Switch to fast clock + prescaler */
    AT91C_BASE_PMC->PMC_MCKR |= AT91C_PMC_CSS_PLL_CLK;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));
//#endif //#if !defined(sdram)
    
    /* Initialize AIC
     ****************/
    AT91C_BASE_AIC->AIC_IDCR = 0xFFFFFFFF;
    AT91C_BASE_AIC->AIC_SVR[0] = (unsigned int) defaultFiqHandler;
    for (i = 1; i < 31; i++) {

        AT91C_BASE_AIC->AIC_SVR[i] = (unsigned int) defaultIrqHandler;
    }
    AT91C_BASE_AIC->AIC_SPU = (unsigned int) defaultSpuriousHandler;

    // Unstack nested interrupts
    for (i = 0; i < 8 ; i++) {

        AT91C_BASE_AIC->AIC_EOICR = 0;
    }

    // Enable Debug mode
    AT91C_BASE_AIC->AIC_DCR = AT91C_AIC_DCR_PROT;

    /* Watchdog initialization
     *************************/
    AT91C_BASE_WDTC->WDTC_WDMR = AT91C_WDTC_WDDIS;

    /* Remap
     *******/
    BOARD_RemapRam();

    // Disable RTT and PIT interrupts (potential problem when program A
    // configures RTT, then program B wants to use PIT only, interrupts
    // from the RTT will still occur since they both use AT91C_ID_SYS)
    AT91C_BASE_RTTC->RTTC_RTMR &= ~(AT91C_RTTC_ALMIEN | AT91C_RTTC_RTTINCIEN);
    AT91C_BASE_PITC->PITC_PIMR &= ~AT91C_PITC_PITIEN;
}






void PWM_Configure(void)
{
    // Enable PWMC peripheral clock
    AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_PWMC;

    // Settings:
    // - 100kHz PWM period (PWM_FREQUENCY)
    // - 1s rise/fall time for the LED intensity

    // Set clock A to run at 100kHz * MAX_DUTY_CYCLE (clock B is not used)
    PWMC_ConfigureClocks(PWM_FREQUENCY * MAX_DUTY_CYCLE, 0, BOARD_MCK);

    // Configure Voltage Regulator Pwm channel 0 (left-aligned)
    PWMC_ConfigureChannel(VOLTAGE_REGULAOR_PWM_CHANNEL, AT91C_PWMC_CPRE_MCKA, 0, 1);
    PWMC_SetPeriod(VOLTAGE_REGULAOR_PWM_CHANNEL, MAX_DUTY_CYCLE);
    PWMC_SetDutyCycle(VOLTAGE_REGULAOR_PWM_CHANNEL, MIN_DUTY_CYCLE);


    // Configure Current Limit Pwm channel 1 (center-aligned, inverted polarity)
    PWMC_ConfigureChannel(CURRENT_LIMIT_PWM_CHANNEL, AT91C_PWMC_CPRE_MCKA, AT91C_PWMC_CALG, AT91C_PWMC_CPOL);
    PWMC_SetPeriod(CURRENT_LIMIT_PWM_CHANNEL, MAX_DUTY_CYCLE);
    PWMC_SetDutyCycle(CURRENT_LIMIT_PWM_CHANNEL, MIN_DUTY_CYCLE);


    // Configure Brightness Regulation channel 2 (left-aligned)
    PWMC_ConfigureChannel(BRIGHTNESS_PWM_CHANNEL, AT91C_PWMC_CPRE_MCKA, 0, 0);
    PWMC_SetPeriod(BRIGHTNESS_PWM_CHANNEL, MAX_DUTY_CYCLE);
    PWMC_SetDutyCycle(BRIGHTNESS_PWM_CHANNEL, MIN_DUTY_CYCLE);



    // Configure interrupt on channel #1
    //xxxAIC_ConfigureIT(AT91C_ID_PWMC, 0, ISR_Pwmc);
    //xxxAIC_EnableIT(AT91C_ID_PWMC);
    //xxxPWMC_EnableChannelIt(CHANNEL_PWM_LED0);



    // Enable channel PWM channel number 0, 1, 2
    PWMC_EnableChannel(VOLTAGE_REGULAOR_PWM_CHANNEL);
    PWMC_EnableChannel(CURRENT_LIMIT_PWM_CHANNEL);
    PWMC_EnableChannel(BRIGHTNESS_PWM_CHANNEL);

    PWMC_SetDutyCycle(CURRENT_LIMIT_PWM_CHANNEL, 20);
    PWMC_SetDutyCycle(VOLTAGE_REGULAOR_PWM_CHANNEL, 20);

}






void ADC_Configure(void)
{
    // Analog digital converter configure section
    ADC_Initialize( AT91C_BASE_ADC,
                    AT91C_ID_ADC,
                    AT91C_ADC_TRGEN_DIS,
                    0,
                    AT91C_ADC_SLEEP_NORMAL_MODE,
                    AT91C_ADC_LOWRES_10_BIT,
                    BOARD_MCK,
                    BOARD_ADC_FREQ,
                    10,
                    1200);

    // Enable all used ADC channels
    ADC_EnableChannel(AT91C_BASE_ADC, ADC_CHANNEL_4);
    ADC_EnableChannel(AT91C_BASE_ADC, ADC_CHANNEL_5);
    ADC_EnableChannel(AT91C_BASE_ADC, ADC_CHANNEL_6);
    ADC_EnableChannel(AT91C_BASE_ADC, ADC_CHANNEL_7);
}







void ConfigurePit(void)
{
    // Initialize the PIT to the desired frequency
    PIT_Init(PIT_PERIOD, BOARD_MCK / 1000000);

    // Configure interrupt on PIT
    AIC_DisableIT(AT91C_ID_SYS);
    AIC_ConfigureIT(AT91C_ID_SYS, AT91C_AIC_PRIOR_LOWEST, ISR_Pit);
    AIC_EnableIT(AT91C_ID_SYS);
    PIT_EnableIT();

    // Enable the pit
    PIT_Enable();
}






void Make_ADC_Measurements(void)
{
	volatile unsigned int conversion_state = 0;
	volatile unsigned char i = 0;

	// Start measurement
	ADC_StartConversion(AT91C_BASE_ADC);

	// Minimal necessary delay befor two fast measurements
	// Added experimentaly value
	UTIL_WaitTimeInUs(BOARD_MCK, 10);


	while( 0xF0 != (unsigned char)conversion_state )
	{
		conversion_state = ADC_GetStatus(AT91C_BASE_ADC);
	};

	for(i=0; i<8; i++)
	{
		conv_result[i] = ConvHex2mV( ADC_GetConvertedData(AT91C_BASE_ADC, i) );
	}
}






unsigned int Obtain_ADC_Conversion_Result(unsigned char idx_channel)
{
	if(idx_channel<8)
		return conv_result[idx_channel];
	else
		return 0;
}






void GPIO_Configure(void)
{
    PIO_Configure(pins, PIO_LISTSIZE(pins));


    // Configure Voltage converter

    // Enable both chip
    PIO_Clear(pins+19);

    // Direction form A sied to B sied on both chip
    PIO_Set(pins+21);
    PIO_Set(pins+18);


}






unsigned char Read_Selected_Pin(unsigned char idx_button)
{
	if( (idx_button > 0) && (idx_button < 6 ) )
		return PIO_Get(pins+21+idx_button);
	else
		return 0;
}






void PWR_Led_State(unsigned char state)
{
    if(state != 0)
    	PIO_Set(pins+20);
    else
    	PIO_Clear(pins+20);
}


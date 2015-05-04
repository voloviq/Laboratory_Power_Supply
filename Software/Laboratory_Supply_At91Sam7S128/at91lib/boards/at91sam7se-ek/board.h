/*
	In this board.h module was described
	all necessary pin configuration
	used in Laboratory suppy V1_0 project

	Compiler: Gnu Gcc

	Language: Ansi C

	Ide: Eclipse

	Author: Michal Wolowik

	Date: Rzeszow may 2010
*/


#ifndef BOARD_H 
#define BOARD_H






// Device model file use


//xxx This files and header shall be reconfigure to proper
//xxx should be change in last revision


#if defined(at91sam7se32)
    #include "at91sam7se32/AT91SAM7SE32_.h"
#elif defined(at91sam7s128)
    #include "at91sam7s128/AT91SAM7S128.h"
#elif defined(at91sam7se256)
    #include "at91sam7se256/AT91SAM7SE256.h"
#elif defined(at91sam7se512)
    #include "at91sam7se512/AT91SAM7SE512_.h"
#else
    #error Board does not support the specified chip.
#endif






// Device configure


//xxx In last revision this name should be change to correct name
#define BOARD_NAME "AT91SAM7SE-EK"
/// Board definition.
#define at91sam7seek
/// Family definition.
#define at91sam7se






// Choose main oscilator and main MCK clock value


/// Frequency of the board main oscillator.
#define BOARD_MAINOSC           14745600

/// Master clock frequency (when using board_lowlevel.c).
#define BOARD_MCK               48000000
//------------------------------------------------------------------------------







/// PWM frequency in Hz.
#define PWM_FREQUENCY               40000

/// Maximum duty cycle value.
#define MAX_DUTY_CYCLE              512

/// Delay for pushbutton debouncing (in milliseconds).
#define DEBOUNCE_TIME       500

/// PIT period value in useconds.
#define PIT_PERIOD          1000

// Minimum PWM duty cycle
#define MIN_DUTY_CYCLE 0 // In some cases shall be 2 look to errata sheet






//------------------------------------------------------------------------------
// ADC
//------------------------------------------------------------------------------


// ADC clock frequency, at 10-bit resolution (in Hz)
#define ADC_MAX_CK_10BIT         5000000

// ADC clock frequency, at 8-bit resolution (in Hz)
#define ADC_MAX_CK_8BIT          8000000

// Startup time max, return from Idle mode (in us)
#define ADC_STARTUP_TIME_MAX       20

// Track and hold Acquisition Time min (in ns)
#define ADC_TRACK_HOLD_TIME_MIN   600

// ADC frequency definition 5[MHz]
#define BOARD_ADC_FREQ 5000000







//------------------------------------------------------------------------------
/// \page "SAM7SE-EK - USB device"
/// This page lists constants describing several characteristics (controller
/// type, D+ pull-up type, etc.) of the USB device controller of the chip/board.
/// 
/// !Constants
/// - BOARD_USB_UDP
/// - BOARD_USB_PULLUP_INTERNAL
/// - BOARD_USB_NUMENDPOINTS
/// - BOARD_USB_ENDPOINTS_MAXPACKETSIZE
/// - BOARD_USB_ENDPOINTS_BANKS
/// - BOARD_USB_BMATTRIBUTES

/// Chip has a UDP controller.
#define BOARD_USB_UDP

/// Indicates the D+ pull-up is internal to the USB controller.
#define BOARD_USB_PULLUP_INTERNAL

/// Number of endpoints in the USB controller.
#define BOARD_USB_NUMENDPOINTS                  8

/// Returns the maximum packet size of the given endpoint.
#define BOARD_USB_ENDPOINTS_MAXPACKETSIZE(i)    (((i == 4) || (i == 5)) ? 512 : 64)

/// Returns the number of FIFO banks for the given endpoint.
#define BOARD_USB_ENDPOINTS_BANKS(i)            (((i == 0) || (i == 3)) ? 1 : 2)

/// USB attributes configuration descriptor (bus or self powered, remote wakeup)
#define BOARD_USB_BMATTRIBUTES                  USBConfigurationDescriptor_SELFPOWERED_NORWAKEUP
//------------------------------------------------------------------------------





// Descripion of all used pins in Laboratory Supply V1_0 Project


// AT91Sam7s128 used pheriperial list:






// PWM Pheriperial

// 1. To regulate PWM brightness used PIN44 - PA2(PWM2)

// 2. To regulate PWM current limit used PIN47 - PA1(PWM1)

// 3. To regulate PWM voltage level used PIN48 - PA0(PWM0)




// ADC Pheripierial

// 4. To measure voltage level used PIN3 - AD4

// 5. To measure current level used PIN4 - AD5

// 6. To measure temperature sensor 1 used PIN5 - AD6

// 7. To measure temperature sensor 2 used PIN6 - AD7




// SPI Pheriperial

// 8. Chip select CS used PIN28 - PA11(NPCS0)

// 9. MISO used PIN27 - PA12(MISO)

// 10. MOSI used PIN22 - PA13(MOSI)

// 11. SPCK used PIN21 - PA14(SPCK)




// USB Pheriperial

// 12. D+ is connected to PIN57 - DDP

// 13. D- is connected to PIN56 - DDM




// GPIO Pheriperial

// 14. NOKIA_N73 display 'D0' signal connected to PIN11 - PA21 - configure this pin to OUTPUT

// 15. NOKIA_N73 display 'D1' signal connected to PIN34 - PA6 - configure this pin to OUTPUT

// 16. NOKIA_N73 display 'D2' signal connected to PIN20 - PA15 - configure this pin to OUTPUT

// 17. NOKIA_N73 display 'D3' signal connected to PIN32 - PA7 - configure this pin to OUTPUT

// 18. NOKIA_N73 display 'D4' signal connected to PIN19 - PA16 - configure this pin to OUTPUT

// 19. NOKIA_N73 display 'D5' signal connected to PIN31 - PA8 - configure this pin to OUTPUT

// 20. NOKIA_N73 display 'D6' signal connected to PIN13 - PA19 - configure this pin to OUTPUT

// 21. NOKIA_N73 display 'D7' signal connected to PIN30 - PA9 - configure this pin to OUTPUT

// 22. NOKIA_N73 display 'RDX' signal connected to PIN36 - PA4 - configure this pin to OUTPUT

// 23. NOKIA_N73 display 'WRX' signal connected to PIN10 - PA18 - configure this pin to OUTPUT

// 24. NOKIA_N73 display 'RESX' signal connected to PIN15 - PA23 - configure this pin to OUTPUT

// 25. NOKIA_N73 display 'CSX' signal connected to PIN14 - PA22 - configure this pin to OUTPUT

// 26. NOKIA_N73 display 'D/CX' signal connected to PIN35 - PA5 - configure this pin to OUTPUT

// 27. NOKIA_N73 display 'TE' signal connected to PIN29 - PA10 - configure this pin to INPUT

// 28. General Purpose should be check 'Pin31' signal connected to PIN37 - PA27 - configure this pin to OUTPUT free to use

// 29. Drive USB load line D+ 'Pin32' signal connected to PIN9 - PA17 - configure this pin to OUTPUT

// 30. Level converter direction 'CONV_DIR_2' signal connected to PIN16 - PA20 - configure this pin to OUTPUT

// 31. Level converter enable 'CONV_OE' signal connected to PIN23 - PA24 - configure this pin to OUTPUT

// 32. Switch button 'S4' signal connected to PIN25 - PA25 - configure this pin to INPUT

// 33. Switch button 'S3' signal connected to PIN26 - PA26 - configure this pin to INPUT

// 34. Level converter direction 'CONV_DIR_1' signal connected to PIN38 - PA28 - configure this pin to OUTPUT

// 35. Switch button 'S5' signal connected to PIN41 - PA29 - configure this pin to INPUT

// 36. Switch button 'S2' signal connected to PIN42 - PA30 - configure this pin to INPUT

// 37. Power LED signal connected to PIN52 - PA31 - configure this pin to OUTPUT

// 38. Switch button 'S1' signal connected to PIN43 - PA3 - configure this pin to INPUT






// 1. To regulate PWM brightness used PIN44 - PA2(PWM2)
#define BRIGHTNESS_PWM_CHANNEL 2
#define BRIGHTNESS_PWM PIN_PWMC_PWM2
#define PIN_PWMC_PWM2  {1 << 2, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}



// 2. To regulate PWM current limit used PIN47 - PA1(PWM1)
#define CURRENT_LIMIT_PWM_CHANNEL 1
#define CURRENT_LIMIT_PWM PIN_PWMC_PWM1
#define PIN_PWMC_PWM1  {1 << 1, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}



// 3. To regulate PWM voltage level used PIN48 - PA0(PWM0)
#define VOLTAGE_REGULAOR_PWM_CHANNEL 0
#define VOLTAGE_REGULATOR_PWM PIN_PWMC_PWM0
#define PIN_PWMC_PWM0  {1 << 0, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}




// ADC Pin Configure


// 4. To measure voltage level used PIN3 - AD4
#define VOLTAGE_MASURE_ADC4 {1 << 17, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_DEFAULT}

// 5. To measure current level used PIN4 - AD5
#define CURRENT_MEASURE_ADC5 {1 << 18, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_DEFAULT}

// 6. To measure temperature sensor 1 used PIN5 - AD6
#define TEMPEARATURE1_MEASURE_ADC6 {1 << 19, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_DEFAULT}

// 7. To measure temperature sensor 2 used PIN6 - AD7
#define TEMPEARATURE1_MEASURE_ADC7 {1 << 20, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_DEFAULT}

// Pins ADC - all each other
#define PINS_ADC VOLTAGE_MASURE_ADC4, CURRENT_MEASURE_ADC5, TEMPEARATURE1_MEASURE_ADC6, TEMPEARATURE1_MEASURE_ADC7




// Work of Voltage converter 74LVC4245A

// To eneable chip on EN pin22 shall be tied logic zero

// Direction from A side to B sied tied logical one to pin2 DIR

// Direction from B side to A sied tied logical zero to pin2 DIR



// GPIO Pheriperial

// 14. NOKIA_N73 display 'D0' signal connected to PIN11 - PA21 - configure this pin to OUTPUT
#define N_D0  {1 << 21, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 15. NOKIA_N73 display 'D1' signal connected to PIN34 - PA6 - configure this pin to OUTPUT
#define N_D1  {1 << 6, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 16. NOKIA_N73 display 'D2' signal connected to PIN20 - PA15 - configure this pin to OUTPUT
#define N_D2  {1 << 15, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 17. NOKIA_N73 display 'D3' signal connected to PIN32 - PA7 - configure this pin to OUTPUT
#define N_D3  {1 << 7, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 18. NOKIA_N73 display 'D4' signal connected to PIN19 - PA16 - configure this pin to OUTPUT
#define N_D4  {1 << 16, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 19. NOKIA_N73 display 'D5' signal connected to PIN31 - PA8 - configure this pin to OUTPUT
#define N_D5  {1 << 8, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 20. NOKIA_N73 display 'D6' signal connected to PIN13 - PA19 - configure this pin to OUTPUT
#define N_D6  {1 << 19, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 21. NOKIA_N73 display 'D7' signal connected to PIN30 - PA9 - configure this pin to OUTPUT
#define N_D7  {1 << 9, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 22. NOKIA_N73 display 'RDX' signal connected to PIN36 - PA4 - configure this pin to OUTPUT
#define N_RDX  {1 << 4, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 23. NOKIA_N73 display 'WRX' signal connected to PIN10 - PA18 - configure this pin to OUTPUT
#define N_WRX  {1 << 18, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 24. NOKIA_N73 display 'RESX' signal connected to PIN15 - PA23 - configure this pin to OUTPUT
#define N_RESX  {1 << 23, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 25. NOKIA_N73 display 'CSX' signal connected to PIN14 - PA22 - configure this pin to OUTPUT
#define N_CSX  {1 << 22, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 26. NOKIA_N73 display 'D/CX' signal connected to PIN35 - PA5 - configure this pin to OUTPUT
#define N_D_CX  {1 << 5, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 27. NOKIA_N73 display 'TE' signal connected to PIN29 - PA10 - configure this pin to INPUT
#define N_TE  {1 << 10, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_PULLUP}

// 28. General Purpose should be check 'Pin31' signal connected to PIN37 - PA27 - configure this pin to OUTPUT free to use
#define N_Pin31  {1 << 27, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 29. Drive USB load line D+ 'Pin32' signal connected to PIN9 - PA17 - configure this pin to OUTPUT
#define N_Pin32  {1 << 17, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 30. Level converter direction 'CONV_DIR_2' signal connected to PIN16 - PA20 - configure this pin to OUTPUT
#define CONV_DIR_2  {1 << 20, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 31. Level converter enable 'CONV_OE' signal connected to PIN23 - PA24 - configure this pin to OUTPUT
#define CONV_OE  {1 << 24, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 32. Switch button 'S4' signal connected to PIN25 - PA25 - configure this pin to INPUT
#define BUTTON_S4  {1 << 25, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_PULLUP}

// 33. Switch button 'S3' signal connected to PIN26 - PA26 - configure this pin to INPUT
#define BUTTON_S3  {1 << 26, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_PULLUP}

// 34. Level converter direction 'CONV_DIR_1' signal connected to PIN38 - PA28 - configure this pin to OUTPUT
#define CONV_DIR_1  {1 << 28, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 35. Switch button 'S5' signal connected to PIN41 - PA29 - configure this pin to INPUT
#define BUTTON_S5  {1 << 29, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_PULLUP}

// 36. Switch button 'S2' signal connected to PIN42 - PA30 - configure this pin to INPUT
#define BUTTON_S2  {1 << 30, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_PULLUP}

// 37. Power LED signal connected to PIN52 - PA31 - configure this pin to OUTPUT
#define POWER_LED  {1 << 31, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}

// 38. Switch button 'S1' signal connected to PIN43 - PA3 - configure this pin to INPUT
#define BUTTON_S1  {1 << 3, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_PULLUP}


/// Programmable clock output 2 pin definition.
//xxx#define PIN_PCK2    {1 << 31, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}

/// DBGU pins (DTXD and DRXD) definitions.
//xxx#define PINS_DBGU  {0x00000600, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}

/// Power LED index.
//xxx#define PWR_LED        31

/// LED #0 pin definition.
//xxx#define POWER_LED  {1 << PWR_LED, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}
/// LED #1 pin definition.
//xxx#define PIN_LED_1  {1 << 11, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_1, PIO_DEFAULT}
/// LED #2 pin definition.
//xxx#define PIN_LED_2  {1 << 12, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_1, PIO_DEFAULT}
/// List of all LEDs pin definitions.
//xxx#define PINS_LEDS  PIN_LED_0, PIN_LED_1, PIN_LED_2
/// DS1 LED index.
#define LED_DS1          11
/// DS2 LED index.
#define LED_DS2          12


/// Push button #1 definition.
#define PIN_PUSHBUTTON_1  {1 << 25, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_PULLUP}
/// Push button #2 definition.
#define PIN_PUSHBUTTON_2  {1 << 22, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_PULLUP}
/// List of all push button definitions.
#define PINS_PUSHBUTTONS  PIN_PUSHBUTTON_1, PIN_PUSHBUTTON_2
/// Push button #1 index.
#define PUSHBUTTON_BP1   0
/// Push button #2 index.
#define PUSHBUTTON_BP2   1

// Joystick definition.
/// Joystick UP.
#define PIN_JOYSTICK_UP    {1 << 23, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_PULLUP}
/// Joystick DOWN.
#define PIN_JOYSTICK_DOWN  {1 << 24, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_PULLUP}
/// Joystick LEFT.
#define PIN_JOYSTICK_LEFT  {1 << 27, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_PULLUP}
/// Joystick RIGHT.
#define PIN_JOYSTICK_RIGHT {1 << 26, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_PULLUP}
/// Joystick LEFT clic.
#define PIN_JOYSTICK_LCLIC {1 << 25, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_PULLUP}
/// Joystick PUSH button.
#define PIN_JOYSTICK_PUSH  PIN_JOYSTICK_LCLIC
/// Joystick RIGHT clic push button.
#define PIN_JOYSTICK_RCLIC {1 << 22, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_PULLUP}
/// List of all Joystick click definitions
#define PINS_JOYSTICK_CLIC   PIN_JOYSTICK_RCLIC, PIN_JOYSTICK_LCLIC
/// List of all Joystick movement direction definitions
#define PINS_JOYSTICK_MOVE  PIN_JOYSTICK_UP, PIN_JOYSTICK_DOWN, \
                            PIN_JOYSTICK_LEFT, PIN_JOYSTICK_RIGHT
/// List of all Joystick definitions
#define PINS_JOYSTICK  PINS_JOYSTICK_MOVE, \
                       PINS_JOYSTICK_CLIC
/// Joystick UP index.
#define JOYSTICK_UP         0
/// Joystick DOWN index.
#define JOYSTICK_DOWN       1
/// Joystick LEFT index.
#define JOYSTICK_LEFT       2
/// Joystick RIGHT index.
#define JOYSTICK_RIGHT      3
/// Joystick LEFT CLICK index.
#define JOYSTICK_LCLIC      4
/// Joystick PUSH button index.
#define JOYSTICK_PUSH       4
/// Joystick RIGHT CLIC index.
#define JOYSTICK_RCLIC      5

/// USART0 TXD pin definition.
#define PIN_USART0_RXD  {1 << 5, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/// USART0 RXD pin definition.
#define PIN_USART0_TXD  {1 << 6, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/// USART0 RTS pin definition
#define PIN_USART0_RTS  {1 << 7, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/// USART0 CTS pin definition
#define PIN_USART0_CTS  {1 << 8, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/// USART0 SCK pin definition
#define PIN_USART0_SCK  {1 << 2, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}


/// SPI MISO pin definition.
#define PIN_SPI_MISO   {1 << 12, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
/// SPI MOSI pin definition.
#define PIN_SPI_MOSI   {1 << 13, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
/// SPI SPCK pin definition.
#define PIN_SPI_SPCK   {1 << 14, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
/// List of SPI pin definitions (MISO, MOSI & SPCK).
#define PINS_SPI       PIN_SPI_MISO, PIN_SPI_MOSI, PIN_SPI_SPCK
/// SPI chip select 0 pin definition.
#define PIN_SPI_NPCS0  {1 << 11, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
/// SPI chip select 1 pin definition.
//xxx #define PIN_SPI_NPCS1  {1 << 31, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
/// SPI chip select 2 pin definition.
#define PIN_SPI_NPCS2  {1 << 10, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_PULLUP}
/// SPI chip select 3 pin definition.
#define PIN_SPI_NPCS3  {1 <<  3, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_PULLUP}

/// SSC transmitter pins definition.
#define PINS_SSC_TX  {0x00038000, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}



/// TWI pins definition.
#define PINS_TWI  {0x00000018, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_OPENDRAIN}

/// USB VBus monitoring pin definition.
#define PIN_USB_VBUS    {1 << 19, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_INPUT, PIO_DEFAULT}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM7SE-EK - External components"
/// This page lists the definitions related to external on-board components
/// located in the board.h file for the AT91SAM7SE-EK.
/// 
/// !AT45 Dataflash (serial onboard DataFlash)
/// - BOARD_AT45_A_SPI_BASE
/// - BOARD_AT45_A_SPI_ID
/// - BOARD_AT45_A_SPI_PINS
/// - BOARD_AT45_A_SPI
/// - BOARD_AT45_A_NPCS
/// - BOARD_AT45_A_NPCS_PIN
///
/// !AT26 Serialflash 
/// - BOARD_AT26_A_SPI_BASE
/// - BOARD_AT26_A_SPI_ID
/// - BOARD_AT26_A_SPI_PINS
/// - BOARD_AT26_A_SPI
/// - BOARD_AT26_A_NPCS
/// - BOARD_AT26_A_NPCS_PIN
///
/// !AT73C213
/// - BOARD_AT73C213_SPI
/// - BOARD_AT73C213_SPI_ID
/// - BOARD_AT73C213_NPCS
/// - BOARD_AT73C213_SSC
/// - BOARD_AT73C213_SSC_ID
/// - BOARD_AT73C213_MCK
///
/// !SD Card SPI
/// - BOARD_SD_SPI_BASE
/// - BOARD_SD_SPI_ID  
/// - BOARD_SD_SPI_PINS
/// - BOARD_SD_NPCS    

/// Base address of SPI peripheral connected to the dataflash.
#define BOARD_AT45_A_SPI_BASE         AT91C_BASE_SPI
/// Identifier of SPI peripheral connected to the dataflash.
#define BOARD_AT45_A_SPI_ID           AT91C_ID_SPI
/// Pins of the SPI peripheral connected to the dataflash.
#define BOARD_AT45_A_SPI_PINS         PINS_SPI
/// Dataflash SPI peripheral index.
#define BOARD_AT45_A_SPI              0
/// Chip select connected to the dataflash.
#define BOARD_AT45_A_NPCS             0
/// Chip select pin connected to the dataflash.
#define BOARD_AT45_A_NPCS_PIN         PIN_SPI_NPCS0

/// Base address of SPI peripheral connected to the serialflash.
#define BOARD_AT26_A_SPI_BASE         AT91C_BASE_SPI
/// Identifier of SPI peripheral connected to the serialflash.
#define BOARD_AT26_A_SPI_ID           AT91C_ID_SPI
/// Pins of the SPI peripheral connected to the serialflash.
#define BOARD_AT26_A_SPI_PINS         PINS_SPI
/// Serialflash SPI number.
#define BOARD_AT26_A_SPI              0
/// Chip select connected to the serialflash.
#define BOARD_AT26_A_NPCS             0
/// Chip select pin connected to the serialflash.
#define BOARD_AT26_A_NPCS_PIN         PIN_SPI_NPCS0

/// Base address of SPI peripheral to which the DAC is connected.
#define BOARD_AT73C213_SPI          AT91C_BASE_SPI
/// Peripheral ID of the SPI connected to the DAC.
#define BOARD_AT73C213_SPI_ID       AT91C_ID_SPI
/// Chip select value for accessing the DAC with the SPI.
#define BOARD_AT73C213_SPI_NPCS     1
/// Pins required by the SPI interface.
#define BOARD_AT73C213_SPI_PINS     PINS_SPI, PIN_SPI_NPCS1
/// SSC peripheral to which the DAC is connected.
#define BOARD_AT73C213_SSC          AT91C_BASE_SSC
/// Peripheral ID of the SSC connected to the DAC.
#define BOARD_AT73C213_SSC_ID       AT91C_ID_SSC
/// Pins required by the SSC interface.
#define BOARD_AT73C213_SSC_PINS     PINS_SSC_TX
/// PCK pin connected to the DAC MCK pin
#define BOARD_AT73C213_MCK          PIN_PCK2

/// Not define in our board, but customer can add this feature
/// Base address of the SPI peripheral connected to the SD card.
#define BOARD_SD_SPI_BASE   AT91C_BASE_SPI
/// Identifier of the SPI peripheral connected to the SD card.
#define BOARD_SD_SPI_ID     AT91C_ID_SPI
/// List of pins to configure to access the SD card
#define BOARD_SD_SPI_PINS   PINS_SPI, PIN_SPI_NPCS2
/// NPCS number
#define BOARD_SD_NPCS       2

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM7SE-EK - Memories"
/// This page lists definitions related to external on-board memories.
///
/// !Embedded flash
/// - BOARD_FLASH_EFC
///
/// !SDRAM
/// - AT91C_EBI_SDRAM
/// - BOARD_SDRAM_SIZE
/// - PINS_SDRAM
/// - BOARD_SDRAM_BUSWIDTH
/// 
/// !Nandflash
/// - BOARD_NF_COMMAND_ADDR
/// - BOARD_NF_ADDRESS_ADDR
/// - BOARD_NF_DATA_ADDR
/// - BOARD_NF_CE_PIN
/// - BOARD_NF_RB_PIN
/// - PINS_NANDFLASH
///
/// !NorFlash
/// - BOARD_NORFLASH_ADDR

/// Indicates board has an EFC.
#define BOARD_FLASH_EFC

/// Base address of the SDRAM memory connected to the EBI.
#define AT91C_EBI_SDRAM    ((volatile unsigned char *) 0x20000000)
/// Board SDRAM size
#define BOARD_SDRAM_SIZE   (64*1024*1024)  // 64 MB
/// List of the pins used by the EBI to connect to the external SDRAM chip.
#define PINS_SDRAM  \
    {0x3F800000, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}, \
    {0x0003FFFF, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_B, PIO_DEFAULT}, \
    {0x0000FFFF, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}
/// SDRAM bus width.
#define BOARD_SDRAM_BUSWIDTH 16

/// Nandflash controller peripheral pins definition.
#define PINS_NANDFLASH          {0x001800FF, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}, \
                                {0x00060000, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT}, \
                                BOARD_NF_CE_PIN, \
                                BOARD_NF_RB_PIN
/// Nandflash chip enable pin definition.
#define BOARD_NF_CE_PIN         {1 << 18, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_1, PIO_DEFAULT}
/// Nandflash ready/busy pin definition.
#define BOARD_NF_RB_PIN         {1 << 19, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_PULLUP}
/// Address for transferring command bytes to the nandflash.
#define BOARD_NF_COMMAND_ADDR   0x40400000
/// Address for transferring address bytes to the nandflash.
#define BOARD_NF_ADDRESS_ADDR   0x40200000
/// Address for transferring data bytes to the nandflash.
#define BOARD_NF_DATA_ADDR      0x40000000

/// NORFlash peripheral pins definition.
#define PINS_NORFLASH           {0xC0000000, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}, \
                                {0xFFFFFFFE, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_B, PIO_DEFAULT},\
                                {0x001FFFFF, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT},\
                                {0x00E00000, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT}
/// Address for transferring command bytes to the norflash.
#define BOARD_NORFLASH_ADDR     0x10000000
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM7SE-EK - External components"
/// This page lists the definitions related to external on-board components
/// located in the board.h file for the SAM7SE-EK.
/// 
/// !ISO7816
/// - PIN_SMARTCARD_CONNECT
/// - PIN_ISO7816_RSTMC
/// - PINS_ISO7816

/// Smartcard detection pin
#define PIN_SMARTCARD_CONNECT   {1 << 5, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_DEFAULT}
/// PIN used for reset the smartcard
#define PIN_ISO7816_RSTMC       {1 << 7, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}
/// Pins used for connect the smartcard
#define PINS_ISO7816            PIN_USART0_TXD, PIN_USART0_SCK, PIN_ISO7816_RSTMC
//------------------------------------------------------------------------------

#endif //#ifndef BOARD_H


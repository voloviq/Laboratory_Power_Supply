EESchema Schematic File Version 2  date śro, 19 sty 2011, 18:23:39
LIBS:Atmel_Arm
LIBS:74xx-us
LIBS:battery
LIBS:crystal
LIBS:display-kingbright
LIBS:fuse
LIBS:jumper
LIBS:resistor
LIBS:lpc2138
LIBS:74xx
LIBS:adc-dac
LIBS:analog_switches
LIBS:audio
LIBS:brooktre
LIBS:cmos4000
LIBS:cmos_ieee
LIBS:conn
LIBS:contrib
LIBS:cypress
LIBS:device
LIBS:digital-audio
LIBS:Discrete_Switches
LIBS:display
LIBS:dsp
LIBS:elec-unifil
LIBS:gennum
LIBS:graphic
LIBS:hc11
LIBS:intel
LIBS:interface
LIBS:linear
LIBS:MacroBloc
LIBS:memory
LIBS:microchip
LIBS:microchip1
LIBS:microcontrollers
LIBS:motorola
LIBS:Nxp_uC
LIBS:opto
LIBS:philips
LIBS:power
LIBS:pspice
LIBS:regul
LIBS:siliconi
LIBS:special
LIBS:st_uC
LIBS:SymbolsSimilarEN60617+oldDIN617
LIBS:texas
LIBS:transistors
LIBS:ttl_ieee
LIBS:valves
LIBS:video
LIBS:xilinx
LIBS:Pcb_Connectors
LIBS:Symbols
LIBS:Lcd_Connector
LIBS:TS_Chip
LIBS:Lab_Supplier-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
Sheet 2 10
Title "Laboratory supply - nonvolatile memory section"
Date "19 jan 2011"
Rev "V4_0"
Comp "Volovique"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	7850 4200 7850 4300
Wire Bus Line
	4500 4900 2350 4900
Wire Bus Line
	4850 4500 4700 4500
Wire Bus Line
	4850 3400 4700 3400
Wire Bus Line
	4850 3100 4700 3100
Wire Wire Line
	5550 4200 5550 4300
Wire Wire Line
	5650 3400 5472 3402
Wire Wire Line
	5650 3100 5430 3100
Wire Wire Line
	7650 4200 7650 3700
Wire Wire Line
	7650 3700 7650 3400
Wire Wire Line
	7650 3400 7150 3400
Wire Wire Line
	7150 3550 7450 3550
Wire Wire Line
	7450 3550 7450 3800
Wire Wire Line
	7150 3250 7850 3250
Wire Wire Line
	7850 3250 7850 3550
Wire Wire Line
	5550 3550 5550 3700
Wire Wire Line
	5398 3250 5650 3250
Wire Wire Line
	5362 3550 5550 3550
Wire Wire Line
	5550 3550 5650 3550
Connection ~ 5550 3550
Wire Wire Line
	7150 3100 8450 3100
Wire Wire Line
	8450 3100 8450 4500
Wire Wire Line
	8450 4500 5400 4500
Wire Bus Line
	4850 3250 4700 3250
Wire Bus Line
	4850 3550 4700 3550
Wire Bus Line
	4600 4800 4600 4600
Wire Bus Line
	4600 4600 4600 3650
Wire Bus Line
	4600 3650 4600 3500
Wire Bus Line
	4600 3500 4600 3350
Wire Bus Line
	4600 3350 4600 3200
Wire Wire Line
	7850 3800 7850 3700
Wire Wire Line
	7850 3700 7650 3700
Connection ~ 7650 3700
$Comp
L GND #PWR?
U 1 1 4D34BCBD
P 7850 4300
F 0 "#PWR?" H 7850 4400 30  0001 C CNN
F 1 "GND" H 7850 4230 30  0001 C CNN
	1    7850 4300
	1    0    0    -1  
$EndComp
$Comp
L C C?
U 1 1 4D34BC84
P 7850 4000
F 0 "C?" H 7600 4000 60  0000 L CNN
F 1 "100nF/25%" H 7300 4100 60  0000 L CNN
	1    7850 4000
	-1   0    0    1   
$EndComp
Entry Bus Bus
	4600 4600 4700 4500
Text GLabel 5362 3550 0    39   Input ~ 8
SPI_OO_3V3_C0
$Comp
L +3.3V #PWR?
U 1 1 4D31D451
P 5550 4350
F 0 "#PWR?" H 5550 4310 30  0001 C CNN
F 1 "+3.3V" V 5600 4450 30  0000 C CNN
	1    5550 4350
	0    1    1    0   
$EndComp
Text GLabel 5400 4500 0    39   Input ~ 8
SPI_IF_3V3_MISO
Text GLabel 5472 3402 0    39   Input ~ 8
JTAG_OO_3V3_NRST
Text GLabel 5398 3250 0    39   Input ~ 8
SPI_OO_3V3_CLK
Text GLabel 5430 3100 0    39   Input ~ 8
SPI_OO_3V3_MOSI
Entry Bus Bus
	4600 3500 4700 3400
$Comp
L R R?
U 1 1 4D31D443
P 5550 3950
F 0 "R?" H 5750 4000 60  0000 C CNN
F 1 "10k/5%" H 5800 3900 60  0000 C CNN
	1    5550 3950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 4D31D436
P 7850 3550
F 0 "#PWR?" H 7850 3650 30  0001 C CNN
F 1 "GND" H 7850 3480 30  0001 C CNN
	1    7850 3550
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 4D31D42B
P 7650 4250
F 0 "#PWR?" H 7650 4210 30  0001 C CNN
F 1 "+3.3V" V 7700 4100 30  0000 C CNN
	1    7650 4250
	0    1    1    0   
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 4D31D41D
P 7450 3850
F 0 "#PWR?" H 7450 3810 30  0001 C CNN
F 1 "+3.3V" V 7500 3700 30  0000 C CNN
	1    7450 3850
	0    1    1    0   
$EndComp
$Comp
L SIGNAL_INOUT SINOUT?
U 1 1 4D31D390
P 2150 4900
F 0 "SINOUT?" H 2150 4800 60  0001 C CNN
F 1 "SPI_Interface" H 2150 5000 60  0000 C CNN
	1    2150 4900
	1    0    0    -1  
$EndComp
Entry Bus Bus
	4500 4900 4600 4800
Entry Bus Bus
	4600 3650 4700 3550
Entry Bus Bus
	4600 3350 4700 3250
Entry Bus Bus
	4600 3200 4700 3100
$Comp
L AT45DB161D U?
U 1 1 4D31D324
P 6400 3300
F 0 "U?" H 6400 3700 60  0000 C CNN
F 1 "AT45DB161D" H 6400 3800 60  0000 C CNN
	1    6400 3300
	1    0    0    -1  
$EndComp
$EndSCHEMATC

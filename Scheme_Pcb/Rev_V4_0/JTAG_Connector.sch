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
Sheet 4 10
Title "Laboratory supply - JTAG connector"
Date "19 jan 2011"
Rev "V4_0"
Comp "Volovique"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	1300 4700 1550 4700
Wire Wire Line
	1550 4700 1550 4500
Wire Bus Line
	4300 6100 1300 6100
Wire Bus Line
	4500 3550 4600 3550
Wire Bus Line
	4500 3750 4600 3750
Wire Wire Line
	5550 4100 5550 4000
Connection ~ 5650 4000
Wire Wire Line
	5550 4000 5650 4000
Wire Wire Line
	5750 3650 5145 3650
Wire Wire Line
	5750 3450 5143 3450
Wire Wire Line
	5120 3750 5750 3750
Wire Wire Line
	5750 3850 5180 3850
Wire Bus Line
	4400 3550 4400 3650
Wire Bus Line
	4400 3650 4400 3750
Wire Bus Line
	4400 3750 4400 3850
Wire Bus Line
	4400 3850 4400 3950
Wire Bus Line
	4400 3950 4400 6000
Wire Bus Line
	4600 3850 4500 3850
Wire Wire Line
	5175 3550 5750 3550
Wire Wire Line
	5750 3950 5650 3950
Wire Wire Line
	5650 3950 5650 4000
Wire Wire Line
	5650 4000 5650 4050
Wire Wire Line
	5650 4050 5750 4050
Wire Wire Line
	5750 3350 5650 3350
Wire Wire Line
	5650 3350 5650 3250
Wire Bus Line
	4500 3650 4600 3650
Wire Bus Line
	4500 3450 4600 3450
Wire Wire Line
	1300 5350 1550 5350
Wire Wire Line
	1550 5350 1550 5550
$Comp
L +3.3V #PWR?
U 1 1 4D330E89
P 1550 4450
F 0 "#PWR?" H 1550 4410 30  0001 C CNN
F 1 "+3.3V" V 1600 4350 30  0000 C CNN
	1    1550 4450
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 4D330E7B
P 1550 5550
F 0 "#PWR?" H 1550 5650 30  0001 C CNN
F 1 "GND" H 1550 5480 30  0001 C CNN
	1    1550 5550
	1    0    0    -1  
$EndComp
$Comp
L SIGNAL_IN SIN?
U 1 1 4D330E4C
P 1100 4700
F 0 "SIN?" H 1100 4600 60  0001 C CNN
F 1 "+3.3V" H 1100 4700 60  0000 C CNN
	1    1100 4700
	1    0    0    -1  
$EndComp
$Comp
L SIGNAL_IN SIN?
U 1 1 4D330E46
P 1100 5350
F 0 "SIN?" H 1100 5250 60  0001 C CNN
F 1 "GND" H 1150 5350 60  0000 C CNN
	1    1100 5350
	1    0    0    -1  
$EndComp
$Comp
L SIGNAL_INOUT SINOUT?
U 1 1 4D330E22
P 1100 6100
F 0 "SINOUT?" H 1100 6000 60  0001 C CNN
F 1 "JTAG_Interface" H 1100 6000 60  0000 C CNN
	1    1100 6100
	1    0    0    -1  
$EndComp
Entry Bus Bus
	4300 6100 4400 6000
$Comp
L +3.3V #PWR?
U 1 1 4D330DAC
P 5650 3200
F 0 "#PWR?" H 5650 3160 30  0001 C CNN
F 1 "+3.3V" V 5700 3050 30  0000 C CNN
	1    5650 3200
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 4D330DA5
P 5550 4100
F 0 "#PWR?" H 5550 4200 30  0001 C CNN
F 1 "GND" H 5550 4030 30  0001 C CNN
	1    5550 4100
	1    0    0    -1  
$EndComp
Text GLabel 5143 3450 0    39   Input ~ 0
JTAG_IF_3V3_TCK
Text GLabel 5175 3550 0    39   Input ~ 0
JTAG_OO_3V3_TDO
Text GLabel 5145 3650 0    39   Input ~ 0
JTAG_IF_3V3_TMS
Text GLabel 5120 3750 0    39   Input ~ 0
JTAG_IF_3V3_TDI
Text GLabel 5180 3850 0    39   Input ~ 0
JTAG_IF_3V3_NRST
Entry Bus Bus
	4400 3950 4500 3850
Entry Bus Bus
	4400 3850 4500 3750
Entry Bus Bus
	4400 3750 4500 3650
Entry Bus Bus
	4400 3650 4500 3550
Entry Bus Bus
	4400 3550 4500 3450
$Comp
L JTAG_CONNECTOR Jp?
U 1 1 4D330C71
P 6000 3650
F 0 "Jp?" H 6650 3750 60  0000 C CNN
F 1 "JTAG_CONNECTOR" H 6600 3600 60  0000 C CNN
	1    6000 3650
	1    0    0    -1  
$EndComp
$EndSCHEMATC

EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Central Harmonic Content PCB"
Date "2021-10-06"
Rev "v01"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 "Author: Savannah Hearn"
$EndDescr
$Comp
L Device:LED D1
U 1 1 615FEF7B
P 2900 3900
F 0 "D1" H 2893 4117 50  0000 C CNN
F 1 "POW" H 2893 4026 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 2900 3900 50  0001 C CNN
F 3 "~" H 2900 3900 50  0001 C CNN
	1    2900 3900
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J1
U 1 1 6160AD0C
P 10250 3900
F 0 "J1" H 10300 4417 50  0000 C CNN
F 1 "POWER HEADER" H 10300 4326 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x08_P2.54mm_Vertical" H 10250 3900 50  0001 C CNN
F 3 "~" H 10250 3900 50  0001 C CNN
	1    10250 3900
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 6161C083
P 7650 2800
F 0 "#PWR0101" H 7650 2550 50  0001 C CNN
F 1 "GND" H 7655 2627 50  0000 C CNN
F 2 "" H 7650 2800 50  0001 C CNN
F 3 "" H 7650 2800 50  0001 C CNN
	1    7650 2800
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR0104
U 1 1 6162992E
P 7900 3400
F 0 "#PWR0104" H 7900 3500 50  0001 C CNN
F 1 "-12V" H 7915 3573 50  0000 C CNN
F 2 "" H 7900 3400 50  0001 C CNN
F 3 "" H 7900 3400 50  0001 C CNN
	1    7900 3400
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0105
U 1 1 61629934
P 8500 3200
F 0 "#PWR0105" H 8500 3050 50  0001 C CNN
F 1 "+5V" H 8515 3373 50  0000 C CNN
F 2 "" H 8500 3200 50  0001 C CNN
F 3 "" H 8500 3200 50  0001 C CNN
	1    8500 3200
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0106
U 1 1 6162993A
P 9050 3000
F 0 "#PWR0106" H 9050 2850 50  0001 C CNN
F 1 "+12V" H 9065 3173 50  0000 C CNN
F 2 "" H 9050 3000 50  0001 C CNN
F 3 "" H 9050 3000 50  0001 C CNN
	1    9050 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	10450 4200 10500 4200
Wire Wire Line
	10500 4200 10500 3400
Wire Wire Line
	9950 4200 9500 4200
Wire Wire Line
	9500 4200 9500 3400
$Comp
L power:GND #PWR0107
U 1 1 6162C97B
P 10800 4250
F 0 "#PWR0107" H 10800 4000 50  0001 C CNN
F 1 "GND" H 10805 4077 50  0000 C CNN
F 2 "" H 10800 4250 50  0001 C CNN
F 3 "" H 10800 4250 50  0001 C CNN
	1    10800 4250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 6162CF33
P 9600 4350
F 0 "#PWR0108" H 9600 4100 50  0001 C CNN
F 1 "GND" H 9605 4177 50  0000 C CNN
F 2 "" H 9600 4350 50  0001 C CNN
F 3 "" H 9600 4350 50  0001 C CNN
	1    9600 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	10450 4100 10800 4100
Wire Wire Line
	10800 4100 10800 4250
Wire Wire Line
	10450 4000 10800 4000
Wire Wire Line
	10800 4000 10800 4100
Connection ~ 10800 4100
Wire Wire Line
	10450 3900 10800 3900
Wire Wire Line
	10800 3900 10800 4000
Connection ~ 10800 4000
Wire Wire Line
	9950 4100 9600 4100
Wire Wire Line
	9950 4000 9600 4000
Wire Wire Line
	9600 4000 9600 4100
Wire Wire Line
	9950 3900 9600 3900
Wire Wire Line
	9600 3900 9600 4000
Connection ~ 9600 4000
Wire Wire Line
	10450 3800 10900 3800
Wire Wire Line
	9950 3800 9900 3800
Wire Wire Line
	10450 3700 10700 3700
Wire Wire Line
	9950 3700 9700 3700
$Comp
L teensy:Teensy4.1 U1
U 1 1 615DD624
P 5052 5748
F 0 "U1" H 5052 8313 50  0000 C CNN
F 1 "Teensy4.1" H 5052 8222 50  0000 C CNN
F 2 "" H 4652 6148 50  0001 C CNN
F 3 "" H 4652 6148 50  0001 C CNN
	1    5052 5748
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 616B52F2
P 6350 7050
F 0 "#PWR0109" H 6350 6800 50  0001 C CNN
F 1 "GND" H 6355 6877 50  0000 C CNN
F 2 "" H 6350 7050 50  0001 C CNN
F 3 "" H 6350 7050 50  0001 C CNN
	1    6350 7050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 616B5948
P 3750 7300
F 0 "#PWR0110" H 3750 7050 50  0001 C CNN
F 1 "GND" H 3755 7127 50  0000 C CNN
F 2 "" H 3750 7300 50  0001 C CNN
F 3 "" H 3750 7300 50  0001 C CNN
	1    3750 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 7050 5050 7300
Wire Wire Line
	5050 7300 3750 7300
Wire Wire Line
	6150 6250 6350 6250
Wire Wire Line
	6350 6250 6350 7050
Wire Wire Line
	3950 6750 3750 6750
Wire Wire Line
	3750 6750 3750 7300
Connection ~ 3750 7300
Wire Wire Line
	6150 5000 6350 5000
Wire Wire Line
	6350 5000 6350 6250
Connection ~ 6350 6250
Wire Wire Line
	6150 3700 6350 3700
Wire Wire Line
	6350 3700 6350 5000
Connection ~ 6350 5000
Wire Wire Line
	3950 3600 3750 3600
Wire Wire Line
	3750 3600 3750 5500
Connection ~ 3750 6750
$Comp
L test-lib:BA7810CP-E2 U2
U 1 1 61610C90
P 9900 5800
F 0 "U2" H 9900 6155 50  0000 C CNN
F 1 "BA7810CP-E2" H 9900 6064 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 9900 5973 50  0000 C CNN
F 3 "https://fscdn.rohm.com/en/products/databook/datasheet/ic/power/linear_regulator/ba78_series-e.pdf" H 9900 5800 50  0001 C CNN
	1    9900 5800
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0111
U 1 1 61611891
P 8950 5800
F 0 "#PWR0111" H 8950 5650 50  0001 C CNN
F 1 "+12V" H 8965 5973 50  0000 C CNN
F 2 "" H 8950 5800 50  0001 C CNN
F 3 "" H 8950 5800 50  0001 C CNN
	1    8950 5800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0112
U 1 1 616148AD
P 9900 6250
F 0 "#PWR0112" H 9900 6000 50  0001 C CNN
F 1 "GND" H 9905 6077 50  0000 C CNN
F 2 "" H 9900 6250 50  0001 C CNN
F 3 "" H 9900 6250 50  0001 C CNN
	1    9900 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 6150 9900 6250
$Comp
L power:+10V #PWR0113
U 1 1 61617614
P 10800 5800
F 0 "#PWR0113" H 10800 5650 50  0001 C CNN
F 1 "+10V" H 10815 5973 50  0000 C CNN
F 2 "" H 10800 5800 50  0001 C CNN
F 3 "" H 10800 5800 50  0001 C CNN
	1    10800 5800
	1    0    0    -1  
$EndComp
Wire Wire Line
	10450 5800 10800 5800
Wire Wire Line
	8950 5800 9350 5800
$Comp
L power:+5V #PWR0114
U 1 1 61627E4C
P 6250 3600
F 0 "#PWR0114" H 6250 3450 50  0001 C CNN
F 1 "+5V" H 6265 3773 50  0000 C CNN
F 2 "" H 6250 3600 50  0001 C CNN
F 3 "" H 6250 3600 50  0001 C CNN
	1    6250 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6150 3600 6250 3600
Text GLabel 3650 4800 0    50   Input ~ 0
MOSI0
Text GLabel 3650 4900 0    50   Input ~ 0
MISO0
Text GLabel 6450 4900 2    50   Input ~ 0
SCK0
Text GLabel 7950 4850 0    50   Input ~ 0
MOSI0
Text GLabel 7950 4950 0    50   Input ~ 0
MISO0
Text GLabel 7950 5050 0    50   Input ~ 0
SCK0
Text GLabel 3650 4700 0    50   Input ~ 0
CS0
Text GLabel 7950 4750 0    50   Input ~ 0
CS0
Wire Wire Line
	8050 4750 7950 4750
Wire Wire Line
	7950 4850 8050 4850
Wire Wire Line
	7950 4950 8050 4950
Wire Wire Line
	7950 5050 8050 5050
Text GLabel 6450 4700 2    50   Input ~ 0
DA2
Text GLabel 6450 4600 2    50   Input ~ 0
DA3
Text GLabel 6450 4500 2    50   Input ~ 0
DA4
Text GLabel 6450 4400 2    50   Input ~ 0
DB1
Text GLabel 6450 4300 2    50   Input ~ 0
DB2
Text GLabel 6450 4200 2    50   Input ~ 0
DB3
Text GLabel 6450 4100 2    50   Input ~ 0
DB4
Text GLabel 6450 4000 2    50   Input ~ 0
DC1
Text GLabel 6450 3900 2    50   Input ~ 0
DC2
Text GLabel 3650 5100 0    50   Input ~ 0
DC3
Text GLabel 3650 5200 0    50   Input ~ 0
DC4
Text GLabel 6450 5400 2    50   Input ~ 0
DD1
Text GLabel 6450 5300 2    50   Input ~ 0
DD2
Text GLabel 6450 5200 2    50   Input ~ 0
DD3
Text GLabel 6450 5100 2    50   Input ~ 0
DD4
Text GLabel 9200 4850 0    50   Input ~ 0
MOSI0
Text GLabel 9200 4950 0    50   Input ~ 0
MISO0
Text GLabel 9200 5050 0    50   Input ~ 0
SCK0
$Comp
L Connector_Generic:Conn_01x04 J4
U 1 1 61D2A9C1
P 9500 4850
F 0 "J4" H 9580 4842 50  0000 L CNN
F 1 "SPI Header 1" H 9580 4751 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 9500 4850 50  0001 C CNN
F 3 "~" H 9500 4850 50  0001 C CNN
	1    9500 4850
	1    0    0    -1  
$EndComp
Text GLabel 9200 4750 0    50   Input ~ 0
CS0
Wire Wire Line
	9300 4750 9200 4750
Wire Wire Line
	9200 4850 9300 4850
Wire Wire Line
	9200 4950 9300 4950
Wire Wire Line
	9200 5050 9300 5050
Text GLabel 3650 5300 0    50   Input ~ 0
MOSI1
Text GLabel 3650 3800 0    50   Input ~ 0
MISO1
Text GLabel 3650 5400 0    50   Input ~ 0
SCK1
Text GLabel 3650 3700 0    50   Input ~ 0
CS1
Wire Wire Line
	3650 3700 3950 3700
Wire Wire Line
	3950 3800 3650 3800
Wire Wire Line
	6150 4900 6450 4900
Wire Wire Line
	3950 4900 3650 4900
Wire Wire Line
	3950 4800 3650 4800
Wire Wire Line
	3950 4700 3650 4700
Text GLabel 6450 4800 2    50   Input ~ 0
DA1
Wire Wire Line
	3950 5100 3650 5100
Wire Wire Line
	3950 5200 3650 5200
Wire Wire Line
	6150 5100 6450 5100
Wire Wire Line
	6150 5200 6450 5200
Wire Wire Line
	6150 5300 6450 5300
Wire Wire Line
	6150 5400 6450 5400
Wire Wire Line
	6150 4800 6450 4800
Wire Wire Line
	6150 4700 6450 4700
Wire Wire Line
	6150 4600 6450 4600
Wire Wire Line
	6150 4500 6450 4500
Wire Wire Line
	6150 4400 6450 4400
Wire Wire Line
	6150 4300 6450 4300
Wire Wire Line
	6150 4200 6450 4200
Wire Wire Line
	6150 4100 6450 4100
Wire Wire Line
	6150 4000 6450 4000
Wire Wire Line
	6150 3900 6450 3900
Wire Wire Line
	3950 5300 3650 5300
Wire Wire Line
	3950 5400 3650 5400
Text GLabel 3650 4400 0    50   Input ~ 0
MIDIREC
Text GLabel 3650 4500 0    50   Input ~ 0
MIDITRANS
Wire Wire Line
	3950 4400 3650 4400
Wire Wire Line
	3950 4500 3650 4500
$Comp
L Connector_Generic:Conn_01x03 J5
U 1 1 616A2375
P 2950 6100
F 0 "J5" H 3030 6142 50  0000 L CNN
F 1 "MIDI IN" H 3030 6051 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 2950 6100 50  0001 C CNN
F 3 "~" H 2950 6100 50  0001 C CNN
	1    2950 6100
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J6
U 1 1 616A3061
P 2950 6700
F 0 "J6" H 3030 6742 50  0000 L CNN
F 1 "MIDI OUT" H 3030 6651 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x03_P2.54mm_Vertical" H 2950 6700 50  0001 C CNN
F 3 "~" H 2950 6700 50  0001 C CNN
	1    2950 6700
	1    0    0    -1  
$EndComp
Text GLabel 2600 6000 0    50   Input ~ 0
MIDREC
Text GLabel 2600 6600 0    50   Input ~ 0
MIDITRANS
Wire Wire Line
	2750 6000 2600 6000
Wire Wire Line
	2750 6600 2600 6600
$Comp
L power:+5V #PWR0115
U 1 1 616DBE5A
P 2000 5850
F 0 "#PWR0115" H 2000 5700 50  0001 C CNN
F 1 "+5V" H 2015 6023 50  0000 C CNN
F 2 "" H 2000 5850 50  0001 C CNN
F 3 "" H 2000 5850 50  0001 C CNN
	1    2000 5850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0116
U 1 1 616DCBBE
P 2650 6950
F 0 "#PWR0116" H 2650 6700 50  0001 C CNN
F 1 "GND" H 2655 6777 50  0000 C CNN
F 2 "" H 2650 6950 50  0001 C CNN
F 3 "" H 2650 6950 50  0001 C CNN
	1    2650 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 6800 2650 6800
Wire Wire Line
	2650 6800 2650 6950
Wire Wire Line
	2750 6200 2650 6200
Wire Wire Line
	2650 6200 2650 6800
Connection ~ 2650 6800
Wire Wire Line
	2750 6700 2000 6700
Wire Wire Line
	2000 6700 2000 6100
Wire Wire Line
	2750 6100 2000 6100
Connection ~ 2000 6100
Wire Wire Line
	2000 6100 2000 5850
$Comp
L Device:R_US R35
U 1 1 6173692B
P 3250 3900
F 0 "R35" V 3045 3900 50  0000 C CNN
F 1 "?" V 3136 3900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3290 3890 50  0001 C CNN
F 3 "~" H 3250 3900 50  0001 C CNN
	1    3250 3900
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R36
U 1 1 6173869F
P 2500 4000
F 0 "R36" V 2295 4000 50  0000 C CNN
F 1 "?" V 2386 4000 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2540 3990 50  0001 C CNN
F 3 "~" H 2500 4000 50  0001 C CNN
	1    2500 4000
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R37
U 1 1 6173951E
P 3250 4100
F 0 "R37" V 3045 4100 50  0000 C CNN
F 1 "?" V 3136 4100 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 3290 4090 50  0001 C CNN
F 3 "~" H 3250 4100 50  0001 C CNN
	1    3250 4100
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R38
U 1 1 6173A88C
P 2500 4200
F 0 "R38" V 2295 4200 50  0000 C CNN
F 1 "?" V 2386 4200 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2540 4190 50  0001 C CNN
F 3 "~" H 2500 4200 50  0001 C CNN
	1    2500 4200
	0    1    1    0   
$EndComp
Wire Wire Line
	2300 4000 2350 4000
Wire Wire Line
	2350 4200 2300 4200
Wire Wire Line
	3100 3900 3050 3900
Wire Wire Line
	3100 4100 3050 4100
Wire Wire Line
	3950 3900 3400 3900
Wire Wire Line
	3950 4000 2650 4000
Wire Wire Line
	3950 4100 3400 4100
Wire Wire Line
	3950 4200 2650 4200
Wire Wire Line
	2000 5500 3750 5500
Connection ~ 3750 5500
Wire Wire Line
	3750 5500 3750 6750
Wire Wire Line
	2750 4100 2000 4100
Wire Wire Line
	2750 3900 2000 3900
$Comp
L Device:Thermistor_US TH2
U 1 1 619360B6
P 8900 3200
F 0 "TH2" V 8660 3200 50  0000 C CNN
F 1 "Thermistor_US" V 8751 3200 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" H 8900 3200 50  0001 C CNN
F 3 "~" H 8900 3200 50  0001 C CNN
	1    8900 3200
	0    1    1    0   
$EndComp
Wire Wire Line
	8750 3200 8650 3200
Wire Wire Line
	9700 3200 9700 3700
Wire Wire Line
	9500 3400 10500 3400
$Comp
L Device:Thermistor_US TH3
U 1 1 619DA6B6
P 8300 3400
F 0 "TH3" V 8060 3400 50  0000 C CNN
F 1 "Thermistor_US" V 8151 3400 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" H 8300 3400 50  0001 C CNN
F 3 "~" H 8300 3400 50  0001 C CNN
	1    8300 3400
	0    1    1    0   
$EndComp
$Comp
L Device:Thermistor_US TH1
U 1 1 619DC3E4
P 9450 3000
F 0 "TH1" V 9210 3000 50  0000 C CNN
F 1 "Thermistor_US" V 9301 3000 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" H 9450 3000 50  0001 C CNN
F 3 "~" H 9450 3000 50  0001 C CNN
	1    9450 3000
	0    1    1    0   
$EndComp
Wire Wire Line
	9050 3000 9250 3000
Wire Wire Line
	9900 3000 9600 3000
Wire Wire Line
	9900 3000 9900 3800
Wire Wire Line
	10700 3200 9700 3200
Wire Wire Line
	10700 3200 10700 3700
Connection ~ 9700 3200
Wire Wire Line
	10900 3000 9900 3000
Wire Wire Line
	10900 3000 10900 3800
Connection ~ 9900 3000
Wire Wire Line
	7900 3400 8150 3400
$Comp
L Device:R_US R34
U 1 1 61BEDF6F
P 9250 3650
F 0 "R34" V 9045 3650 50  0000 C CNN
F 1 "?" V 9136 3650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 9290 3640 50  0001 C CNN
F 3 "~" H 9250 3650 50  0001 C CNN
	1    9250 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 3800 9250 3850
$Comp
L Device:LED D5
U 1 1 61C7A0EA
P 8650 4000
F 0 "D5" H 8643 4217 50  0000 C CNN
F 1 "5V_POW" H 8643 4126 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 8650 4000 50  0001 C CNN
F 3 "~" H 8650 4000 50  0001 C CNN
	1    8650 4000
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_US R33
U 1 1 61C7A0F0
P 8650 3650
F 0 "R33" V 8445 3650 50  0000 C CNN
F 1 "?" V 8536 3650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 8690 3640 50  0001 C CNN
F 3 "~" H 8650 3650 50  0001 C CNN
	1    8650 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 3800 8650 3850
Wire Wire Line
	9050 3200 9700 3200
Connection ~ 9500 3400
Wire Wire Line
	8450 3400 9500 3400
Wire Wire Line
	9600 4100 9600 4300
Connection ~ 9600 4100
Wire Wire Line
	9250 4150 9250 4300
Wire Wire Line
	9250 4300 9600 4300
Connection ~ 9600 4300
Wire Wire Line
	9600 4300 9600 4350
Wire Wire Line
	8650 4150 8650 4300
Wire Wire Line
	8650 4300 9250 4300
Connection ~ 9250 4300
Wire Wire Line
	8650 3500 8650 3200
Connection ~ 8650 3200
Wire Wire Line
	8650 3200 8500 3200
Wire Wire Line
	9250 3500 9250 3000
Connection ~ 9250 3000
Wire Wire Line
	9250 3000 9300 3000
$Comp
L Device:LED D20
U 1 1 6224F6A1
P 9250 4000
F 0 "D20" H 9243 4217 50  0000 C CNN
F 1 "12V_POW" H 9243 4126 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 9250 4000 50  0001 C CNN
F 3 "~" H 9250 4000 50  0001 C CNN
	1    9250 4000
	0    -1   -1   0   
$EndComp
$Comp
L Device:LED D21
U 1 1 622BF7F7
P 2900 4100
F 0 "D21" H 2893 4317 50  0000 C CNN
F 1 "POW" H 2893 4226 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 2900 4100 50  0001 C CNN
F 3 "~" H 2900 4100 50  0001 C CNN
	1    2900 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D22
U 1 1 622C0785
P 2150 4200
F 0 "D22" H 2143 4417 50  0000 C CNN
F 1 "POW" H 2143 4326 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 2150 4200 50  0001 C CNN
F 3 "~" H 2150 4200 50  0001 C CNN
	1    2150 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:LED D19
U 1 1 622DBF78
P 2150 4000
F 0 "D19" H 2143 4217 50  0000 C CNN
F 1 "POW" H 2143 4126 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 2150 4000 50  0001 C CNN
F 3 "~" H 2150 4000 50  0001 C CNN
	1    2150 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2000 4200 2000 5500
Wire Wire Line
	2000 3900 2000 4000
Wire Wire Line
	2000 4100 2000 4200
Connection ~ 2000 4200
Wire Wire Line
	2000 4100 2000 4000
Connection ~ 2000 4100
Connection ~ 2000 4000
$Comp
L power:+3.3V #PWR?
U 1 1 623E2584
P 8300 800
F 0 "#PWR?" H 8300 650 50  0001 C CNN
F 1 "+3.3V" H 8315 973 50  0000 C CNN
F 2 "" H 8300 800 50  0001 C CNN
F 3 "" H 8300 800 50  0001 C CNN
	1    8300 800 
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J?
U 1 1 626A8EDE
P 8250 4950
F 0 "J?" H 8330 4992 50  0000 L CNN
F 1 "Conn_01x05" H 8330 4901 50  0000 L CNN
F 2 "" H 8250 4950 50  0001 C CNN
F 3 "~" H 8250 4950 50  0001 C CNN
	1    8250 4950
	1    0    0    -1  
$EndComp
$Comp
L power:+10V #PWR?
U 1 1 626A98C8
P 7500 5150
F 0 "#PWR?" H 7500 5000 50  0001 C CNN
F 1 "+10V" H 7515 5323 50  0000 C CNN
F 2 "" H 7500 5150 50  0001 C CNN
F 3 "" H 7500 5150 50  0001 C CNN
	1    7500 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7500 5150 8050 5150
$Comp
L Diode:BZT52Bxx D?
U 1 1 62774536
P 4600 2600
F 0 "D?" H 4600 2817 50  0000 C CNN
F 1 "3.3v Zener" H 4600 2726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 4600 2425 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds18010.pdf" H 4600 2600 50  0001 C CNN
	1    4600 2600
	0    -1   1    0   
$EndComp
$Comp
L Connector_Generic:Conn_02x16_Top_Bottom J?
U 1 1 6188DECB
P 7150 1550
F 0 "J?" H 7200 2467 50  0000 C CNN
F 1 "Conn_02x16_Top_Bottom" H 7200 2376 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_2x16_P2.54mm_Vertical" H 7150 1550 50  0001 C CNN
F 3 "~" H 7150 1550 50  0001 C CNN
	1    7150 1550
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR?
U 1 1 618BFAC2
P 7800 800
F 0 "#PWR?" H 7800 650 50  0001 C CNN
F 1 "+12V" H 7815 973 50  0000 C CNN
F 2 "" H 7800 800 50  0001 C CNN
F 3 "" H 7800 800 50  0001 C CNN
	1    7800 800 
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 618C6CC3
P 8050 800
F 0 "#PWR?" H 8050 650 50  0001 C CNN
F 1 "+5V" H 8065 973 50  0000 C CNN
F 2 "" H 8050 800 50  0001 C CNN
F 3 "" H 8050 800 50  0001 C CNN
	1    8050 800 
	1    0    0    -1  
$EndComp
Text GLabel 4450 1050 0    50   Input ~ 0
DA3
Text GLabel 4450 1250 0    50   Input ~ 0
DB1
Text GLabel 4450 1450 0    50   Input ~ 0
DB3
Text GLabel 4450 1650 0    50   Input ~ 0
DC1
Text GLabel 4450 1850 0    50   Input ~ 0
DC3
Text GLabel 4450 2050 0    50   Input ~ 0
DD1
Text GLabel 4450 2250 0    50   Input ~ 0
DD3
Text GLabel 4450 950  0    50   Input ~ 0
DA2
Text GLabel 4450 1150 0    50   Input ~ 0
DA4
Text GLabel 4450 1350 0    50   Input ~ 0
DB2
Text GLabel 4450 1550 0    50   Input ~ 0
DB4
Text GLabel 4450 1950 0    50   Input ~ 0
DC4
Text GLabel 4450 2150 0    50   Input ~ 0
DD2
Text GLabel 4450 2350 0    50   Input ~ 0
DD4
Text GLabel 4450 1750 0    50   Input ~ 0
DC2
Text GLabel 4450 850  0    50   Input ~ 0
DA1
Wire Wire Line
	6950 850  6850 850 
Wire Wire Line
	6950 950  6700 950 
Wire Wire Line
	6950 1050 6550 1050
Wire Wire Line
	6950 1150 6400 1150
Wire Wire Line
	4450 1250 6250 1250
Wire Wire Line
	6950 1350 6100 1350
Wire Wire Line
	6950 1450 5950 1450
Wire Wire Line
	4450 1550 5800 1550
Wire Wire Line
	6950 1650 5650 1650
Wire Wire Line
	6950 1750 5500 1750
Wire Wire Line
	6950 1850 5350 1850
Wire Wire Line
	4450 1950 5200 1950
Wire Wire Line
	6950 2050 5050 2050
Wire Wire Line
	4450 2150 4900 2150
Wire Wire Line
	6950 2250 4750 2250
Wire Wire Line
	4450 2350 4600 2350
Wire Wire Line
	4600 2450 4600 2350
Connection ~ 4600 2350
Wire Wire Line
	7450 2350 7650 2350
Wire Wire Line
	7450 2250 7650 2250
Wire Wire Line
	7650 2250 7650 2350
Connection ~ 7650 2350
Wire Wire Line
	7450 2150 7650 2150
Wire Wire Line
	7650 2150 7650 2250
Connection ~ 7650 2250
Wire Wire Line
	7450 2050 7650 2050
Wire Wire Line
	7650 2050 7650 2150
Connection ~ 7650 2150
Wire Wire Line
	7450 850  7800 850 
Wire Wire Line
	7800 850  7800 800 
Wire Wire Line
	7450 950  7800 950 
Wire Wire Line
	7800 950  7800 850 
Connection ~ 7800 850 
Wire Wire Line
	7450 1050 7800 1050
Wire Wire Line
	7800 1050 7800 950 
Connection ~ 7800 950 
Wire Wire Line
	7450 1150 7800 1150
Wire Wire Line
	7800 1150 7800 1050
Connection ~ 7800 1050
Wire Wire Line
	8050 1250 8050 800 
Wire Wire Line
	7450 1250 8050 1250
Wire Wire Line
	7450 1350 8050 1350
Wire Wire Line
	8050 1350 8050 1250
Connection ~ 8050 1250
Wire Wire Line
	7450 1450 8050 1450
Wire Wire Line
	8050 1450 8050 1350
Connection ~ 8050 1350
Wire Wire Line
	7450 1550 8050 1550
Wire Wire Line
	8050 1550 8050 1450
Connection ~ 8050 1450
Wire Wire Line
	7450 1650 8300 1650
Wire Wire Line
	8300 1650 8300 800 
Wire Wire Line
	7450 1750 8300 1750
Wire Wire Line
	8300 1750 8300 1650
Connection ~ 8300 1650
Wire Wire Line
	7450 1850 8300 1850
Wire Wire Line
	8300 1850 8300 1750
Connection ~ 8300 1750
Wire Wire Line
	7450 1950 8300 1950
Wire Wire Line
	8300 1950 8300 1850
Connection ~ 8300 1850
Wire Wire Line
	4600 2350 6950 2350
Wire Wire Line
	4750 2450 4750 2250
Connection ~ 4750 2250
Wire Wire Line
	4750 2250 4450 2250
Wire Wire Line
	4900 2450 4900 2150
Connection ~ 4900 2150
Wire Wire Line
	4900 2150 6950 2150
Wire Wire Line
	5050 2450 5050 2050
Connection ~ 5050 2050
Wire Wire Line
	5050 2050 4450 2050
Wire Wire Line
	5200 2450 5200 1950
Connection ~ 5200 1950
Wire Wire Line
	5200 1950 6950 1950
Wire Wire Line
	5350 2450 5350 1850
Connection ~ 5350 1850
Wire Wire Line
	5350 1850 4450 1850
Wire Wire Line
	5500 2450 5500 1750
Connection ~ 5500 1750
Wire Wire Line
	5500 1750 4450 1750
Wire Wire Line
	5650 2450 5650 1650
Connection ~ 5650 1650
Wire Wire Line
	5650 1650 4450 1650
Wire Wire Line
	5800 2450 5800 1550
Connection ~ 5800 1550
Wire Wire Line
	5800 1550 6950 1550
Wire Wire Line
	5950 2450 5950 1450
Connection ~ 5950 1450
Wire Wire Line
	5950 1450 4450 1450
Wire Wire Line
	6100 1350 6100 2450
Connection ~ 6100 1350
Wire Wire Line
	6100 1350 4450 1350
Wire Wire Line
	6250 2450 6250 1250
Connection ~ 6250 1250
Wire Wire Line
	6250 1250 6950 1250
Wire Wire Line
	6400 2450 6400 1150
Connection ~ 6400 1150
Wire Wire Line
	6400 1150 4450 1150
Wire Wire Line
	6550 2450 6550 1050
Connection ~ 6550 1050
Wire Wire Line
	6550 1050 4450 1050
Wire Wire Line
	6700 2450 6700 950 
Connection ~ 6700 950 
Wire Wire Line
	6700 950  4450 950 
Wire Wire Line
	6850 2450 6850 850 
Connection ~ 6850 850 
Wire Wire Line
	6850 850  4450 850 
Wire Wire Line
	7650 2350 7650 2750
$Comp
L Diode:BZT52Bxx D?
U 1 1 61CF6BC1
P 4750 2600
F 0 "D?" H 4750 2817 50  0000 C CNN
F 1 "3.3v Zener" H 4750 2726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 4750 2425 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds18010.pdf" H 4750 2600 50  0001 C CNN
	1    4750 2600
	0    -1   1    0   
$EndComp
$Comp
L Diode:BZT52Bxx D?
U 1 1 61D0436E
P 4900 2600
F 0 "D?" H 4900 2817 50  0000 C CNN
F 1 "3.3v Zener" H 4900 2726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 4900 2425 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds18010.pdf" H 4900 2600 50  0001 C CNN
	1    4900 2600
	0    -1   1    0   
$EndComp
$Comp
L Diode:BZT52Bxx D?
U 1 1 61D1EF4D
P 5050 2600
F 0 "D?" H 5050 2817 50  0000 C CNN
F 1 "3.3v Zener" H 5050 2726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 5050 2425 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds18010.pdf" H 5050 2600 50  0001 C CNN
	1    5050 2600
	0    -1   1    0   
$EndComp
$Comp
L Diode:BZT52Bxx D?
U 1 1 61D2C3F3
P 5200 2600
F 0 "D?" H 5200 2817 50  0000 C CNN
F 1 "3.3v Zener" H 5200 2726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 5200 2425 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds18010.pdf" H 5200 2600 50  0001 C CNN
	1    5200 2600
	0    -1   1    0   
$EndComp
$Comp
L Diode:BZT52Bxx D?
U 1 1 61D4721B
P 5350 2600
F 0 "D?" H 5350 2817 50  0000 C CNN
F 1 "3.3v Zener" H 5350 2726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 5350 2425 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds18010.pdf" H 5350 2600 50  0001 C CNN
	1    5350 2600
	0    -1   1    0   
$EndComp
$Comp
L Diode:BZT52Bxx D?
U 1 1 61D54A26
P 5500 2600
F 0 "D?" H 5500 2817 50  0000 C CNN
F 1 "3.3v Zener" H 5500 2726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 5500 2425 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds18010.pdf" H 5500 2600 50  0001 C CNN
	1    5500 2600
	0    -1   1    0   
$EndComp
$Comp
L Diode:BZT52Bxx D?
U 1 1 61D61E77
P 5650 2600
F 0 "D?" H 5650 2817 50  0000 C CNN
F 1 "3.3v Zener" H 5650 2726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 5650 2425 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds18010.pdf" H 5650 2600 50  0001 C CNN
	1    5650 2600
	0    -1   1    0   
$EndComp
$Comp
L Diode:BZT52Bxx D?
U 1 1 61D730E3
P 5800 2600
F 0 "D?" H 5800 2817 50  0000 C CNN
F 1 "3.3v Zener" H 5800 2726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 5800 2425 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds18010.pdf" H 5800 2600 50  0001 C CNN
	1    5800 2600
	0    -1   1    0   
$EndComp
$Comp
L Diode:BZT52Bxx D?
U 1 1 61D730E9
P 5950 2600
F 0 "D?" H 5950 2817 50  0000 C CNN
F 1 "3.3v Zener" H 5950 2726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 5950 2425 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds18010.pdf" H 5950 2600 50  0001 C CNN
	1    5950 2600
	0    -1   1    0   
$EndComp
$Comp
L Diode:BZT52Bxx D?
U 1 1 61D730EF
P 6100 2600
F 0 "D?" H 6100 2817 50  0000 C CNN
F 1 "3.3v Zener" H 6100 2726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 6100 2425 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds18010.pdf" H 6100 2600 50  0001 C CNN
	1    6100 2600
	0    -1   1    0   
$EndComp
$Comp
L Diode:BZT52Bxx D?
U 1 1 61D730F5
P 6250 2600
F 0 "D?" H 6250 2817 50  0000 C CNN
F 1 "3.3v Zener" H 6250 2726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 6250 2425 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds18010.pdf" H 6250 2600 50  0001 C CNN
	1    6250 2600
	0    -1   1    0   
$EndComp
$Comp
L Diode:BZT52Bxx D?
U 1 1 61D730FB
P 6400 2600
F 0 "D?" H 6400 2817 50  0000 C CNN
F 1 "3.3v Zener" H 6400 2726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 6400 2425 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds18010.pdf" H 6400 2600 50  0001 C CNN
	1    6400 2600
	0    -1   1    0   
$EndComp
$Comp
L Diode:BZT52Bxx D?
U 1 1 61D73101
P 6550 2600
F 0 "D?" H 6550 2817 50  0000 C CNN
F 1 "3.3v Zener" H 6550 2726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 6550 2425 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds18010.pdf" H 6550 2600 50  0001 C CNN
	1    6550 2600
	0    -1   1    0   
$EndComp
$Comp
L Diode:BZT52Bxx D?
U 1 1 61D73107
P 6700 2600
F 0 "D?" H 6700 2817 50  0000 C CNN
F 1 "3.3v Zener" H 6700 2726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 6700 2425 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds18010.pdf" H 6700 2600 50  0001 C CNN
	1    6700 2600
	0    -1   1    0   
$EndComp
$Comp
L Diode:BZT52Bxx D?
U 1 1 61D7310D
P 6850 2600
F 0 "D?" H 6850 2817 50  0000 C CNN
F 1 "3.3v Zener" H 6850 2726 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 6850 2425 50  0001 C CNN
F 3 "https://www.diodes.com/assets/Datasheets/ds18010.pdf" H 6850 2600 50  0001 C CNN
	1    6850 2600
	0    -1   1    0   
$EndComp
Wire Wire Line
	4600 2750 4750 2750
Wire Wire Line
	4750 2750 4900 2750
Connection ~ 4750 2750
Wire Wire Line
	5050 2750 5200 2750
Wire Wire Line
	5350 2750 5200 2750
Connection ~ 5200 2750
Wire Wire Line
	5050 2750 4900 2750
Connection ~ 5050 2750
Connection ~ 4900 2750
Wire Wire Line
	5350 2750 5500 2750
Connection ~ 5350 2750
Wire Wire Line
	5650 2750 5500 2750
Connection ~ 5500 2750
Wire Wire Line
	5800 2750 5650 2750
Connection ~ 5650 2750
Wire Wire Line
	5950 2750 5800 2750
Connection ~ 5800 2750
Wire Wire Line
	6100 2750 5950 2750
Connection ~ 5950 2750
Wire Wire Line
	6250 2750 6100 2750
Connection ~ 6100 2750
Wire Wire Line
	6400 2750 6250 2750
Connection ~ 6250 2750
Wire Wire Line
	6550 2750 6400 2750
Connection ~ 6400 2750
Wire Wire Line
	6700 2750 6550 2750
Connection ~ 6550 2750
Wire Wire Line
	6850 2750 6700 2750
Connection ~ 6700 2750
Wire Wire Line
	6850 2750 7650 2750
Connection ~ 6850 2750
Connection ~ 7650 2750
Wire Wire Line
	7650 2750 7650 2800
$EndSCHEMATC

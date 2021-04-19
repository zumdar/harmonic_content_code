# harmonic_content_code
code and software documentation for the Harmonic Content installation
# teensy pinouts
3.3V pin --> out to DAC DVCC and pots VCC  
GND --> DAC gnd, pots gnd, jacks gnd  
*spi pins*  
11 - sync  
12 - sda (data out)  
13 - sck (clock)  
**pot pins**  
14 (A0) - pot 1  
15 (A1) - pot 2  
16 (A2) - pot 3  
17 (A3) - pot 4  
18 (A4) - pot 5  
19 (A5) - pot 6  
20 (A6) - pot 7 - future  
21 (A7) - pot 8 - future  
**frequency counter pins**  
5 - vco 1 IN  
6 - vco 2 IN  
9 - vco 3 IN  
10 - vco 4 IN - future  
22 - vco 5 IN - future  
23 - vco 6 IN - future  
  
# DAC outputs (preliminary)  
(out0 wasnt doing full voltage when i tried to use it, so I am skipping it)  
*4.19 idea.. take all 6 oscillators, feed thru individual vcas, then feed thru 1 filter...*  
1 - VCO1 pitch   
2 - VCO2 pitch  
3 - VCO3 pitch  
3 - VCO4 pitch  
4 - VCO5 pitch  
5 - VCO6 pitch  
6 - VCF cutoff  
7 - VCF resonance  
8 - VCA1 level  
9 - VCA2 level  
10 - VCA3 level  
11 - VCA4 level  
12 - VCA5 level  
13 - VCA6 level  
14  
15  
  

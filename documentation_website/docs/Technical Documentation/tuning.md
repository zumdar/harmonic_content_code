title:      Tuning
desc:       How to keep 6 oscillators in tune
date:       2021/4/27
version:    1.0.0
template:   document
nav:        Technical Documentation>Tuning
percent:    100
authors:    freakylamps@gmail.com


# Tuning

A main aesthetic goal of the installation is to explore harmonic relationships between sound and light. To this end, a well calibrated and finely tuned audio oscillator section will be necessary, as the human ear is very sensitive to changes in pitch.  

## Musical Background
It is essential to establish the relationship between frequency (measured in Hertz) and musical note. While this installation will not be limited to the Western notion of discrete pitches and harmony, it is helpful to think about notes as discrete pitches quantized to a certain frequency.  The  frequency range of a typical grand piano is from 27.5 Hz (A0) to 4186 Hz (C8).  Below is a formula for frequency of a note based on it's placement on the piano keyboard. A4 (or "A above Middle-C") is the 49th note. We use it as a reference. n is the note number. 

![](media/Pasted%20image%2020210303232621.png)


![](media/Pasted%20image%2020210303222657.png)
**Figure 1. Chart of Frequency to Note relationship of a typical musical scale **

### Musical Terms 

octave 
 
- interval between one musical pitch and another with double its frequency 
	- ie. if the one note has frequency of 440 hz, one octave about it has frequency of 880 hz
- Below is a formula descripting the number of octaves between two frequencies
 ![](media/Pasted%20image%2020210303221509.png)

cent   

- logarithmic unit of measurement used for musical intervals
- using the standard Western 12 tone scale, there are 100 cents between  each tone, 1200 between octaves. 
- number of cents between frequencies *a* and *b* is ![](media/Pasted%20image%2020210303221738.png)
- It is difficult to establish how many cents are perceptible to humans; this accuracy varies greatly from person to person. One author stated that humans can distinguish a difference in pitch of about 5 - 6 cents.[\[5\]](https://en.wikipedia.org/wiki/Cent_(music)#cite_note-5) The threshold of what is perceptible, technically known as the [just noticeable difference](https://en.wikipedia.org/wiki/Just_noticeable_difference "Just noticeable difference") (JND), also varies as a function of the frequency, the amplitude and the [timbre](https://en.wikipedia.org/wiki/Timbre "Timbre").


## Tuning Relationship to Electronics
For this synthesizer, we will be using a 1 volt per octave standard of tuning. The control voltage is an analog voltage that can vary continuously between 0 and 5V. We can have precise control of 5 octaves of our synthesizer. All control voltages are being originated from the digital domain; in other words our precision is limited to how many bits are available. A typically digital to analog converter has 8 bits which allows for 256 discrete steps.  To achieve satisfactory precision based on human's sensitivity to pitch, we must calculate how many steps are needed. 

- 1 volt / octave
	- 1 volt / 1200 cents =>  1 cent = 0.83 mV 
	-  for a 5 octave range:  5volts / 0.83 mv = 6024 steps to get full 1 cent resolution for all 5 octaves
	- 12 bit dac has 4096 steps
	- 14 bit dac has 16384 steps

As there were only options for 12 bit and 14 bit DACs, this project used a 14 bit DAC as the way to control the pitch of oscillators (as well as other parameters of the sound)



## Additional Tuning Resources 
An autotuning mechanism:  [https://duskwork.net/projects-296561/cem3340-vco-with-autotune-octave-switch-wave-mixer/ ]()
"The idea is to replace what would normally be an analogue potentiometer that you would adjust to tune, with a digital potentiometer (MCP41100) which is controlled by an Arduino. The arduino counts the frequency of the CEM3340, then adjusts the digital potentiometer accordingly."

[A good conversation about tuning and how many bits is needed for accurate tuning](https://www.muffwiggler.com/forum/viewtopic.php?t=183486) - there are suggestions that a 20 bit DAC is needed for 1 cent accuracy. That is for a full 10 octave range though.  

### Sources
Columbia College, Chicago - Audio Arts & Acoustics. *Perceptual attributes of acoustic waves* [http://www.acousticslab.org/psychoacoustics/PMFiles/Module05.htm]()

Zajac, Andrew. *How many cents are in a Hz?* [https://harp.andrewzajac.ca/CentsHz]()

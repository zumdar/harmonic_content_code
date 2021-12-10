title:      Digital To Analog Conversion
desc:       Overview of DAC and how it was implemented in Harmonic Content
date:       2021/12/10
version:    2.0.0
template:   document
nav:        Technical Documentation>DAC
percent:    100
authors:    freakylamps@gmail.com

# Digital to Analog

We need a way to route signals like button presses and sliders to different parts of the synthesizer in the form of 'control voltage'  (an analog voltage between 0 and +10 volts). In order to do this in a expandable way, we have opted to use digital circuity and a microcontroller so we can reroute signals and change things easily with software. In addition, we are using the user interface to control the lighting and motors, so it is convenient for all signals to go back to a central microcontroller and then go out to different subsytems of control voltages and digital control. 

What follow here background and theory of how to convert a digital signal to an analog signal. The reliable and consistent conversion of digital signals to analog control voltage signals for the synthesizer is central to the installation. In the end of it all, we opted to send digital signals from the MCU using the MIDI standard and then use a prebuild MIDI to CV converter that can easily take those MIDI messages and turn them into our 0-10V voltage for the synth. 

### Pulse Width Modulation 
Instead of using a standard  off the shelf 'DAC' which uses shift registers , the simplest way of creating a DAC is using pulse width modulation with a reconstruction filter as shown in Figure 1. After trying this, it was decided that switching cannot happen fast enough. It is not high speed technique. 
![](media/Pasted%20image%2020210415161228.png)
**Figure 1. Digital to Analog conversion via pulse width modulation**  

### Multiplexing
Multiplexing consists of using one high resolution DAC and sending that signal to many different places in your circuit.  Control voltage signal is sent at the same time the output is selected. With a high speed processor,  cycling through many different outputs is possible at an very fast rate. In Figure 2, you see the ditigal input going into the DAC determining the analog voltage out. The voltage out is decided which output to go to using S1, S2, S3... S_n. In this case, the switches take the place of the multiplexer.  Figure 3 shows a full 16 channel multiplexer setup using a CD4051 multiplexer chip. The analog voltage is fed into the CD4051 and then a binary channel select signal is sent to the CD4051 to determine to which output the analog voltage will go. If this process is sped up and voltages and select signals are sent at rates at tens of thousands of times per second, sending analog voltages to many different outputs is possible using just one DAC. 
![](media/Pasted%20image%2020210415161720.png)
**Figure 2. Multiplexing DAC**  

![](media/Pasted%20image%2020210415162028.png)
**Figure 3.  16 channel multiplexed DAC**  

### DAC 
After consideration of time and resources, we decided to opt for the easiest, but more costly solution of purchasing a multichannel high resolution DAC chip. This chip communicates with a microcontroller using the SPI protocol. 

![](media/Pasted%20image%2020210415162305.png)
**Figure 4. Block Diagram of AD5390 14 bit 16 channel DAC**  

As timing is critical for this application, a logic analyzer was used to collect data on exactly how long it would take to send each control signal. Using the SPI protocol from a Teensy 3.6 microcontroller running at 10 MHz, the total time for one signal was 3.21us and there was 4.369 uS between signals. So for one signal it takes about 7.579 uS. To go through all 16 channels at that rate it would take 121.264 uS, or only 1/10th of a millisecond. This equates to a sampling rate of 8kHz which for updating pitches and controlling envelopes is a sufficiently fast speed for our applications. Luckily, there is no need to send audio rate control signal (20hz to 20kHz), unless doing frequency modulation, which at this stage is not being implemented. 

![](media/Pasted%20image%2020210324195601.png)
**Figure 5. Logic analyzer of signal going into AD5390 from Teensy 3.6 microcontroller**  


### Sources 

Chamberlin, Hal. *Musical Applications of Microprocessors.* Hayden Book Company. 1980. 

Analog Devices. *AD5390.* 2014
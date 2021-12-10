title:      System Architecture
desc:       High level functions of the installation
date:       2021/4/27
version:    1.0.0
template:   document
nav:        Technical Documentation>System Architecture
percent:    100
authors:    freakylamps@gmail.com

# System Architecture

## System Organization

The installation will be setup as a standalone playable instrument. It will feature user inputs through the form of buttons, knobs, gestural control, and even allow users to take control of the instrument via the internet. Through a small microcontroller and a mini-computer, the user input will be processed and sent out to the analog circuity consisting of oscillators, waveshapers, filters, and amplifiers. The signal will then be fed to speakers on the installation. Based on the pitch and timbre of the sound, the lighting of the sculpture will react accordingly, based on researched sound and light harmonic relationships. A big inspiration of the technical side of this system comes from the 1978 classic polyphonic synthesizer, the Sequential Circuits Prophet 5. It was one of the first analog polyphonic synthesizers with a digital microcontroller controlling the analog circuitry. Due to its early microcontroller implementation, it is a fairly simple and well documented system. It is also robust and well designed, there are many thousands of these instruments still working and preforming 40 years after they were built.  Figure 3 and Figure 4 show block diagrams from the technical manual of the Prophet 5 depicting how the system was implemented. 


![](media/Block%20Diagram%202021.png)
**Figure 1. Overview of the system**

![](media/Digital%20Subsystem%20Diagram%202021.png)
**Figure 2. Overview of the processor subsystem**

![](media/Pasted%20image%2020210303172657.png)
**Figure 3. Overview of a Prophet 5 polyphonic synthesizer**

![](media/Pasted%20image%2020210303172618.png)
**Figure 4. Overview of a Prophet 5 processor subsystem**



### Interface Subsystem 

The interface subsystem will be the digital 'brain' of the operation. It will take input, process it and send output. This system is concerned with generating and manipulating control voltages which will be fed into the analog sound generating circuity, and digital lighting control signal which will be fed into the lighting control system. 

#### List of signal processing tasks for computer + microcontroller
##### Outputs 
 - auto playing of chordal patterns when installation is inactive
 -  autotuning of oscillators
 -  control of led lighting  
##### Inputs 
 - live parameter editing
	 - pots, switches, knobs, gestural + sensor control
 - patch recall
 - MIDI to control voltage 
 - external patch bay for control via new interfaces
 - sequencer // note storage

##### Potential future microcontroller tasks 
 - software envelopes for timbre or amplitude modulation
 - low frequency oscillators


### Sources
Jungleib, Stanley. *Prophet 5 Service Manual* https://medias.audiofanzine.com/files/sequentialcircuitsprophet-5servicemanual-text-470674.pdf
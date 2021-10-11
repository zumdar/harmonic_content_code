#include <SPI.h>

/*
 * References:
 * MIDI: https://www.pjrc.com/teensy/td_libs_MIDI.html
 * ADC: https://github.com/pedvide/ADC
 */

/*
 * Pinouts
 * 0    SPI_1 (CS)
 * 1    SPI_1 (MISO)
 * 2    power LED
 * 3    warning LED
 * 4    Error LED
 * 5    Comm LED (SPI)
 * 6    Tune button
 * 7    MIDI (Receive)
 * 8    MIDI (Transmit)
 * 9
 * 10   SPI_0 (CS)
 * 11   SPI_0 (MOSI)
 * 12   SPI_0 (MISO)
 * 13   SPI_0 (SCK)
 * 14   AnalogInput0
 * 15   AnalogInput1
 * 16   AnalogInput2
 * 17   AnalogInput3
 * 18   AnalogInput4
 * 19   AnalogInput5
 * 20   AnalogInput6
 * 21   AnalogInput7
 * 22   AnalogInput8
 * 23   AnalogInput9
 * 24   AnalogInput10
 * 25   AnalogInput11
 * 26   SPI_1 (MOSI)
 * 27   SPI_1 (SCK)
 * 28   
 * 29
 * 30
 * 31
 * 32
 * 33
 * 34
 * 35
 * 36
 * 37
 * 38   AnalogInput12
 * 39   AnalogInput13
 * 40   AnalogInput14
 * 41   AnalogInput15
 */

// SPI 0
const int CS0 = 10;
const int MISO0 = 12;
const int MOSI0 = 11;
const int SCK0 = 13;

// SPI 1
const int CS1 = 0;
const int MISO1 = 1;
const int MOSI1 = 26;
const int SCK1 = 27;

// Analog Inputs
const int AnalogInput0 = 14;
const int AnalogInput1 = 15;
const int AnalogInput2 = 16;
const int AnalogInput3 = 17;
const int AnalogInput4 = 18;
const int AnalogInput5 = 19;
const int AnalogInput6 = 20;
const int AnalogInput7 = 21;
const int AnalogInput8 = 22;
const int AnalogInput9 = 23;
const int AnalogInput10 = 24;
const int AnalogInput11 = 25;
const int AnalogInput12 = 38;
const int AnalogInput13 = 39;
const int AnalogInput14 = 40;
const int AnalogInput15 = 41;
const int AnalogInputs[] = [14,15,16,17,18,19,20,21,22,23,24,26,38,39,40,41];

//Outputs
const int tuner = 6;


//Private variables-----------------------------------------------------
enum state {
  idle,
  tune,
  play
};
int curr_state;
int inputTime;

//Private functions-----------------------------------------------------
/*
 * DAC SPI data transfer
 * @param address: address of data
 * @param value: value to be sent
 */
int dacWrite(int address, int value) {
  digitalWrite(CS0, LOW);
  SPI.transfer(address);
  SPI.transfer(value);
  // take the SS pin high to de-select the chip:
  digitalWrite(CS0, HIGH);
  return 0;
}
 
/*
 * tunes oscillators
 * @param: None
 * @return: None
 */
void tuneOscillators()
{
  dacWrite(0, 1); //Write A to DAC ocsllator output
  dacWrite(1, 1);
  dacWrite(2, 1);
  dacWrite(3, 1);
  digitalWrite(Tuner, HIGH);
  delay(200);
  digitalWrite(Tuner, LOW);
  return;
}

/*
 * checks for user input
 * @param: None
 * @return: true if user input is detected, else false
 */
bool detectUserInput()
{
  int inputThreshold = 0;
  for(int i = 0, i < 16; i++)
  {
    if(inputThreshold <= AnalogRead(AnalogInputs[i]))
      return true;
  }
  return false;
}

/*
 * Plays idle notes
 * @param: None
 * @return: None
 */
void idlePlay()
{
  static noteIndex = 0;
  //note thread
  return;
}

/*
 * Plays user notes
 * @param: None
 * @return: None
 */
void userPlay()
{
  //GetInput()
  //ProcessInput()
  //Envelope()
  //SPI Output
  return;
}

//Main Program-----------------------------------------------------------
void setup() {
  Serial.begin(9600);
  
  //SPI Setup
  pinMode(CS0, OUTPUT);
  digitalWrite(CS0, HIGH);
  SPI.begin();
  SPI.beginTransaction(SPISettings(100000000, MSBFIRST, SPI_MODE1));

  //Output Setup
  pinMode(Tuner, OUTPUT);
  digitalWrite(Tuner, LOW);

  //State Machine
  curr_state = idle;
}

void loop() {
  switch (curr_state) {
    case idle:
      if (!detectUserInput())
        Serial.print("");//idlePlay()
      else
        curr_state = play;
      break;
      
    case tune:
      //tuneOscillators()
      delay(1000);
      curr_state = idle;
      break;
      
    case play:
      if (detectUserInput())
        inputTime = millis();
      if (millis() - inputTime > 30000)
        curr_state = idle;
        break;
      userPlay();
      break;
  }
}

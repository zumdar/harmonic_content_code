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
 * 18   AnalogInput4 i2c
 * 19   AnalogInput5 i2c
 * 20   AnalogInput6
 * 21   AnalogInput7
 * 22   AnalogInput8
 * 23   AnalogInput9
 * 24   AnalogInput10
 * 25   AnalogInput11
 * 26   SPI_1 (MOSI) analog
 * 27   SPI_1 (SCK)  analog
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
int attackTime = 500;
int releaseTime = 500;

//Private functions-----------------------------------------------------
/*
 * 
 */
void playNote(int note, int oscillator, int t)
{
  static int prevNote[] = [0, 0, 0, 0];
  static int prevAmp[] = [0, 0, 0, 0];
  //If note being played
  if(note != 0)
  {
    if(note != prevNote[oscillator])
    {
      //SPI send out note
      prevNote[oscillator] = note;
    }
    //Attack
    if (prevAmp[oscillator] < 10)
    {
      prevAmp[oscillator] += 10/attackTime;
      //send newAmp 
    }
  }
  else    //if no note
  {
    //Release
    if (prevAmp[oscillator] > 0)
    {
      prevAmp[oscillator] -= 10/releaseTime;
      //send newAmp 
    }
    else
    {
      prevNote[oscillator] =0;
      //sendOut note
    }
  }
}

/*
 * DAC SPI data transfer
 * @param dacNum: integer index out dac output
 * @param value: value to be sent
 */
int dacWrite(int dacNum, int value) {
  int address = dacNum + 0xc8;
  byte beginning = (header | address); // create the 1st byte
  word data = ((word)value); // create the next 2 bytes
  valueHighByte = highByte(data);
  valueLowByte = lowByte(data);
  digitalWrite(CS0, HIGH);
  digitalWrite(CS0, LOW);
  SPI.transfer(beginning);
  SPI.transfer(valueHighByte);
  SPI.transfer(valueLowByte);
  digitalWrite(LDAC, LOW);
  digitalWrite(LDAC, HIGH);
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
  for(int i = 0, i < 4; i++)
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
  int input0 = AnalogRead(AnalogInput0);
  int input1 = AnalogRead(AnalogInput1);
  int input2 = AnalogRead(AnalogInput2);
  int input3 = AnalogRead(AnalogInput3);
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
      tuneOscillators()
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

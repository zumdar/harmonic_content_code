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
 * 2
 * 3
 * 4
 * 5
 * 6
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
const int CS1 = 10;
const int MISO1 = 12;
const int MOSI1 = 11;
const int SCK1 = 13;

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
 * tunes oscillators
 * @param: None
 * @return: None
 */
void tuneOscillators()
{
  return;
}

/*
 * checks for user input
 * @param: None
 * @return: true if user input is detected, else false
 */
bool detectUserInput()
{
  //note thread
  return true;
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
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));
  Serial.begin(9600);
  //inputs outputs
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

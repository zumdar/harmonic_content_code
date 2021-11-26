#include <SPI.h>
#include <MIDI.h>
#include <Wire.h>

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

//MIDI
MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);
#define HIGHEST_NOTE 72
#define LOWEST_NOTE 24
#define TUNE_NOTE 24
const int numNotes = HIGHEST_NOTE - LOWEST_NOTE;
const int noteStep = 1024/numNotes;

// SPI 0
const int CS0 = 10;
const int MISO0 = 12;
const int MOSI0 = 11;
const int SCK0 = 13;

// Analog Inputs
const int AnalogInputs[] = {14,15,16,17,18,19,20,21,22,23,24,26,38,39,40,41};

//Outputs
const int tuner = 6;

int songNotes[] = {43, 43, 50, 50, 52, 52, 50, 50, 48, 48, 47, 47, 45, 45, 43, 43 };
int songNotes2[]= {43, 50, 50, 50, 52, 50, 50, 50, 48, 50, 47, 50, 45, 50, 43, 50 };

//Private variables-----------------------------------------------------
enum state {
  idle,
  tune,
  play
};
int curr_state;
int inputTime;
int attackStep = 5;
int releaseStep = 5;
int prevNote[] = {24, 24, 24, 24};
static int prevAmp[] = {0, 0, 0, 0};

//Private functions-----------------------------------------------------
/*
 * 
 */
void playNote(int note, int oscillator)
{
  //If note being played
  if(note != 24)
  {
    if(note != prevNote[oscillator])
    {
      MIDI.sendNoteOff(prevNote[oscillator], 100, oscillator+1);
      MIDI.sendNoteOn(note, 100, oscillator+1);
      prevNote[oscillator] = note;
    }
    //Attack
    /*if (prevAmp[oscillator] < 120)
    {
      prevAmp[oscillator] += attackStep;
      //send amp 
    }*/
  }
  else    //if no note
  {
    //Release
    if (prevAmp[oscillator] > 0)
    {
      prevAmp[oscillator] -= releaseStep;
      //send amp
    }
    else
    {
      prevNote[oscillator] = 24;
    }
  }
}
 
/*
 * tunes oscillators
 * @param: None
 * @return: None
 */
void tuneOscillators()
{
  MIDI.sendNoteOn(TUNE_NOTE, 100, 1);
  MIDI.sendNoteOn(TUNE_NOTE, 100, 2);
  MIDI.sendNoteOn(TUNE_NOTE, 100, 3);
  MIDI.sendNoteOn(TUNE_NOTE, 100, 4);
  digitalWrite(tuner, HIGH);
  delay(200);
  digitalWrite(tuner, LOW);
  delay(30000); //30 second tuning time
  return;
}

/*
 * checks for user input
 * @param: None
 * @return: true if user input is detected, else false
 */
bool detectUserInput()
{
  int inputThreshold = 50;
  for(int i = 0; i < 4; i++)
  {
    if(inputThreshold <= analogRead(AnalogInputs[i]))
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
  static int noteIndex = 0;
  if (noteIndex == 16)
    noteIndex = 0;
  MIDI.sendNoteOn(songNotes[noteIndex], 100, 1);
  MIDI.sendNoteOn(songNotes2[noteIndex], 100, 2);
  delay(500);
  MIDI.sendNoteOff(songNotes[noteIndex], 100, 1);
  MIDI.sendNoteOff(songNotes2[noteIndex], 100, 2);
  delay(100);
  noteIndex++;
  return;
}

/*
 * Plays user notes
 * @param: None
 * @return: None
 */
void userPlay()
{
  for (int i = 0; i < 4; i++)
  {
    int input = analogRead(AnalogInputs[i]);
    int note = input/noteStep + LOWEST_NOTE;
    //Serial.println(note);
    playNote(note, i);
  }
  return;
}

//Main Program-----------------------------------------------------------
void setup() {
  Serial.begin(9600);
  MIDI.begin(); //MIDI serial
  Wire.begin(); //I2C to visual Display
  /*Wire.beginTransmission(9); // transmit to device #4
  Serial.print(x);
  Wire.write("x is ");        // sends five bytes
  Wire.write(x);              // sends one byte  
  Wire.endTransmission();    // stop transmitting*/
 
  //Output Setup
  pinMode(tuner, OUTPUT);
  digitalWrite(tuner, LOW);

  //State Machine
  curr_state = idle;
  MIDI.sendProgramChange(4, 1);
  MIDI.sendNoteOn(TUNE_NOTE, 100, 1);
  MIDI.sendNoteOn(TUNE_NOTE, 100, 2);
  MIDI.sendNoteOn(TUNE_NOTE, 100, 3);
  MIDI.sendNoteOn(TUNE_NOTE, 100, 4);
}

void loop() {
  switch (curr_state) {
    case idle:
      if (!detectUserInput())
      {
        Serial.print("idle\n");
        idlePlay();
      }
      else
        curr_state = play;
      break;
      
    case tune:
      Serial.print("tune");
      tuneOscillators();
      delay(1000);
      curr_state = idle;
      break;
      
    case play:
      Serial.println("play");
      if (detectUserInput())
      {
        inputTime = millis();
      }
      if (millis() - inputTime > 30000)
      {
        curr_state = idle;
        break;
      }
      userPlay();
      break;
  }
  delay(10);
}

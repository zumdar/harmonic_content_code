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
 * 14   AnalogInput1 slider1 v 215-260
 * 15   AnalogInput2 button11 v
 * 16   AnalogInput3 button12 v
 * 17   AnalogInput4 slider2 203-222
 * 18   #AnalogInput5 sda
 * 19   #AnalogInput6 scl
 * 20   AnalogInput5 button21
 * 21   AnalogInput6 button22
 * 22   AnalogInput7 attack
 * 23   AnalogInput8
 * 24   AnalogInput9 slider3 210-237
 * 25   AnalogInput10 button31
 * 26   AnalogInput11 button32
 * 27   AnalogInput12 slider4 205-220
 * 28   
 * 29
 * 30
 * 31
 * 32
 * 33   Tuner1
 * 34   Tuner2
 * 35   Tuner3
 * 36   Tuner4
 * 37
 * 38   AnalogInput13 button41 v
 * 39   AnalogInput14 button42 v
 * 40   AnalogInput15 releaseKnob v
 * 41   AnalogInput16
 */

//MIDI
MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, MIDI);
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
const int AnalogInputs[] = {15,16,20,21,25,26,38,39};
const int Button11 = 15;
const int Button12 = 16;
const int Button21 = 20;
const int Button22 = 21;
const int Button31 = 25;
const int Button32 = 26;
const int Button41 = 38;
const int Button42 = 39;
const int attackKnob = 22;
const int releaseKnob = 40;

//Outputs
const int tuner = 6;

int songNotes1[] = { 36, 35, 33, 33};
int songNotes2[] = { 40, 38, 36, 36};
int songNotes3[] = { 43, 43, 40, 41};
int songNotes4[] = { 48, 47, 45, 45 };

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
/* Sends data to display
 * @param: oscil Oscillator number
 * @param: pitch Pitch level
 * @param: volume based on envelope
 * @return: None
 */
void sendI2C(int oscil, int pitch, int vol)
{
  Wire.beginTransmission(9); // transmit to device #4
  Wire.write("a");
  Wire.write(oscil); 
  Wire.write(":");
  Wire.write(pitch); 
  Wire.write(":");
  Wire.write(vol); 
  Wire.endTransmission();    // stop transmitting
}

/* Plays Note and keeps track of current envelope
 * @param: note Note Number MIDI
 * @param: oscillator Oscillator number
 * @return: None
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
    if (prevAmp[oscillator] < 120)
    {
      prevAmp[oscillator] += attackStep;
      switch(oscillator)
      {
        case 0:
          MIDI.sendControlChange(71, prevAmp[oscillator], oscillator+1);
          break;
        case 1:
          MIDI.sendControlChange(72, prevAmp[oscillator], oscillator+1);
          break;
        case 2:
          MIDI.sendControlChange(73, prevAmp[oscillator], oscillator+1);
          break;
        case 3:
          MIDI.sendControlChange(74, prevAmp[oscillator], oscillator+1);
          break;
      }
      delay(5);
    }
  }
  else    //if no note
  {
    //Release
    if (prevAmp[oscillator] > 0)
    {
      prevAmp[oscillator] -= releaseStep;
      switch(oscillator)
      {
        case 0:
          MIDI.sendControlChange(71, prevAmp[oscillator], oscillator+1);
          break;
        case 1:
          MIDI.sendControlChange(72, prevAmp[oscillator], oscillator+1);
          break;
        case 2:
          MIDI.sendControlChange(73, prevAmp[oscillator], oscillator+1);
          break;
        case 3:
          MIDI.sendControlChange(74, prevAmp[oscillator], oscillator+1);
          break;
      }
      delay(5);
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
  /*for(int i = 0; i < 9; i++)
  {
    if(digitalRead(AnalogInputs[i])==LOW)
      return true;
  }*/
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
  if (noteIndex == 3)
    noteIndex = 0;
  int startTime = millis();
  MIDI.sendNoteOn(songNotes1[noteIndex], 100, 1);
  MIDI.sendNoteOn(songNotes2[noteIndex], 100, 2);
  MIDI.sendNoteOn(songNotes3[noteIndex], 100, 3);
  MIDI.sendNoteOn(songNotes4[noteIndex], 100, 4);
  Serial.println(songNotes1[noteIndex]);
  while (millis() - startTime < 5000)
  {
    if (detectUserInput())
      return;
    delay(5);
  }
  MIDI.sendNoteOff(songNotes1[noteIndex], 100, 1);
  MIDI.sendNoteOff(songNotes2[noteIndex], 100, 2);
  MIDI.sendNoteOff(songNotes3[noteIndex], 100, 3);
  MIDI.sendNoteOff(songNotes4[noteIndex], 100, 4);
  while (millis() - startTime < 100)
  {
    if (detectUserInput())
      return;
    delay(5);
  }
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
  //Wire.begin(); //I2C to visual Display

  //Input Setup
  pinMode(Button11, INPUT);
  pinMode(Button12, INPUT);
  pinMode(Button21, INPUT);
  pinMode(Button22, INPUT);
  pinMode(Button31, INPUT);
  pinMode(Button32, INPUT);
  pinMode(Button41, INPUT);
  pinMode(Button42, INPUT);  
 
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
        Serial.print("n");
        //curr_state = play;
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

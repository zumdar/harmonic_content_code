#include <MIDI.h>

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);
const int channel = 1;
int ramp;

void setup() {
  Serial.begin(9600);
  MIDI.begin();
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  ramp = 0;
}

void loop() {
  if (digitalRead(2) == LOW)
  {
    MIDI.sendNoteOn(48, 100, channel);
    if (ramp < 120)
    {
      MIDI.sendControlChange(73, ramp+=5, channel);
      delay(5);
    }
  }
  else
  {
    MIDI.sendNoteOff(48, 100, channel);
    if (ramp > 0)
    {
      MIDI.sendControlChange(73, ramp-=5, channel);
      delay(5);
    }
  }
  
  if (digitalRead(3) == LOW)
  {
    MIDI.sendNoteOn(50, 100, channel);
    /*if (ramp < 120)
    {
      MIDI.sendControlChange(73, ramp+=5, channel);
      delay(5);
    }*/
  }
  else
  {
    MIDI.sendNoteOff(50, 100, channel);
    /*if (ramp > 5)
    {
      MIDI.sendControlChange(73, ramp-=5, channel);
      delay(5);
    }*/
  }
  
  if (digitalRead(4) == LOW)
  {
    MIDI.sendNoteOn(28, 100, channel);
  }
  else
  {
    MIDI.sendNoteOn(28, 0, channel);
  }
  
  if (digitalRead(5) == LOW)
  {
    MIDI.sendNoteOn(29, 100, channel);
  }
  else
  {
    MIDI.sendNoteOn(29, 0, channel);
  }
  delay(10);
  /*int note;
  for (note=10; note <= 127; note++) {
    MIDI.sendNoteOn(note, 100, channel);
    delay(200);
    MIDI.sendNoteOff(note, 100, channel);
  }
  delay(2000);*/
}

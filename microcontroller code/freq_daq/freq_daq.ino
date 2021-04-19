#include <FreqMeasureMulti.h>
#include <SPI.h>
#include "pitches.h"

//frequency measuring stuff:
FreqMeasureMulti freq1;
float frequency1;
float sum1 = 0, sum2 = 0, sum3 = 0;
int count1 = 0, count2 = 0, count3 = 0;
elapsedMillis timeout;

// dac (SPI) stuff:
// pins // SS = 10 // mosi (data out of teensy)  = 11 // clock = 13
// busy = 2 (in case monitoring is wanted)
const int slaveSelectPin = 10;
byte header = 0b00000000; // first two 4 bits are 0000 -- disable toggle mode, enable write , then two blank
byte address = 1;  // this is just 4 bits but we will OR it with header
word regi = 0b1100000000000000; // need the first 2 bits of the data word to be 11 to select the input data register
word value; // this will be a 14 bit number, go up to 16384.
byte valueHighByte;
byte valueLowByte;
const int busyPin = 2;

//timing stuff

unsigned long time_now = 0;
int period = 1000;
int ind;

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
//should be 0v, 1v, 2v, 3v, 4v, 5v
int octaveVolts[] = {0, 3276, 6552, 9828, 13104, 16383};


void setup() {
  Serial.begin(57600);
  //  while (!Serial) ; // wait for Arduino Serial Monitor
  //  delay(10);
  freq1.begin(6);
  //SPI stuff:
  pinMode (slaveSelectPin, OUTPUT);
  pinMode (busyPin, OUTPUT);
  digitalWrite (slaveSelectPin, HIGH);
  // initialize SPI:
  SPI.begin();
  SPI.beginTransaction(SPISettings(100000000, MSBFIRST, SPI_MODE1));
}


void loop() {

  if (millis() > time_now + period) {
    //play a note
    value = octaveVolts[ind];
    dacWrite(address, value);
    ind++;
    time_now = millis();
    if (ind > 5) {
      ind = 0;
    }
  }


  if (freq1.available()) {
    sum1 = sum1 + freq1.read();
    count1 = count1 + 1;
  }
  frequency1 = sum1 / count1;
  frequency1 = freq1.countToFrequency(frequency1);
  //   print results every half second
  if (timeout > 20) {
    if (count1 > 0) {
      Serial.print(frequency1);
    } else {
      Serial.print("(no pulses)");
    }
    Serial.println();
    sum1 = 0;
    count1 = 0;
    timeout = 0;
  }
}


void dacWrite(byte address, word value) {
  byte beginning = (header | address); // create the 1st byte
  word data = (regi | value); // create the next 2 bytes
  valueHighByte = highByte(data);
  valueLowByte = lowByte(data);
  // take the SS pin low to select the chip:
  digitalWrite(slaveSelectPin, LOW);
  SPI.transfer(beginning);
  SPI.transfer(valueHighByte);
  SPI.transfer(valueLowByte);
  // take the SS pin high to de-select the chip:
  digitalWrite(slaveSelectPin, HIGH);
}

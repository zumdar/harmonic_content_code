#include <SPI.h>

// SPI 0
const int CS0 = 10;
const int MISO0 = 12;
const int MOSI0 = 11;
const int SCK0 = 13;

#define LDAC 23
#define CLEAR 24
#define RESET 22

#define VMIN          21844
#define VMAX          65535

int attackInterval = 100;
int releaseInterval = 100;
byte header = 0b00000000; // first two 4 bits are 0000 -- disable toggle mode, enable write , then two blank
byte address =1;   // this is just 4 bits but we will OR it with header
word regi = 0b1100000000000000; // need the first 2 bits of the data word to be 11 to select the input data register
word value; // this will be a 14 bit number, go up to 16384.
byte valueHighByte;
byte valueLowByte;

bool note;
int runtime;

/*
 * DAC SPI data transfer
 * @param address: address of data
 * @param value: value to be sent
 */
int dacWrite(int address, int value) {
  byte beginning = (header | address); // create the 1st byte
  word data = (regi | value); // create the next 2 bytes
  valueHighByte = highByte(data);
  valueLowByte = lowByte(data);
  // take the SS pin low to select the chip:
  digitalWrite(CS0, LOW);
  SPI.transfer(beginning);
  SPI.transfer(valueHighByte);
  SPI.transfer(valueLowByte);
  // take the SS pin high to de-select the chip:
  digitalWrite(CS0, HIGH);
  return 0;
}

void playNote(bool note)
{
  static int prevNote = true;
  static int prevAmp = 21844;
  //If note being played
  if(note)
  {
    if (prevAmp < 65535)
    {
      prevAmp += attackInterval;
      Serial.print(prevAmp);
      Serial.print("\n");
      dacWrite(1, prevAmp);
    }
  }
  else 
  {
    //Release
    if (prevAmp > 21844)
    {
      prevAmp -= releaseInterval;
      Serial.print(prevAmp);
      Serial.print("\n");
      dacWrite(1, prevAmp);
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  note = true;
  runtime = millis();
  Serial.begin(9600);
  pinMode (CS0, OUTPUT);SPI.begin();
  digitalWrite (CS0, HIGH);
  SPI.beginTransaction(SPISettings(100000000, MSBFIRST, SPI_MODE1));
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() - runtime > 7000)
  {
    note = !note;
    runtime = millis();
    Serial.print("Cycling\n");
  }
  
  playNote(note);
  delay(40);

}

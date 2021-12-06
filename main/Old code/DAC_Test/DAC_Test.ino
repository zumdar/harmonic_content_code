#include <SPI.h>

// SPI 0
const int CS0 = 10; //grey
const int MISO0 = 12; //blk
const int MOSI0 = 11; //white
const int SCK0 = 13;  //red

#define LDAC 0
#define CLEAR 1
#define RESET 2

#define VMIN          21844
#define VMAX          65535

int attackInterval = 500;
int releaseInterval = 500;
byte header = 0b00000000; // first two 4 bits are 0000 -- disable toggle mode, enable write , then two blank
word regi = 0b0000000000000000; // need the first 2 bits of the data word to be 11 to select the input data register
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
int dacWrite(int dacNum, int value) {
  int address = dacNum + 0xC8;
  byte beginning (byte)address;
  //byte beginning = (header | address); // create the 1st byte
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

void playNote(bool note, int address)
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
      dacWrite(address, prevAmp);
    }
    else
    {
      prevAmp = 65535;
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
      dacWrite(address, prevAmp);
    }
    else
    {
      prevAmp = 21844;
    }
  }
}

void setup() {
  // put your setup code here, to run once:
  note = true;
  runtime = millis();
  Serial.begin(9600);
  pinMode (CS0, OUTPUT);
  pinMode (LDAC, OUTPUT);
  pinMode (RESET, OUTPUT);
  SPI.begin();
  digitalWrite (CS0, LOW);
  digitalWrite(LDAC, HIGH);
  digitalWrite(RESET, HIGH);
  SPI.beginTransaction(SPISettings(40000000, MSBFIRST, SPI_MODE1));

  for (int i = 0; i < 40; i++)
  {
    dacWrite(i, 0x0000);
    //delayMicroseconds(20);
  }
  //dacWrite(0xc8, 0xffff);
  //delay(1);
  //dacWrite(0xc8, 0x0000);

  /*
  byte beginning = (header | address); // create the 1st byte
  word data = (regi | 65535); // create the next 2 bytes
  valueHighByte = highByte(data);
  valueLowByte = lowByte(data);
  // take the SS pin low to select the chip:
  digitalWrite(CS0, LOW);
  SPI.transfer(0xc8);
  SPI.transfer(0xff);
  SPI.transfer(0xff);
  //Serial.print(beginning);
  //SPI.transfer(beginning);
  //SPI.transfer(valueHighByte);
  //SPI.transfer(valueLowByte);
  // take the SS pin high to de-select the chip:
  digitalWrite(CS0, HIGH);*/
}

void loop() {

  /*for (int i = 0; i < 40; i++)
  {
    dacWrite(i, 0x0000);
    delayMicroseconds(100);
  }
  for (int i = 0; i < 40; i++)
  {
    dacWrite(i, 0xffff);
    delayMicroseconds(100);
  }*/
  
  /*if (num < 0xffff)
  {
    num+=100;
  }
  else
  {
    num = 0x0000;
  }
  dacWrite(0xc8, num);
  delayMicroseconds(10);*/
  //Serial.print(num);
  //Serial.print("\n");*/
  /*if (Serial.available() > 0) {
    incomingByte = Serial.read();
    Serial.println(incomingByte, DEC);
    if (incomingByte !=10)
      
  }*/
  
  /*dacWrite(0, 0xffff);
  delayMicroseconds(100);
  dacWrite(0, 0x0000);
  delayMicroseconds(100);*/
  /*//Serial.println("low");
  delay(3000);
  //Serial.println("high");
  dacWrite(0xc8, 0xffff);
  delay(3000);*/
  /*if(millis() - runtime > 7000)
  {
    note = !note;
    runtime = millis();
    Serial.print("Cycling\n");
  }
  
  playNote(note);*/

}

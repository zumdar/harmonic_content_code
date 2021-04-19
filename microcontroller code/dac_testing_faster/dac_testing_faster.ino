#include <SPI.h>

const int slaveSelectPin = 10;
byte header = 0b00000000; // first two 4 bits are 0000 -- disable toggle mode, enable write , then two blank
byte address =1;   // this is just 4 bits but we will OR it with header
word regi = 0b1100000000000000; // need the first 2 bits of the data word to be 11 to select the input data register
word value; // this will be a 14 bit number, go up to 16384.
byte valueHighByte;
byte valueLowByte;
const int busyPin = 2;
const int ldac = 3;


void setup() {
  // set the slaveSelectPin as an output:
  pinMode (slaveSelectPin, OUTPUT);
  pinMode (busyPin, OUTPUT);
  pinMode (ldac, OUTPUT);
  digitalWrite (slaveSelectPin, HIGH);
  // initialize SPI:
  SPI.begin();
  SPI.beginTransaction(SPISettings(100000000, MSBFIRST, SPI_MODE1));

}

void loop() {
//  for (value = 0; value < 16383; value = value + 1) {
//    Serial.print("value going up is :");
//    Serial.println(value, BIN);
    value = random(0,16000);
    dacWrite(address, value);
    delay(20);
//  }
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

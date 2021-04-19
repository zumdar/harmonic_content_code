#include <SPI.h>

const int slaveSelectPin = 10;
byte header = 0b00000000; // first two 4 bits are 0000 -- disable toggle mode, enable write , then two blank
byte address;   // this is just 4 bits but we will OR it with header
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
}

void loop() {
  address = 0;
  for (value = 0; value < 16383; value = value+1) {
    Serial.print("value going up is :");
    Serial.println(value, BIN);
    dacWrite(address, value);
//    delay(1);
  }
//  delay(100);
  for (value = 16383; value > 0; value = value-1) {
    Serial.print("value going down is :");
    Serial.println(value, BIN);
    dacWrite(address, value);
//    delay(1);
  }
}

void dacWrite(byte address, word value) {
  // gain control of the SPI port
  // and configure settings
  SPI.beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE1));
  // take the SS pin low to select the chip:
  //  send in the address and value via SPI:
  byte beginning = (header | address);
  word data = (regi | value);
  beginning = beginning >> 0;
  valueHighByte = highByte(data);
  valueLowByte = lowByte(data);
  Serial.print("header byte is: ");
  Serial.println(beginning, BIN);
  Serial.print("data word is: ");
  Serial.println(data, BIN);
  digitalWrite(slaveSelectPin, LOW);
  SPI.transfer(beginning);
  SPI.transfer(valueHighByte);
  SPI.transfer(valueLowByte);
  // take the SS pin high to de-select the chip:
  digitalWrite(slaveSelectPin, HIGH);
  digitalWrite(ldac, LOW);
  digitalWrite(ldac, HIGH); // ldac goes high first just like the datasheet
  // release control of the SPI port
  SPI.endTransaction();
}

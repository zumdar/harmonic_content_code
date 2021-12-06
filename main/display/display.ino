#include <Arduino.h>
#include <i2c_driver.h>
#include <i2c_driver_wire.h>

//Private variables-----------------------------------------------------
int note[] = {24, 24, 24, 24};
int amp[] = {0, 0, 0, 0};

void setup()
{
  Wire.begin(9);                // join i2c bus with address #9
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop()
{
  delay(100);
}

void receiveEvent(int howMany)
{
  char c = Wire.read(); // &
  Serial.print(c);
  int oscil = Wire.read(); //oscil number
  Serial.print(oscil);
  c = Wire.read(); // :
  note[oscil] = Wire.read(); // pitch
  Serial.print(note[oscil]);
  c = Wire.read(); // :
  amp[oscil] = Wire.read(); // vol
  Serial.print(amp[oscil]);
  //message in &<oscil>:<note>:<vol> format
}

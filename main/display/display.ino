#include <Arduino.h>
#include <i2c_driver.h>
#include <i2c_driver_wire.h>

#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 80 // Popular NeoPixel ring size

#define MOTOR1 2 // pin 2 for motor1
#define MOTOR2 3 // pin 2 for motor1
#define MOTOR3 4 // pin 2 for motor1
#define MOTOR4 5 // pin 2 for motor1

Adafruit_NeoPixel pixels1(NUMPIXELS, 24, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS, 25, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS, 26, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4(NUMPIXELS, 27, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 100 // Time (in milliseconds) to pause between pixels

//Private variables-----------------------------------------------------
int note[] = {24, 24, 24, 24};
int amp[] = {0, 0, 0, 0};
int osc1, osc2, osc3, osc4, motor1speed, motor2speed, motor3speed, motor4speed;

void setup()
{
  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);
  pinMode(MOTOR3, OUTPUT);
  pinMode(MOTOR4, OUTPUT);
  pixels1.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels2.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels3.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels4.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Wire.begin(9);                // join i2c bus with address #9
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop()
{
  osc1 = map(note[0], 24, 48, 0, 255);
  osc2 = map(note[1], 24, 48, 0, 255);
  osc3 = map(note[2], 24, 48, 0, 255);
  osc4 = map(note[3], 24, 48, 0, 255);
//  motor1speed = map(note[0], 24, 48, 100, 200);
//  motor2speed = map(note[1], 24, 48, 100, 200);
//  motor3speed = map(note[2], 24, 48, 100, 200);
//  motor4speed = map(note[3], 24, 48, 100, 200);
//
//
//  analogWrite(MOTOR1, motor1speed);
//  analogWrite(MOTOR2, motor2speed);
//  analogWrite(MOTOR3, motor3speed);
//  analogWrite(MOTOR4, motor4speed);

  pixels1.clear(); // Set all pixel colors to 'off'
  pixels2.clear(); // Set all pixel colors to 'off'
  pixels3.clear(); // Set all pixel colors to 'off'
  pixels4.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    //    pixels1.setPixelColor(i, pixels1.Color(255, 0, 40));
    pixels1.setPixelColor(i, pixels1.Color(osc1, 100, 0));
    pixels2.setPixelColor(i, pixels2.Color(0, osc2, 20));
    pixels3.setPixelColor(i, pixels3.Color(0, 10, osc3));
    pixels4.setPixelColor(i, pixels4.Color(osc4, osc4, 70));
  }

  pixels1.show();   // Send the updated pixel colors to the hardware.
  pixels2.show();   // Send the updated pixel colors to the hardware.
  pixels3.show();   // Send the updated pixel colors to the hardware.
  pixels4.show();   // Send the updated pixel colors to the hardware.

  delay(100);
}

void receiveEvent(int howMany)
{
  char c = Wire.read(); // a
  Serial.print(c);
  int oscil = Wire.read(); //oscil number
  Serial.print(oscil);
  Serial.print(":");
  c = Wire.read(); // :
  note[oscil] = Wire.read(); // pitch
  Serial.print(note[oscil]);
  Serial.print(":");
  c = Wire.read(); // :
  amp[oscil] = Wire.read(); // vol
  Serial.print(amp[oscil]);
  Serial.print("\n");
  //message in a<oscil>:<note>:<vol> format
}

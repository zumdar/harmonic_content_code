import processing.serial.*; //<>//

import cc.arduino.*;

Arduino arduino;

color off = color(0, 79, 111);
color on = color(84, 145, 158);
int sensor1;
int sensor2;
int [] sensors = {sensor1, sensor2};
int mappedSensor1;
int mappedSensor2;
int mappedSensorOutput1;
int mappedSensorOutput2;

void setup() {
  size(800, 800);
  println(Arduino.list());

  // Modify this line, by changing the "0" to the index of the serial
  // port corresponding to your Arduino board (as it appears in the list
  // printed by the line above).
  arduino = new Arduino(this, Arduino.list()[0], 57600);

  // Alternatively, use the name of the serial port corresponding to your
  // Arduino (in double-quotes), as in the following line.
  //arduino = new Arduino(this, "/dev/tty.usbmodem621", 57600);

  // Set the Arduino digital pins as inputs.
  for (int i = 0; i <= 13; i++)
    arduino.pinMode(i, Arduino.INPUT);
}

void draw() {
  background(255);
  stroke(0);
  noFill();
  for (int i = 0; i <= 1; i++) {
    sensors[i] = arduino.analogRead(i);
  }
  println(sensors[1]);
  mappedSensor1 = int(map(sensors[0], 0, 1024, 0, width));
  mappedSensor2 = int(map(sensors[1], 0, 1024, 0, height));
  if (sensors[1] < 600) {
    arduino.analogWrite(11, 0);
  }  
  if (680 < sensors[1] && sensors[1] < 710) {
    arduino.analogWrite(11, 100);
  }
  if (820 < sensors[1] && sensors[1] < 850) {
    arduino.analogWrite(11, 110);
  }
  if (960 < sensors[1] && sensors[1] < 990) {
    arduino.analogWrite(11, 120);
  }
  strokeWeight(10);  // Beastly
  rect(mappedSensor1, 50, 10, 100);
  rect(50, mappedSensor2, 10, 100);
  mappedSensorOutput1 = int(map(sensors[0], 0, 1024, 0, 255));
  arduino.analogWrite(9, mappedSensorOutput1);
}

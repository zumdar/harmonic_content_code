#define OUT1 10            // PWM output pin

int sensorValue; 
int motorSpeed;

void setup() {                // This executes once
  Serial.begin(9600);             // Initialize serial port
  pinMode(OUT1, OUTPUT);        // Prepare output pin
}

void loop() {                 // This loops continuously
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  motorSpeed = map(sensorValue, 0, 1023, 0, 255);
  analogWrite(OUT1, motorSpeed);      // Pass the value of "in" to the pin

}

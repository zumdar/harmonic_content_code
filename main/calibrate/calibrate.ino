const int AnalogInputs[] = {15,16,20,21,25,26,38,39};
const int button11 = 15;
const int button12 = 16;
const int button21 = 20;
const int button22 = 21;
const int button31 = 25;
const int button32 = 26;
const int button41 = 38;
const int button42 = 39;
const int attackKnob = 22;
const int releaseKnob = 40;

int buttonRead(int i)
{
  if(analogRead(i) > 100)
    return 1;
  else
    return 0;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(14, INPUT);
  pinMode(17, INPUT);
  pinMode(24, INPUT);
  pinMode(27, INPUT);
  pinMode(button11, INPUT_PULLUP);
  pinMode(button12, INPUT_PULLUP);
  pinMode(button21, INPUT_PULLUP);
  pinMode(button22, INPUT_PULLUP);
  pinMode(button31, INPUT_PULLUP);
  pinMode(button32, INPUT_PULLUP);
  pinMode(button41, INPUT_PULLUP);
  pinMode(button42, INPUT_PULLUP);
  //analogReadResolution(10);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  /*if (digitalRead(button11) == HIGH)
    Serial.println("button11");
  if (digitalRead(button12) == HIGH)
    Serial.println("button12");
    
  if (digitalRead(button21) == HIGH)
    Serial.println("button21");
  if (digitalRead(button22) == HIGH)
    Serial.println("button22");
    
  if (digitalRead(button31) == HIGH)
    Serial.println("button31");
  if (digitalRead(button32) == HIGH)
    Serial.println("button32");*/
 
  /*if (digitalRead(button41) == HIGH)
    Serial.println("button41");
  if (digitalRead(button42) == HIGH)
    Serial.println("button42");*/

  for(int i = 14; i < 18; i++)
  {
    Serial.print(i);
    Serial.print(": ");
    Serial.print(analogRead(i));
    Serial.print(" : Button : ");
    Serial.print(digitalRead(i));
    Serial.print("\n");
  }
  for(int i = 20; i < 28; i++)
  {
    Serial.print(i);
    Serial.print(": ");
    Serial.print(analogRead(i));
    Serial.print(" : Button : ");
    Serial.print(digitalRead(i));
    Serial.print("\n");
  }
  for(int i = 38; i < 42; i++)
  {
    Serial.print(i);
    Serial.print(": ");
    Serial.print(analogRead(i));
    Serial.print(" : Button : ");
    Serial.print(digitalRead(i));
    Serial.print("\n");
  }
    
  //Serial.println(analogRead(A3));
  //Serial.println(analogRead(releaseKnob);
  delay(100);
}

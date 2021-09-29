#include <SPI.h>

//Private variables-----------------------------------------------------
enum state {
  idle,
  tune,
  play
};
int curr_state;
int inputTime;

//Private functions-----------------------------------------------------
/*
 * tunes oscillators
 * @param: None
 * @return: None
 */
void tuneOscillators()
{
  return;
}

/*
 * checks for user input
 * @param: None
 * @return: true if user input is detected, else false
 */
bool detectUserInput()
{
  //note thread
  return true;
}

/*
 * Plays idle notes
 * @param: None
 * @return: None
 */
void idlePlay()
{
  static noteIndex = 0;
  //note thread
  return;
}

/*
 * Plays user notes
 * @param: None
 * @return: None
 */
void userPlay()
{
  //GetInput()
  //ProcessInput()
  //Envelope()
  //SPI Output
  return;
}

//Main Program-----------------------------------------------------------
void setup() {
  SPI.beginTransaction(SPISettings(14000000, MSBFIRST, SPI_MODE0));
  Serial.begin(9600);
  //inputs outputs
  curr_state = idle;
}

void loop() {
  switch (curr_state) {
    case idle:
      if (!detectUserInput())
        Serial.print("");//idlePlay()
      else
        curr_state = play;
      break;
      
    case tune:
      //tuneOscillators()
      delay(1000);
      curr_state = idle;
      break;
      
    case play:
      if (detectUserInput())
        inputTime = millis();
      if (millis() - inputTime > 30000)
        curr_state = idle;
        break;
      userPlay();
      break;
  }
}

#include "RBGLed.h"

const short ledNumber = 3; // Number od LED diodes
short pinArray [ledNumber][3];
RBGLed* ledArray[ledNumber];
void initPorts();
void initLeds();

void setup() 
{
 initPorts();
 initLeds();
}

void loop() 
{
  ledArray[0]->setColor(0,255,255); 
  ledArray[1]->setColor(255,0,255);
  ledArray[2]->setColor(255,255,0);;
  delay(1000);
  
  ledArray[0]->setColor(255,255,0);
  ledArray[1]->setColor(0,255,255);
  ledArray[2]->setColor(255,0,255);;
  delay(1000);
  
  ledArray[0]->setColor(255,0,255);
  ledArray[1]->setColor(255,255,0);
  ledArray[2]->setColor(0,255,255);
  delay(1000);
}

void initPorts () 
{
  const short firstPin = 22; // First pin Used
  const short LedChannels = 3; // Couldn't be changed
  short pinNumber = firstPin;
  for (int i = 0; i < ledNumber; i++) 
  {
    for (int j = 0; j < LedChannels; j++) 
    {
      pinArray[i][j] = pinNumber;
      pinMode(pinArray[i][j], OUTPUT);
      pinNumber++;
    }
  }
}

void initLeds() 
{
 for (int i = 0; i < ledNumber; i++) {
   ledArray[i] = new RBGLed(pinArray[i][0], pinArray[i][1], pinArray[i][2]);
 }
}


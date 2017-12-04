#include "RBGLed.h"

const short ledNumber = 6; // Number od LED diodes
short pinArray [ledNumber][3];
RBGLed* ledArray[ledNumber];
void initPorts();
void initLeds();
short ledColors [6][3] = {
  {0,0,255}, //Blue
  {255,255,0}, //Yellow
  {255,0,255}, // Pink
  {255,0,0}, // Red
  {0,255,0}, //Green
  {0,255,255} //Light Blue
};
enum LEDPinE 
{
  RED = 0,
  GREEN,
  BLUE
};
/*
  {0,0,255}, //Blue
  {255,255,0}, //Yellow
  {255,0,255}, // Pink
  {255,0,0}, // Red
  {0,255,0}, //Green
  {0,255,255} //Light Blue
 */
int arrayIndex = 0, cycle = 0, index = 0;

void setup() 
{
 initPorts();
 initLeds();
 index = 0;
}

void loop() 
{  
  if (index == ledNumber) index = 0;
  for (int i = 0; i < ledNumber; i++) 
  {     
    arrayIndex = (cycle + index) % ledNumber;
    if (arrayIndex == ledNumber) arrayIndex = 0;
    ledArray[arrayIndex]->setColor(ledColors[i][RED],ledColors[i][GREEN],ledColors[i][BLUE]);
    cycle ++;
  }
  index ++;
  delay(1000);
}

void initPorts () 
{
  const short firstPin = 22; // First pin Used, Red Color
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
   ledArray[i] = new RBGLed(pinArray[i][RED], pinArray[i][GREEN], pinArray[i][BLUE]);
 }
}

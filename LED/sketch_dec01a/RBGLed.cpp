#include "RBGLed.h"
#include "Arduino.h"

RBGLed ::  RBGLed(short pinRed, short pinGreen, short pinBlue) 
{
  this->pinRed = pinRed;
  this->pinGreen = pinGreen;
  this->pinBlue = pinBlue;
  this->isCathodeLed = true;
}

void RBGLed :: setColor(int redValue, int greenValue, int blueValue) 
{
  if (this->isCathodeLed) 
  {
  analogWrite(this->pinRed, 255 - redValue);
  analogWrite(this->pinGreen, 255 - greenValue);
  analogWrite(this->pinBlue, 255 - blueValue);
  }
  else 
  {
  analogWrite(this->pinRed, redValue);
  analogWrite(this->pinGreen, greenValue);
  analogWrite(this->pinBlue, blueValue);
  }
}

void RBGLed :: mixColor()
{
  
}


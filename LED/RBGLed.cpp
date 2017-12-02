#include "RBGLed.h"
#include "Arduino.h"

RBGLed ::  RBGLed(short pinRed, short pinGreen, short pinBlue) 
{
  this->pinRed = pinRed;
  this->pinGreen = pinGreen;
  this->pinBlue = pinBlue;
}

void RBGLed :: setColor(int redValue, int greenValue, int blueValue) 
{
  analogWrite(this->pinRed, redValue);
  analogWrite(this->pinGreen, greenValue);
  analogWrite(this->pinBlue, blueValue);
}

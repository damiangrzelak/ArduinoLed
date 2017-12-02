class RBGLed 
{
  private:
  short pinRed;
  short pinGreen;
  short pinBlue;

  public:
  RBGLed(short pinRed, short pinGreen, short pinBlue);
  void setColor(int redValue, int greenValue, int blueValue); 
};
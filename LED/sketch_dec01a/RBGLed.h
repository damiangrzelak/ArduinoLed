class RBGLed 
{
  private:
  short pinRed;
  short pinGreen;
  short pinBlue;
  bool isCathodeLed;
  
  public:
  RBGLed(short pinRed, short pinGreen, short pinBlue);
  void setColor(int redValue, int greenValue, int blueValue); 
  void mixColor();
};




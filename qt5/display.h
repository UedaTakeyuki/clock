#ifndef DISPLAY_H
#define DISPLAY_H

class Display
{

public:
  Display();
  ~Display();
  int getWidth(){return width;}
  int getHight(){return hight;}

private:
  int width;
  int hight;
};
#endif // DISPLAY_H

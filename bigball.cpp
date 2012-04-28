#include "bigball.h"
#include "ball.h"

Big_Ball::Big_Ball(Ball *ball)
{
  xdir = ball->getXDir();
  ydir = ball->getYDir();
  speed = ball->getSpeed();
  x = ball->getX();
  y = ball->getY();
  powered = TRUE;
  
  image.load("bigball.png");
  
  rect = image.rect();
  rect.translate(x,y);
}

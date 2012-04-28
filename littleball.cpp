#include "littleball.h"
#include "ball.h"

Little_Ball::Little_Ball(Ball *ball)
{
  xdir = ball->getXDir();
  ydir = ball->getYDir();
  speed = ball->getSpeed();
  x = ball->getX();
  y = ball->getY();
  powered = TRUE;
  
  image.load("littleball.png");
  
  rect = image.rect();
  rect.translate(x,y);
}

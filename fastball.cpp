#include "fastball.h"
#include "ball.h"

Fast_Ball::Fast_Ball(Ball *ball)
{
  xdir = ball->getXDir();
  ydir = ball->getYDir();
  speed = ball->getSpeed();
  x = ball->getX();
  y = ball->getY();
  powered = TRUE;
  
  image.load("ball.png");
  
  rect = image.rect();
  rect.translate(x,y);
}

void Fast_Ball::autoMove()
{
  rect.translate(2*((xdir * speed) + xdir),2*((ydir * speed) + ydir));
  x += xdir;
  y += ydir;

  if(rect.left() <= 0)
   xdir = 1;
  else if(rect.right() >= 600)
    xdir = -1;
}

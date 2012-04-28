#include "ball.h"
#include <ctime>
#include <cstdlib>

Ball::Ball()
{
  xdir = 1;
  ydir = -1;
  speed = 0;
  powered = FALSE;
  
  image.load("ball.png");
  
  rect = image.rect();
  resetState();
}

Ball::Ball(Ball *ball)
{
  xdir = ball->getXDir();
  ydir = ball->getYDir();
  speed = ball->getSpeed();
  x = ball->getX();
  y = ball->getY();
  powered = FALSE;

  image.load("ball.png");

  rect = image.rect();
}

void Ball::resetState()
{
  rect.moveTo(300,400);
  x = 300;
  y = 400;
  xdir = 0;
  srand(time(NULL));
  if(rand()%2 == 0)
    ydir = -1;
  else
    ydir = 1;
  speed = 0.1;
}

void Ball::autoMove()
{
  rect.translate((xdir * speed) + xdir,(ydir * speed) + ydir);
  x += xdir;
  y += ydir;
  
  if(rect.left() <= 0)
   xdir = 1;
  else if(rect.right() >= 600)
    xdir = -1;
}

void Ball::setXDir(int dir)
{
  xdir = dir;
}

void Ball::setYDir(int dir)
{
  ydir = dir;
}

void Ball::setX(int num)
{
  x = num;
}

void Ball::setY(int num)
{
  y = num;
}

void Ball::setSpeed(float num)
{
  speed += num;
}

int Ball::getXDir()
{
  return xdir;
}

int Ball::getYDir()
{
  return ydir;
}

int Ball::getX()
{
  return x;
}

int Ball::getY()
{
  return y;
}

float Ball::getSpeed()
{
  return speed;
}

QRect Ball::getRect()
{
  return rect;
}

QImage & Ball::getImage()
{
  return image;
}

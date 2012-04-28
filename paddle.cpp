#include "paddle.h"


Paddle::Paddle()
{
  image.load("paddle.png");
  
  rect = image.rect();
}

void Paddle::moveLeft(int dist)
{
  if(rect.left() >= 1)
  {
	rect.moveTo(x-dist, y);
	x -= dist;
  }
}

void Paddle::moveRight(int dist)
{
  if(rect.right() <= 599)
  {
	rect.moveTo(x+dist, y);
	x += dist;
  }
}

void Paddle::setX(int num)
{
  x = num;
}

void Paddle::setY(int num)
{
  y = num;
}

int Paddle::getX()
{
  return x;
}

int Paddle::getY()
{
  return y;
}

QRect Paddle::getRect()
{
  return rect;
}

QImage & Paddle::getImage()
{
  return image;
}


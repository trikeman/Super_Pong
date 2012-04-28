#include "obstacle.h"

Obstacle::Obstacle(int xpos, int ypos)
{
  image.load("obstacle.png");
  
  rect = image.rect();
  rect.translate(xpos,ypos);
  x = xpos;
  y = ypos;
}

void Obstacle::setRect(QRect rectangle)
{
  rect = rectangle;
}

QRect Obstacle::getRect()
{
  return rect;
}

QImage & Obstacle::getImage()
{
  return image;
}

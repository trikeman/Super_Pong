#include "powerup.h"
#include <cstdlib>
#include <ctime>

Powerup::Powerup()
{
  srand(time(NULL));
  visible = FALSE;
  type = 4;
  x = rand()%500 + 50;
  y = rand()%550 + 100;
}

void Powerup::move()
{
  srand(time(NULL));
  visible = FALSE;
  x = rand()%500 + 50;
  y = rand()%550 + 100;
  
  rect.translate(x,y);
}

void Powerup::makeVisible()
{
  visible = TRUE;
}

bool Powerup::isVisible()
{
  return visible;
}

int Powerup::getType()
{
  return type;
}

QRect Powerup::getRect()
{
    return rect;
}

QImage & Powerup::getImage()
{
    return image;
}

#include "fastpowerup.h"
#include <cstdlib>
#include <ctime>

Fast_Powerup::Fast_Powerup()
{
  srand(time(NULL));
  visible = FALSE;
  type = 2;
  x = rand()%500 + 50;
  y = rand()%550 + 100;
  
  image.load("fast.png");
  
  rect = image.rect();
  
  rect.translate(x,y);
}

#include "bigpowerup.h"
#include <cstdlib>
#include <ctime>

Big_Powerup::Big_Powerup()
{
  srand(time(NULL));
  visible = FALSE;
  type = 1;
  x = rand()%500 + 50;
  y = rand()%550 + 100;
  
  image.load("big.png");
  
  rect = image.rect();
  
  rect.translate(x,y);
}

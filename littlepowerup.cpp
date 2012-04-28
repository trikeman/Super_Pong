#include "littlepowerup.h"
#include <cstdlib>
#include <ctime>

Little_Powerup::Little_Powerup()
{
  srand(time(NULL));
  visible = FALSE;
  type = 3;
  x = rand()%500 + 50;
  y = rand()%550 + 100;
  
  image.load("little.png");
  
  rect = image.rect();
  
  rect.translate(x,y);
}

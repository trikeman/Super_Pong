#include "playerpaddle.h"
#include "paddle.h"

Player_Paddle::Player_Paddle()
{
  image.load("paddle.png");
  
  rect = image.rect();
  resetState();
}

void Player_Paddle::resetState()
{
  rect.moveTo(300,730);
  x = 300;
  y = 730;
}

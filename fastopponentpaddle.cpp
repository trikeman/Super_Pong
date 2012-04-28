#include "fastopponentpaddle.h"
#include "paddle.h"
#include "opponentpaddle.h"

Fast_Opponent_Paddle::Fast_Opponent_Paddle()
{
  image.load("paddle.png");
  
  rect = image.rect();
  resetState();
}

void Fast_Opponent_Paddle::autoMove(Ball *ball)
{
  if(ball->getX()>x+120)
    moveRight(10);
  if(ball->getX()<x+40)
    moveLeft(10);
}

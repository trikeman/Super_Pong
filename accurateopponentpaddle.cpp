#include "accurateopponentpaddle.h"
#include "paddle.h"
#include "opponentpaddle.h"

Accurate_Opponent_Paddle::Accurate_Opponent_Paddle()
{
  image.load("paddle.png");
  
  rect = image.rect();
  resetState();
}

void Accurate_Opponent_Paddle::autoMove(Ball *ball)
{
  if(ball->getX()>x+150)
    moveRight(10);
  if(ball->getX()<x+10)
    moveLeft(10);
}

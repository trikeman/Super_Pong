#include "ball.h"
#include "opponentpaddle.h"
#include "paddle.h"

Opponent_Paddle::Opponent_Paddle()
{
  image.load("paddle.png");
  
  rect = image.rect();
  resetState();
}

void Opponent_Paddle::resetState()
{
  rect.moveTo(300,30);
  x = 300;
  y = 30;
}

void Opponent_Paddle::autoMove(Ball *ball)
{
  if(ball->getX()>x+150)
    moveRight(3);
  if(ball->getX()<x+10)
    moveLeft(3);
}

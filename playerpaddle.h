#ifndef PLAYERPADDLE_H
#define PLAYERPADDLE_H

#include "paddle.h"
#include <QImage>
#include <QRect>

//the Player_Paddle is the paddle that the player controls
class Player_Paddle : public Paddle
{
public:
  Player_Paddle();
  void resetState();
};

#endif
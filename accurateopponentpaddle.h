#ifndef ACCURATEOPPONENTPADDLE_H
#define ACCURATEOPPONENTPADDLE_H

#include "paddle.h"
#include "opponentpaddle.h"

//the Accurate_Opponent_Paddle is the most advanced enemy, and will return
//the ball in the most difficult fashion
class Accurate_Opponent_Paddle : public Opponent_Paddle
{
public:
    Accurate_Opponent_Paddle();
	void autoMove(Ball *ball);
};

#endif
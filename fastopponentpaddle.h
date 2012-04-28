#ifndef FASTOPPONENTPADDLE_H
#define FASTOPPONENTPADDLE_H

#include "paddle.h"
#include "opponentpaddle.h"

//the Fast_Opponent_Paddle is a slightly more advanced,
//faster enemy, that will miss returning the ball less frequently
class Fast_Opponent_Paddle : public Opponent_Paddle
{
public:
    Fast_Opponent_Paddle();
	void autoMove(Ball *ball);
};

#endif
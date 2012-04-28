#ifndef OPPONENTPADDLE_H
#define OPPONENTPADDLE_H

#include "ball.h"
#include "paddle.h"

//the Opponent_Paddle class is the base level enemy
//it is relatively slow and inaccurate compared to it's child classes
class Opponent_Paddle : public Paddle
{
public:
    Opponent_Paddle();
	void resetState();
	virtual void autoMove(Ball *ball);
};

#endif

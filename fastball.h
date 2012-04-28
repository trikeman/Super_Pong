#ifndef FASTBALL_H
#define FASTBALL_H

#include "ball.h"

//the Fast_Ball class is a ball that has the "fast" powerup,
//which increases the speed of the ball
class Fast_Ball : public Ball
{
public:
    Fast_Ball(Ball *ball);
	void autoMove();
};

#endif // FASTBALL_H

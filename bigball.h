#ifndef BIGBALL_H
#define BIGBALL_H

#include "ball.h"

//the Big_Ball class is a Ball that has gained the "big" powerup,
//and will be larger
class Big_Ball : public Ball
{
public:
    Big_Ball(Ball *ball);
};

#endif // BIGBALL_H

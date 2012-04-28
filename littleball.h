#ifndef LITTLEBALL_H
#define LITTLEBALL_H

#include "ball.h"

//the Little_Ball class is a Ball that has gained the "little" powerup,
//making it smaller
class Little_Ball : public Ball
{
public:
    Little_Ball(Ball *ball);
};

#endif // LITTLEBALL_H

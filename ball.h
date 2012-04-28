#ifndef BALL_H
#define BALL_H

#include <QImage>
#include <QRect>

//the Ball class keeps track of the ball when it is in its normal state
//it is also the parent class of the "special" balls
class Ball
{
  protected:
	float speed;
	int xdir;
	int ydir;
	int x;
	int y;
	QImage image;
	QRect rect;
  public:
    bool powered;
    Ball();
    Ball(Ball *ball);
	void resetState();
	virtual void autoMove();
	void setXDir(int);
	void setYDir(int);
	void setX(int);
	void setY(int);
    void setSpeed(float);
	int getXDir();
	int getYDir();
	int getX();
	int getY();
    float getSpeed();
	QRect getRect();
	QImage &getImage();
};

#endif

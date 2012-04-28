#ifndef PADDLE_H
#define PADDLE_H

#include <QImage>
#include <QRect>

//the Paddle class is the parent of each type of paddle:
//the player's, the enemy, and the two "advanced" enemy paddles
class Paddle
{
  protected:
	int x;
	int y;
	QRect rect;
	QImage image;
  public:
    Paddle();
	virtual void resetState() =0;
	void moveLeft(int);
	void moveRight(int);
	void setX(int);
	void setY(int);
	int getX();
	int getY();
	QRect getRect();
	QImage & getImage();
};

#endif
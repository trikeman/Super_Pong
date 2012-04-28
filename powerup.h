#ifndef POWERUP_H
#define POWERUP_H

#include <QImage>
#include <QRect>

//the Powerup class contains all the types of powerups that can change the ball
class Powerup
{
  protected:
    int x;
	int y;
	int type;
	bool visible;
	QRect rect;
    QImage image;
  public:
    Powerup();
	void move();
	void makeVisible();
	bool isVisible();
	int getType();
    QRect getRect();
    QImage & getImage();
};

#endif

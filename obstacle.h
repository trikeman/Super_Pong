#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <QImage>
#include <QRect>

//an Obstacle is an object that blocks part of the play field
//it appears in levels 2 and 3 (and the repeats of these levels as the game goes on)
//in order to change the dynamics of gameplay
class Obstacle
{
  private:
	int x;
	int y;
	QImage image;
	QRect rect;
  public:
   Obstacle(int, int);
   void setRect(QRect);
   QRect getRect();
   QImage & getImage();
};

#endif
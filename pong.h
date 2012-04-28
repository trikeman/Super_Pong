#ifndef PONG_H
#define PONG_H

#include "ball.h"
#include "bigball.h"
#include "littleball.h"
#include "fastball.h"
#include "paddle.h"
#include "playerpaddle.h"
#include "opponentpaddle.h"
#include "fastopponentpaddle.h"
#include "fastopponentpaddle.h"
#include "accurateopponentpaddle.h"
#include "powerup.h"
#include "littlepowerup.h"
#include "fastpowerup.h"
#include "bigpowerup.h"
#include "obstacle.h"
#include <QWidget>
#include <QKeyEvent>
#include <vector>

class Pong : public QWidget
{
  Q_OBJECT
  
  private:
    //int level;
	int x;
	int timerId;
	int playerScore;
	int enemyScore;
	Ball *ball;
	Player_Paddle *player;
	Opponent_Paddle *enemy;
    //std::vector<Obstacle *> obstacles;
    Powerup *powerup;
	bool gameOver;
	bool gameWon;
	bool gameStarted;
	bool paused;
  protected:
    void paintEvent(QPaintEvent *event);
	void timerEvent(QTimerEvent *event);
	void keyPressEvent(QKeyEvent *event);
	void startGame();
	void pauseGame();
	void stopGame();
	void levelUp();
	void checkCollision();
  public:
    Pong(QWidget *parent = 0);
	~Pong();
};

#endif

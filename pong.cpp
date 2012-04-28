#include "pong.h"
#include <QPainter>
#include <QApplication>
#include <ctime>
#include <cstdlib>

Pong::Pong(QWidget *parent) : QWidget(parent)
{
  //level = 1;
  x =0;
  playerScore = 0;
  enemyScore = 0;
  gameOver = FALSE;
  gameWon = FALSE;
  paused = FALSE;
  gameStarted = FALSE;
  ball = new Ball();
  player = new Player_Paddle();
  enemy = new Opponent_Paddle();
  srand(time(NULL));
  if(rand()%3 == 0)
    powerup = new Big_Powerup;
  else if(rand()%3 == 1)
    powerup = new Fast_Powerup;
  else
    powerup = new Little_Powerup;
}

Pong::~Pong()
{
  delete ball;
  delete player;
  delete enemy;
  delete powerup;
  //while(!obstacles.empty())
  //{
      //delete obstacles[0];
  //}
}

void Pong::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  
  if(gameOver)
  {
    QFont font("Courier", 15, QFont::DemiBold);
	QFontMetrics fm(font);
	int textWidth = fm.width("Game Over!");
	
	painter.setFont(font);
	int h = height();
	int w = width();
	
	painter.translate(QPoint(w/2, h/2));
	painter.drawText(-textWidth/2, 0, "Game Over!");
  }
  
  else if(gameWon)
  {
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Victory!");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, "Victory!");
  }
	
  else
  {
    painter.drawImage(ball->getRect(), ball->getImage());
	painter.drawImage(player->getRect(), player->getImage());
	painter.drawImage(enemy->getRect(), enemy->getImage());
    /*if(level%3 != 1)
	{
	  for(int i=0; i<obstacles.size(); i++)
		painter.drawImage(obstacles[i]->getRect(), obstacles[i]->getImage());
    }*/
    if(powerup->isVisible())
      painter.drawImage(powerup->getRect(), powerup->getImage());
  }
}

void Pong::timerEvent(QTimerEvent *event)
{
  ball->autoMove();
  enemy->autoMove(ball);
  if(!powerup->isVisible())
  {
    srand(time(NULL));
    if(!ball->powered)
    {
      if(rand()%40 == 0)
        powerup->makeVisible();
    }
  }
  checkCollision();
  repaint();
}

void Pong::keyPressEvent(QKeyEvent *event)
{
  switch(event->key())
  {
    case Qt::Key_Left:
      player->moveLeft(5);
	  break;
	case Qt::Key_Right:
	  player->moveRight(5);
	  break;
	case Qt::Key_P:
	  pauseGame();
	  break;
	case Qt::Key_Space:
	  startGame();
	  break;
	case Qt::Key_Escape:
	  qApp->exit();
	  break;
	default:
	  QWidget::keyPressEvent(event);
  }
}

void Pong::startGame()
{
  if(!gameStarted)
  {
    ball->resetState();
	player->resetState();
	enemy->resetState();
	gameOver = FALSE;
	gameWon = FALSE;
	gameStarted = TRUE;
	timerId = startTimer(10);
  }
}

void Pong::pauseGame()
{
  if(paused)
  {
    timerId = startTimer(10);
	paused = FALSE;
  }
  else
  {
    paused = TRUE;
	killTimer(timerId);
  }
}

void Pong::stopGame()
{
  enemyScore++;
  ball->resetState();
  enemy->resetState();
  player->resetState();
  if(ball->powered)
  {
    Ball *temp;
    temp = ball;
    delete ball;
    ball = new Ball(temp);
  }
  if(enemyScore >= 3)
  {
    killTimer(timerId);
	gameOver = TRUE;
	gameStarted = FALSE;
	enemyScore = 0;
	playerScore = 0;
  }
}

void Pong::levelUp()
{
  playerScore++;
  ball->resetState();
  enemy->resetState();
  player->resetState();
  if(ball->powered)
  {
    Ball *temp;
    temp = ball;
    delete ball;
    ball = new Ball(temp);
  }
  if(playerScore >= 3)
  {
      killTimer(timerId);
      gameWon = TRUE;
      gameStarted = FALSE;
      enemyScore = 0;
      playerScore = 0;
  }
}

void Pong::checkCollision()
{
  if(ball->getRect().bottom()>800)
    stopGame();
  if(ball->getRect().top()<0)
    levelUp();

  if(powerup->isVisible())
  {
    if((ball->getRect()).intersects(powerup->getRect()))
    {
      Ball *temp;

      temp = ball;
      delete ball;
      if(powerup->getType() == 1)
        ball = new Big_Ball(temp);
      else if(powerup->getType() == 2)
        ball = new Fast_Ball(temp);
      else if(powerup->getType() == 3)
        ball = new Little_Ball(temp);
      else
        ball = new Ball(temp);
      delete powerup;

      srand(time(NULL));
      if(rand()%3 == 0)
        powerup = new Big_Powerup;
      else if(rand()%3 == 1)
        powerup = new Fast_Powerup;
      else
        powerup = new Little_Powerup;
    }
  }
  if((ball->getRect()).intersects(player->getRect()))
  {
    int playerLPos = player->getRect().left();
	int ballLPos = ball->getRect().left();
	
    int first = playerLPos + 32;
    int second = playerLPos + 64;
    int third = playerLPos + 96;
    int fourth = playerLPos + 128;
	
	if(ballLPos < first)
	{
	  ball->setXDir(-1);
	  ball->setYDir(-1);
      ball->setSpeed(.1);
	}
	else if(ballLPos < second)
	{
	  ball->setXDir(0);
	  ball->setYDir(-1*ball->getYDir());
      ball->setSpeed(.1);
	}
	else if(ballLPos < third)
	{
	  ball->setXDir(0);
	  ball->setXDir(-1);
      ball->setSpeed(.1);
	}
    else if(ballLPos < fourth)
	{
	  ball->setXDir(1);
	  ball->setYDir(-1*ball->getYDir());
      ball->setSpeed(.1);
	}
	else
	{
	  ball->setXDir(1);
	  ball->setYDir(-1);
      ball->setSpeed(.1);
	}
  }
  
  if((ball->getRect()).intersects(enemy->getRect()))
  {
    int enemyLPos = enemy->getRect().left();
    int ballLPos = ball->getRect().left();
	
    int first = enemyLPos + 32;
    int second = enemyLPos + 64;
    int third = enemyLPos + 96;
    int fourth = enemyLPos + 128;
	
    if(ballLPos < first)
	{
	  ball->setXDir(-1);
	  ball->setYDir(1);
      ball->setSpeed(.1);
	}
    else if(ballLPos < second)
	{
	  ball->setXDir(0);
      ball->setYDir(-1*ball->getYDir());
      ball->setSpeed(.1);
	}
    else if(ballLPos < third)
	{
	  ball->setXDir(0);
	  ball->setXDir(1);
      ball->setSpeed(.1);
	}
    else if(ballLPos < fourth)
	{
	  ball->setXDir(1);
      ball->setYDir(-1*ball->getYDir());
      ball->setSpeed(.1);
	}
	else
	{
	  ball->setXDir(1);
	  ball->setYDir(1);
      ball->setSpeed(.1);
    }
  }
}

#include "pong.h"
#include <QDesktopWidget>
#include <QApplication>

void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 600;
  int HEIGHT = 800;


  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();

  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
  widget.setFixedSize(WIDTH, HEIGHT);
}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  Pong window;

  window.setWindowTitle("Super Pong");
  window.show();
  center(window);

  return app.exec();
}

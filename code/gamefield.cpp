#include "gamefield.h"

GameField::GameField()
{

}

void GameField::fieldSize(int x, int y)
{
   fieldWidth=x;
   fieldHeight=y;
   field.resize(fieldWidth);
   for(auto it:field){
       it.resize(fieldHeight);
   }
}

void GameField::fieldSettings(int type, int speed)
{
    gameType=type;
    snakeSpeed=speed;
    snake=new Snake(fieldWidth, fieldHeight);
    updateTimer=new QTimer();
    updateTimer->start(1000/speed);
    QObject::connect(updateTimer,SIGNAL(timeout()),this,SLOT(update()));
}


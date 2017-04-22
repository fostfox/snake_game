#include "gamefield.h"

GameController::GameController()
{

}

const QVector<QVector<GameController::ObjectType> >& GameController::getField()
{
    return field;
}

void GameController::startGame()
{
    //Создаем змейку
    snake=new Snake(fieldWidth, fieldHeight);
    if(gameType==0){
        for(int i(0);i<fieldWidth;i++){
            for(int j(0);j<fieldHeight;j++){
                if(i==0 || j==0 ||i==(fieldWidth-1)||j==(fieldHeight-1))
                    field[i][j]=fWall;
                else
                    field[i][j]=fEmpty;
            }
        }
    }else if(gameType==1){
        for(int i(0);i<fieldWidth;i++){
            for(int j(0);j<fieldHeight;j++){

            }
        }
    }
    updateTimer=new QTimer();
    QObject::connect(updateTimer,SIGNAL(timeout()),this,SLOT(update()));
    QObject::connect(updateTimer,SIGNAL(timeout()),this,SLOT(draw()));
    updateTimer->start(1000/speed);
}

void GameController::fieldSize(int x, int y)
{
   fieldWidth=x;
   fieldHeight=y;
   field.resize(fieldWidth);
   for(auto it:field){
       it.resize(fieldHeight);
   }
}

void GameController::fieldSettings(int type, int speed)
{
    gameType=type;
    snakeSpeed=speed;
}

void GameController::update()
{
snake->move();
vector<Point> coordSnake=snake->getCoordinates();

}


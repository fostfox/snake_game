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
    //Заполняем поле значениями в зависимости от режима игры
    if(gameType==0){    //Аркадный
        for(int i(0);i<fieldWidth;i++){
            for(int j(0);j<fieldHeight;j++){
                if(i==0 || j==0 ||i==(fieldWidth-1)||j==(fieldHeight-1))
                    field[i][j]=fWall;
                else
                    field[i][j]=fEmpty;
            }
        }
    }else if(gameType==1){      //Свободный
        for(int i(0);i<fieldWidth;i++){
            for(int j(0);j<fieldHeight;j++){
                 field[i][j]=fEmpty;
            }
        }
    }
    //Получаем данные о змейке
    vector<Point> coordSnake=snake->getCoordinates();
    for(int i(0);i<coordSnake.size();i++){
        field[coordSnake[i].x][coordSnake[i].y]=fSnake;
    }
    //Получаем данные о бонусах

    //Создаем таймер и конектим его с интервалом вычеслинным относительно скорости
    updateTimer=new QTimer();
    QObject::connect(updateTimer,SIGNAL(timeout()),this,SLOT(update()));
    updateTimer->start(1000/speed);
}

//Слот для получения размера с окна конфигураций
void GameController::fieldSize(int x, int y)
{
   fieldWidth=x;
   fieldHeight=y;
   field.resize(fieldWidth);
   for(auto it:field){
       it.resize(fieldHeight);
   }
}

//Слот для получения типа игры и скорости змейки с окна конфигураций
void GameController::fieldSettings(int type, int speed)
{
    gameType=type;
    snakeSpeed=speed;
}

void GameController::update()
{
snake->move();
vector<Point> coordSnake=snake->getCoordinates();
if(field[coordSnake[i].x][coordSnake[i].y]==fSnake ||
        field[coordSnake[i].x][coordSnake[i].y]==fWall){
    emit gameOver();
}else{

}
emit draw();
}


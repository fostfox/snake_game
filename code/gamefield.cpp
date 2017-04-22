#include "gamefield.h"
//Конструктор по умолчанию
GameController::GameController(){}

//Метод для получения игрвого поля
const QVector<QVector<GameController::ObjectType> >& GameController::getField()
{
    return field;
}

//Метод для начала игры
void GameController::startGame()
{
    //Создаем змейку
    snake=new Snake(fieldWidth, fieldHeight);

    //Получаем данные о бонусах

    //Создаем таймер и конектим его с интервалом вычеслинным относительно скорости
    updateTimer=new QTimer();
    QObject::connect(updateTimer,SIGNAL(timeout()),this,SLOT(update()));
    updateTimer->start(1000/speed);
}

//Метод для получения размера с окна конфигураций
void GameController::setFieldSize(int x, int y)
{
   fieldWidth=x;
   fieldHeight=y;
   field.resize(fieldWidth);
   for(auto it:field){
       it.resize(fieldHeight);
   }
}

//Метод для получения типа игры и скорости змейки с окна конфигураций
void GameController::fieldSettings(int type, int speed)
{
    gameType=type;
    snakeSpeed=speed;
}

int GameController::getScore()
{
    return score;
}

//Метод для обновления информации об состоянии игры
void GameController::update()
{
    //Перемещение
    snake->move();
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
    //Проверяем на столкновение со стеной
    if(field[coordSnake[0].x][coordSnake[0].y]==fSnake ||
            field[coordSnake[0].x][coordSnake[0].y]==fWall){
        emit gameOver();
    }
    //Проверяем на нахождение бонуса
    if(field[coordSnake[0].x][coordSnake[0].y]==fBonus ){
        score++;
        snake->increase();
    }
    //Задаем значения змейки на поле
    for(int i(0);i<coordSnake.size();i++){
        field[coordSnake[i].x][coordSnake[i].y]=fSnake;
    }



    emit draw();
}


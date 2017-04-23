#include "gamefield.h"
//Конструктор по умолчанию
GameController::GameController(QWidget *parent) :
QWidget(parent)
{
    bonusExist=false;
}

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
    srand(time(NULL));

    //Создаем таймер и конектим его с интервалом вычеслинным относительно скорости
    updateTimer=new QTimer();
    QObject::connect(updateTimer,SIGNAL(timeout()),this,SLOT(update()));
    updateTimer->start(1000/snakeSpeed);
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

//Метод возвращающий счет
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
    QVector<Point> coordSnake=snake->getCoordinates();

    //Рандомим положение бонусов
    if(!bonusExist){
        QVector<Point> emptyElements;
        for(int i(0);i<fieldWidth;i++){
            for(int j(0);j<fieldHeight;j++){
                if(field[i][j]==fEmpty)
                    emptyElements.push_back(Point(i,j));
            }
        }
        int bonus=rand()%emptyElements.size();
        field[emptyElements[bonus].x][emptyElements[bonus].y]=fBonus;
        bonusExist=true;
    }

    //Проверяем на столкновение со стеной
    if(field[coordSnake[0].x][coordSnake[0].y]==fSnake ||
            field[coordSnake[0].x][coordSnake[0].y]==fWall){
        emit gameOver();
    }

    //Проверяем на нахождение бонуса
    if(field[coordSnake[0].x][coordSnake[0].y]==fBonus ){
        score++;
        snake->increase();
        bonusExist=false;
    }

    //Задаем значения змейки на поле
    for(int i(0);i<coordSnake.size();i++){
        field[coordSnake[i].x][coordSnake[i].y]=fSnake;
    }


    emit draw();
}

//Отслеживаем нажатие клавиш по смене направления
void GameController::keyPressEvent(QKeyEvent *event){
int key=event->key();
switch(key){
    case Qt::Key_Up:{
        snake->changeDirection(Up);
        break;
    }
    case Qt::Key_Down:{
        snake->changeDirection(Down);
        break;
    }
    case Qt::Key_Left:{
        snake->changeDirection(Left);
        break;
    }
    case Qt::Key_Right:{
        snake->changeDirection(Right);
        break;
    }
}
}


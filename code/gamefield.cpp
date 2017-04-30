#include "gamefield.h"


//Конструктор по умолчанию
GameController::GameController(QSize sizeField_ ,int type_  ,int speed_,int score_,QWidget *parent) :
    QWidget(parent)
  ,bonusExist(false)
  ,fieldWidth(sizeField_.width())
  ,fieldHeight(sizeField_.height())
  ,score(score_)
  ,gameType(type_)
  ,snakeSpeed(speed_)
{
    field.resize(fieldWidth);
    for(auto& it : field){
        it.resize(fieldHeight);
    }
}

//Метод для получения игрвого поля
const QVector<QVector<GameController::ObjectType> >& GameController::getField()
{
    return field;
}

//Метод для начала игры
void GameController::startGame()
{
    srand(time(NULL));
    //Создаем таймер и конектим его с интервалом вычеслинным относительно скорости
    updateTimer=new QTimer();
    QObject::connect(updateTimer,SIGNAL(timeout()),SLOT(update()));
    updateTimer->start(1000/snakeSpeed);
}

void GameController::newGame()
{
    //Создаем змейку
    snake=new Snake(fieldWidth, fieldHeight);
}

void GameController::resumeGame(QVector<QPoint> snake_, int direction_, QPoint posBonus_)
{
    //Создаем змейку
    snake=new Snake(snake_, direction_,fieldWidth, fieldHeight);
    pBonus=posBonus_;
    bonusExist=true;
}


//Метод возвращающий счет
int GameController::getScore()
{
    return score;
}

//Метод для обновления информации об состоянии игры
void GameController::update()
{
    //Получаем данные о змейке
    QVector<QPoint> coordSnake=snake->getCoordinates();

    //Проверяем на столкновение с самим собой
    if(field[coordSnake[0].x()][coordSnake[0].y()]==fSnake){
        emit gameOver();
    }
    //Проверяем на столкновение со стеной
    if( field[coordSnake[0].x()][coordSnake[0].y()]==fWall){
        emit gameOver();
    }

    //Проверяем на нахождение бонуса
    if(field[coordSnake[0].x()][coordSnake[0].y()]==fBonus
            ||field[coordSnake[1].x()][coordSnake[1].y()]==fBonus){
        score++;
        snake->increase();
        bonusExist=false;
    }

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

    //Задаем значения змейки на поле
    for(int i(0);i<coordSnake.size();i++){
        field[coordSnake[i].x()][coordSnake[i].y()]=fSnake;
    }

    //Рандомим положение бонусов
    if(!bonusExist){
        //Возможно потом оптимизируется
        QVector<QPoint> emptyElements;
        for(int i(0);i<fieldWidth;i++){
            for(int j(0);j<fieldHeight;j++){
                if(field[i][j]==fEmpty ) {
                    emptyElements.push_back(QPoint(i,j));
                }
            }
        }
        int bonus=rand()%emptyElements.size();
        field[emptyElements[bonus].x()][emptyElements[bonus].y()]=fBonus;
        pBonus = QPoint(emptyElements[bonus].x(), emptyElements[bonus].y());
        bonusExist=true;
    }else{
        field[pBonus.x()][pBonus.y()] = fBonus;
    }

    //Перемещение
    snake->move();

    //На отрисовку Богдану
    emit draw();
}


//Отслеживаем нажатие клавиш по смене направления
void GameController::keyPress(QKeyEvent *event){
    int key=event->nativeScanCode();
    switch(key){
    case ArrowUp :
    case W: {
        snake->changeDirection(Up);
        break;
    }
    case ArrowDown:
    case S:{
        snake->changeDirection(Down);
        break;
    }
    case ArrowLeft:
    case A:{
        snake->changeDirection(Left);
        break;
    }
    case ArrowRight:
    case D:{
        snake->changeDirection(Right);
        break;
    }
    default:
        break;
    }
}

QSize GameController::getFieldSize() const
{
    return QSize(fieldWidth, fieldHeight);
}

int GameController::getGameMode() const
{
    return gameType;
}

int GameController::getGameSpeed() const
{
    return snakeSpeed;
}

QVector<QPoint> GameController::getSnake() const
{
    return snake->getCoordinates();
}

QPoint GameController::getBonus() const
{
    return pBonus;
}

int GameController::getDirection() const
{
    return snake->getDirection();
}


#ifndef GAMEFIELD_H
#define GAMEFIELD_H
#include <QVector>
#include <QTimer>
#include "snake.h"

class GameField
{
    Q_OBJECT
public:
    GameField();
    enum ObjectType{fSnake,fWall,fBonus};


public slots:
    void fieldSize(int x, int y);
    void fieldSettings(int type, int speed);
private slots:
    void update();
private:
    QVector<QVector<ObjectType>> field;
    int fieldWidth;
    int fieldHeight;
    Snake *snake;
    //Bonus *bonus;
    int gameType;
    int snakeSpeed;
    QTimer *updateTimer;
};

#endif // GAMEFIELD_H

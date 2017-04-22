#ifndef GAMEFIELD_H
#define GAMEFIELD_H
#include <QVector>
#include <QTimer>
#include "snake.h"

class GameController
{
    Q_OBJECT
public:
    GameController();
    enum ObjectType{fEmpty,fSnake,fWall,fBonus};
    const QVector<QVector<ObjectType>>& getField();
    void startGame();
    void setFieldSize(int x, int y);
    void fieldSettings(int type, int speed);
signals:
    void draw();
    void gameOver();
private slots:
    void update();
private:
    QVector<QVector<ObjectType>> field;
    bool isPause;
    int fieldWidth;
    int fieldHeight;
    Snake *snake;
    //Bonus *bonus;
    int score;
    int gameType;
    int snakeSpeed;
    QTimer *updateTimer;
};

#endif // GAMEFIELD_H

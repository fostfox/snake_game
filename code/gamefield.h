#ifndef GAMEFIELD_H
#define GAMEFIELD_H
#include <QVector>
#include <QTimer>
#include "snake.h"
#include <random>
#include <ctime>
#include <QWidget>
#include <QKeyEvent>

#include <QDebug>

class GameController: public QWidget
{
    Q_OBJECT
public:
    GameController(QWidget *parent = 0);
    enum ObjectType{fEmpty,fSnake,fWall,fBonus};
    const QVector<QVector<ObjectType>>& getField();
    void startGame();
    void setFieldSize(int x, int y);
    void fieldSettings(int type, int speed);
    int getScore();
    void keyPress(QKeyEvent *event);

    // TODO: Добавить медоды pauseGame() \ stopGame()

signals:
    void draw();
    void gameOver();
private slots:
    void update();
private:
    QVector<QVector<ObjectType>> field;
    bool bonusExist;
    Point pBonus;
    int fieldWidth;
    int fieldHeight;
    Snake *snake;
    int score;
    int gameType;
    int snakeSpeed;
    QTimer *updateTimer;
};

#endif // GAMEFIELD_H

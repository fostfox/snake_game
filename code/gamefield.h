#ifndef GAMEFIELD_H
#define GAMEFIELD_H
#include <QVector>
#include <QTimer>
#include "snake.h"
#include <random>
#include <ctime>
#include <QWidget>
#include <QKeyEvent>
#include <QSize>
#include <QDebug>

class GameController: public QWidget
{
    Q_OBJECT
public:
    GameController(
    QSize sizeField_
    ,int type_
    ,int speed_
    ,int score_
    ,QWidget *parent = 0
    );
    enum ObjectType{fEmpty,fSnake,fWall,fBonus};
    const QVector<QVector<ObjectType>>& getField();
    void startGame();
    void newGame();
    void resumeGame(QVector<QPoint> snake_, int direction_);
    int getScore();
    void keyPress(QKeyEvent *event);
    enum Keys{ArrowUp=328,W=17,ArrowDown=336,S=31,ArrowRight=333,D=32,ArrowLeft=331,A=30};
    // TODO: Добавить методы pauseGame() \ stopGame()

    QSize getFieldSize() const;
    int getGameMode() const;
    int getGameSpeed() const;
    QVector<QPoint> getSnake() const;
    int getDirection() const;

signals:
    void draw();
    void gameOver();
private slots:
    void update();
private:
    QVector<QVector<ObjectType>> field;
    bool bonusExist;
    QPoint pBonus;
    int fieldWidth;
    int fieldHeight;
    Snake *snake;
    int score;
    int gameType;
    int snakeSpeed;
    QTimer *updateTimer;
};

#endif // GAMEFIELD_H

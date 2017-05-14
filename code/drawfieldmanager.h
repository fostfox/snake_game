#pragma once
#include <QObject>
#include <QVector>
#include <QSize>
#include <QPixmap>
#include <QLabel>
#include <QWidget>

#include "gamefield.h"

class DrawFieldManager : public QObject
{
    Q_OBJECT
public:
    /* Передаем в класс DrawFieldManager widget_игрового_поля и
     * GameController для получения информации об игре
    */
    DrawFieldManager(QWidget *gf, GameController *gc, QSize fieldSize, QObject* parent = 0);

public slots:
    void updateField_type1();
    void updateField_type2();

private:

    QPixmap img_Empty,
            img_Snake2,
            img_Bonus2, img_Bonus,
            img_Wall,
            img_Head_N, img_Head_S, img_Head_W, img_Head_E,
            img_Body_NS, img_Body_WE,
            img_Body_side_NW, img_Body_side_NE, img_Body_side_SW, img_Body_side_SE,
            img_Tail_N, img_Tail_S, img_Tail_W, img_Tail_E;

    QVector<QVector<QLabel*> > imgField; // массив картинок

    GameController* m_gameController;
    QWidget* m_gameField;
    QSize m_fieldSize;      // размер поля, пример: 30*20
    int m_boxSize;       // размер клетки (квадрата) на поле

    int count;

    void loadPictures();

    //New Functoinality
    enum class Direction { N, S, W, E, };
    enum SnakeType { Head_N, Head_S, Head_W, Head_E,
                     Body_NS, Body_WE,
                     Body_side_NW, Body_side_NE, Body_side_SW, Body_side_SE,
                     Tail_N, Tail_S, Tail_W, Tail_E,
                     Empty
                   } ;
    bool isNear_inFree(QPoint current, QPoint near, Direction d);
    SnakeType getElentType(const QVector<QPoint>& vSnake, int i);
};


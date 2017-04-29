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
    void updateField();

private:
    QPixmap imgEmpty;       //HUCK:
    QPixmap imgSnake;
    QPixmap imgBonus;
    QPixmap imgWall;
    QVector<QVector<QLabel*> > imgField; // массив картинок

    GameController* m_gameController;
    QWidget* m_gameField;
    QSize m_fieldSize;      // размер поля, пример: 30*20
    int m_boxSize;       // размер клетки (квадрата) на поле

    int count;
};


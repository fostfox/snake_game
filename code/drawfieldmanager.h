#pragma once
#include <QObject>
#include <QVector>
#include <QFrame>
#include <QSize>
#include <QPixmap>
#include <QLabel>

#include "gamefield.h"
#include "wgt_pages/page_field.h" ///???

class DrawFieldManager : public QObject
{
    Q_OBJECT
public:
    /* Передаем в класс DrawFieldManager widget_игрового_поля и
     * GameController для получения информации об игре
    */
    DrawFieldManager(page_field *gf, GameController *gc, QSize fieldSize, QObject* parent = 0);

public slots:
    void updateField();

private:
    QPixmap imgEmpty;       //HUCK:
    QPixmap imgSnake;
    QPixmap imgBonus;
    QPixmap imgWall;
    QVector<QVector<QLabel*> > imgField; // массив картинок

    GameController* m_gameController;
    page_field* m_page_field;
    QSize m_fieldSize;      // размер поля, пример: 30*20
    double m_boxSize;       // размер клетки (квадрата) на поле

    QFrame* m_gameField ;   // игровое поле для отрисовки

    int count;
};


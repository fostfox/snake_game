#pragma once
#include "gamefield.h"
#include "wgt_pages/page_field.h" ///???
#include <QObject>

class DrawFieldManager
{
    Q_OBJECT
public:
    /* Передаем в класс DrawFieldManager widget_игрового_поля и
     * GameController для получения информации об игре
    */
    DrawFieldManager(const page_field* gf, const GameController* gc);

public slots:
    void updateField();

private:
    GameController* m_gameController;
    page_field* m_gameField;
};

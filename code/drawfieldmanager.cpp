#include "drawfieldmanager.h"

DrawFieldManager::DrawFieldManager(const page_field* gf, const GameController *gc)
    : m_gameField(gf), m_gameController(gc)
{
    //При получении сигнала draw необходимо перерисовать поле
    QObject::connect(m_gc, SIGNAL(draw()), SLOT(updateField()));
}

void DrawFieldManager::updateField()
{
    m_gameField->ui
}

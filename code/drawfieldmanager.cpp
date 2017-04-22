#include "drawfieldmanager.h"
#include <QLabel>

DrawFieldManager::DrawFieldManager(const page_field* gf, const GameController *gc, QSize fieldSize)
    : m_gameField(gf)
    , m_gameController(gc)
    , m_fieldSize(fieldSize)

    //загружаем картинки
    ,imgEmpty(QPixmap("C:/Qt/Projects/Game_snake/code/img/empty.png"))
    ,imgSnake(QPixmap("C:/Qt/Projects/Game_snake/code/img/snakeBody.png"))
    ,imgBonus(QPixmap("C:/Qt/Projects/Game_snake/code/img/bonus1.png"))
    ,imgWall(QPixmap("C:/Qt/Projects/Game_snake/code/img/wall.png"))
{
    m_gameField = m_page_field->getGameField();
    ///При получении сигнала draw необходимо перерисовать поле
    QObject::connect(m_gameController, SIGNAL(draw()), SLOT(updateField()));

    ///получаем разрешение окошка игры
    QSize pageFieldSize = m_page_field->size();
    ///изменяем размер поля в виджете
    m_page_field->setFrameFieldSize(pageFieldSize * 0.8);

    ///вычисляем размер клетки
    m_boxSize = m_page_field->getFrameFieldSize().height() / m_fieldSize.height();


    //--------------------------------------------------------------------------
    //создаем массив картинок для поля
    int numberOfFields = m_fieldSize.height() * m_fieldSize.width();
    for (int i = 0; i < m_fieldSize.width(); ++i) {
        for (int j = 0; j < m_fieldSize.height(); ++j) {
            QLabel* plbl = new QLabel(m_gameField);
            plbl->setPixmap(imgEmpty);
            plbl->setGeometry(i*m_boxSize, j*m_boxSize, m_boxSize, m_boxSize);

            imgField.push_back(plbl);
        }
    }
}

void DrawFieldManager::updateField()
{
    //int newScore = m_gameController->getScore();
    //m_page_field->setScore(newScore);

    ///Получение массива сущностей на поле
    QVector<QVector<GameController::ObjectType> > objFields = m_gameController->getField();

    ///Перерисовка поля
    for (int i = 0; i < m_fieldSize.width(); ++i) {
        for (int j = 0; j < m_fieldSize.height(); ++j) {
            switch (objFields) {
            case GameController::fEmpty : imgField[i*j]->setPixmap(imgEmpty); break;
            case GameController::fSnake : imgField[i*j]->setPixmap(imgSnake); break;
            case GameController::fBonus : imgField[i*j]->setPixmap(imgBonus); break;
            case GameController::fWall  : imgField[i*j]->setPixmap(imgWall);  break;
            }
        }
    }





}

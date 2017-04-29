#include "drawfieldmanager.h"
#include <QLabel>

#include <QDebug>
#include <QMainWindow>

DrawFieldManager::DrawFieldManager(QWidget* gf, GameController *gc, QSize fieldSize, QObject *parent)
    : m_gameField(gf)
    , m_gameController(gc)
    , m_fieldSize(fieldSize)
    , QObject(parent)
    , count(0)

    //загружаем картинки

    ,imgEmpty(QPixmap(":/img/page_field/empty.png"))
    ,imgSnake(QPixmap(":/img/page_field/snakeBody.png"))
    ,imgBonus(QPixmap(":/img/page_field/bonus1.png"))
    ,imgWall(QPixmap(":/img/page_field/wall.png"))

{
    ///При получении сигнала draw необходимо перерисовать поле
    QObject::connect(m_gameController, SIGNAL(draw()), SLOT(updateField()));

    ///Изменяем размер поля
    m_gameField->setFixedSize(dynamic_cast<QMainWindow*>(gf->parent()->parent())->size() * 0.8);

    ///вычисляем размер клетки
    m_boxSize = floor(m_gameField->minimumSize().height() / m_fieldSize.height());

    ///изменяем размер поля в виджете, убирая зазоры
    m_gameField->setFixedSize(QSize(m_boxSize*m_fieldSize.width(), m_boxSize*m_fieldSize.height()));


    //--------------------------------------------------------------------------
    //создаем массив картинок для поля
    for (int i = 0; i < m_fieldSize.width(); ++i) {
        QVector<QLabel*> temp;
        for (int j = 0; j < m_fieldSize.height(); ++j) {
            QLabel* plbl = new QLabel(m_gameField);
            plbl->setPixmap(imgEmpty);
            plbl->setGeometry(i*m_boxSize, j*m_boxSize, m_boxSize, m_boxSize);
            plbl->setScaledContents(true);

            temp.push_back(plbl);
        }
        imgField.push_back(temp);
    }
}

void DrawFieldManager::updateField()
{   ///Получение массива сущностей на поле
    const QVector<QVector<GameController::ObjectType> >& objFields = m_gameController->getField();

    ///Перерисовка поля
    for (int i = 0; i < m_fieldSize.width(); ++i) {
        for (int j = 0; j < m_fieldSize.height(); ++j) {
            switch (objFields[i][j]) {
            case GameController::fEmpty : imgField[i][j]->setPixmap(imgEmpty); break;

            case GameController::fBonus : imgField[i][j]->setPixmap(imgBonus); break;
            case GameController::fSnake : imgField[i][j]->setPixmap(imgSnake); break;
            case GameController::fWall  : imgField[i][j]->setPixmap(imgWall);  break;
            }
        }
    }

   //qDebug() << "Lapse: " << count++ << " ----------------------";

    //for (int i = 0; i < m_fieldSize.width(); ++i) {
    //    for (int j = 0; j < m_fieldSize.height(); ++j) {
    //        switch (objFields[i][j]) {
            //case GameController::fEmpty : qDebug() << "fEmpty"<< i << " " << j; break;
            //case GameController::fSnake : qDebug() << "fSnake" << i << " " << j; break;
            //case GameController::fBonus : qDebug() << "fBonus" << i << " " << j; break;
            //case GameController::fWall  : qDebug() << "fWall" << i << " " << j;  break;
    //        }
    //    }
    //}

}

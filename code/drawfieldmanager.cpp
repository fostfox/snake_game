#include "drawfieldmanager.h"
#include <QLabel>

#include <QDebug>
#include <QMainWindow>
#include <QApplication>

DrawFieldManager::DrawFieldManager(QWidget* gf, GameController *gc, QSize fieldSize, QObject *parent)
    : m_gameField(gf)
    , m_gameController(gc)
    , m_fieldSize(fieldSize)
    , QObject(parent)
    , count(0)
{

    //загружаем картинки
    loadPictures();

    ///При получении сигнала draw необходимо перерисовать поле
    //QObject::connect(m_gameController, SIGNAL(draw()), SLOT(updateField()));

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
            plbl->setPixmap(img_Empty);
            plbl->setGeometry(i*m_boxSize, j*m_boxSize, m_boxSize, m_boxSize);
            plbl->setScaledContents(true);

            temp.push_back(plbl);
        }
        imgField.push_back(temp);
    }
}

void DrawFieldManager::updateField_type1()
{   ///Получение массива сущностей на поле
    const QVector<QVector<GameController::ObjectType> >& objFields = m_gameController->getField();

    ///Перерисовка поля
    for (int i = 0; i < m_fieldSize.width(); ++i) {
        for (int j = 0; j < m_fieldSize.height(); ++j) {
            switch (objFields[i][j]) {
            case GameController::fEmpty : imgField[i][j]->setPixmap(img_Empty); break;
            case GameController::fBonus : imgField[i][j]->setPixmap(img_Bonus); break;
            case GameController::fSnake : imgField[i][j]->setPixmap(img_Snake2); break;
            case GameController::fWall  : imgField[i][j]->setPixmap(img_Wall);  break;
            }
        }
    }
}

void DrawFieldManager::updateField_type2()
{
    const QVector<QPoint> &vSnake = m_gameController->getSnake();
    const QVector<QVector<GameController::ObjectType> >& objFields = m_gameController->getField();

    ///Перерисовка поля (Можно как-то сделать без обновления вего поля?

    for (int i = 0; i < m_fieldSize.width(); ++i) {
        for (int j = 0; j < m_fieldSize.height(); ++j) {
            imgField[i][j]->clear();
        }
    }

    for (int i = 0; i < m_fieldSize.width(); ++i) {
        for (int j = 0; j < m_fieldSize.height(); ++j) {
            switch (objFields[i][j]) {
            case GameController::fBonus : imgField[i][j]->setPixmap(img_Bonus); break;
            case GameController::fWall  : imgField[i][j]->setPixmap(img_Wall);  break;
            }
        }
    }

    for (int i(0); i < vSnake.size(); ++i) {
        switch (getElentType(vSnake, i)) {
        case Head_N :       imgField[vSnake[i].x()][vSnake[i].y()]->setPixmap(img_Head_N); break;
        case Head_S :       imgField[vSnake[i].x()][vSnake[i].y()]->setPixmap(img_Head_S); break;
        case Head_W :       imgField[vSnake[i].x()][vSnake[i].y()]->setPixmap(img_Head_W); break;
        case Head_E :       imgField[vSnake[i].x()][vSnake[i].y()]->setPixmap(img_Head_E); break;
        case Body_NS :      imgField[vSnake[i].x()][vSnake[i].y()]->setPixmap(img_Body_NS); break;
        case Body_WE :      imgField[vSnake[i].x()][vSnake[i].y()]->setPixmap(img_Body_WE); break;
        case Body_side_NW : imgField[vSnake[i].x()][vSnake[i].y()]->setPixmap(img_Body_side_NW); break;
        case Body_side_NE : imgField[vSnake[i].x()][vSnake[i].y()]->setPixmap(img_Body_side_NE); break;
        case Body_side_SW : imgField[vSnake[i].x()][vSnake[i].y()]->setPixmap(img_Body_side_SW); break;
        case Body_side_SE : imgField[vSnake[i].x()][vSnake[i].y()]->setPixmap(img_Body_side_SE); break;
        case Tail_N :       imgField[vSnake[i].x()][vSnake[i].y()]->setPixmap(img_Tail_N); break;
        case Tail_S :       imgField[vSnake[i].x()][vSnake[i].y()]->setPixmap(img_Tail_S); break;
        case Tail_W :       imgField[vSnake[i].x()][vSnake[i].y()]->setPixmap(img_Tail_W); break;
        case Tail_E :       imgField[vSnake[i].x()][vSnake[i].y()]->setPixmap(img_Tail_E); break;
        case Empty :        imgField[vSnake[i].x()][vSnake[i].y()]->setPixmap(img_Empty); break;
    }
    }
}

void DrawFieldManager::loadPictures()
{
    img_Empty = QPixmap(":/img/page_field/empty.png");
    img_Snake2 = QPixmap(":/img/page_field/snakeBody2.png");
    img_Bonus = QPixmap(":/img/page_field/bonus1.png");
    img_Wall = QPixmap(":/img/page_field/wall.png");

    img_Head_N = QPixmap(":/img/page_field/Head_N.png");
    img_Head_S = QPixmap(":/img/page_field/Head_S.png");
    img_Head_W = QPixmap(":/img/page_field/Head_W.png");
    img_Head_E = QPixmap(":/img/page_field/Head_E.png");
    img_Body_NS = QPixmap(":/img/page_field/Body_NS.png");
    img_Body_WE = QPixmap(":/img/page_field/Body_WE.png");
    img_Body_side_NW = QPixmap(":/img/page_field/Body_side_NW.png");
    img_Body_side_NE = QPixmap(":/img/page_field/Body_side_NE.png");
    img_Body_side_SW = QPixmap(":/img/page_field/Body_side_SW.png");
    img_Body_side_SE = QPixmap(":/img/page_field/Body_side_SE.png");
    img_Tail_N = QPixmap(":/img/page_field/Tail_N.png");
    img_Tail_S = QPixmap(":/img/page_field/Tail_S.png");
    img_Tail_W = QPixmap(":/img/page_field/Tail_W.png");
    img_Tail_E = QPixmap(":/img/page_field/Tail_E.png");
}

bool DrawFieldManager::isNear_inFree(QPoint current, QPoint near, DrawFieldManager::Direction d)
{
    // для проверки приводит current индекс к возможному near и проверяет на равенство

    int maxFieldH = m_fieldSize.height()-1;
    int minFieldH = 0;
    int maxFieldW = m_fieldSize.width()-1;
    int minFieldW = 0;

    switch (d) {
    case Direction::N :
        if (current.y() - 1 < minFieldH) {
            current.ry() = maxFieldH;
        } else {
            current.ry()--;
        }
        ///qDebug() << " > isNear_inFree -> Direction::N";
        break;
    case Direction::S :
        if (current.y() + 1 > maxFieldH) {
            current.ry() = minFieldH;
        } else {
            current.ry()++;
        }
        ///qDebug() << " > isNear_inFree -> Direction::S";
        break;
    case Direction::W :
        if (current.x() - 1 < minFieldW) {
            current.rx() = maxFieldW;
        } else {
            current.rx()--;
        }
        ///qDebug() << " > isNear_inFree -> Direction::W";
        break;
    case Direction::E :
        if (current.x() + 1 > maxFieldW) {
            current.rx() = minFieldW;
        } else {
            current.rx()++;
        }
        ///qDebug() << " > isNear_inFree -> Direction::E";
        break;
    }

    ///qDebug() << " >> " << bool(current == near);
    return current == near;
}

DrawFieldManager::SnakeType DrawFieldManager::getElentType(const QVector<QPoint> &vSnake, int i)
{
    const int N = vSnake.size();
    //qDebug() << N << " " << i;

    if (i == 0) /*HEAD*/ {
        if (isNear_inFree(vSnake[0], vSnake[1], Direction::N)) { return Head_S; }
        if (isNear_inFree(vSnake[0], vSnake[1], Direction::S)) { return Head_N; }
        if (isNear_inFree(vSnake[0], vSnake[1], Direction::W)) { return Head_E; }
        if (isNear_inFree(vSnake[0], vSnake[1], Direction::E)) { return Head_W; }

    } else if (i < N - 1) /*BODY*/ {
        Direction dirFrom, dirTo;

        if (isNear_inFree(vSnake[i], vSnake[i - 1], Direction::N)) { dirFrom = Direction::N; }
        if (isNear_inFree(vSnake[i], vSnake[i - 1], Direction::S)) { dirFrom = Direction::S; }
        if (isNear_inFree(vSnake[i], vSnake[i - 1], Direction::W)) { dirFrom = Direction::W; }
        if (isNear_inFree(vSnake[i], vSnake[i - 1], Direction::E)) { dirFrom = Direction::E; }

        if (isNear_inFree(vSnake[i], vSnake[i + 1], Direction::N)) { dirTo = Direction::N; }
        if (isNear_inFree(vSnake[i], vSnake[i + 1], Direction::S)) { dirTo = Direction::S; }
        if (isNear_inFree(vSnake[i], vSnake[i + 1], Direction::W)) { dirTo = Direction::W; }
        if (isNear_inFree(vSnake[i], vSnake[i + 1], Direction::E)) { dirTo = Direction::E; }

        //Было бы удобно работать с битовыми флагами
        if (dirFrom == Direction::N && dirTo == Direction::S
            || dirFrom == Direction::S && dirTo == Direction::N) {
            return Body_NS; }
        if (dirFrom == Direction::W && dirTo == Direction::E
            || dirFrom == Direction::E && dirTo == Direction::W) {
            return Body_WE; }
        if (dirFrom == Direction::N && dirTo == Direction::W
            || dirFrom == Direction::W && dirTo == Direction::N) {
            return Body_side_NW;
        }
        if (dirFrom == Direction::N && dirTo == Direction::E
            || dirFrom == Direction::E && dirTo == Direction::N) {
            return Body_side_NE;
        }
        if (dirFrom == Direction::S && dirTo == Direction::W
            || dirFrom == Direction::W && dirTo == Direction::S) {
            return Body_side_SW;
        }
        if (dirFrom == Direction::S && dirTo == Direction::E
            || dirFrom == Direction::E && dirTo == Direction::S) {
            return Body_side_SE;
        }

    } else if (i == N - 1) /*TAIL*/ {
        if (isNear_inFree(vSnake[N - 1], vSnake[N - 2], Direction::N)) { return Tail_N; }
        if (isNear_inFree(vSnake[N - 1], vSnake[N - 2], Direction::S)) { return Tail_S; }
        if (isNear_inFree(vSnake[N - 1], vSnake[N - 2], Direction::W)) { return Tail_W; }
        if (isNear_inFree(vSnake[N - 1], vSnake[N - 2], Direction::E)) { return Tail_E; }
    }

    qDebug() << "------------------------";
    qDebug() << "Error: getElentType\n incorrect index 'i'";
    foreach (QPoint var, vSnake) {
        qDebug() << var.x() << " " << var.y();
    }
    return Empty;


}

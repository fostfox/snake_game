#ifndef SNAKE_H
#define SNAKE_H
#include <QVector>
#include <QObject>
#include <QDebug>
#include <QPoint>

enum Direction { Up, Down, Left, Right };

struct Point {
    int x;
    int y;
    Point(int x_,int y_):x(x_),y(y_){}
    Point() : x(0), y(0) {}
};

class Snake : public QObject
{
    Q_OBJECT

public:
    Snake(int p_x, int p_y);
    Snake(const QVector<QPoint>& snake_, int direction_, int p_x, int p_y);
    void increase();
    const QVector<QPoint>& getCoordinates() const;

public slots:
    void move();
    void changeDirection(Direction newDir);

private:
    int max_x,max_y;
    bool readyToInput;
    Direction m_direction;
    const int StartSize=3; /// TODO: Если размер превышает половину ширины поля - ОШИБКА
    QVector<QPoint> m_body;
};

#endif // SNAKE_H

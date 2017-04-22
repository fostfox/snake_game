#ifndef SNAKE_H
#define SNAKE_H
#include <QVector>

struct Point {
    int x;
    int y;
    Point(int x_,int y_):x(x_),y(y_){}
};

class Snake
{
public:
    enum Direction { Up, Down, Left, Right };

    Snake();
    void increase();
    void getCoordinates();

public slots:
    void move();
    void changeDirection(Direction newDir);


private:
    Direction m_direction;
    const int StartSize=3;
    QVector<Point> m_body;
};

#endif // SNAKE_H

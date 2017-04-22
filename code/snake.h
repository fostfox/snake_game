#ifndef SNAKE_H
#define SNAKE_H
#include <QVector>

enum Direction { Up, Down, Left, Right };

struct Point {
    int x;
    int y;
    Point(int x_,int y_):x(x_),y(y_){}
};

class Snake
{
public:

    Snake(int p_x, int p_y);
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

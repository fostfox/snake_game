#ifndef SNAKE_H
#define SNAKE_H
#include <QVector>
#include <QObject>

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
    void increase();
    const QVector<Point>& getCoordinates() const;

public slots:
    void move();
    void changeDirection(Direction newDir);


private:
    int max_x,max_y;
    Direction m_direction;
    const int StartSize=3;
    QVector<Point> m_body;
};

#endif // SNAKE_H

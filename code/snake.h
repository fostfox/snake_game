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

public slots:
    void move(){
        switch(Direction){
        case Up:{
            (m_body[0].y)--;
        }
        case Down:{
            (m_body[0].y)++;
        }
        case Left:{
            (m_body[0].x)--;
        }
        case Right:{
            (m_body[0].x)++;
        }
        }
        for(int i(1);i<m_body.size();i++){
            m_body[i]=m_body[i-1];
        }
    }

    void changeDirection(Direction newDir);

private:
    Direction m_direction;
    const int StartSize=3;
    QVector<Point> m_body;
};

#endif // SNAKE_H

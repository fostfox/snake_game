#include "snake.h"

Snake::Snake(int p_x, int p_y):m_direction(Left){
    for(int i(0);i<StartSize;i++){
        m_body.push_back(Point((p_x/2)+i,(p_y/2)));
    }
}

void Snake::increase(){
    m_body.push_back(m_body[m_body.size()-1]);
}

const vector<Point>& Snake::getCoordinates()
{
    return m_body;
}

void Snake::move(){
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

void Snake::changeDirection(Snake::Direction newDir){
    m_direction=newDir;
}


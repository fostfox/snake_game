#include "snake.h"

Snake::Snake(int p_x, int p_y):m_direction(Left){
   max_x=p_x;
   max_y=p_y;
    for(int i(0);i<StartSize;i++){
        m_body.push_back(Point((p_x/2)+i,(p_y/2)));
    }
}

void Snake::increase(){
    m_body.push_back(m_body[m_body.size()-1]);
}

const QVector<Point>& Snake::getCoordinates() const
{
    return m_body;
}

void Snake::move(){
    switch(m_direction){
    case Up:{
        (m_body[0].y)--;
        if(m_body[0].y<0)
            m_body[0].y=max_y;
        break;
    }
    case Down:{
        (m_body[0].y)++;
        if(m_body[0].y==max_y)
            m_body[0].y=0;
        break;
    }
    case Left:{
        (m_body[0].x)--;
        if(m_body[0].x<0)
            m_body[0].x=max_x;
        break;
    }
    case Right:{
        (m_body[0].x)++;
        if(m_body[0].x==max_x)
            m_body[0].x=0;
        break;
    }
    }
    for(int i(1);i<m_body.size();i++){
        m_body[i]=m_body[i-1];
    }
}

void Snake::changeDirection(Direction newDir){
    switch(newDir){
    case Up:{
        if(m_direction!=Down)
            m_direction=newDir;
        break;
    }
    case Down:{
        if(m_direction!=Up)
            m_direction=newDir;
        break;
    }
    case Left:{
        if(m_direction!=Right)
            m_direction=newDir;
        break;
    }
    case Right:{
        if(m_direction!=Left)
            m_direction=newDir;
        break;
    }
    }


}


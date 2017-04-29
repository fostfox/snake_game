#include "snake.h"

Snake::Snake(int p_x, int p_y):
    m_direction(Left), max_x(p_x), max_y(p_y), readyToInput(true)
{
    for(int i(0);i<StartSize;i++){
        m_body.push_back(QPoint((p_x/2)+i,(p_y/2)));
    }
}

Snake::Snake(const QVector<QPoint> &snake_, int direction_,int p_x, int p_y)
    :max_x(p_x),max_y(p_y),readyToInput(true)
{
    m_body=snake_;
    m_direction=(Direction)direction_;
}

void Snake::increase(){
    m_body.push_back(m_body[m_body.size()-1]);
}

const QVector<QPoint>& Snake::getCoordinates() const
{
    return m_body;
}

int Snake::getDirection()
{
    return static_cast<int>(m_direction);
}

void Snake::move(){
    for(int i(m_body.size()-1); i > 0; i--){
        m_body[i]=m_body[i-1];
    }

    switch(m_direction){
    case Up:{
        (m_body[0].ry())--;
        if(m_body[0].y()<0)
            m_body[0].ry()=max_y-1;
        break;
    }
    case Down:{
        (m_body[0].ry())++;
        if(m_body[0].y()==max_y)
            m_body[0].ry()=0;
        break;
    }
    case Left:{
        (m_body[0].rx())--;
        if(m_body[0].x()<0)
            m_body[0].rx()=max_x-1;
        break;
    }
    case Right:{
        (m_body[0].rx())++;
        if(m_body[0].x()==max_x)
            m_body[0].rx()=0;
        break;
    }
    }
    readyToInput=true;
}

void Snake::changeDirection(Direction newDir){
    if(readyToInput){
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
        readyToInput=false;
    }
}


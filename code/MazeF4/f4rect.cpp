#include "f4rect.h"

F4rect::F4rect()
{

}

bool F4rect::isobstacle()
{
    if(this->pattern ==1)
        return true;
    else
        return false;
}

F4rect::F4rect(qreal x, qreal y,qreal width, qreal height,int Pattern):QRectF(qreal(x),qreal(y),qreal(width),qreal(height))
{
    this->pattern=Pattern;
}

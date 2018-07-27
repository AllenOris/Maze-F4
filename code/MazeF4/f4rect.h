#ifndef F4RECT_H
#define F4RECT_H
#include <QRectF>

class F4rect:public QRectF
{
protected:
    int pattern;
public:
    F4rect();
    F4rect(qreal,qreal,qreal,qreal,int);
    bool isobstacle();
};

#endif // F4RECT_H


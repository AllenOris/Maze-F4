#ifndef F4MAZEMAPPLUS_H
#define F4MAZEMAPPLUS_H
#include "f4mazemap.h"
#include "f4rect.h"
#include "f4point.h"
#include <QRectF>

class F4mazemapPlus:public F4mazemap
{
protected:
    int left,right,up,down;
    void loadmap();
    int origin_width,origin_height;
public:
    QVector<F4rect> Rec;
    int total_width, total_height;
    F4mazemapPlus();
    F4mazemapPlus(int,int);
    void setsize(int,int);
    void setlocaltion(QRectF);
    F4point topoint(int);
    QVector<int> findfullpath(int);
    int turnplus(int);
    int turnorigin(int);
    ~F4mazemapPlus();
};


#endif // F4MAZEMAPPLUS_H

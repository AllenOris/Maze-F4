#ifndef F4MAZEMAP_H
#define F4MAZEMAP_H
#include <QVector>
#include "F4point.h"
#include "F4edge.h"

class F4mazemap
{
private:
    int max_width,max_height;
    int min_widht,min_height;
    int width,height;
    void make_edge();
    void Kruskal();
    int union_find(int,QVector<int>&);//并查集查询
public:
    QVector <F4edge> e;   //边集
    QVector <QVector<int> > tree;//树
    F4mazemap(int Height=10,int Width=10);
    F4point topoint(int);
};

#endif // F4MAZEMAP_H

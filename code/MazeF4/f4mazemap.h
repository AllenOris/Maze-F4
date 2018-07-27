#ifndef F4MAZEMAP_H
#define F4MAZEMAP_H

#include <QVector>
#include <QList>
#include "F4point.h"
#include "F4edge.h"

class F4mazemap
{
protected:
    int max_width,max_height;
    int min_widht,min_height;
    void make_edge();
    void Kruskal();
    void Prime();
    int union_find(int,QVector<int>&);//并查集查询
    QVector <QVector<F4edge> > point_connect;
    QVector <F4edge> e;   //边集
public:
    int width,height;
    QVector <bool> line;
    QVector <bool> col;
    QVector <QVector<int> > tree;//树
    QVector <int> path;
    F4mazemap(int Height=10,int Width=10);
    F4point topoint(int);
    QSet<int> vectoset(QVector<int>&);
    void turntomap();
    void clearall();
    void findpath();
    QVector<int> findpath(int);
    ~F4mazemap();
};

#endif // F4MAZEMAP_H

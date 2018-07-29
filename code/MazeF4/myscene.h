#ifndef MYSCENE_H
#define MYSCENE_H
#include<QGraphicsScene>
#include <QScreen>
#include <QGuiApplication>
#include <QCursor>
#include <QApplication>
#include<QList>
#include<QPointF>
#include"myitem.h"
#include"music.h"
class MyScene:public QGraphicsScene
{
    int id_exit;
public:
    MyScene(music *p,QApplication*a);
    int W,H;
    MyItem *item;
    music *mus;
    QApplication*a;

protected:
    void timerEvent(QTimerEvent *event);
};

#endif // MYSCENE_H

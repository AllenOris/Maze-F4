#ifndef F4SETSCENE_H
#define F4SETSCENE_H


#include<QGraphicsScene>
#include <QScreen>
#include <QGuiApplication>
#include <QCursor>
#include <QApplication>
#include"f4setitem.h"
#include"music.h"
#include"f4overall.h"
class SetScene:public QGraphicsScene
{
public:
    SetScene(music *p,QApplication*a);
    int W,H;
    SetItem *item;
    music *mus;
};


#endif // F4SETSCENE_H

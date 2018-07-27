#ifndef MYVIEW_H
#define MYVIEW_H
#include <QGraphicsView>
#include "myscene.h"
#include"f4setscene.h"
class MyView:public QGraphicsView
{
    Q_OBJECT
public:
    MyView(music *p,QApplication*a);
    MyScene* beg_scene;
    SetScene* set_scene;
    //f4mapscene* map_scene;
    music *mus;
    QApplication*a;
protected:
    void timerEvent(QTimerEvent *event);
};

#endif // MYVIEW_H

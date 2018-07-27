#include "myview.h"

MyView::MyView(music *p,QApplication*a):a(a)
{
    mus=p;
    this->startTimer(100);
    beg_scene = new MyScene(mus,a);
    set_scene = new SetScene(mus,a);

    beg_scene->setItemIndexMethod(QGraphicsScene::BspTreeIndex);
    // 视图关联场景
    this->setScene(beg_scene);
}

void MyView::timerEvent(QTimerEvent *event)
{
    QPointF p1(beg_scene->W*0.8,beg_scene->H*0.75);
    QTransform transform;
    transform.rotate(+0.0);
    MyItem* item1=(MyItem*)beg_scene->itemAt(p1,transform);
    QPointF p3(beg_scene->W*0.55,beg_scene->H*0.2);
    MyItem* item3=(MyItem*)beg_scene->itemAt(p3,transform);
    QPointF p2(set_scene->W*0,set_scene->H*0.75);
    SetItem* item2=(SetItem*)set_scene->itemAt(p2,transform);
    if(item1->setting_press)
    {
        this->setScene(set_scene);
        item1->setting_press=false;
    }
    if(item2->exit_press)
    {
        this->setScene(beg_scene);
        item2->exit_press=false;
    }
    if(item3->start_press)
    {
        //this->setScene(map_scene);
        item3->start_press=false;
    }
}

#include "myview.h"

MyView::MyView(music *p,QApplication*a):a(a)
{
    mus=p;
    this->startTimer(100);
    beg_scene = new MyScene(mus,a);
    set_scene = new SetScene(mus,a);
    this->demo_scene=NULL;
    this->map_scene=NULL;
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
    QPointF p4(set_scene->W*0.43,set_scene->H*0.715);
    SetItem* item4=(SetItem*)set_scene->itemAt(p4,transform);
    int w=w0*10+w1,h=h0*10+h1;
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
        if(map_scene!=NULL){
            delete map_scene;
            map_scene=NULL;
        }
        map_scene=new F4MazeScene(w,h);
        this->setScene(map_scene);
        item3->start_press=false;
    }
    if(item4->demo_press)
    {
        if(demo_scene!=NULL){
            delete demo_scene;
            demo_scene=NULL;
        }
        demo_scene=new F4MazeDemo(w,h,this);
        this->setScene(demo_scene);
        item4->demo_press=false;
    }
    if(map_scene!=NULL&&map_scene->ExitFlag)
    {
        this->setScene(beg_scene);
        map_scene->ExitFlag=false;
    }
    if(map_scene!=NULL&&map_scene->next_maze==true){
        if(map_scene!=NULL){
            delete map_scene;
            map_scene=NULL;
        }
        map_scene=new F4MazeScene(w,h);
        this->setScene(map_scene);
        item3->start_press=false;
    }
    if(demo_scene!=NULL&&demo_scene->ExitFlag){
        this->setScene(beg_scene);
        demo_scene->ExitFlag=false;
    }

}

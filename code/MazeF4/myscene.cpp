#include "myscene.h"
#include <QGraphicsView>
MyScene::MyScene(music *p,QApplication*a):a(a)
{
    mus=p;
    W=QGuiApplication::primaryScreen()->availableGeometry().width();
    H=QGuiApplication::primaryScreen()->availableGeometry().height();
    setSceneRect(0,0,W,H);
    this->startTimer(100);
    item = new MyItem(":/new/f4resource/image/resource/background2.jpg",0,0,mus,true,0,a);
    this->addItem(item);
    item = new MyItem(":/new/f4resource/image/resource/start.png",0.55,0.2,mus,false,1,a);
    // 项添加到场景
     this->addItem(item);
    // 视图
    item = new MyItem(":/new/f4resource/image/resource/exit.png",0.01,0.75,mus,false,2,a);
    this->addItem(item);
    item = new MyItem(":/new/f4resource/image/resource/about.png",0.05,0.05,mus,false,3,a);
    this->addItem(item);
    item = new MyItem(":/new/f4resource/image/resource/title1.png",0.1,0.2,mus,false,4,a);
    this->addItem(item);
    item = new MyItem(":/new/f4resource/image/resource/title2.png",0.25,0.45,mus,false,5,a);
    this->addItem(item);
    item = new MyItem(":/new/f4resource/image/resource/setting.png",0.8,0.75,mus,false,6,a);
    this->addItem(item);
    mus->set_index(3);
    mus->setvol(50);
    mus->set_model(QMediaPlaylist::CurrentItemInLoop);

}

void MyScene::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==id_exit){
        a->exit();
    }
    QPointF p(0.05*W,0.05*H);
    QTransform transform;
    transform.rotate(+0.0);
    MyItem* item=(MyItem*)this->itemAt(p,transform);
    QPointF p1(0.55*W,0.2*H);
    MyItem* item1=(MyItem*)this->itemAt(p1,transform);
    QPointF p2(0.01*W,0.75*H);
    MyItem* item2=(MyItem*)this->itemAt(p2,transform);
    QPointF p3(0.1*W,0.2*H);
    MyItem* item3=(MyItem*)this->itemAt(p3,transform);
    QPointF p4(0.25*W,0.45*H);
    MyItem* item4=(MyItem*)this->itemAt(p4,transform);
    QPointF p5(0.8*W,0.75*H);
    MyItem* item5=(MyItem*)this->itemAt(p5,transform);
    MyItem* item6=new MyItem(":/new/f4resource/image/resource/member.png",0.4,0.4,mus,false,1,a);
    QPointF p6(0.01*W,0.75*H);
    MyItem* item_exit=(MyItem*)this->itemAt(p6,transform);

    if(item->about_press&&item1->is_background==false)
    {
        this->removeItem(item1);
        this->removeItem(item2);
        this->removeItem(item3);
        this->removeItem(item4);
        this->removeItem(item5);
        this->addItem(item6);
        item->about_press=false;
    }
    if(item->about_release)
    {
        QPointF p6(0.4*W,0.4*H);
        item6=(MyItem*)this->itemAt(p6,transform);
        this->removeItem(item6);
        item1=new MyItem(":/new/f4resource/image/resource/start.png",0.55,0.2,mus,false,1,a);
        this->addItem(item1);
        item2=new MyItem(":/new/f4resource/image/resource/exit.png",0.01,0.75,mus,false,2,a);
        this->addItem(item2);
        item3=new MyItem(":/new/f4resource/image/resource/title1.png",0.1,0.2,mus,false,4,a);
        this->addItem(item3);
        item4=new MyItem(":/new/f4resource/image/resource/title2.png",0.25,0.45,mus,false,5,a);
        this->addItem(item4);
        item5=new MyItem(":/new/f4resource/image/resource/setting.png",0.8,0.75,mus,false,6,a);
        this->addItem(item5);

        item->about_release=false;
        mus->set_index(3);
        mus->set_model(QMediaPlaylist::CurrentItemInLoop);
    }
    if(item_exit->ExitFlag){
        this->id_exit=this->startTimer(1010);
        item_exit->ExitFlag=false;
    }
}

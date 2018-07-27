#include "f4Setscene.h"
#include "f4overall.h"

int F4vol;
int w0;
int w1;
int h0;
int h1;
SetScene::SetScene(music *p,QApplication*a)
{
    F4vol=50;
    w0=1;
    w1=1;
    h0=1;
    h1=1;
    mus=p;
    W=QGuiApplication::primaryScreen()->availableGeometry().width();
    H=QGuiApplication::primaryScreen()->availableGeometry().height();
    setSceneRect(0,0,W,H);
    //setBackgroundBrush(QPixmap(":/new/f4resource/image/resource/setbg.jpg"));
    item = new SetItem(":/new/f4resource/image/resource/setbg.jpg",0,0,mus,true,0,0);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/BGM.png",0.1,0.3,mus,false,6,a,this);
    // 项添加到场景
      this->addItem(item);
    // 视图
    item = new SetItem(":/new/f4resource/image/resource/exit.png",0,0.75,mus,false,2,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/maps.png",0.1,0.5,mus,false,5,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/on.png",0.3,0.3,mus,false,4,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/off.png",0.7,0.3,mus,false,3,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/size.png",0.3,0.5,mus,false,7,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/type.png",0.3,0.7,mus,false,8,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/Set.png",0.05,0.08,mus,false,9,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/h.png",0.41,0.5,mus,false,10,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/w.png",0.6,0.5,mus,false,11,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/demo.png",0.43,0.715,mus,false,12,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/dark.png",0.64,0.71,mus,false,13,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/plus.png",0.41,0.315,mus,false,14,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/menu.png",0.61,0.325,mus,false,15,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/50.png",0.495,0.30,mus,false,16,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/plus.png",0.5,0.42,mus,false,21,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/plus.png",0.523,0.42,mus,false,22,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/plus.png",0.7,0.42,mus,false,23,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/plus.png",0.723,0.42,mus,false,24,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/menu.png",0.5,0.6,mus,false,25,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/menu.png",0.523,0.6,mus,false,26,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/menu.png",0.7,0.6,mus,false,27,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/menu.png",0.723,0.6,mus,false,28,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/1.png",0.5,0.485,mus,false,29,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/1.png",0.523,0.485,mus,false,30,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/1.png",0.7,0.485,mus,false,31,a,this);
    this->addItem(item);
    item = new SetItem(":/new/f4resource/image/resource/1.png",0.723,0.485,mus,false,32,a,this);
    this->addItem(item);
    mus->set_index(3);
    mus->play();
    mus->set_model(QMediaPlaylist::CurrentItemOnce);
    mus->setvol(F4vol);
}

#include "f4mazescene.h"
#include <QtGlobal>
#include <QDebug>
#include <QPixmap>
#include <QBrush>
#include <QT>
#include <QObject>
#include <QPointF>
#include <QRectF>
#include "f4rect.h"
#include "f4player.h"
#include <QRectF>
#include <QGuiApplication>
#include <QApplication>
#include <QScreen>
#include <QPen>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QGraphicsEffect>
void F4MazeScene::initial()
{
    pix_width=45;

    this->Width=QGuiApplication::primaryScreen()->availableGeometry().width();
    this->Height=QGuiApplication::primaryScreen()->availableGeometry().height();
    //设置边界矩形
    this->setSceneRect(QRectF(0,0,this->Width,this->Height));


    QPixmap bgpix(":/imgs/bg3.jpg");
    QSize *bgsize=new QSize(this->Width,this->Height);
    bgpix=bgpix.scaled(*bgsize);
    this->setBackgroundBrush(bgpix);//背景图

    QPixmap pix;
    QPixmap pix2;
    //this->setSceneRect(QRectF(QPointF(0,0),QPointF(1920,1080)));

    pix.load(":/imgs/road2.png");
    pix2.load(":/imgs/obstacle2.png");


    QSize pixsize(pix_width,pix_width);
    pix=pix.scaled(pixsize);
    pix2=pix2.scaled(pixsize);

    qreal maze_w=mazemap.total_width*pix.width();
    qreal maze_h=mazemap.total_height*pix.height();
    mazemap.setlocaltion(QRectF((this->Width-maze_w)/2,(this->Height-maze_h)/2,maze_w,maze_h));//this->Width*0.1,this->Height*0.1,this->Width*0.8,this->Height*0.8));
    QVector <int>qqq=mazemap.findfullpath(0);
    QSet<int>set=mazemap.vectoset(qqq);

    int len=mazemap.Rec.size();
    for(int i=0;i<len;++i){
//        if(set.find(i)!=set.end()){
//            this->addRect(mazemap.Rec[i],QPen(Qt::black),QBrush(Qt::red));
//        }
       // else
        if(mazemap.Rec[i].isobstacle()){
            QGraphicsPixmapItem *Pix=new QGraphicsPixmapItem(pix2);
            Pix->setPos(mazemap.Rec[i].left(),mazemap.Rec[i].top());
            this->addItem(Pix);
            //this->addRect(mazemap.Rec[i],QPen(Qt::black),QBrush(Qt::black));
        }
        else{
            QGraphicsPixmapItem *Pix=new QGraphicsPixmapItem(pix);
            Pix->setPos(mazemap.Rec[i].left(),mazemap.Rec[i].top());
            this->addItem(Pix);
            // this->addRect(mazemap.Rec[i],QPen(Qt::white),QBrush(Qt::black));
        }
    }

    //添加玩家
    int start=mazemap.total_width;
    player=new F4player(mazemap.Rec[mazemap.total_width],start,this);
    player->setFlag(QGraphicsItem::ItemIsFocusable,true);
    this->addItem(player);

    //添加终点
    int end=mazemap.Rec.size()-mazemap.total_width-1;
    QPixmap pix_final(":/imgs/final.png");
    pix_final=pix_final.scaled(QSize(mazemap.Rec[0].width(),mazemap.Rec[0].height()));
    QGraphicsPixmapItem *final=new QGraphicsPixmapItem(pix_final);
    final->setPos(mazemap.Rec[end].left(),mazemap.Rec[end].top());
    this->addItem(final);

    //计时器
    this->restartTimer();
    cnt=0;
    ScareItem=NULL;

    //退出按钮
    ExitItem =new QGraphicsPixmapItem(QPixmap(":/imgs/exit.png"));
    ExitItem->setPos(0,this->Height*0.5);
    this->addItem(ExitItem);
    ExitFlag=false;

    //下一个
    this->next_maze=false;
}

void F4MazeScene::restartTimer()
{
    qDebug()<<"restartTimer";
    this->startTimer(100);
}

void F4MazeScene::timerEvent(QTimerEvent *)
{
    int op=100;
    cnt=(cnt+1)%op;
    qreal maze_w=mazemap.total_width*this->pix_width;
    qreal x=maze_w+(this->Width-maze_w)/2,y=0;

    if(ScareItem){
        delete ScareItem;
        ScareItem=NULL;
    }
    ScareItem=new QGraphicsPixmapItem(QPixmap(":/imgs/scare1.png").scaledToWidth((this->Width-this->pix_width*mazemap.total_width)/2));
    ScareItem->setOpacity(qreal(qMin(cnt,abs(op-cnt)))/100);
    ScareItem->setPos(x,y);
    this->addItem(ScareItem);

}

void F4MazeScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QTransform transform;
    transform.rotate(+0.0);
    if(this->itemAt(QPointF(event->scenePos()),transform)==ExitItem){
        ExitFlag=true;
    }
    QGraphicsScene::mousePressEvent(event);
}

void F4MazeScene::keyPressEvent(QKeyEvent *event)
{
//    qDebug()<<keypressed;
//    if(keypressed)
//        return;
//    this->keypressed=true;

    int num=player->getnum();
    F4point point=mazemap.topoint(num);
    if(event->key()==Qt::Key_A){
        player->setpix(QPixmap(":/imgs/Hero_Left.png"));
        if (point.get_x()>1&&!mazemap.Rec[num-1].isobstacle()){
            player->setpix(QPixmap(":/imgs/Hero_Left.png"));
            player->setnum(num-1);
            player->move(-this->pix_width,0);
        }
    }
    else if(event->key()==Qt::Key_D){
        player->setpix(QPixmap(":/imgs/Hero_Right.png"));
        if (( (point.get_x()==mazemap.total_width-1&&point.get_y()==mazemap.total_height-1)
             ||(point.get_x()<mazemap.total_width-1))&&!mazemap.Rec[num+1].isobstacle()){
            player->setnum(num+1);
            player->move(this->pix_width,0);
        }
    }
    else if(event->key()==Qt::Key_W){
        if (point.get_y()>1&&!mazemap.Rec[num-mazemap.total_width].isobstacle()){
            player->move(0,-this->pix_width);
            player->setnum(num-mazemap.total_width);
        }
    }
    else if(event->key()==Qt::Key_S){
        if (point.get_y()<mazemap.total_height-1&&!mazemap.Rec[num+mazemap.total_width].isobstacle()){
            player->move(0,this->pix_width);
            player->setnum(num+mazemap.total_width);
        }
    }
    this->update();
    if(player->getnum()==mazemap.Rec.size()-1-mazemap.total_width)
        next_maze=true;
    QGraphicsScene::keyPressEvent(event);
}

void F4MazeScene::keyReleaseEvent(QKeyEvent *event)
{
    keypressed=false;
    QGraphicsScene::keyReleaseEvent(event);
}

F4MazeScene::F4MazeScene():mazemap(20,15)
{
    initial();
}

F4MazeScene::F4MazeScene(int height, int width):mazemap(height,width),keypressed(false)
{
    initial();
}


int F4MazeScene::width()
{
    return this->Width;
}

int F4MazeScene::height()
{
    return this->Height;
}


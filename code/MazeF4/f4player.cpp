#include "f4player.h"
#include <QKeyEvent>
#include <Qt>
#include <QDebug>
#include <QPainter>
#include <QTime>
#include <QCoreApplication>
#include <QGraphicsEffect>
void F4player::keyPressEvent(QKeyEvent *)
{
}

F4player::F4player()
{

}

void F4player::setnum(int Num)
{
    this->num=Num;
}

void F4player::move(qreal dx, qreal dy)
{
    //移动动画
    qreal Fx=this->x+dx,Fy=this->y+dy;
    this->x=Fx;
    this->y=Fy;
    father->update();


}

void F4player::setpix(QPixmap newpix)
{
    QSize size=pix.size();
    pix=newpix.scaled(size);
    this->update();
}

int F4player::getnum()
{
    return this->num;
}

F4player::F4player(QRectF &rec,int num, QGraphicsScene *father):num(num),father(father)
{
    //this->setCacheMode(QGraphicsItem::DeviceCoordinateCache);
    this->setZValue(1);//叠放次序
    this->setFlag(QGraphicsItem::ItemIsFocusable,true);
    pix.load(":/imgs/resource/Hero_Right.png");
    pix=pix.scaled(QSize(rec.width(),rec.height()));
    this->x=rec.left();
    this->y=rec.top();
}

QRectF F4player::boundingRect() const
{
    return QRectF(this->x,this->y,this->pix.width(),this->pix.height());
}

void F4player::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(QRectF(this->x,this->y,pix.width(),pix.height()),pix,QRectF(0,0,pix.width(),pix.height()));
}



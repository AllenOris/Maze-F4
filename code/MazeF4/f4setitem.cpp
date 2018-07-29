#include "f4Setitem.h"
#include<QDebug>
#include "f4overall.h"
#include <QPointF>
#include <QTransform>

int F4voltemp;
QRectF SetItem::boundingRect() const
{
    if(is_background)
    {
        return QRectF(0,0,W,H);
    }
    else
    {
        return QRectF(W*address_x,H*address_y,size_w,size_h);
    }

}

void SetItem::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget)
{
    Q_UNUSED(option);  //标明该参数没有使用
    Q_UNUSED(widget);

    if(is_background)
    {
        QPixmap scaledPixmap = pix_pic.scaled(*size);
        painter->drawPixmap(0,0,scaledPixmap,0,0,W,H);
    }
    else if(this->button_fun==16){
        QString temp=QString::number(F4vol);
        pix_pic=QPixmap(":/new/f4resource/image/resource/"+temp+".png");
        painter->drawPixmap(W*address_x,H*address_y,pix_pic,0,0,pix_pic.width(),pix_pic.height());
    }
    else if(this->button_fun==29)
    {
        QString tempw0=QString::number(w0);
        pix_pic=QPixmap(":/new/f4resource/image/resource/"+tempw0+".png");
        painter->drawPixmap(W*address_x,H*address_y,pix_pic,0,0,pix_pic.width(),pix_pic.height());
    }
    else if(this->button_fun==30)
    {
        QString tempw1=QString::number(w1);
        pix_pic=QPixmap(":/new/f4resource/image/resource/"+tempw1+".png");
        painter->drawPixmap(W*address_x,H*address_y,pix_pic,0,0,pix_pic.width(),pix_pic.height());
    }
    else if(this->button_fun==31)
    {
        QString temph0=QString::number(h0);
        pix_pic=QPixmap(":/new/f4resource/image/resource/"+temph0+".png");
        painter->drawPixmap(W*address_x,H*address_y,pix_pic,0,0,pix_pic.width(),pix_pic.height());
    }
    else if(this->button_fun==32)
    {
        QString temph1=QString::number(h1);
        pix_pic=QPixmap(":/new/f4resource/image/resource/"+temph1+".png");
        painter->drawPixmap(W*address_x,H*address_y,pix_pic,0,0,pix_pic.width(),pix_pic.height());
    }

    else
    {
        QSize *size=new QSize(size_w,size_h);
        pix_pic = pix_pic.scaled(*size);
        painter->drawPixmap(W*address_x,H*address_y,pix_pic,0,0,size_w,size_h);
    }
}

SetItem::SetItem(QString file_n,double ad_x,double ad_y,music *p,bool back,int button,QApplication*a,QGraphicsScene*father):a(a),father(father)
{
    this->setAcceptHoverEvents(true);
    file_name=file_n;
    address_x=ad_x;
    address_y=ad_y;
    mus=p;
    is_background=back;
    button_fun=button;
    pix_cur.load(":/new/f4resource/image/resource/cursor.png");
    pix_wait.load(":/new/f4resource/image/resource/cursor_wait.png");
    pix_pic.load(file_name);
    size_h=pix_pic.height();
    size_w=pix_pic.width();
    MyCursor = QCursor(pix_cur,-1,-1);
    setCursor(MyCursor);
    MyCursor_wait = QCursor(pix_wait,-1,-1);
    W=QGuiApplication::primaryScreen()->availableGeometry().width();
    H=QGuiApplication::primaryScreen()->availableGeometry().height();
    size=new QSize(W,H);
}

void SetItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->update();
    if(event->button() != Qt::LeftButton)
    {

        //如果不是鼠标左键按下，则忽略该事件
        event->ignore();
        return;

    }
    if(is_background)
    {
        event->ignore();
        return;
    }
    setCursor(MyCursor_wait);
    QTransform transform;//QT5添加
        transform.rotate(+0.0);//QT5添加

    switch (button_fun)
    {
    case 2:
        exit_press=true;            //跳回到主页面
        break;
    case 3:                         //静音
        if(F4vol!=0)
        {
            F4voltemp=F4vol;
            F4vol=0;
            this->father->itemAt(QPointF(0.495,0.3),transform)->update();
            mus->setvol(F4vol);
        }
        break;
    case 4:                      //以原音量开启
        if(F4vol==0)
        {
            F4vol=F4voltemp;
            F4voltemp=0;
            this->father->itemAt(QPointF(0.495,0.3),transform)->update();
            mus->setvol(F4vol);
        }
        break;
    case 12:
            this->demo_press=true;
    case 14:
        F4vol+=10;
        if(F4vol<=100)
        {
            this->father->itemAt(QPointF(0.495,0.3),transform)->update();
            mus->setvol(F4vol);
        }
        else
        {
            F4vol=100;
            this->father->itemAt(QPointF(0.495,0.3),transform)->update();
            mus->setvol(F4vol);
        }
        break;                   //增大音量并显示

    case 15:
         F4vol-=10;
        if(F4vol>=0)
        {
            this->father->itemAt(QPointF(0.495,0.3),transform)->update();
            mus->setvol(F4vol);
        }
        else
        {
            F4vol=0;
            this->father->itemAt(QPointF(0.495,0.3),transform)->update();
            mus->setvol(F4vol);
        }
        break;                   //减小音量

    case 21:                     //增大地图高度十位
        w0+=1;
        if(w0<=9)
        {
            this->father->itemAt(QPointF(0.5,0.485),transform)->update();
        }
        else
        {
            w0=9;
        }
        break;

    case 22:                     //增大地图高度个位
        w1+=2;
        if(w1<=9)
        {
            this->father->itemAt(QPointF(0.523,0.485),transform)->update();
        }
        else
        {
            w1=9;
        }
        break;

    case 23:                     //增大地图宽度十位
        h0+=1;
        if(h0<=9)
        {
            this->father->itemAt(QPointF(0.7,0.485),transform)->update();
        }
        else
        {
            h0=9;
        }
        break;

    case 24:                     //增大地图宽度个位
        h1+=2;
        if(h1<=9)
        {
            this->father->itemAt(QPointF(0.723,0.485),transform)->update();
        }
        else
        {
            h1=9;
        }
        break;

    case 25:                     //减小地图高度十位
        w0-=1;
        if(w0>=0)
        {
            this->father->itemAt(QPointF(0.5,0.485),transform)->update();
        }
        else
        {
            w0=0;
        }
        break;

    case 26:                     //减小地图高度个位
        w1-=2;
        if(w1>=1)
        {
            this->father->itemAt(QPointF(0.523,0.485),transform)->update();
        }
        else
        {
            w1=1;
        }
        break;

    case 27:                     //减小地图宽度十位
        h0-=1;
        if(h0>=0)
        {
            this->father->itemAt(QPointF(0.7,0.485),transform)->update();
        }
        else
        {
            h0=0;
        }
        break;

    case 28:                     //减小地图宽度个位
        h1-=2;
        if(h1>=1)
        {
            this->father->itemAt(QPointF(0.723,0.485),transform)->update();
        }
        else
        {
            h1=1;
        }
        break;

    default:
        mus->set_index(3);
        break;
    }


}
void SetItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(MyCursor);    //改变光标形状
}

void SetItem::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    if(!is_background)
    {
        if(button_fun==1)
        {
            size_h*=1.2;
            size_w*=1.2;
            this->update();
        }
    }
}

void SetItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    if(button_fun==1)
    {
        this->hide();
        size_h/=1.2;
        size_w/=1.2;
        this->update();
        this->show();
    }

}


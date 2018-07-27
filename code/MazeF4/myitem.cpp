#include "myitem.h"
#include<QDebug>
QRectF MyItem::boundingRect() const
{
    //qreal penWidth = 1;
    if(is_background)
    {
        return QRectF(0,0,W,H);
    }
    else
    {
        return QRectF(W*address_x,H*address_y,size_w,size_h);
    }

}

void MyItem::paint(QPainter *painter,
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
    else
    {
        QSize *size=new QSize(size_w,size_h);
        pix_pic = pix_pic.scaled(*size);
        painter->drawPixmap(W*address_x,H*address_y,pix_pic,0,0,size_w,size_h);
    }
}


MyItem::MyItem(QString file_n,double ad_x,double ad_y,music *p,bool back,int button,QApplication* a):a(a)
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
void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
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

    switch (button_fun)
    {
    case 1:                      //start
        mus->set_model(QMediaPlaylist::CurrentItemOnce);
        this->start_press=true;
        mus->set_index(0);
        break;
    case 2:                       //exit
        mus->set_model(QMediaPlaylist::CurrentItemOnce);
        mus->set_index(1);
        for(qint64 i=0;i<1000000000;++i);
        a->exit();
        break;
    case 3:                       //about
        mus->set_model(QMediaPlaylist::CurrentItemOnce);
        mus->set_index(2);
        about_press=true;
        break;
    case 6:                       //member
        setting_press=true;

    default:
        break;
    }
    //如果是鼠标左键按下，改变光标形状

}
void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

    if(is_background)
    {
        event->ignore();
        return;
    }
    setCursor(MyCursor);    //改变光标形状
    if(button_fun==3)
    {
        about_release=true;
    }

}

void MyItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug()<<0;
    if(!is_background)
    {
        if(button_fun==1||button_fun==3)
        {
            size_h*=1.2;
            size_w*=1.2;
            this->update();
        }
    }
}

void MyItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if(button_fun==1||button_fun==3)
    {
        this->hide();
        size_h/=1.2;
        size_w/=1.2;
        this->update();
        this->show();
    }

}


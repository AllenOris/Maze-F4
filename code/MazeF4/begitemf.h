#ifndef MYITEM_H
#define MYITEM_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QCursor>
#include <QScreen>
#include <QGuiApplication>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <QString>
#include <QSize>
#include <QGraphicsItemAnimation>
#include <QMouseEvent>
#include <QApplication>
#include <QList>
#include "music.h"

class MyItem : public QGraphicsItem
{
    QApplication *a;
public:
    MyItem(QString file_n,double ad_x,double ad_y,music *p,bool back,int button,QApplication* a);
    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    int W,H;
    int size_w,size_h;
    double address_x,address_y;
    QSize* size;
    QString file_name;
    QCursor MyCursor,MyCursor_wait;
    QPixmap pix_cur,pix_wait,pix_pic;
    music* mus;
    QGraphicsScene* father;
    bool is_background;
    int button_fun;
    bool about_press=false,about_release=false,setting_press=false,start_press=false;
private slots:
    void TimetoExit();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

};

#endif // MYITEM_H

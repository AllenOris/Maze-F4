#ifndef F4SETITEM_H
#define F4SETITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QCursor>
#include <QScreen>
#include <QGuiApplication>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <QString>
#include <QSize>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QMouseEvent>
#include <QTimer>
#include <QApplication>
#include <QGraphicsScene>
#include "music.h"


class SetItem : public QGraphicsItem
{

    QGraphicsScene *father;
    QApplication *a;
public:
    SetItem(QString file_n,double ad_x,double ad_y,music *p,bool back,int button, QApplication*,QGraphicsScene*father=NULL);
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
    bool exit_press=false,demo_press=false;
    bool is_background;
    int button_fun;
private slots:
    void TimetoExit();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
   // void timerEvent(QTimerEvent * event);

};
#endif // F4SETITEM_H

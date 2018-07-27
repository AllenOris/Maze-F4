#ifndef F4PLAYER_H
#define F4PLAYER_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QRectF>
#include <QGraphicsItemAnimation>
#include <QTimeLine>

class F4player:public QGraphicsItem
{
private:
    int num;
    QGraphicsScene *father;
    QPixmap pix;
    qreal x,y;
    int pix_width,pix_height;
protected:
    void keyPressEvent(QKeyEvent *event);
public:
    F4player();
    F4player(QRectF&rec,int,QGraphicsScene *father);
    QRectF boundingRect()const override; //用来设置该item的大小
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;//用来绘制该item的东西
    int getnum();
    void setnum(int);
    void move(qreal,qreal);
    void setpix(QPixmap);
};

#endif // F4PLAYER_H

#include "widget.h"
#include "ui_widget.h"
#include "f4mazemap.h"
#include "f4point.h"
#include "test.h"
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    showFullScreen();
    this->setFixedSize(1920,1080);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent*)
{

    F4mazemap *mp=new F4mazemap(20,20);
    int w=mp->width;int h=mp->height;
    qDebug()<<w<<h;
    mp->turntomap();
    QVector<bool>Line(mp->line);
    QVector<bool>Col(mp->col);
    QPainter painter(this);
    painter.translate(width()*0.1,height()*0.1);
    int dx=width()*0.8/w,dy=height()*0.8/h;
    //line
    for(int i=0;i<Line.size();i+=w){
        for(int j=i;j-i<w;++j){
            if(!Line[j]){
                int x1=dx*(j-i);
                int y1=dy*(i/w);
                int x2=x1+dx;
                int y2=y1;
                painter.drawLine(x1,y1,x2,y2);
            }
        }
    }
    //col
    for(int i=0;i<Col.size();i+=w+1){
        for(int j=i;j-i<=w;++j){
            if(!Col[j]){
                int x1=(j-i)*dx;
                int y1=(i/w)*dy;
                int x2=x1;
                int y2=y1+dy;
                painter.drawLine(x1,y1,x2,y2);
            }
        }
    }

//    QPainter painter(this);
//    int w=20,h=15;
//    if(mp)delete mp;
//    mp=new F4mazemap(h,w);
//    painter.translate(width()*0.05,height()*0.1);
//    int dx=width()*0.9/w,dy=height()*0.8/h;
//    qDebug()<<width()<<height()<<dx<<dy;
//    for(int i=0;i<mp->tree.size();++i){
//        for(int j=0;j<mp->tree[i].size();++j){
//            F4point p1=mp->topoint(i);
//            F4point p2=mp->topoint(mp->tree[i][j]);
//            int x1=p1.get_x()*dx-dx/2;
//            int y1=p1.get_y()*dy-dy/2;
//            int x2=p2.get_x()*dx-dx/2;
//            int y2=p2.get_y()*dy-dy/2;
//            painter.drawLine(x1,y1,x2,y2);
//        }
//    }
}

void Widget::on_pushButton_clicked()
{
    this->close();
}


void Widget::on_pushButton_2_clicked()
{
     this->update();
}

void Widget::on_pushButton_3_clicked()
{
      this->update();
//    qDebug()<<"hi:"<<mp->width<<mp->height;
//    Test *T=new Test(mp,this);
//    T->show();
}

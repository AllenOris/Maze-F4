#include "widget.h"
#include "ui_widget.h"
#include "f4mazemap.h"
#include "f4point.h"
#include <QPainter>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //showFullScreen();
    this->setFixedSize(1920,1080);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    int w=40,h=40;
    F4mazemap mp(w,h);
    painter.translate(width()*0.05,height()*0.1);
    int dx=width()*0.9/w,dy=height()*0.8/h;
    for(int i=0;i<mp.tree.size();++i){
        for(int j=0;j<mp.tree[i].size();++j){
            F4point p1=mp.topoint(i);
            F4point p2=mp.topoint(mp.tree[i][j]);
            int x1=p1.get_x()*dx-dx/2;
            int y1=p1.get_y()*dy-dy/2;
            int x2=p2.get_x()*dx-dx/2;
            int y2=p2.get_y()*dy-dy/2;
            painter.drawLine(x1,y1,x2,y2);
        }
    }
}

void Widget::on_pushButton_clicked()
{
    this->close();
}


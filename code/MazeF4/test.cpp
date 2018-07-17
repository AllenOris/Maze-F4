#include "test.h"
#include "ui_test.h"
#include <QPainter>
#include <QDebug>
Test::Test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Test)
{
    ui->setupUi(this);
    this->setFixedSize(1920,1080);
}

Test::~Test()
{
    delete ui;
}

void Test::paintEvent(QPaintEvent*)
{
    F4mazemap *mp=new F4mazemap(20,20);
    int w=mp->width;int h=mp->height;
    qDebug()<<w<<h;
    mp->turntomap();
    QVector<bool>Line(mp->line);
    QVector<bool>Col(mp->col);
    QPainter painter(this);
    painter.translate(width()*0.05,height()*0.1);
    int dx=width()*0.9/w,dy=height()*0.8/h;
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

}

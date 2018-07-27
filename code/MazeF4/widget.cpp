#include "widget.h"
#include "ui_widget.h"
#include "f4mazemap.h"
#include "f4point.h"
#include "test.h"
#include "f4mazescene.h"
#include "f4mazedemo.h"
#include <QPainter>
#include <QDebug>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QPixmap>
#include <QGraphicsView>
#include <QScreen>
#include <Qt>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    isupdate=true;
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
   showFullScreen();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent*)
{
    if(isupdate){
        isupdate=false;
        F4mazemap *mp=new F4mazemap(20,15);
        int w=mp->width;int h=mp->height;
        qDebug()<<w<<h;
        mp->turntomap();
        QVector<bool>Line(mp->line);
        QVector<bool>Col(mp->col);
        QPainter painter(this);
        painter.translate(width()*0.1,height()*0.1);
        int dx=width()*0.8/w,dy=height()*0.8/h;
        //Line[0]=true;
        Col[0]=true;
        //Line[Line.size()-1]=true;
        Col[Col.size()-1]=true;
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
                    int y1=(i/(w+1))*dy;
                    int x2=x1;
                    int y2=y1+dy;
                    painter.drawLine(x1,y1,x2,y2);
                }
            }
        }
    }
}


void Widget::on_pushButton_clicked()
{
    this->close();
}


void Widget::on_pushButton_2_clicked()
{
    int W=QGuiApplication::primaryScreen()->availableGeometry().width();
    int H=QGuiApplication::primaryScreen()->availableGeometry().height();

    QGraphicsView *view=new QGraphicsView;
    F4MazeDemo *mazescene=new F4MazeDemo(20,31,view);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff) ;
    view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff) ;
    view->setScene(mazescene);
    view->setSceneRect(0,0,W,H);
    view->showFullScreen();
}

void Widget::on_pushButton_3_clicked()
{
    int W=QGuiApplication::primaryScreen()->availableGeometry().width();
    int H=QGuiApplication::primaryScreen()->availableGeometry().height();
    qDebug()<<W<<H;
    F4MazeScene *mazescene=new F4MazeScene(20,31);
    QGraphicsView *view=new QGraphicsView;
   // view->resize(W,H);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff) ;
    view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff) ;

    view->setScene(mazescene);
    view->setSceneRect(0,0,W,H);
    view->showFullScreen();
}


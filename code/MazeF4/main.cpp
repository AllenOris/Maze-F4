#include "mainwindow.h"
#include "music.h"
#include "myview.h"
#include "myloading.h"
#include <QApplication>
#include <QString>
int main(int argc, char *argv[])
{

//    QApplication a(argc, argv);
//    QString address=a.applicationFilePath();
//    music*mus=new music(address);
//    // 场景
//    MyScene *scene = new MyScene(mus,&a);
//    // 矩形项
//    QGraphicsView *view = new QGraphicsView;
//    // 视图关联场景
//    view->setScene(scene);
//    // 显示视图
//    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->showFullScreen();

//    view->show();

//    return a.exec();
    QApplication a(argc, argv);
        QString address=a.applicationFilePath();
        music*mus=new music(address);

        // 矩形项
    MyView *view = new MyView(mus,&a);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->showFullScreen();
    view->hide();
    myloading *F4=new myloading(1,QPixmap(":/new/f4resource/image/resource/loading.png"),view);//拿随便一张图片初始化
    F4->loading();
    return a.exec();
}

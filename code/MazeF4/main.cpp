
#include "music.h"
#include "myview.h"
#include "myloading.h"
#include <QApplication>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString address=a.applicationFilePath();    //找到当前路径
    music *mus=new music(address);              //由于QMediaPlayer类的特殊性，不能使用资源文件加载音乐，故采用当前目录加相对目录的方式

    //矩形项
    MyView *view = new MyView(mus,&a);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->showFullScreen();
    view->hide();

    //进度条加载
    myloading *F4=new myloading(1,QPixmap(":/new/f4resource/image/resource/loading.png"),view);
    F4->loading();

    return a.exec();
}

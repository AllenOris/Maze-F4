#ifndef MYLOADING_H
#define MYLOADING_H

#include<QApplication>
#include<QProgressBar>
#include<QTime>
#include<QtWidgets>
#include<QSplashScreen>
#include<QPixmap>
#include<QMovie>
#include<QLabel>
#include<QGraphicsView>
#include"myview.h"

class myloading:public QSplashScreen
{
    int loading_time;   //加载时间
    QPixmap pixmap;     //加载界面图片
    QProgressBar *progressbar;//进度条
    MyView* view;
    int W,H;
public:
    myloading(int loading_time,QPixmap pixmap,MyView* p);//构造函数 初始化时间和图片

    void set_image(QPixmap pixmap);//重置图片
    void loading();//运行加载界面
    void sleep(double msec);//延时函数
    void finish();//加载结束处理
};

#endif // MYLOADING_H



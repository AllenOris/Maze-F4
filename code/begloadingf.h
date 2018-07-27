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
class myloading:public QSplashScreen{
    int loading_time;
    QPixmap pixmap;
    QProgressBar *progressbar;
    MyView* view;
    int W,H;
public:
    myloading(int loading_time,QPixmap pixmap,MyView* p);
    //~F4loading();
    void set_flash(QMovie movie);
    void set_image(QPixmap pixmap);
    void set_image_list(QPixmap *pixmap[]);
    void loading();
    void sleep(double msec);
    void finish();
};

#endif // MYLOADING_H

#include "myloading.h"
#include<QDebug>
myloading::myloading(int loading_time,QPixmap pixmap,MyView* p):QSplashScreen(pixmap){
    this->loading_time=loading_time;
    W=QGuiApplication::primaryScreen()->availableGeometry().width();
    H=QGuiApplication::primaryScreen()->availableGeometry().height();
    QSize *size=new QSize(W,H);
    pixmap = pixmap.scaled(*size);
    this->pixmap=pixmap;
    this->setPixmap(pixmap);
    view=p;

}


void myloading::set_image(QPixmap pixmap){
    this->pixmap=pixmap;
    this->setPixmap(pixmap);
}


void myloading::loading(){
    this->setGeometry(0,0,pixmap.width(),pixmap.height());//整个界面绝对位置
    this->progressbar=new QProgressBar(this);
    progressbar->setGeometry(0,pixmap.height()-40,pixmap.width(),40);//进度条绝对位置
    progressbar->setRange(0,100);//进度条范围（0，100）
    QFile qss(":/new/f4resource/qss/resource/stylesheet.qss");//设置进度条qss
    qss.open(QFile::ReadOnly);
    progressbar->setStyleSheet(qss.readAll());
    qss.close();
    for(int i=0;i<=100;i++)//显示进度i
    {
        progressbar->setValue(i);
        this->show();
        sleep(loading_time*10);
        if(i==0)
            sleep(500);
        if(i==35)
            sleep(500);
        if(i==90)
            sleep(1000);
        if(i==99)
            sleep(1500);
        if(i==100){
            sleep(1000);
            //view->show();

            this->finish();//进度条走完：退出
            //exit(0);//调试时直接退出了

        }
    }
}

void myloading::sleep(double msec){
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
void myloading::finish()
{
    view->show();
}

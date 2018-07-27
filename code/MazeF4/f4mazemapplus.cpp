#include "f4mazemapplus.h"
#include "f4rect.h"
#include <QScreen>

void F4mazemapPlus::loadmap()
{
    int DX=this->right-this->left;
    int DY=this->down-this->up;
    qreal dx=qreal(DX)/this->total_width;
    qreal dy=qreal(DY)/this->total_height;
    for(int i=0;i<total_height;++i){
        for(int j=0;j<total_width;++j){
            qreal x=this->left+dx*j;
            qreal y=this->up+dy*i;
            int pattern=0;
            if((i==1&&(j<=1))||(i==total_height-2&&(j>=total_width-2)))
                pattern=0;
            else if(i==0||i==total_height-1||j==0||j==total_width-1)
                pattern=1;
            else if((i&1)&&(j&1))
                pattern=0;
            else if((!(i&1))&&(!(j&1)))
                pattern=1;
            else if(i&1){
                pattern=this->col[(i/2)*(this->width+1)+j/2]?0:1;
            }
            else if(j&1){
                pattern=this->line[i/2*this->width+j/2]?0:1;
            }
            this->Rec.push_back(F4rect(x,y,dx,dy,pattern));
        }
    }
}

int F4mazemapPlus::turnplus(int p)
{
    int x=p/origin_width, y=p%origin_width;
    return (2*x+1)*(total_width)+2*y+1;
}

int F4mazemapPlus::turnorigin(int p)
{
    int x=p/this->total_width,y=p%this->total_width;
    qDebug()<<p<<x<<y;
    qDebug()<<"!"<<(int(x/2)*origin_width+x<1?0:int(y/2))<<int(x/2)*origin_width<<(x<1?0:int(y/2));

    return (int(x/2)*origin_width+(x<1?0:int(y/2)));
}

F4mazemapPlus::F4mazemapPlus():F4mazemap(10,10)
{
    origin_height=origin_width=10;
    this->total_height=21;
    this->total_width=21;
    turntomap();
}

F4mazemapPlus::F4mazemapPlus(int h, int w):F4mazemap((h-1)/2,(w-1)/2)
{
    origin_height=(h-1)/2;origin_width=(w-1)/2;
    this->total_height=h&1?h:h-1;
    this->total_width=w&1?w:w-1;
    turntomap();
}

void F4mazemapPlus::setsize(int h, int w)
{
    this->clearall();
    this->width=w;
    this->height=h;
    this->make_edge();
    this->Prime();
    this->turntomap();
}

void F4mazemapPlus::setlocaltion(QRectF rec)
{
    this->left=rec.left();
    this->right=rec.right();
    this->up=rec.top();
    this->down=rec.bottom();
    this->loadmap();
}

F4point F4mazemapPlus::topoint(int num)
{
    return F4point(int(num%(this->total_width))+1,int(num/(this->total_width))+1);
}

QVector<int> F4mazemapPlus::findfullpath(int p)
{
    QVector<int>temp=findpath(p);
    QVector<int>newpath;
    int n=temp.size();
    for(int i=0;i<n-1;++i){
        newpath.push_back(turnplus(temp[i]));
        newpath.push_back((turnplus(temp[i])+turnplus(temp[i+1]))/2);
    }
    newpath.push_back(turnplus(temp[n-1]));
    return newpath;
}

F4mazemapPlus::~F4mazemapPlus()
{
    this->Rec.clear();
}



#include "f4mazemap.h"
#include <QTime>
#include <QDebug>
#include <QObject>

F4point F4mazemap::topoint(int num)
{
    return F4point(int(num%this->width)+1,int(num/this->height)+1);       //x是行，y是列
}


F4mazemap::F4mazemap(int Height,int Width){
    width=Width;height=Height;

    make_edge();
    Kruskal();
}

void F4mazemap::make_edge()
{
    tree.clear();
    tree.resize(width*height);
    e.clear();
    int maze_size=width*height;

    //添加点右边
    for(int i=0;i<maze_size;i+=width){
        for(int j=i;j-i<width-1;++j){
            F4edge temp(j,j+1);
            this->e.append(temp);
        }
    }
    //添加点下边
    for(int i=0;i<maze_size-width;i+=width){
        for(int j=i;j-i<width;++j){
            F4edge temp(j,j+width);
            this->e.append(temp);
        }
    }

    //随边权值
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    int INF=~(1<<31);
    qDebug()<<(QObject::tr("F4edge:"))<<e.size();
    for(int i=0;i<e.size();++i){
        e[i].w=qrand() % INF;
    }
}

void F4mazemap::Kruskal()
{
    QVector<F4edge> edge(this->e);
    QVector<int> fa(tree.size());
    QVector<int> cnt;
    std::sort(edge.begin(),edge.end());
    for(int i=0;i<fa.size();++i)
        fa[i]=i;

    int k=0;
    int edge_num=0;
    int m=edge.size(),n=tree.size();
    while(edge_num<n-1&&k<m){
        int fa1=union_find(edge[k].from,fa);
        int fa2=union_find(edge[k].to,fa);
        if(fa1!=fa2){
            ++edge_num;
            cnt.push_back(k);
            fa[fa1]=fa2;
        }
        ++k;
    }

    //生成树
    for(int i=0;i<edge_num;++i){
        int j=cnt[i];
        tree[edge[j].from].push_back(edge[j].to);
   //     tree[edge[j].to].push_back(edge[j].from);
    }
}

int F4mazemap::union_find(int the_point,QVector<int>&fa)
{
    int r=the_point;
    while(fa[r]!=r)          //查询祖先
        r=fa[r];
    int j;
    int i=the_point;
    while(fa[i]!=r){         //合并子树
        j=fa[i];
        fa[i]=r;
        i=j;
    }
    return r;
}


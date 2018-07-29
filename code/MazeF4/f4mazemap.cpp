#include "f4mazemap.h"
#include "f4edge.h"
#include <QTime>
#include <QDebug>
#include <Qqueue>
#include <QObject>
#include <QSet>
#include <QStack>
#include <queue>

F4point F4mazemap::topoint(int num)
{
    return F4point(int(num%this->width)+1,int(num/this->width)+1);       //x是行，y是列
}

QSet<int> F4mazemap::vectoset(QVector<int> &a)
{
    QSet<int>s;
    for(int i=0;i<a.size();++i){
        s.insert(a[i]);
    }
    return s;
}

F4mazemap::~F4mazemap()
{
    point_connect.clear();
    e.clear();
    tree.clear();
    line.clear();
    col.clear();
}


F4mazemap::F4mazemap(int Height,int Width){
    width=Width;height=Height;

    make_edge();
   // Kruskal();
    Prime();
    this->findpath();
    point_connect.clear();
    e.clear();
}

void F4mazemap::make_edge()
{
    tree.clear();
    tree.resize(width*height);
    point_connect.resize(width*height);
    e.clear();
    int maze_size=width*height;

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    int INF=~(1<<31);
    //添加点右边
    for(int i=0;i<maze_size;i+=width){
        for(int j=i;j-i<width-1;++j){
            F4edge temp(j,j+1,qrand() % INF);
            point_connect[j].push_back(temp);
            point_connect[j+1].push_back(temp.reverse());
            this->e.append(temp);
        }
    }
    //添加点下边
    for(int i=0;i<maze_size-width;i+=width){
        for(int j=i;j-i<width;++j){
            F4edge temp(j,j+width,qrand() % INF);
            point_connect[j].push_back(temp);
            point_connect[j+width].push_back(temp.reverse());
            this->e.append(temp);
        }
    }
}

void F4mazemap::Prime()
{
    int start=0;
    std::priority_queue <F4edge> q(point_connect[start].begin(),point_connect[start].end());
    int n=tree.size();
    QVector<bool>visit(n,false);
    visit[start]=1;
    for(int i=0;i<n-1;++i){
        while(visit[q.top().to])
            q.pop();
        int to=q.top().to;
        int from=q.top().from;
        q.pop();
        visit[to]=true;
        tree[to].push_back(from);
        for(int j=0;j<point_connect[to].size();++j)
            if(!visit[point_connect[to][j].to])
                q.push(point_connect[to][j]);
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

void F4mazemap::turntomap()
{
    int n=tree.size();
    line.resize(n+width);
    col.resize(n+height);
    line.fill(false);col.fill(false);
    for(int i=0;i<tree.size();++i){
        for(int j=0;j<tree[i].size();++j){
            int x=tree[i][j]-i;
            F4point p=topoint(i);
            if(x==1)
                col[(p.y-1)*(width+1)+p.x]=true;
            else if(x==-1)
                col[(p.y-1)*(width+1)+p.x-1]=true;
            else if(x==width)
                line[p.y*width+p.x-1]=true;
            else if(x==0-width)
                line[(p.y-1)*width+p.x-1]=true;
        }
    }
}

void F4mazemap::clearall()
{
    point_connect.clear();
    e.clear();
    line.clear();
    col.clear();
    tree.clear();
}

void F4mazemap::findpath()
{
    //int start=0;
    int end=tree.size()-1;
    int p=end;
    QStack <int> temp;
    temp.push(end);
    while(!tree[p].empty()){
        temp.push(tree[p][0]);
        p=tree[p][0];
    }
    path.clear();
    while(!temp.empty())
        path.push_back(temp.pop());
}

QVector <int>F4mazemap::findpath(int x)
{
    QSet <int> s=vectoset(path);
    QVector <int> temp;
    int p=x;
    while(s.find(p)==s.end()){
        temp.push_back(p);
        p=tree[p][0];
    }
    temp.push_back(p);

    return temp;

}


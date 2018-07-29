#include "f4mazedemo.h"

F4MazeDemo::F4MazeDemo(int H, int W, QGraphicsView *):mazemap(H,W)
{
    this->Screen_Width=QGuiApplication::primaryScreen()->availableGeometry().width();
    this->Screen_Height=QGuiApplication::primaryScreen()->availableGeometry().height();
    //设置边界矩形
    this->setSceneRect(QRectF(0,0,this->Screen_Width,this->Screen_Height));

    //初始化地图
    //Screen_Height;
    mazemap.setlocaltion(QRectF(this->Screen_Width*0.1,this->Screen_Height*0.1,this->Screen_Width*0.8,this->Screen_Height*0.8));
    map.resize(mazemap.Rec.size());
    int len=mazemap.Rec.size();
    for(int i=0;i<len;++i)
        if(mazemap.Rec[i].isobstacle())
            map[i]=false;
        else
            map[i]=true;
    //画地图
    for(int i=0;i<len;++i)
        if(mazemap.Rec[i].isobstacle())
            this->addRect(mazemap.Rec[i],QPen(Qt::white),QBrush(Qt::black));
        else
            this->addRect(mazemap.Rec[i],QPen(Qt::black),QBrush(Qt::white));

    //定义方向
    dir[0]=-1;dir[1]=1;dir[2]=-mazemap.total_width;dir[3]=mazemap.total_width;

    //设置文字
    //QFont(const QString &family, int pointSize = -1, int weight = -1, bool italic = false);
    QFont font("Segoe Script",15,3,false);
    Text_DFS=new QGraphicsTextItem("DFS");
    Text_BFS=new QGraphicsTextItem("BFS");
    Text_Double_BFS=new QGraphicsTextItem("DoubleBFS");
    Text_LCA=new QGraphicsTextItem("LCA");
    Text_DFS->setPos(3,this->Screen_Height*0.2);
    Text_BFS->setPos(3,this->Screen_Height*0.4);
    Text_Double_BFS->setPos(3,this->Screen_Height*0.6);
    Text_LCA->setPos(3,this->Screen_Height*0.8);
    int text_width=1000;
    Text_DFS->setTextWidth(text_width);
    Text_BFS->setTextWidth(text_width);
    Text_Double_BFS->setTextWidth(text_width);
    Text_LCA->setTextWidth(text_width);
    Text_DFS->setFont(font);
    Text_BFS->setFont(font);
    Text_Double_BFS->setFont(font);
    Text_LCA->setFont(font);
    this->addItem(Text_DFS);
    this->addItem(Text_BFS);
    this->addItem(Text_Double_BFS);
    this->addItem(Text_LCA);

    //设置玩家
    int start=mazemap.total_width;
    player=new F4player(mazemap.Rec[mazemap.total_width],start,this);
    player->setFlag(QGraphicsItem::ItemIsFocusable,true);
    this->addItem(player);

    //退出按钮
    ExitFlag=false;
    QPixmap pix(":/imgs/resource/exit.png");
    pix=pix.scaledToHeight(this->Screen_Height*0.1);
    Exit=new QGraphicsPixmapItem(pix);
    Exit->setPos(this->Screen_Width*0.9,this->Screen_Height*0.9);
    this->addItem(Exit);

    //键盘状态
    keypress=false;

}


F4MazeDemo::F4MazeDemo()
{

}

F4MazeDemo::~F4MazeDemo()
{
    this->DFS_Mode.clear();
    this->BFS_Mode.clear();
    this->Double_BFS_Mode.clear();
    this->LCA_Mode.clear();
    this->DFS_Visit.clear();
    this->BFS_Visit.clear();
}


int F4MazeDemo::find_middle(int a,int b)
{
    return (a+b)/2;
}

bool F4MazeDemo::dfs(int x,int end)
{
    DFS_Mode.push_back(x);
    if(x==end)return true;
    for(int i=0;i<4;++i){
        int y=x+dir[i];
        if(map[y]&&IsValidMove(x,y)&&IsValidPoint(y)&&!this->DFS_Visit[y]){
            DFS_Visit[y]=true;
            if (dfs(y,end))
                return true;
        }
    }
    return false;
}

void F4MazeDemo::Show_DFS(int start, int end)
{
    DFS_Mode.clear();
    DFS_Visit.resize(mazemap.Rec.size());
    DFS_Visit.fill(false);
    this->dfs(start,end);
    Show_Path(DFS_Mode);
    DFS_Visit.clear();
}

void F4MazeDemo::Show_BFS(int start, int end)
{
    BFS_Visit.resize(mazemap.Rec.size());
    BFS_Visit.fill(false);
    DFS_Mode.clear();
    QQueue <int> q;
    q.enqueue(start);
    bool findit=false;
    while(!q.empty()){
        int x=q.dequeue();
        BFS_Mode.push_back(x);
        for(int i=0;i<4;++i){
            int y=x+dir[i];
            if(map[y]&&IsValidMove(x,y)&&IsValidPoint(y)&&!BFS_Visit[y]){
                if(y==end){
                    BFS_Mode.push_back(end);
                    findit=true;
                    break;
                }
                q.enqueue(y);
                BFS_Visit[y]=true;
            }
        }
        if(findit)break;
    }
    Show_Path(BFS_Mode);
    BFS_Visit.clear();
}

void F4MazeDemo::Show_Double_BFS_Mode(int start, int end)
{
   QVector<bool> Double_BFS_Visit;
   Double_BFS_Visit.resize(mazemap.Rec.size());
   QQueue<int>q1;
   QQueue<int>q2;
   QSet<int>s;
   q1.enqueue(start);Double_BFS_Mode.push_back(start);Double_BFS_Visit[start]=true;
   q2.enqueue(end);Double_BFS_Mode.push_back(end);Double_BFS_Visit[end]=true;
   bool f=false;
   while(true){
       int x=q1.dequeue();
       if(s.find(x)!=s.end())
           break;
       for(int i=0;i<4;++i){
           int y=x+dir[i];
           if(s.find(y)!=s.end()){
               f=true;
               break;
           }
           if(map[y]&&IsValidMove(x,y)&&IsValidPoint(y)&&!Double_BFS_Visit[y]){
               Double_BFS_Visit[y]=true;
               q1.enqueue(y);
               Double_BFS_Mode.push_back(y);
           }
       }
       if(f)break;

       x=q2.dequeue();
       for(int i=0;i<4;++i){
           int y=x+dir[i];
           if(map[y]&&IsValidMove(x,y)&&IsValidPoint(y)&&!Double_BFS_Visit[y]){
               Double_BFS_Visit[y]=true;
               q2.enqueue(y);
               s.insert(y);
               Double_BFS_Mode.push_back(y);
           }
       }
   }

   Show_Path(Double_BFS_Mode);
   Double_BFS_Visit.clear();
   s.clear();
   q1.clear();
   q2.clear();
}

void F4MazeDemo::Show_LCA_Mode(int now,int end)
{
    LCA_Mode.clear();
    int n=mazemap.path.size();
    int start=mazemap.total_width;
    LCA_Mode.push_back(end);
    for(int i=n-1;i>0;--i){
        int x1=mazemap.turnplus(mazemap.path[i]);
        int x2=mazemap.turnplus(mazemap.path[i-1]);
        LCA_Mode.push_back(x1);
        LCA_Mode.push_back(find_middle(x1,x2));
    }
    LCA_Mode.push_back(mazemap.turnplus(mazemap.path[0]));
    LCA_Mode.push_back(start);

    QVector<int>temp=mazemap.findpath(mazemap.turnorigin(now));
    for(int i=0;i<temp.size()-1;++i){
        int x1=mazemap.turnplus(temp[i]);
        int x2=mazemap.turnplus(temp[i+1]);
        LCA_Mode.push_back(x1);
        LCA_Mode.push_back(find_middle(x1,x2));
    }
    Show_Path(LCA_Mode);
}

void F4MazeDemo::Show_Path(QVector<int>& L)
{
    //覆盖
    for(int i=0;i<Temp_Show.size();++i)
        this->addRect(mazemap.Rec[Temp_Show[i]],QPen(Qt::black),QBrush(Qt::white));
    Temp_Show.clear();
    for(int i=0;i<L.size();++i)
        Temp_Show.push_back(L[i]);
    cnt=0;
    startTimer(40);
}

bool F4MazeDemo::IsValidPoint(int x)
{
    return (x<mazemap.Rec.size()&&x>=0);
}

bool F4MazeDemo::IsValidMove(int x, int y)
{
    if(abs(x-y)==1)
        return(x/mazemap.total_width==y/mazemap.total_width);
    return true;
}

void F4MazeDemo::timerEvent(QTimerEvent *event)
{
    player->setZValue(1);
    if(cnt<Temp_Show.size()){
        int x=Temp_Show[cnt];
        this->addRect(mazemap.Rec[x],QPen(Qt::black),QBrush(Qt::yellow));
        if(player->getnum()==x)this->update();
        ++cnt;
    }
    else{
        killTimer(event->timerId());
    }
}

void F4MazeDemo::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF point(event->scenePos());
    QTransform transform;
    transform.rotate(+0.0);
    int end=mazemap.Rec.size()-mazemap.total_width-1;
    int start=player->getnum();
    if(this->itemAt(point,transform)==Text_BFS){
        this->Show_BFS(start,end);
    }
    else if(this->itemAt(point,transform)==Text_DFS){
        this->Show_DFS(start,end);
    }
    else if(this->itemAt(point,transform)==Text_Double_BFS){
        this->Show_Double_BFS_Mode(start,end);
    }
    else if(this->itemAt(point,transform)==Text_LCA){
        this->Show_LCA_Mode(start,end);
    }
    else  if(this->itemAt(point,transform)==Exit){
        ExitFlag=true;
    }
    QGraphicsScene::mousePressEvent(event);
}

void F4MazeDemo::keyPressEvent(QKeyEvent *event)
{
    int pixw=mazemap.Rec[0].width(),pixh=mazemap.Rec[0].height();
    int num=player->getnum();
    F4point point=mazemap.topoint(num);
    if(event->key()==Qt::Key_A){
        player->setpix(QPixmap(":/imgs/resource/Hero_Left.png"));
        if (point.get_x()>1&&!mazemap.Rec[num-1].isobstacle()){
            player->setpix(QPixmap(":/imgs/resource/Hero_Left.png"));
            player->setnum(num-1);
            player->move(-pixw,0);
        }
    }
    else if(event->key()==Qt::Key_D){
        player->setpix(QPixmap(":/imgs/resource/Hero_Right.png"));
        if (point.get_x()<mazemap.total_width-1&&!mazemap.Rec[num+1].isobstacle()){
            player->setnum(num+1);
            player->move(pixw,0);
        }
    }
    else if(event->key()==Qt::Key_W){
        if (point.get_y()>1&&!mazemap.Rec[num-mazemap.total_width].isobstacle()){
            player->move(0,-pixh);
            player->setnum(num-mazemap.total_width);
        }
    }
    else if(event->key()==Qt::Key_S){
        if (point.get_y()<mazemap.total_height-1&&!mazemap.Rec[num+mazemap.total_width].isobstacle()){
            player->move(0,pixh);
            player->setnum(num+mazemap.total_width);
        }
    }
    this->update();
    QGraphicsScene::keyPressEvent(event);
}

void F4MazeDemo::keyReleaseEvent(QKeyEvent *event)
{
    keypress=false;
    QGraphicsScene::keyReleaseEvent(event);
}

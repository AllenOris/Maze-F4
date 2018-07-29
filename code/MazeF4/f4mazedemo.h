#ifndef F4MAZEDEMO_H
#define F4MAZEDEMO_H

#include "f4mazemapplus.h"
#include "f4player.h"
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGuiApplication>
#include <QScreen>
#include <QQueue>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QFont>

class F4MazeDemo:public QGraphicsScene
{
private:
    int Screen_Width;
    int Screen_Height;
    int dir[4];
    int Temp_Point;
    int cnt;
    QVector<int>Temp_Show;
    bool dfs(int,int);

    QGraphicsTextItem *Text_DFS;
    QGraphicsTextItem *Text_BFS;
    QGraphicsTextItem *Text_Double_BFS;
    QGraphicsTextItem *Text_LCA;
    QGraphicsPixmapItem *Exit;
    F4player *player;

public:
    F4MazeDemo(int,int,QGraphicsView*);
    F4MazeDemo();
    ~F4MazeDemo();
    F4mazemapPlus mazemap;

    QVector <bool> map;
    QVector<int> DFS_Mode;
    QVector<int> BFS_Mode;
    QVector<int> Double_BFS_Mode;
    QVector<int> LCA_Mode;

    QVector<bool>  DFS_Visit;
    QVector<bool>  BFS_Visit;

    int find_middle(int,int);
    void Show_DFS(int,int);
    void Show_BFS(int,int);
    void Show_Double_BFS_Mode(int,int);
    void Show_LCA_Mode(int,int);
    void Show_Path(QVector<int>&);
    bool IsValidPoint(int);
    bool IsValidMove(int,int);

    bool keypress,ExitFlag;


protected:
    void timerEvent(QTimerEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent*);
    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*);
};

#endif // F4MAZEDEMO_H

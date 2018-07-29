#ifndef F4MAZESCENE_H
#define F4MAZESCENE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include "f4mazemapplus.h"
#include "f4player.h"

class F4MazeScene: public QGraphicsScene//,public QObject
{
   // Q_OBJECT
private:
    F4mazemapPlus mazemap;
    int Width,Height;
    int pix_width;
    int cnt;
    QGraphicsPixmapItem *ScareItem;
    QGraphicsPixmapItem *ExitItem;

    F4player *player;
    bool keypressed;
    void restartTimer();
    void timerEvent(QTimerEvent *event);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
public:
    F4MazeScene();
    F4MazeScene(int,int);
    F4player *virtualplayer;
    void initial();
    void show();
    int width();
    int height();
    bool ExitFlag;
    bool next_maze;
};

#endif // F4MAZESCENE_H

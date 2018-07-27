#ifndef MUSIC_H
#define MUSIC_H

#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QUrl>
#include<QString>
class music
{
public:
    music(QString ad);
    void play();
    void next();
    void setvol(int vol);
    void stop();
    void previous();
    void set_model(QMediaPlaylist::PlaybackMode mode);
    void set_index(int index);
    QMediaPlaylist* playlist;
    QMediaPlayer* player;
};

#endif // MUSIC_H

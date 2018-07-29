#include "music.h"
#include<QtDebug>
music::music(QString ad)
{
    playlist = new QMediaPlaylist;
    player = new QMediaPlayer;
    ad1=ad2=ad3=ad4=ad;
    QString Name="DarkMaze.exe";
    int len=Name.length();
    ad1=ad1.replace(ad.indexOf(Name),len,"resource/begscr_bgm.mp3");
    ad2=ad2.replace(ad.indexOf(Name),len,"resource/close_door.mp3");
    ad3=ad3.replace(ad.indexOf(Name),len,"resource/emmmm.mp3");
    ad4=ad4.replace(ad.indexOf(Name),len,"resource/game_bgm.mp3");
    playlist->addMedia(QUrl::fromLocalFile(ad1));  //index 0
    playlist->addMedia(QUrl::fromLocalFile(ad2));  //index 1
    playlist->addMedia(QUrl::fromLocalFile(ad3));       //index 2
    playlist->addMedia(QUrl::fromLocalFile(ad4));    //index 3
    player->setPlaylist(playlist);
}
void music::play()
{
    player->play();
}
void music::next()
{
    playlist->next();
    player->play();
}
void music::setvol(int vol)
{
    player->setVolume(vol);
}
void music::stop()
{
    player->stop();
}
void music::previous()
{
    playlist->previous();
    player->play();
}
void music::set_model(QMediaPlaylist::PlaybackMode mode)
{
    playlist->setPlaybackMode(mode);

}
void music::set_index(int index)
{
    playlist->setCurrentIndex(index);
    player->play();
}

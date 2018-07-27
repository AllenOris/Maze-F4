#include "music.h"
#include<QtDebug>
music::music(QString ad)
{
    playlist = new QMediaPlaylist;
    player = new QMediaPlayer;
    qDebug()<<ad;
    playlist->addMedia(QUrl::fromLocalFile("C:\\Users\\ASUS\\Desktop\\QT\\new_journey\\MazeF4\\MazeF4\\resource\\begscr_bgm.mp3"));  //index 0
    playlist->addMedia(QUrl::fromLocalFile("C:\\Users\\ASUS\\Desktop\\QT\\new_journey\\MazeF4\\MazeF4\\resource\\close_door.mp3"));  //index 1
    playlist->addMedia(QUrl::fromLocalFile("C:\\Users\\ASUS\\Desktop\\QT\\new_journey\\MazeF4\\MazeF4\\resource\\emmmm.mp3"));       //index 2
    playlist->addMedia(QUrl::fromLocalFile("C:\\Users\\ASUS\\Desktop\\QT\\new_journey\\MazeF4\\MazeF4\\resource\\game_bgm.mp3"));    //index 3

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

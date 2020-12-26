#ifndef AUDIO_H
#define AUDIO_H
#include <QMediaPlayer>
//#include <QVideoWidget>/// DONT FORGET QT += multimediawidgets IN .pro FILE
#include <QMediaPlaylist>

class audio///    DONT FORGET  QT += multimedia   IN .pro FILE
{
public:
    audio();
public slots:
    void play();
    void pause();
    void stop();
    void unloop();
    void setVolume(int volume);
    void addToPlaylist(QUrl pathToMusic);
    void setPlaylist();/// for  "void addToPlaylist(QString pathToMusic)" to set playlist :-)
    void removeFromPlaylist(int position);
    void mute(bool mutes);
    void setRate(qreal rate);///speed of playing
    void setCurrentTrack(int ind);/// chose track from playlist
    void loop();
    bool isActive();

    QMediaPlaylist *playlist;
    //QMediaPlaylist playlist;
private:
    QMediaPlayer *player;
    //QMediaPlayer player;
};
/// &D   (*_*)  |@-_-@|
#endif // AUDIO_H

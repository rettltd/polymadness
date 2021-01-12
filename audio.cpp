#include "audio.h"

audio::audio()
{
    player = new QMediaPlayer(nullptr, QMediaPlayer::LowLatency);
    playlist = new QMediaPlaylist(player);/// плейлист
    //player->setAudioRole(QAudio::Role::GameRole);
    //playlist->setCurrentIndex(1);
    player->setPlaylist(playlist);
}

void audio::play()
{
    player->play();
}

void audio::pause()
{
    player->pause();
}

void audio::stop()
{
    player->stop();
}

void audio::unloop()
{
    //playlist->setPlaybackMode(QMediaPlaylist::)
    //QMediaPlaylist *l = new QMediaPlaylist();
    //player->setPlaylist(l);
    //delete player;
    //player = nullptr;
}

void audio::setVolume(int volume)
{
    player->setVolume(volume);
}

void audio::addToPlaylist(QUrl pathToMusic)
{
    playlist->addMedia(pathToMusic);
}

void audio::setPlaylist()
{
    player->setPlaylist(playlist);
}

void audio::removeFromPlaylist(int position)
{
    playlist->removeMedia(position);
}

void audio::mute(bool mutes)
{
    player->setMuted(mutes);
}

void audio::setRate(qreal rate)
{
    player->setPlaybackRate(rate);
}

void audio::setCurrentTrack(int ind)
{
    playlist->setCurrentIndex(ind);
}

void audio::loop()
{
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
}

bool audio::isActive()
{
    return player->state() == player->PlayingState;
}


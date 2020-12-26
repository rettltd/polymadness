#include "sound.h"

sound::sound()
{
    //m_explosion.setSource(QUrl::fromLocalFile(":/mus1.wav"));
    if(m_explosion.isLoaded()){/*потом доделаю*/}
}
sound::sound(QString pathToSound){
    m_explosion.setSource(pathToSound);
}

sound::~sound()
{
    //
}
void sound::play(){
    m_explosion.play();
}
void sound::setLoop(qint32 loop){
    if(!loop)m_explosion.setLoopCount(QSoundEffect::Infinite);
    else m_explosion.setLoopCount(loop);
}

void sound::setVolume(qreal soundVolume)
{
    m_explosion.setVolume(soundVolume);
}

void sound::stop()
{
    m_explosion.stop();
}

void sound::mute(bool U)
{
    m_explosion.setMuted(U);
}

void sound::setSoundSource(QString pathToSound)
{
    m_explosion.setSource(QUrl::fromLocalFile(pathToSound));
}

void sound::category(QString categorY)
{
    m_explosion.setCategory(categorY);
}

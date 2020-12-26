#ifndef SOUND_H
#define SOUND_H
#include <QSoundEffect>
//#include <QSound>

class sound
{

public:
    sound();//по дефолту
    sound(QString pathToSound);
    virtual ~sound();
public slots:
    void play();
    void setLoop(qint32 loop);//колво повторов. 0 - бесконечно повторять
    void setVolume(qreal soundVolume);// 0.0 - 1.0
    void stop();
    void mute(bool U);
    void setSoundSource(QString pathToSound);
    void category(QString categorY);//хызы нужно ли, так,чтоб не забыть
private:
    QSoundEffect m_explosion;
   // QSound m_explosion;
};

#endif // SOUND_H

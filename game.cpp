#include "game.h"
#include "polyn69.h"
#include "playmode.h"


/*sound Game::poped;
sound Game::boom12;
sound Game::offf;*/
QSoundEffect Game::poped;
QSoundEffect Game::boom12;
QSoundEffect Game::offf;

Game::Game(char& flag, Widget& n, score& s, healthbar &h, int& vx, int& vy, QPolygonF& ac, polyar& p2, qreal& r123, float &sp)
    : touch_flag(flag), nativ(n), sc(s), bar(h), vidx(vx), vidy(vy), aimcirc(ac), po1(p2), rad123(r123), speed(sp)
{
    poped.setSource(QUrl("qrc:/audio/sounds48/click.wav"));
    offf.setSource(QUrl("qrc:/audio/sounds48/miss.wav"));
    boom12.setSource(QUrl("qrc:/audio/sounds48/boom.wav"));
    if(Playmode::MODE_OF_GAME == 2)
        offf.setSource(QUrl("qrc:/audio/sounds48/boom.wav"));
}

Game::~Game()
{
    offf.setSource(QUrl("qrc:/audio/sounds48/miss.wav"));
}

bool Game::updateGame()
{
    td += 5;
    WHOLEtime += 5;
        //необх усл//|||дополнительно влияет на частоту
    updateModeExcl();

    if(touch_flag){flag1 = po1.popTouched(); touch_flag=0;}
    flag2 = po1.update();
    switch (flag1) {
    case -1:
        bar.misclick();
        playSound(&offf);
        break;
    case 1:
        bar.lifeup();
        playSound(&poped);
        sc.inc();
        if(sc.m_pts ==  (level * per_lvl) ){
            level++;
            speed += 0.4f;
        }
        break;
    case 2:
        bar.boom();
        playSound(&boom12);
        break;
    case 3:
        sc.inc();
        if(sc.m_pts ==  (level * per_lvl) ){
            level++;
            speed += 0.4f;
        }
        playSound(&poped);
        break;
    default:
        break;
    }
    switch (flag2) {
    case 1:
        bar.misclick();
        playSound(&offf);
        break;
    default:
        break;
    }
    flag1=flag2=0;
    if(bar.health<=0){
        return 1;//death_screen();
    }
    return 0;
}

void Game::setMode(int m1)
{
    mode = m1;
}

void Game::updateModeExcl()
{
    polyn69 REKT(rad123, vidx, vidy, speed);
    int random = qrand();
    qint8 bf = 0;

    switch(Playmode::MODE_OF_GAME){
    case 0:
        if(td > 350 || ((td > 100) && ((rand()%500 + WHOLEtime/(10.2f*level)) > 600)))
        {
            if (random > 0x68000000){
                if (random > 0x72000000) bf = 2;
                else bf = 1;
            }
            REKT.bombflag = bf;
            po1.append(REKT);
            td=0;
        } // связать с бустом (а именно td > 0.5)
        break;
    case 1:
        if(td > 500 || ((td > 80) && ((rand()%300 + WHOLEtime/(level*8.0f)) > 400)))
        {
            if (random > 0x78000000){bf = 1; REKT.accel(qrand()%10+1);}
            REKT.bombflag = bf;
            po1.prepend(REKT);
            td=0;
        }
        break;
    case 2:
        REKT.bombflag = 0;
        po1.append(REKT);
        bar.amount_lifeup((100-bar.health)/4+1);
        sc.null();
        break;
    }
}

void Game::playSound(QSoundEffect *s)
{
    if(s->isPlaying()){s->stop(); s->play();}
    else if(s->isLoaded()) s->play();
}

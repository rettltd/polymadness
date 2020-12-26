#ifndef GAME_H
#define GAME_H

#include "polyar_copy.h"
#include "widget.h"
#include "score.h"
#include "healthbar.h"
#include "sound.h"
//ff
class Game
{
public:
    Game(char& flag, Widget& n, score& s, healthbar &h, int& vx, int& vy, QPolygonF& ac, polyar& p2, qreal& r123, float &sp);
    virtual ~Game();
    bool updateGame();
    void setMode(int m1);


    static QSoundEffect poped;
    static QSoundEffect offf;
    static QSoundEffect boom12;


    char& touch_flag;
    Widget& nativ;
    score& sc;
    healthbar& bar;
    int &vidx, &vidy;
    QPolygonF& aimcirc;
    polyar& po1;
    qreal& rad123;
private:
    void updateModeExcl();
    void playSound(QSoundEffect *s);

    qint8 flag1=0, flag2=0;
    int mode;

    double boost;
    float td = 0;

    /*static sound poped;
    static sound offf;
    static sound boom12;*/
    int level = 1;
    const int per_lvl = 20;
    float &speed;
    float WHOLEtime=0;
};

#endif // GAME_H

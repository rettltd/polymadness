#include "klaxlife.h"

KlaxLife::KlaxLife(polyn69 it, int lifetime_ms) : the(it), life_time_msec(lifetime_ms), curr_t(life_time_msec)
{

}

KlaxLife::KlaxLife(const KlaxLife &c)
{
    the = c.the;
    curr_t = life_time_msec = c.life_time_msec;
}

KlaxLife::~KlaxLife()
{

}

bool KlaxLife::cycle()
{
    const int t = 25;

    if(curr_t <= 0)
    {
        return 1;
    }
    the.fadeoff(0xf0*t/1000);
    curr_t -= t;
    return 0;
}

void KlaxLife::draw(QPainter &w)
{
    the.draw(w);
}

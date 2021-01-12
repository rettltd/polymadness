#ifndef KLAXLIFE_H
#define KLAXLIFE_H
#include <QPainter>
#include <polyn69.h>

class KlaxLife
{
public:
    KlaxLife(polyn69 it, int lifetime_ms = 1000);
    KlaxLife(const KlaxLife& c);
    ~KlaxLife();

    bool cycle();
    void draw(QPainter &w);

    polyn69 the;

    int life_time_msec=1000;
    int curr_t;
};

#endif // KLAXLIFE_H

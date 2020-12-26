#ifndef POLYAR_H
#define POLYAR_H

#include "polyn69.h"
#include <QList>


class polyar
{
public:
    polyar(QPolygonF& ac, int& vx, int& vy, qreal& r123, float& sp);

    /*void bst(gameMode g){
        boost = g.getBoost();
    }*/
    void append(polyn69 RE);
    void prepend(polyn69 RE);
    void append();
    void popAt(int at);
    polyn69 at(int at_);
    qint8 popTouched();
    void draw(QPainter &w);
    void clear();

    qint8 update();
private:
    void colChk(int it2);

    QList<polyn69> vec;

    QPolygonF& aimcirc;
    int &vidx, &vidy;
    qreal &rad123;
    float &speed;
};

#endif // POLYAR_H

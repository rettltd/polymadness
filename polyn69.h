#ifndef POLYN69_H
#define POLYN69_H

#include <QObject>
#include <QPolygonF>
#include <QPainter>
#include "generator.h"

class polyn69
{

public:
    QPolygonF poly1;
    qreal xcenter=0, ycenter=0;//mass center
    qreal rotation, rotspeed=0; qint8 momentum=0;
    qreal velocity, velangle;
    int opacity = 0xf0; //transparencyn't (transparency == 0)
    int colorIndex;

    qint8 bombflag = 0;//0 - normal/ 1- bomb /2 - hp up

    polyn69(qreal& r, int &vx, int &vy, float &boost);
    polyn69();

    void countCentr();
    void fadeoff(int percents);

    void move(qreal offx, qreal offy);
    void rotate(qreal offr);
    void accel(qreal offvel);
    void turn(qreal offvang);

    void setPos(qreal x_, qreal y_);
    void setRot(qreal r_, qreal rs_=0);
    void setVel(qreal v_, qreal angle_in_rad = 0);
    void setCol(QColor col_);

    float getPos(bool x_0___y_1 = 0);
    QPointF getPos();
    float getRot();
    float getVel();
    QColor getCol();

    void direct(float where_to_x, float where_to_y);
    void spawn1(int& vx, int& vy, qreal &r123, float &boost);

    bool outscreen(int &vx, int &vy);

    bool containsP(const QPolygonF &pol13213);
    bool containsP(qreal x_, qreal y_);

    void draw(QPainter &p);
    void update();

private:

    QColor color;
    static QColor cols[16];
};

#endif // POLYN69_H

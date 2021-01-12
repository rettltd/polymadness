#include "polyn69.h"
#include <QTransform>
#include <QPolygonF>
#include <QPainterPath>
#include <QRandomGenerator>
#include <window.h>
#include <math.h>

#define qrand() QRandomGenerator::global()->generate()

QColor polyn69::cols[16]{
                        QColor(0xb3,0xca,0xfe,0xf0),QColor(0xfe,0xb3,0xca,0xf0),QColor(0xd3,0x2f,0x2f,0xf0),
                        QColor(0xe9,0x1e,0x63,0xf0),QColor(0xca,0xfe,0xb3,0xf0),QColor(0x67,0x3a,0xb7,0xf0),
                        QColor(0x39,0x49,0xab,0xf0),QColor(0x1e,0x88,0xe5,0xf0),QColor(0x29,0xb6,0xf6,0xf0),
                        QColor(0x00,0xac,0xc1,0xf0),QColor(0x32,0xf0,0x02,0xf0),QColor(0x4c,0xaf,0x50,0xf0),
                        QColor(0xcd,0xdc,0x39,0xf0),QColor(0xfd,0xd8,0x35,0xf0),QColor(0xff,0x98,0x00,0xf0),
                        QColor(0xf4,0x51,0x1e,0xf0)
                        };
/////////////////////////////////////////////////////////////////////////////////////////////
polyn69::polyn69(qreal& r,int &vx, int &vy, float &boost)
{
    poly1 = polygonGeneretor().polygon(r);
    countCentr();
    spawn1(vx, vy, r, boost);
}

polyn69::polyn69()
{

}

void polyn69::countCentr()
{
    int it = 0;
    for(; it < poly1.size(); it++){
        xcenter += poly1.at(it).x();
        ycenter += poly1.at(it).y();
    }
    xcenter = xcenter / qreal(it);
    ycenter = ycenter / qreal(it);
}

void polyn69::fadeoff(int percents)
{
    opacity -= percents;
    if(opacity < 0) opacity = 0;
    color.setAlpha(opacity);
}


void polyn69::move(qreal offx, qreal offy)
{
    poly1.translate(QPointF(offx, offy));
    xcenter += offx; ycenter += offy;
}

void polyn69::rotate(qreal offr)
{
    poly1.translate(-xcenter, -ycenter);

    QTransform trans;
    trans.rotateRadians(offr);
    poly1 = trans.map(poly1);

    poly1.translate(xcenter, ycenter);

    rotation += offr;
}

void polyn69::accel(qreal offvel)
{
    velocity += offvel;
}

void polyn69::turn(qreal offvang)
{
    velangle += offvang;
}

void polyn69::setPos(qreal x_, qreal y_)
{
    //QTransform trans;
    //trans.translate(x_ - xcenter, y_ - ycenter);
    //poly1 = trans.map(poly1);
    poly1.translate(x_ - xcenter, y_ - ycenter);
    xcenter = x_; ycenter = y_;
}

void polyn69::setRot(qreal r_, qreal rs_)
{
    poly1.translate(-xcenter, -ycenter);

    QTransform trans;
    trans.rotateRadians(r_ - rotation);
    poly1 = trans.map(poly1);

    poly1.translate(xcenter, ycenter);

    rotation = r_;
    rotspeed = rs_;
}

void polyn69::setVel(qreal v_, qreal angle_in_rad)
{
    velocity = v_;
    velangle = angle_in_rad;
}

void polyn69::setCol(QColor col_)
{
    color = col_;
}

float polyn69::getPos(bool x_0___y_1)
{
    return bool(x_0___y_1*ycenter + !x_0___y_1*xcenter);
}

QPointF polyn69::getPos()
{
    return QPointF(xcenter, ycenter);
}

QColor polyn69::getCol()
{
    return color;
}
void polyn69::direct(float where_to_x, float where_to_y)
{
    velangle = acos((where_to_x-xcenter)/sqrt(pow(xcenter-where_to_x, 2.0)+pow(ycenter-where_to_y, 2.0)));
    velangle = velangle*2*(((where_to_y-ycenter) >= 0)-0.5);
}

void polyn69::spawn1(int &vx, int &vy, qreal &r123, float &boost)
{
    qreal xi, yi;
    if(qrand()%2){
        //xi = (vx/10)+(9*vx/10.f)*(qrand()%2);
        xi = vx*(qrand()%2);
        yi = qrand()%vy;
        xi-=0.09*vx; yi-=0.09*vy;
    }
    else{
        //yi = (vy/10)+(9*vy/10)*(qrand()%2);
        yi = vy*(qrand()%2);
        xi = qrand()%vx;
        xi-=0.09*vx; yi-=0.09*vy;
    }
    setPos(xi, yi);
    setRot(qrand()%6283/qreal(1000));
    velocity = boost*0.1*(qrand()%2+5)*r123/qreal(5)+0.07*r123;
    direct(vx/2.f, vy/2.f);

    int random = qrand();
    if (random > 0x68000000){
        if (random > 0x72000000) bombflag = 2;
        else bombflag = 1;
    }
    //char temp_flag = qrand()>0x68000000;
    //if(bombflag==1 || temp_flag) velocity = boost*r123*0.25;
    colorIndex = qrand()%16;
    color = cols[colorIndex];
    /*switch(bombflag){
    case 0:

        break;
    case 1:

        break;
    case 2:

        break;
    }*/
}

bool polyn69::outscreen(int &vx, int &vy)
{
    return (abs(xcenter-vx*0.6) > 1.2*vx) || (abs(ycenter-vy*0.6) > 1.2*vy);
}

bool polyn69::containsP(const QPolygonF& pol13213)
{
    return poly1.intersects(pol13213);
}

bool polyn69::containsP(qreal x_, qreal y_)
{
    return poly1.containsPoint(QPointF(x_, y_), Qt::FillRule::OddEvenFill);
}

void polyn69::draw(QPainter &p)
{
    QPen pen;
    QPainterPath ppath;
    QBrush bruhs;
    QColor temp_q;

    pen.setWidth(4);

    switch(bombflag){
    case 0:
        bruhs.setStyle(Qt::BrushStyle::SolidPattern);
        bruhs.setColor(color);
        temp_q = color.darker(200);
        pen.setColor(temp_q);
        break;
    case 1:
        bruhs.setStyle(Qt::BrushStyle::DiagCrossPattern);
        pen.setCapStyle(Qt::PenCapStyle::SquareCap);
        bruhs.setColor(QColor(0,0,0,0xf0));
        //pen.setStyle(Qt::PenStyle::DotLine);
        pen.setColor(QColor(0,0,0,0xf0));
        break;
    case 2:
        bruhs.setStyle(Qt::BrushStyle::Dense2Pattern);
        pen.setCapStyle(Qt::PenCapStyle::SquareCap);
        bruhs.setColor(QColor(0x10,0xff,0x20,0xf0));
        pen.setColor(QColor(0,0xff,0,0xf0));
        break;
    case 3:
        bruhs.setStyle(Qt::BrushStyle::Dense2Pattern);
        pen.setCapStyle(Qt::PenCapStyle::SquareCap);
        temp_q = color;
        temp_q.setAlpha(0x80);
        bruhs.setColor(temp_q);
        pen.setColor(temp_q);
    }

    p.setPen(pen);

    p.drawPolygon(poly1);
    ppath.addPolygon(poly1);
    p.fillPath(ppath, bruhs);

    p.setPen(Qt::NoPen);
}

void polyn69::update()
{
    move(velocity*5*cos(velangle), velocity*5*sin(velangle));

    rotate(rotspeed);

    if(qrand()%40 == 0) momentum = qrand()%3-1;
    else if(abs(rotspeed-0.05) >= 0.1){
        if(qrand()%6)momentum = 0;
        else momentum = (rotspeed<0)*2-1;
    }
    else if(abs(rotspeed-0.1) <= 0.2) momentum = 0;

    rotspeed += momentum/double(20);
}

/*polyn69::~polyn69()
{

}*/

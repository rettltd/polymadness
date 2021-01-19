#include "widget.h"
#include <math.h>

#include <QPainter>
#include <QTimer>
#include <QMouseEvent>
#include <QPainterPath>
#include <QStyle>
#include <iostream>
#include <QSizePolicy>
#include <QDebug>
#include "healthbar.h"


//! [0]
//int Widget::vidx, Widget::vidy;
//QPolygonF Widget::aimcirc;
//qreal Widget::rad123;

Widget::Widget(int &vx, int &vy, QPolygonF &ac, polyar &p, qreal &r123, char &f, QWidget *parent)
    : vidx(vx), vidy(vy), aimcirc(ac), po1(p), rad123(r123), f1(f), QGraphicsView(parent)
{
//    po1 = new polyar;
}
//! [0]

//! [1]
void Widget::tick()
{
    update();
    viewport()->update();
}
//! [1]

//! [2]
void Widget::paintEvent(QPaintEvent *event)
{
    painter.begin(viewport());
    painter.setRenderHint(QPainter::Antialiasing);

    painter.drawPolygon(aimcirc);
    painter.fillPath(*ppath1, *bru1);

    po1.draw(painter);
    painter.end();

    QGraphicsView::paintEvent(event);
}
//! [2]

void Widget::mousePressEvent(QMouseEvent *eve)
{
    emit game_tapped();
}

void Widget::mouseDoubleClickEvent(QMouseEvent *wvw)
{
    emit game_tapped();
}

void Widget::resizeEvent(QResizeEvent *e)
{
    vidx = e->size().width();
    vidy = e->size().height();
    aimcirc.translate(0.5*(e->size().width() - e->oldSize().width()), 0.5*(e->size().height() - e->oldSize().height()));
    delete ppath1;
    ppath1 = new QPainterPath;
    ppath1->addPolygon(aimcirc);
}

void Widget::drawBackground(QPainter *p, const QRectF &rect)
{
    QGraphicsView::drawBackground(p, rect);
}

void Widget::lateinit()
{
    const qint8 n=10;
    rad123 = 0.03*(sqrt(vidx*vidx + vidy*vidy)/sqrt(2));
    for(int i=0; i<n; i++){
        aimcirc.push_back(QPointF(rad123*cos(3.1416*2*i/double(n)), rad123*sin(3.1416*2*i/double(n))));
    }

    bru1 = new QBrush(Qt::BrushStyle::Dense1Pattern);
    bru1->setColor(QColor(230, 0, 0));

    ppath1 = new QPainterPath;
    ppath1->addPolygon(aimcirc);
}

/*void Widget::game_tapped()
{

}*/

Widget::~Widget()
{
//    aimcirc.clear();
//    po1->clear();
//    delete po1;
    delete bru1;
    delete ppath1;
}

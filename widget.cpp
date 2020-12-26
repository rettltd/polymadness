
/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

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

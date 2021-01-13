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
#include "window.h"
#include "rett.h"
#include "money.h"

#include <QIcon>
#include <QGridLayout>
#include <QTimer>
#include <QMouseEvent>
#include <QPushButton>


//! [0]

Window::Window(QWidget *parent, int ch_game) : QWidget (parent),
    po1(aimcirc, vidx, vidy, rad123, speed)
{
    //setup layout
    setup_layout();

    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &Window::tick);

    timer->start(25);
    game = new Game(result_flag, *native, *score12, *hbr, vidx, vidy, aimcirc, po1, rad123, speed);
    game->setMode(ch_game);

    connect(native, &Widget::game_tapped, [=]{result_flag=1;});
}

Window::~Window()
{
    delete timer;
    delete game;
    delete native;
    delete hbr;
    delete score12;
    delete pause;
    delete qgreff; qgreff=nullptr;
    delete to_menu;
    delete layout;
}

void Window::tick()
{
//    game_processing();
    if(game->updateGame()) death_screen();
    update();
    native->tick();
    hbr->update();
    score12->update();
}

void Window::pause_menu()
{
    native->setEnabled(0);
    score12->save();
    disconnect(timer, &QTimer::timeout, this, &Window::tick);
    timer->stop();


    to_menu->show();
    layout->removeWidget(native);
    layout->removeWidget(hbr);
    layout->removeWidget(score12);
    layout->addWidget(to_menu, 2, 2, 1, 1);
    setLayout(layout);

    ///////////////////////////////////////////////////////////////////////
    /// icon
    //////////////////////////////////////////////////////////////////////
    QIcon icon = QIcon();
    icon.addFile(QString::fromUtf8(":/icons/try_playButton.png"), QSize(), QIcon::Normal, QIcon::Off);
    pause->setIcon(icon);
    pause->setIconSize(QSize(qMin(pause->width(),pause->height()),qMin(pause->width(),pause->height())));
    //////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////
    //pause->setStyleSheet("background-color: #828282;");
    gameflag=1;
    emit paused();
}

void Window::continue1()
{
    ///////////////////////////////////////////////////////////////////
    /// \brief icon
    ///////////////////////////////////////////////////////////////////
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/icons/pause.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
    pause->setIcon(icon);
    pause->setIconSize(QSize(qMin(pause->width(),pause->height()) ,qMin(pause->width(),pause->height())));
    ///////////////////////////////////////////////////////////////////

    //pause->setStyleSheet("background-color: #a5a5a5;");
    native->setEnabled(1);
    score12->save();
    connect(timer, &QTimer::timeout, this, &Window::tick);
    timer->start(25);

    //layout->addWidget(pause, 0, 0, 1, 1);
    layout->addWidget(hbr, 0, 1, 1, 1);
    layout->addWidget(score12, 0, 2, 1, 1);
    layout->addWidget(native, 1, 0, 2, 3);
    layout->removeWidget(to_menu);
    to_menu->hide();
    setLayout(layout);

    gameflag=0;
    emit continued();
}

void Window::death_screen()
{
 //   pause->setStyleSheet("background-color: #a5a5a5;"
 //   pause->setStyleSheet( "border-image:url(:/icons/restart.png)");
    //pause->setStyleSheet("border-image: none;");
    //pause->setStyleSheet("background-color: #5872b1;");
    native->setEnabled(0);
    score12->save();
    disconnect(timer, &QTimer::timeout, this, &Window::tick);
    timer->stop();

    to_menu->show();
    layout->removeWidget(native);
    layout->removeWidget(hbr);
    layout->removeWidget(score12);
    layout->addWidget(to_menu, 2, 2, 1, 1);


    setLayout(layout);

     ///////////////////////////////////////////////////////////////////////
    /// \brief icon
    ///////////////////////////////////////////////////////////////////////
 //   QIcon icon;
 //   icon.addFile(QString::fromUtf8(":/icons/home2.png"), QSize(), QIcon::Normal, QIcon::Off);
 //   to_menu->setIcon(icon);
 //   to_menu->setIconSize(QSize(qMin(to_menu->width(),to_menu->height()),qMin(to_menu->width(),to_menu->height())));


    ///////////////////////////////////////////////////////////////////////
    /// icon
    //////////////////////////////////////////////////////////////////////
    QIcon icon = QIcon();
    icon.addFile(QString::fromUtf8(":/icons/restart.png"), QSize(), QIcon::Normal, QIcon::Off);
    pause->setIcon(icon);
    pause->setIconSize(QSize(qMin(pause->width(),pause->height()),qMin(pause->width(),pause->height())));
    //////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////

    gameflag=2;
    emit dead();
}

void Window::restart_game()
{
    //   pause->setStyleSheet( "border-image:url(:/icons/pause.svg.png)");
    native->setEnabled(1);
    layout->addWidget(hbr, 0, 1, 1, 1);
    layout->addWidget(score12, 0, 2, 1, 1);
    layout->addWidget(native, 1, 0, 2, 3);
    layout->removeWidget(to_menu);
    to_menu->hide();

    //pause->setText("pause");

    po1.clear();
    hbr->health = money().hitPoints();
    hbr->setValue(money().hitPoints());
    score12->save();
    score12->null();
    //score12->setText(QString().setNum(0));

    setLayout(layout);
    connect(timer, &QTimer::timeout, this, &Window::tick);
    timer->start(25);

    ///////////////////////////////////////////////////////////////////
    /// \brief icon
    ///////////////////////////////////////////////////////////////////
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/icons/pause.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
    pause->setIcon(icon);
    pause->setIconSize(pause->size());
    ///////////////////////////////////////////////////////////////////

    gameflag=0;
    emit restarted();
}

void Window::setFonts()
{
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/icons/pause.svg.png"), QSize(), QIcon::Normal, QIcon::Off);
    pause->setIcon(icon);
    pause->setIconSize(QSize(qMin(pause->width(),pause->height()),qMin(pause->width(),pause->height())));
}

void Window::setup_layout()
{
    //initialization
    qgreff = new QGraphicsOpacityEffect;
    qgreff->setOpacity(0.6);
    native = new Widget(vidx, vidy, aimcirc, po1, rad123, result_flag, this);
    score12 = new score(this);
    hbr = new healthbar(this);
    pause = new QPushButton(this);
    to_menu = new QPushButton(this);

    //set stylesheets

    to_menu->setStyleSheet( "*{border-image:url(:/icons/home2.png); background-color: transparent;}");
    native->setStyleSheet("background-color: #779BF0;");
    pause->setStyleSheet("background-color: #5872b1;");
    score12->setStyleSheet("*{background-color: #5872b1; border-bottom-width: 6px;color: #000000;}");
    hbr->setStyleSheet("background-color: #5872b1;");

    //set size policy

    QSizePolicy qspol(QSizePolicy::Expanding, QSizePolicy::Expanding);
    native->setSizePolicy(qspol);
    score12->setSizePolicy(qspol);
    hbr->setSizePolicy(qspol);
    pause->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Expanding);
    to_menu->setSizePolicy(qspol);

    //setup game engine(native)

    native->setFrameShape(QFrame::WinPanel);
    native->setFrameStyle(QFrame::Sunken);
    native->setLineWidth(1);
    score12->setFrameShape(QFrame::StyledPanel);
    score12->setFrameStyle(QFrame::Plain);
    score12->setLineWidth(1);
    score12->setSegmentStyle(QLCDNumber::Flat);

    //to_menu shjuld be shown only if game is paused

    to_menu->hide();
    //to_menu->setGraphicsEffect(qgreff);

    //add all widgets to QGridLayout and setup layout

    layout = new QGridLayout(this);
    layout->setSpacing(0);
    layout->setContentsMargins(0,0,0,0);
    layout->addWidget(pause, 0, 0, 1, 1);
    layout->addWidget(hbr, 0, 1, 1, 1);
    layout->addWidget(score12, 0, 2, 1, 1);
    layout->addWidget(native, 1, 0, 2, 3);

    int rows[3] = {1,7,1};
    int colu[3] = {1,6,2};
    for(int i12=0;i12<3;i12++){
        layout->setRowStretch(i12, rows[i12]);
        layout->setColumnStretch(i12, colu[i12]);
    }

    setLayout(layout);

    //for native

    vidx = native->sizeHint().width();
    vidy = native->sizeHint().height();
    native->lateinit();
}

void Window::game_processing()
{
    /*native->flag2 = native->po1->update();
    switch (native->flag1) {
    case 1:
        hbr->misclick();
        break;
    case 2:
        hbr->boom();
        break;
    case 3:
        score12->inc();
        break;
    default:
        break;
    }
    switch (native->flag2) {
    case 1:
        hbr->misclick();
        break;
    default:
        break;
    }
    native->flag1=0; native->flag2=0;
    if(hbr->health<=0){
        death_screen();
    }*/
}

void Window::flagProc()
{
    switch(gameflag){
    case 0:
        pause_menu();
        break;
    case 1:
        continue1();
        break;
    case 2:
        restart_game();
        break;
    default:
        break;
    }
}

//! [0]

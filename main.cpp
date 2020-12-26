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

//#include "signal.h"
//#include "setjmp.h"
#include "rett.h"
//#include "datarwer.h"
#include "save.h"
#include <QFontDatabase>
#include "languages.h"
#include <QApplication>
#include <QSurfaceFormat>
#include <QScreen>
#include <QFile>
#include <QObject>
#include <money.h>
#include "scale.h"
/*
    static void sig_handler(int no, siginfo_t *si, void* unusd){
    //quick_exit(0);
}
*/


int main(int argc, char *argv[])
{

/*
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sa.sa_sigaction = sig_handler;
    sigaction(SIGSEGV, &sa, NULL);
*/

    Q_INIT_RESOURCE(res);
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/icons1/icon.png"));
   // saveNload().save("money",99999);
    saveNload().check();
 //   saveNload().save("heal",5);
 //  saveNload().save("polygonVariable",5);
 //   saveNload().save("hitPoints",50);
 //  saveNload().save("moneyVel",1.0);
//    saveNload().save("money",5000);

    QFontDatabase::addApplicationFont(":/fonts/UbuntuMono-Bold.ttf");

    settings::MUSIC_VOL = saveNload().valueInt("musicVolume");
    settings::SOUND_VOL = saveNload().valueInt("soundVolume");
    settings::LANGUAGE = saveNload().valueInt("language");


    saveNload().save("hitPoints",money().encrypT(50));
    saveNload().save("moneyVel",money().encrypT(1));
    saveNload().save("polygonVariable",money().encrypT(8));
    saveNload().save("heal",money().encrypT(5));
    saveNload().save("money",money().encrypT(6955));




    //DataRWer::init();
    //DataRWer::readAll();
    //rett *ret = new rett();
    rett ret;

    QFile file(":/style.qss");
    file.open(QIODevice::ReadOnly);
    QString line = file.readAll();
    app.setStyleSheet(line);
    file.close();

    fuckinShit::x = app.screens().at(0)->size().width();
    fuckinShit::y = app.screens().at(0)->size().height();

    //ret->show();
    ret.show();
    app.connect(&app, &QApplication::applicationStateChanged, &ret, &rett::go_background);


    return app.exec();

}

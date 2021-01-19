#include "rett.h"
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

int main(int argc, char *argv[])
{
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

/*
    saveNload().save("hitPoints",money().encrypT(50));
    saveNload().save("moneyVel",money().encrypT(1));
    saveNload().save("polygonVariable",money().encrypT(8));
    saveNload().save("heal",money().encrypT(5));
    saveNload().save("money",money().encrypT(6955));
*/
    rett ret;

    QFile file(":/style.qss");
    file.open(QIODevice::ReadOnly);
    QString line = file.readAll();
    app.setStyleSheet(line);
    file.close();

    fuckinShit::x = app.screens().at(0)->size().width();
    fuckinShit::y = app.screens().at(0)->size().height();

    ret.show();
    app.connect(&app, &QApplication::applicationStateChanged, &ret, &rett::go_background);


    return app.exec();

}

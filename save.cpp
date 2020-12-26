#include "save.h"
#include "money.h"
#include <QSettings>
#include "settings.h"
#include <QStringList>
saveNload::saveNload()
{
    QSettings setts("rett","PolygonMadness");
    //setts.setValue("musicVolume",0);

}

void saveNload::check()
{
    QSettings setts("rett","PolygonMadness");
  ///  QStringList basikList = {"heal","hitPoints","language","money","moneyVel","polygonVariable","soundVolume","musicVolume"};
  /// check all saves
    if(!setts.contains("heal")){
        setts.setValue("heal",money().encrypT(5));
    }
    if(!setts.contains("languages")){
        setts.setValue("languages","english");
    }
    if(!setts.contains("hitPoints")){
        setts.setValue("hitPoints",money().encrypT(50));
    }
    if(!setts.contains("language")){
        setts.setValue("language","english");
    }
    if(!setts.contains("money")){
        setts.setValue("money",money().encrypT(50));
    }
    if(!setts.contains("moneyVel")){
        setts.setValue("moneyVel",money().encrypT(1));
    }
    if(!setts.contains("polygonVariable")){
        setts.setValue("polygonVariable",money().encrypT(5));
    }
    if(!setts.contains("soundVolume")){
        setts.setValue("soundVolume",100);
    }
    if(!setts.contains("musicVolume")){
        setts.setValue("musicVolume",100);
    }
    /*
    QStringList list = setts.allKeys();
    bool wasChecked = 0;
    for(int i = 0; i != basikList.size(); i++){
        for(int p = 0; p != list.size(); p++){
            if(basikList[i] == list[p]) wasChecked= 1;
        }
        if(!wasChecked){
            setts.setValue(basikList[i],"");
        }
    }*/

}

void saveNload::init()
{
    QSettings setts("rett","PolygonMadness");
    settings::MUSIC_VOL = setts.value("musicVolume",0).toInt();
    settings::SOUND_VOL = setts.value("soundVolume",0).toInt();
    settings::LANGUAGE = setts.value("language",0).toInt();

    //read settings::MUSIC_VOL etc
}
/// обращаться к функциям: saveNload(). ...
int saveNload::score(int flag)
{
    QSettings setts("rett","PolygonMadness");
    switch (flag){
    case 0:
        return setts.value("classicHighScore",0).toInt();
    case 1:
        return setts.value("survivalHighScore",0).toInt();
    default:
        return 0;
    }
}


void saveNload::setScore(int flag,int score)
{
    QSettings setts("rett","PolygonMadness");
    switch (flag) {
    case 0:
         setts.setValue("classicHighScore",score);
        break;
    case 1:
         setts.setValue("survivalHighScore",score);
        break;
    default:
        break;
    }
}

void saveNload::save(QString key, QVariant value)
{
    QSettings setts("rett","PolygonMadness");
    setts.setValue(key,value);
}

void saveNload::saveAll()///useless
{
    QSettings setts("rett","PolygonMadness");
    //setts.setValue("musicVolume", settings::MUSIC_VOL);
    //setts.setValue("soundVolume", settings::SOUND_VOL);
    //setts.setValue("language", settings::LANGUAGE);
}

int saveNload::valueInt(QString key)
{
    QSettings setts("rett","PolygonMadness");
    return setts.value(key,0).toInt();
}

QString saveNload::valueString(QString key)
{
    QSettings setts("rett","PolygonMadness");
    return setts.value(key,"").toString();
}

QByteArray saveNload::valueByteArray(QString key)
{
    QSettings setts("rett","PolygonMadness");
    return setts.value(key,"").toByteArray();
}

float saveNload::valueFloat(QString key)
{
    QSettings setts("rett","PolygonMadness");
    return setts.value(key,0).toFloat();
}

bool saveNload::check(QString key)
{
    QSettings setts("rett","PolygonMadness");
    return setts.contains(key);
}



#include "languagesre.h"
#include "save.h"

const QString language::languages[2][26]={
    //----0--------------1-------------2-----------3----------4-------------5-----------6------------7-------------8------9-------10-------------11-----------12-------------13---------14-------------------------15-----------------16------------------------17-------------------------18--------------------19--------------20------------21---------------------------22--------------------------------------23-----------------------24------------------------------25-------
    {"CHOOSE MODE", "COMING SOON!","YOU LOOSE!","SHOP","Maximum level","Upgarde:","Hit Points","Money Boost","Polygons","Heal","Language","Music Volume","Sound Volume","Wellcome","Your game statistics:","Classic high score :","Survival high score :","Survival mode attempts:","Classic mode attempts:","Total attempts:","BACK","Increase initial health points","Increase amount of gained coins","Adds one more shape","Increase green polygons healing power","INFORMATION"},
    //----0--------------1-------------2-----------3----------4---------------5-----------6---------7---------8---------9-------10-------11-----12-------------13---------------14---------------------15------------------16-------------------------17-------------------18--------------------19-----------20------------------------21----------------------------------22-----------------------------------23-------------------------------24-------------------------25--------
    {"РЕЖИМ ИГРЫ","Скоро выйдет","ВЫ ПРОИГРАЛИ!","МАГАЗИН","Макс уровень","Улучшить :","Жизни","Заработок","Фигуры","Лечение","Язык","Музыка","Звуки","Добро пожаловать!","Статистика игры:","Рекорд в 'Classic' :","Рекорд в 'Survival' :","Попыток в 'Survival':","Попыток в 'Classic':","Всего попыток:","НАЗАД","Увеличение начального уровня здоровья","Получайте больше денег за каждую игру","Добавляется больше фигур в игру","Востановление даёт больше жизней","ИНФОРМАЦИЯ"}
};
/*
 * ++0 CHOOSE MODE
 * 1 COMING SOON!
 * 2 YOU LOOSE!
 * 3 SHOP
 *
 * ++4 Maximum level
 * ++5 Upgarde:
 * ++6 Hit Points
 * ++7 Money Boost
 * ++8 Polygons
 * ++9 Heal
 *
 * ++10 Language
 * ++11 Music Volume
 * ++12 Sound Volume
 *
 * ++13 Wellcome
 * ++14 Your game statistics:
 * ++15 Classic high score :
 * ++16 Survival high score :
 * ++17 Survival mode attempts:
 * ++18 Classic mode attempts:
 * ++19 Total attempts:
 * ++20 BACK
 * ++21 "Increase initial health points"
 * ++22 "Increase amount of gained coins per 5 points"
 * ++23 "  Adds one more shape"
 * ++24 "  Increase green polygons healing power"
 * ++25 INFORMATION
 * */
QString language::lang(int nomb)
{
    QString langg = saveNload().valueString("languages");
    if(langg == "russian") return languages[1][nomb];
    else return languages[0][nomb];
}

language::language()
{

}

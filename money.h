#ifndef MONEY_H
#define MONEY_H
#include <QString>
#include "save.h"
//#include <QVector>
class money
{
public:
    money();
    void read();
    int mooney;


    //boosters
    static  float getBoost(qint8 key);// получить один из бустеров ниже по его названию // 0 - hitPoints // 1 - speed // 2 - moneyVel
    //static  float getBoost(QString key); // for future, bright future // doesnt work so far

    int upgrade(qint8 key); // когда что-то апаешь в магазе // 0 - hitPoints // 1 - speed // 2 - moneyVel
    int getLVLs(qint8 key);// чтоб в магазе отображать лвл данного перка или сказать что он уже вкачан // пусть лвл будет 8
    int getValues(int key);
    float getBoost(int key);
    /*
     * 1- HP
     * 2- money_vel
     * 3- addPolygon
     * 4- moreHeal
     */
    static float money_vel;

    static int getMooney();
    static void addMooney(int money);
    static int hitPoints();
    static float speed();
    static float moneyVel();
    static QString decrypT(QString keyForSave);
    static QByteArray encrypT(QVariant keyForSave);
private:
    int transaction(int value);
    const int basicValue = 50;//начальная стоимость апгрейда
    const int addValue = 20;//на сколько каждый раз будет подниматься цена при каждои апгрейде
    const int maxLVL = 9;//максимальный лвл
    const int maxPolyLVL = 6;
    const float basikSpeed = 0.9,basikMoneyVel = 1;
    const int basikHP = 50,addHP = 5;
    const float addSpedd = 0.1,addMoneyVel = 0.3;
    const int basicPolygonVariable = 5;
    const int basikHeal = 5;
    const int basikHealCost = 100;
    const int addHealCost = 300;
    const int maxHealLVL = 2;
    const int addHeal = 5;

  //  const QString key ="trytodosmthwintit999000111ppp";
    int hitPoints_lvl,polygon_lvl,moneyVel_lvl,heal_lvl,hp;
    int polygon,heal;
    float speed_;
};

#endif // MONEY_H

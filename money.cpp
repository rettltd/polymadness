#include "money.h"
#include <QDebug>
#include "qaesencryption.h"
#include <QCryptographicHash>
#include <QByteArray>
#include <QTextCodec>


float money::money_vel;


money::money()
{
    bool ok =1;
    mooney = decrypT("money").toInt(&ok,10);



    money_vel = decrypT("moneyVel").toFloat(&ok);
    heal = decrypT("heal").toInt(&ok,10);
    polygon = decrypT("polygonVariable").toInt(&ok,10);
    hp = decrypT("hitPoints").toInt(&ok,10);


    hitPoints_lvl  = (hp - basikHP) / addHP;
    heal_lvl  = ((heal - basikHeal)/addHeal) ;// (/1)
    polygon_lvl = polygon - basicPolygonVariable;
    moneyVel_lvl = (money_vel - basikMoneyVel) / addMoneyVel;
}

void money::read()
{

}


int money::getMooney()
{
    bool ok =1;
    int mon = decrypT("money").toInt(&ok,10);
    return  mon;
}

void money::addMooney(int money) /// money - points from game
{
    bool ok =1;
    money_vel = decrypT("moneyVel").toFloat(&ok);
    int add =money  * money_vel / 5.f;
    add += decrypT("money").toInt(&ok,10);
    saveNload().save("money", encrypT(add));
}

float money::getBoost(qint8 key)
{
    bool ok =1;
    switch (key) {
    case 1:
        return decrypT("hitPoints").toInt(&ok,10);
    case 2:
        return decrypT("moneyVel").toFloat(&ok);
    case 3:
        return decrypT("polygonVariable").toInt(&ok,10);
    case 4:
        return decrypT("heal").toInt(&ok,10);
    default: return 0;
    }
}



float money::moneyVel()
{
    bool ok =1;
    return decrypT("moneyVel").toFloat(&ok);
}

int money::transaction(int value)
{

    mooney -= value;
    saveNload().save("money",encrypT(mooney));
    return mooney;
}
QByteArray money::encrypT(QVariant keyForSave){
    QString inputStr = keyForSave.toString();
    QAESEncryption encryption(QAESEncryption::AES_256, QAESEncryption::ECB);
    QString key("HarasovaElmiraNakipovna99");
    QString iv("your-IV-vector153");
    QByteArray hashKey = QCryptographicHash::hash(key.toLocal8Bit(), QCryptographicHash::Sha256);
    QByteArray hashIV = QCryptographicHash::hash(iv.toLocal8Bit(), QCryptographicHash::Md5);
    QByteArray encodeText =  encryption.encode(inputStr.toLocal8Bit(), hashKey, hashIV);
    return encodeText;

}
QString money::decrypT(QString keyForSave)
{
    QByteArray encodeText =  saveNload().valueByteArray(keyForSave);
    QAESEncryption encryption(QAESEncryption::AES_256, QAESEncryption::ECB);
    QString key("HarasovaElmiraNakipovna99");
    QString iv("your-IV-vector153");
    QByteArray hashKey = QCryptographicHash::hash(key.toLocal8Bit(), QCryptographicHash::Sha256);
    QByteArray hashIV = QCryptographicHash::hash(iv.toLocal8Bit(), QCryptographicHash::Md5);
    QByteArray decodedText = encryption.decode(encodeText, hashKey, hashIV);
    QString decodedString = QString(encryption.removePadding(decodedText));
    return decodedString;
}

float money::speed()
{
    bool ok =1;
     return decrypT("speed").toFloat(&ok);
}

int money::hitPoints()
{
    bool ok =1;
     return decrypT("hitPoints").toInt(&ok,10);
}



/*
 * 1- HP
 * 2- money_vel
 * 3- addPolygon
 * 4- moreHeal
 */
int money::upgrade(qint8 key)
{
    switch (key) {
    case 1:// hp

        if(hitPoints_lvl <= maxLVL && mooney >= (hitPoints_lvl  * addValue + basicValue)){
            hp += addHP;
            hitPoints_lvl++;
            saveNload().save("hitPoints",encrypT(hp));
            //qDebug() << hp;
            return transaction(basicValue + (hitPoints_lvl -1) * addValue);
        }
        else {
            return mooney;
        }
 //   break;
    case 2://speed
       // qDebug() << moneyVel_lvl  * addValue + basicValue;
        if(moneyVel_lvl <= maxLVL && mooney >= (moneyVel_lvl  * addValue + basicValue)){
            moneyVel_lvl++;
            money_vel += addMoneyVel;
            saveNload().save("moneyVel",encrypT(money_vel));
            //qDebug() <<money_vel;
            return transaction(basicValue + (moneyVel_lvl - 1) * addValue);
        }
        else {
            return mooney;
        }
        //break;
    case 3:
        if(polygon_lvl <= maxPolyLVL && mooney >= basicValue){
            //hp += addHP;
            polygon++;
            polygon_lvl++;
            saveNload().save("polygonVariable",encrypT(polygon));
            //qDebug() <<polygon;
            return transaction(basicValue );
        }
        else {
            return mooney;
        }
     //   break;
    case 4:
        if(heal_lvl < maxHealLVL && mooney >= (heal_lvl  * addHealCost + basikHealCost)){
            heal+= 5;
            heal_lvl++;
            saveNload().save("heal",encrypT(heal));
            //qDebug() << heal;
            return transaction(basikHealCost + (heal_lvl-1)  * addHealCost);
        }
        else {
            return mooney;
        }
    //    break;
    default:return 0;
    }
}
/*
 * 1- HP
 * 2- money_vel
 * 3- addPolygon
 * 4- moreHeal
 */
int money::getLVLs(qint8 key)
{
    //return  saveNload().valueString(key + "_lvl" );
    switch (key) {
    case 1:
        return  hitPoints_lvl;
    case 2:
        return moneyVel_lvl;
    case 3:
        return  polygon_lvl;
    case 4:
        return heal_lvl;
    default:return 0;
    }
}

int money::getValues(int key)
{
    switch (key) {
    case 1:
        return ((hitPoints_lvl ) * addValue + basicValue);
    case 2:
        return ((moneyVel_lvl) * addValue + basicValue);
    case 3:
        return basicValue;
    case 4:
        return ((heal_lvl) * addHealCost + basikHealCost);
    default: return 0;
    }
}

float money::getBoost(int key)
{
    switch (key) {
    case 1:
        return hp;
    case 2:
        return money_vel;
    case 3:
        return polygon;
    case 4:
        return heal;
    default: return 0;
    }
}

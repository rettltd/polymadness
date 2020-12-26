#ifndef LANGUAGES_H
#define LANGUAGES_H
#include <QFile>
//#include <QString>

class languages
{
public:
    languages();
    static QString choose_mode;
    static QString upgrade_cost;
    static QString level;
    static QString maxLVL;
    static QString shop;
    static QString apply;
    static QString settings_help;
    static QString reset;
    static QString music;
    static QString sound;
    static QString setts_language;
    static QString hitPoints;
    static QString moneyVelocity;
    static QString heal;
    static QString polygonVar;
    static QString wellcome;
    static QString urstats;
    static QString cl_hisc;
    static QString  su_hisc;
    static QString cl_attempts;
    static QString su_attempts;
    static QString totl_att;
    static QString upgarde;
    static QString comingSoon;
//    static QString chooseMode;

    QString lang[2][90][90];
     void read(QString lang);
private:
    QString getData(QString keu);
    void init(QString &str, QString keu,bool sleshN = 0);
    QString language;
    //static QString language;
    //static QString translate(QString lang = language,QString key = "" );
};

#endif // LANGUAGES_H

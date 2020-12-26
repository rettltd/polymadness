#include "languages.h"
#include <QFile>
//#include <QDebug>
//QString languages::language = "english";
QString languages::choose_mode = "CHOOSE MODE";//по дефолту ангилйский
QString languages::shop = "SHOP";
QString languages::apply = "Apply";
QString languages::settings_help = "HELP";
QString languages::reset = "Reset";
QString languages::sound = "Sound";
QString languages::music = "Music";
QString languages::setts_language = "Language";
QString languages::hitPoints = "Hit Points";
QString languages::heal = "Heal";
QString languages::moneyVelocity = "Money Boost";
QString languages::polygonVar = "Polygons ";
QString languages::maxLVL = "Maximum level";
QString languages::level = "level ";
QString languages::upgrade_cost = "Upgrade cost : ";
QString languages::wellcome ="Wellcome!";
QString languages::urstats = "Your game statistics: ";
QString languages::cl_hisc = "Classic high score : ";
QString languages::su_hisc = "Survival high score : ";
QString languages::su_attempts = "Survival mode attempts: ";
QString languages::totl_att = "Total attempts: ";
QString languages::cl_attempts = "Classic mode attempts: ";
//QString languages::chooseMode = "Choose mode:";
QString languages::comingSoon = "COMING SOON";
/*  reset");
    lang_label->setText("language");
    soundv->setText("Sound");
    musicv->setText("Music");*/
languages::languages()
{

}

void languages::read(QString lang)
{
   // if(lang != "english"){
        QString check;
        language = lang;

        init(choose_mode,"choose_mode");
        init(shop,"shop");
        init(settings_help,"settings_help");
        init(reset,"reset");
        init(sound,"sound");
        init(music,"music");
        init(apply,"apply");
        init(setts_language,"setts_language");
        init(hitPoints,"hitPoints",1);
        init(heal,"heal",1);
        init(moneyVelocity,"moneyVelocity",1);
        init(polygonVar,"polygonVar",1);
        init(wellcome , "wellcome");
        init(urstats,"urstats");
        init(cl_hisc, "cl_hisc");
        init(su_hisc,"su_hisc");
        init(su_attempts,"su_attmpts");
        init(cl_attempts,"cl_attmpts");
        init(totl_att,"total_attmpts");
        init(maxLVL,"maxLVl");
        init(upgrade_cost,"upgradeCost",1);
        init(comingSoon, "comSoon");
     //   init(chooseMode,"chooseMode");
    //}
}

QString languages::getData(QString keu)
{
    QFile ffile(":/language");
    ffile.open(QIODevice::ReadOnly);
    QString find;
    bool wasFound = 1;
    keu = language + "::" + keu + "\n";

    while(find != keu ){
        if( ffile.atEnd()){ // todo exeption
            wasFound = 0;
            break;
        }
        find = ffile.readLine();
      //  qDebug() << find;
    }
    QString exactData;
    find ="";
    while(!ffile.atEnd()){
        find = ffile.readLine();
        if(find == ";\n") break;
        exactData += find;
    }
    ffile.close();
    return exactData;
}

void languages::init(QString &str, QString keu,bool sleshN)
{
    QFile ffile(":/language");
    ffile.open(QIODevice::ReadOnly);
    QString find;
    bool wasFound = 1;
    keu = language + "::" + keu + "\n";

    while(find != keu ){
        if( ffile.atEnd()){ // todo exeption
            wasFound = 0;
            break;
        }
        find = ffile.readLine();
       // qDebug() << find;
    }
    QString exactData;
    find ="";
    while(!ffile.atEnd()){
        find = ffile.readLine();
        if(find == ";\n") break;
        exactData += find;
    }
    if(exactData != ""){
       // str.remove(QChar('\n'), Qt::CaseInsensitive);
        //qDebug() << str;
        str =exactData;
    }

    if(sleshN) str.remove(QChar('\n'));
    ///qDebug() << str;
    ffile.close();

}

#ifndef SAVE_H
#define SAVE_H
#include <QString>
#include <QVariant>
#include <QByteArray>
class saveNload
{
public:
    saveNload();
    static void check();
    static void init();
    static int score(int flag);
    static void setScore(int flag,int score);
    static void save(QString key, QVariant value);
    static void saveAll();
    static int valueInt(QString key);
    static QString valueString(QString key);
    static QByteArray valueByteArray(QString key);
    static float valueFloat(QString key);
    static void checkAll();

private:
    bool check(QString key);

};

#endif // SAVE_H

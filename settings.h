#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QScrollBar>
#include <QComboBox>
#include <QLabel>
#include <QRadioButton>
#include <QIcon>
#include <QSize>
//#include "datarwer.h"

class settings : public QWidget
{
    Q_OBJECT
public:
    settings(QWidget *parent = nullptr);
    virtual ~settings();

    QPushButton* leave_tomenu;
    static int SOUND_VOL;
    static int MUSIC_VOL;
    static int LANGUAGE;

public slots:
     void changeSettings();
       void changeSettsLanguage();
signals:
    void lang_chd();
    void sound_chd();
private:
    QGridLayout* lay1;

    QPushButton *help;
    QPushButton *reset1;
    QScrollBar *sound_vol;
    QScrollBar *music_vol;
    //QComboBox *language_box;
    QFrame *lang_icon;
    QLabel *lang_label;
    QLabel *soundv;
    QLabel *musicv;

    QPushButton *rusian, *englih;

    void setup_layout();
};

#endif // SETTINGS_H

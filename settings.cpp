#include "settings.h"
#include "save.h"
#include "languagesre.h"
#include "game.h"
#include "rett.h"
#include "scale.h"
#include <QLayout>
#include <QFontDatabase>

int settings::LANGUAGE;
int settings::MUSIC_VOL;
int settings::SOUND_VOL;

settings::settings(QWidget *parent) : QWidget(parent)
{
    setup_layout();
    connect(sound_vol, &QScrollBar::valueChanged, this, &settings::changeSettings);
    connect(music_vol, &QScrollBar::valueChanged, this, &settings::changeSettings);
    connect(englih, &QPushButton::pressed, [=]{LANGUAGE = 0; emit lang_chd();
        englih->setStyleSheet("*{background-color: #3e5486;"
                              "border-width: 10px;"
                              "border-top-left-radius: 7px;"
                              "border-bottom-left-radius: 7px;"
                              "}");
        rusian->setStyleSheet("*{border-width: 6px;"
                              "border-color: rgba(0,0,0,170);"
                              "border-top-right-radius: 7px;"
                              "border-bottom-right-radius: 7px;}");});
    connect(englih, &QPushButton::pressed, [=]{LANGUAGE = 0; emit lang_chd();
        lang_label->setText(language().lang(10));
        soundv->setText(language().lang(12));
        musicv->setText(language().lang(11));

    });
    connect(rusian, &QPushButton::pressed, [=]{LANGUAGE = 1; emit lang_chd();
        lang_label->setText(language().lang(10));
        soundv->setText(language().lang(12));
        musicv->setText(language().lang(11));

    });
    connect(rusian, &QPushButton::pressed, [=]{LANGUAGE = 1; emit lang_chd();
        rusian->setStyleSheet("*{background-color: #3e5486;"
                              "border-width: 10px;"
                              "border-top-right-radius: 7px;"
                              "border-bottom-right-radius: 7px;}");
        englih->setStyleSheet("*{border-width: 6px;"
                              "border-color: rgba(0,0,0,170);"
                              "border-bottom-left-radius: 7px;"
                              "border-top-left-radius: 7px;}");
        lang_label->setText(language().lang(10));
        soundv->setText(language().lang(12));
        musicv->setText(language().lang(11));
    });
    connect(this, &settings::lang_chd, this, &settings::changeSettsLanguage);

    //connect(language_box, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &settings::changeSettings);
}

settings::~settings()
{
    delete leave_tomenu;
    delete help;
    delete reset1;
    delete sound_vol;
    delete music_vol;
    delete background;
    delete lang_label;
    delete soundv;
    delete musicv;
    delete lay1;
}

void settings::changeSettings()
{
    MUSIC_VOL = music_vol->value();
    SOUND_VOL = sound_vol->value();
    qreal temp = qreal(SOUND_VOL/100.f);

    rett::button_pop.setVolume(temp);
    Game::offf.setVolume(temp);
    Game::poped.setVolume(temp);
    Game::boom12.setVolume(temp);

    emit sound_chd();
    //DataRWer::writeAll();
}

void settings::changeSettsLanguage()
{
    //not in use
}

void settings::setFonts()
{
    //set icons

    QIcon icon;
    icon.addFile(QString::fromUtf8(":/icons/back_flat_right1.png"), QSize(), QIcon::Normal, QIcon::Off);
    leave_tomenu->setIcon(icon);
    leave_tomenu->setIconSize(leave_tomenu->size());


    /////THIS IS FOR FONT IN RESOURCES/////
    int id = QFontDatabase::addApplicationFont(":/fonts/UbuntuMono-Bold.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);

    QFont font = QFont(family);
    font.setPixelSize(50);
    font.setBold(true);
    font.setKerning(false);
    ///////////////////////////////////////

    //set font size for text

    font = scale().textResize(font,"Русский  ",rusian->size());
    rusian->setFont(font);
    englih->setFont(font);
    font = scale().textResize(font,language().lang(12)+"12345678910",sound_vol->size());
    help->setFont(font);
    //font = scale().textResize(font,language().lang(12),soundv->size());
    soundv->setFont(font);
    musicv->setFont(font);
    //font = scale().textResize(font,language().lang(10),soundv->size());
    lang_label->setFont(font);
    soundv->setAlignment(Qt::AlignCenter);
    musicv->setAlignment(Qt::AlignCenter);
    lang_label->setAlignment(Qt::AlignCenter);
    rusian->setText("Русский");
    englih->setText("English");

    //set text

    lang_label->setText(language().lang(10));
    sound_vol->setPageStep(50);
    music_vol->setPageStep(50);
    soundv->setText(language().lang(12));
    //musicv->setText(language().lang(11));
    reset1->setText("APPLY");//todo
    help->setText("HELP");//todo


    //aditional settings for text in widgets

    sound_vol->setValue(SOUND_VOL);
    music_vol->setValue(MUSIC_VOL);
    sound_vol->setOrientation(Qt::Orientation::Horizontal);
    music_vol->setOrientation(Qt::Orientation::Horizontal);
    lang_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
    soundv->setAlignment(Qt::AlignmentFlag::AlignCenter);
    musicv->setAlignment(Qt::AlignmentFlag::AlignCenter);
}

void settings::setup_layout()
{
    //initialization

    leave_tomenu = new QPushButton(this);
    help = new QPushButton(this);
    reset1 = new QPushButton(this);
    sound_vol = new QScrollBar(this);
    music_vol = new QScrollBar(this);
    rusian = new QPushButton(this);
    englih = new QPushButton(this);
    lang_label = new QLabel(this);
    soundv = new QLabel(this);
    musicv = new QLabel(this);
    background = new QLabel(this);

    //set stylesheets

    setStyleSheet("background-color: #779BF0;");
    lang_label->setStyleSheet("background-color: #779BF0;");
    background->setStyleSheet("background-color: #779BF0;");
    setStyleSheet("background-color: #779BF0;");
    if(LANGUAGE){
        rusian->setStyleSheet("*{background-color: #3e5486;"
                             "border-width: 10px;"
                              "border-top-right-radius: 7px;"
                              "border-bottom-right-radius: 7px;}");
        englih->setStyleSheet("*{border-width: 6px;"
                              "border-color: rgba(0,0,0,170);"
                              "border-top-left-radius: 7px;}");
    }
    else{
        englih->setStyleSheet("*{background-color: #3e5486;"
                              "border-width: 10px;"
                              "border-top-left-radius: 7px;"
                              "border-bottom-left-radius: 7px;}");
        rusian->setStyleSheet("*{border-width: 6px;"
                              "border-color: rgba(0,0,0,170);"
                              "border-bottom-right-radius: 7px;"
                              "border-top-right-radius: 7px;}");
    }
    sound_vol->setStyleSheet("*{"
                             "background-color: rgba(0,0,0,50);"
                             "color: #3e5486;"
                             "}");
    music_vol->setStyleSheet("*{"
                             "background-color: rgba(0,0,0,50);"
                             "}");

    reset1->hide();//not in use
    //help->setStyleSheet("background-color: rgba(0,0,0,50);");
    //leave_tomenu->setStyleSheet("background-color: rgba(0,0,0,50);");

    //set size policy

    QSizePolicy t = QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    leave_tomenu->setSizePolicy(t);
    help->setSizePolicy(t);
    reset1->setSizePolicy(t);
    sound_vol->setSizePolicy(t);
    music_vol->setSizePolicy(t);
    lang_label->setSizePolicy(t);
    soundv->setSizePolicy(t);
    musicv->setSizePolicy(t);
    englih->setSizePolicy(t); rusian->setSizePolicy(t);
    
    //add all widgets to QGridLayout and setup layout

    lay1 = new QGridLayout(this);
    lay1->setContentsMargins(0,0,0,0);
    lay1->addWidget(leave_tomenu, 0, 0, 1, 3);
    lay1->addWidget(help, 0, 3, 1, 2);
    lay1->addWidget(reset1, 7, 1, 1, 3);
    lay1->addWidget(sound_vol, 4, 0, 1, 6);
    lay1->addWidget(music_vol, 2, 0, 1, 6);
    lay1->addWidget(englih, 6, 1, 1, 2);
    lay1->addWidget(rusian, 6, 3, 1, 2);
    lay1->addWidget(lang_label, 5, 0, 1, 6);
    lay1->addWidget(soundv, 3, 0, 1, 6);
    lay1->addWidget(musicv, 1, 0, 1, 6);
    lay1->addWidget(background, 0, 0, 14,6);


    lay1->setSpacing(0);
    //////////////0,1,2,3,4,5,6,7
    int row[8] = {1,1,4,1,4,1,4,3};
    int col[8] = {1,50,50,50,50,1,0,0};
    for(int i=0;i<8;i++){
        lay1->setRowStretch(i, row[i]);
        lay1->setColumnStretch(i, col[i]);
    }
    background->lower();
    setLayout(lay1);
}

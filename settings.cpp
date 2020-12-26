#include "settings.h"
#include "save.h"
#include "languagesre.h"
#include "game.h"
#include "rett.h"
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
        englih->setStyleSheet("*{background-color: #828282;"
                              "border-width: 5px;"
                              "border-top-left-radius: 7px;"
                              "border-bottom-left-radius: 7px;"
                              "}");
        rusian->setStyleSheet("*{border-width: 3px;"
                              "border-color: #828282;"
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
        rusian->setStyleSheet("*{background-color: #828282;"
                              "border-width: 5px;"
                              "border-top-right-radius: 7px;"
                              "border-bottom-right-radius: 7px;}");
        englih->setStyleSheet("*{border-width: 3px;"
                              "border-color: #828282;"
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
    //saveNload().saveAll();
    delete leave_tomenu;
    delete help;
    delete reset1;
    delete sound_vol;
    delete music_vol;
    //delete language_box;
   // delete lang_icon;
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
    /*lang_label->setText(language().lang(10));
    soundv->setText(language().lang(12));
    musicv->setText(language().lang(11));
    if(LANGUAGE){
        rusian->setStyleSheet("*{background-color: #828282;"
                             "border-width: 2px;}");
        englih->setStyleSheet("*{border-width: 1px;"
                              "border-color: #828282;}");
    }
    else{
        englih->setStyleSheet("*{background-color: #828282;"
                              "border-width: 2px;}");
        rusian->setStyleSheet("*{border-width: 1px;"
                              "border-color: #828282;}");
    }*/
}

void settings::setup_layout()
{
    leave_tomenu = new QPushButton(this);
 //   leave_tomenu->setStyleSheet("*{border-image: url(:/icons/back_flat_right.png)}");//("border-image: url(:/button_back_pushed.svg);");
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/icons/back_flat_right1.png"), QSize(), QIcon::Normal, QIcon::Off);
    leave_tomenu->setIcon(icon);
    leave_tomenu->setIconSize(QSize(150,150));
    help = new QPushButton(this);
    reset1 = new QPushButton(this);
    sound_vol = new QScrollBar(this);
    music_vol = new QScrollBar(this);
    //sound_vol->setValue(10);
    //language_box = new QComboBox(this);
    rusian = new QPushButton(this);
    englih = new QPushButton(this);
   // lang_icon = new QFrame(this);
    lang_label = new QLabel(this);
    soundv = new QLabel(this);
    musicv = new QLabel(this);


    /////THIS IS FOR FONT IN RESOURCES/////
    int id = QFontDatabase::addApplicationFont(":/fonts/UbuntuMono-Bold.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);

    QFont font = QFont(family);
    //font.setFamily(QString::fromUtf8("Ubuntu Mono"));
    font.setPixelSize(50);
    font.setBold(true);
   // font.setWeight(75);
    font.setKerning(false);
    ///////////////////////////////////////
    rusian->setFont(font);
    englih->setFont(font);
    help->setFont(font);
    soundv->setFont(font);
    musicv->setFont(font);
    lang_label->setFont(font);
    soundv->setAlignment(Qt::AlignCenter);
    musicv->setAlignment(Qt::AlignCenter);
    lang_label->setAlignment(Qt::AlignCenter);
    rusian->setText("Русский");
    englih->setText("English");
    //rusian->setSizePolicy()
    //sound_vol->setValue(SOUND_VOL);
    //money_image->setStyleSheet("*{border-image: url(:/icons/Mmoney.png);}");
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if(LANGUAGE){
        rusian->setStyleSheet("*{background-color: #828282;"
                             "border-width: 5px;"
                              "border-top-right-radius: 7px;"
                              "border-bottom-right-radius: 7px;}");
        englih->setStyleSheet("*{border-width: 3px;"
                              "border-color: #828282;"
                              "border-top-left-radius: 7px;}");
    }
    else{
        englih->setStyleSheet("*{background-color: #828282;"
                              "border-width: 5px;"
                              "border-top-left-radius: 7px;"
                              "border-bottom-left-radius: 7px;}");
        rusian->setStyleSheet("*{border-width: 3px;"
                              "border-color: #828282;"
                              "border-bottom-right-radius: 7px;"
                              "border-top-right-radius: 7px;}");
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //leave_tomenu->setText("back");
    help->setText("HELP");//todo
    reset1->setText("APPLY");//todo

    /////
    reset1->hide();//за ненадобностью
    /////
    lang_label->setText(language().lang(10));
    sound_vol->setPageStep(50);
    music_vol->setPageStep(50);
    soundv->setText(language().lang(12));
    musicv->setText(language().lang(11));
    sound_vol->setValue(SOUND_VOL);
    music_vol->setValue(MUSIC_VOL);
  /*  if(LANGUAGE == 0){
        englih->setText("english");
    }
    else{
        rusian->setText("русский");
    }*/

    sound_vol->setOrientation(Qt::Orientation::Horizontal);
    music_vol->setOrientation(Qt::Orientation::Horizontal);

    lang_label->setAlignment(Qt::AlignmentFlag::AlignCenter);
    soundv->setAlignment(Qt::AlignmentFlag::AlignCenter);
    musicv->setAlignment(Qt::AlignmentFlag::AlignCenter);

    QSizePolicy t = QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    leave_tomenu->setSizePolicy(t);
    help->setSizePolicy(t);
    reset1->setSizePolicy(t);
    sound_vol->setSizePolicy(t);
    music_vol->setSizePolicy(t);
    //language_box->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
  //  lang_icon->setSizePolicy(t);
    lang_label->setSizePolicy(t);
    soundv->setSizePolicy(t);
    musicv->setSizePolicy(t);
    englih->setSizePolicy(t); rusian->setSizePolicy(t);
    
    lay1 = new QGridLayout(this);
    lay1->setContentsMargins(0,10,0,0);
    //////////////0,1,2,3,4,5,6,7
    int row[8] = {2,1,3,1,3,1,3,1};
    int col[8] = {1,50,50,50,50,1,0,0};
    for(int i=0;i<8;i++){
        lay1->setRowStretch(i, row[i]);
        lay1->setColumnStretch(i, col[i]);
    }

    lay1->addWidget(leave_tomenu, 0, 1, 1, 3);
    lay1->addWidget(help, 0, 3, 1, 2);
    lay1->addWidget(reset1, 7, 1, 1, 3);
    lay1->addWidget(sound_vol, 4, 0, 1, 6);
    lay1->addWidget(music_vol, 2, 0, 1, 6);
    //lay1->addWidget(language_box, 6, 0, 1, 3);
    lay1->addWidget(englih, 6, 1, 1, 2);
    lay1->addWidget(rusian, 6, 3, 1, 2);
    //lay1->addWidget(lang_icon, 6, 3, 1, 1);
    lay1->addWidget(lang_label, 5, 0, 1, 6);
    lay1->addWidget(soundv, 3, 0, 1, 6);
    lay1->addWidget(musicv, 1, 0, 1, 6);

    setLayout(lay1);
}

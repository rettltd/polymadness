#include "playmode.h"
#include "languagesre.h"
#include "scale.h"
#include <QPixmap>
#include <QFile>
#include <QFont>
#include <QIcon>
#include <QSize>
#include <QFontDatabase>
int Playmode::MODE_OF_GAME;

Playmode::Playmode(QWidget *parent) : QWidget(parent)
{
    //setup layout

    setup_layout();
}

void Playmode::buttonProc()
{
    QPushButton* B = qobject_cast<QPushButton*>(sender());
    if(B){
        MODE_OF_GAME = QString(B->objectName().at(2)).toInt();
    }
    emit ready();
}

void Playmode::setFonts()
{
    /////THIS IS FOR FONT IN RESOURCES/////
    int id = QFontDatabase::addApplicationFont(":/fonts/UbuntuMono-Bold.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);

    QFont font = QFont(family);

    font.setBold(true);
    font.setKerning(false);
    font = scale().textResize(font,language().lang(0)+"00",CHOOSE_GAME->size());
    CHOOSE_GAME->setFont(font);
    ///////////////////////////////////////

    ///set icons///

    //for back button
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/icons/back_flat_right1.png"), QSize(), QIcon::Normal, QIcon::Off);
    back->setIcon(icon);
    back->setIconSize(back->size());
    //for each of playmode buttons


    icon = QIcon();
    icon.addFile(QString::fromUtf8(":/icons/classic_mode.png"), QSize(), QIcon::Normal, QIcon::Off);
    game_classic->setIcon(icon);
    game_classic->setIconSize(game_classic->size());

    icon = QIcon();
    icon.addFile(QString::fromUtf8(":/icons/surv_mode.png"), QSize(), QIcon::Normal, QIcon::Off);
    game_survival->setIcon(icon);
    game_survival->setIconSize(game_survival->size());
}

Playmode::~Playmode()
{
    delete back;
    delete game_classic;
    delete game_2;
    delete game_survival;
    delete CHOOSE_GAME;
    delete LAY_OUT;

}

void Playmode::setup_layout()
{
    //widgets initialization

    back = new QPushButton(this);
    game_classic = new QPushButton(this);
    game_2 = new QPushButton(this);
    game_survival = new QPushButton(this);
    background = new QLabel(this);
    CHOOSE_GAME = new QLabel(this);

    //set objects names

    game_classic->setObjectName("B_0");
    game_survival->setObjectName("B_1");
    game_2->setObjectName("B_2");

    //setup texsts

    CHOOSE_GAME->setText(language().lang(0));

    //size policy

    back->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
    game_classic->setSizePolicy(QSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred));
    game_2->setSizePolicy(QSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred));
    game_survival->setSizePolicy(QSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred));

    //set stylesheets

    CHOOSE_GAME->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));
    /* //old style buttons and icons
    game_2->setStyleSheet("*{border-image: url(:/icons/comSoon.png);}");
    game_classic->setStyleSheet( "*{border-image: url(:/icons/classic_mode.png);"
                                 "border-color: #000000;"
                                 "border-width: 5px;}" );
    game_survival->setStyleSheet("*{border-image: url(:/icons/surv_mode.png);}");
    */
    setStyleSheet("background-color: #779BF0;");
    background->setStyleSheet("background-color: #779BF0;");

    //add all widgets to QGridLayout and setup layout

    LAY_OUT = new QGridLayout(this);
    LAY_OUT->addWidget(back, 0, 0, 1, 1);
    LAY_OUT->addWidget(game_classic, 2, 0, 1, 2);
    LAY_OUT->addWidget(game_survival, 3, 0, 1, 2);
    LAY_OUT->addWidget(game_2, 4, 0, 1, 2);
    LAY_OUT->addWidget(CHOOSE_GAME, 0, 1, 1, 1);
    LAY_OUT->addWidget(background,0,0,5,6);
    background->lower();//on background
    int rows[5] = {1,2,3,3,3};
    int cols[5] = {2,5,0,0,0};

    for(int i=0;i<5;i++){
        LAY_OUT->setRowStretch(i, rows[i]);
        LAY_OUT->setColumnStretch(i, cols[i]);
    }
    LAY_OUT->setContentsMargins(0,0,0,0);
    setLayout(LAY_OUT);
}

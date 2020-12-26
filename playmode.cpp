#include "playmode.h"
#include "languagesre.h"
#include "scale.h"
#include <QPixmap>
//#include <QImage>
#include <QFile>
#include <QFont>
#include <QIcon>
#include <QSize>
#include <QFontDatabase>
int Playmode::MODE_OF_GAME;

Playmode::Playmode(QWidget *parent) : QWidget(parent)
{
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
    font = scale().textResize(font,language().lang(0),CHOOSE_GAME->size());
    ///////////////////////////////////////
    CHOOSE_GAME->setFont(font);
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
    back = new QPushButton(this);
    game_classic = new QPushButton(this);
    game_2 = new QPushButton(this);
    game_survival = new QPushButton(this);
    CHOOSE_GAME = new QLabel(this);

    game_classic->setObjectName("B_0");
    game_survival->setObjectName("B_1");
    game_2->setObjectName("B_2");


    CHOOSE_GAME->setText(language().lang(0));


    back->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    game_classic->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    game_2->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    game_survival->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    CHOOSE_GAME->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    game_2->setStyleSheet("*{border-image: url(:/icons/comSoon.png);}");
    //game_2->setText(languages().comingSoon);
    //font.setPointSize(15);
    //game_2->setFont(font);
    game_classic->setStyleSheet( "*{border-image: url(:/icons/classic_mode.png);"
                                 "border-color: #000000;"
                                 "border-width: 5px;}" );

    game_survival->setStyleSheet("*{border-image: url(:/icons/surv_mode.png);}");
    LAY_OUT = new QGridLayout(this);
    LAY_OUT->addWidget(back, 0, 0, 1, 1);
    LAY_OUT->addWidget(game_classic, 2, 0, 1, 2);
    LAY_OUT->addWidget(game_survival, 3, 0, 1, 2);
    LAY_OUT->addWidget(game_2, 4, 0, 1, 2);
    LAY_OUT->addWidget(CHOOSE_GAME, 0, 1, 1, 1);

    int rows[5] = {1,2,2,2,2};
    int cols[5] = {2,5,0,0,0};

    for(int i=0;i<5;i++){
        LAY_OUT->setRowStretch(i, rows[i]);
        LAY_OUT->setColumnStretch(i, cols[i]);
    }
    LAY_OUT->setContentsMargins(3,3,3,3);
    ///sht
    //QImage img(":/button_back.png");
    //QPixmap pix(":/button_back.png");
    //pix = pix.fromImage(img.scaled(back->width(),back->height(),Qt::IgnoreAspectRatio,Qt::FastTransformation));
    //pix = pix.scaled(back->width()/pix.width(), back->height()/pix.height());//, Qt::IgnoreAspectRatio, Qt::FastTransformation);

    //back->setIcon(pix);
   // back->setStyleSheet(");
   //back->setIcon(pix);
   // back->setIconSize(pix.rect().size());
    /*QFile file(":/backbutton_styleSheet.qss");
    file.open(QIODevice::ReadOnly);
    QString line = file.readAll();
    */
    //file.close();
    QIcon icon;
     icon.addFile(QString::fromUtf8(":/icons/back_flat_right1.png"), QSize(), QIcon::Normal, QIcon::Off);
    back->setIcon(icon);
    back->setIconSize(QSize(150,150));
  ///  back->setStyleSheet("*{border-image: url(:/icons/back_flat_right.png);}");
                      //  ":pressed{ border-image: url(:/icons/button_back_pushed.png);}");//("border-image: url(:/button_back_pushed.svg);");
}

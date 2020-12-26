#include "stats.h"
#include "save.h"
#include "rett.h"
#include <QFont>
#include "languagesre.h"
#include <statistics.h>
#include <QDebug>
#include <QFontDatabase>
#include "scale.h"

Stats::Stats(QWidget *parent) : QWidget (parent)
{
    setup_layout();
}

Stats::~Stats()
{
    delete hiscor;
    delete back1;
    delete lay;
}

void Stats::setFonts()
{
    int id = QFontDatabase::addApplicationFont(":/fonts/UbuntuMono-Bold.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);


    QFont font = QFont(family);
    font = scale().textResize(font,"+++++++++++++++++++++++++++++++",hiscor->size());
    font.setBold(true);
    font.setKerning(false);

    hiscor->setFont(font);
    font = scale().textResize(font,back1->text(),back1->size());
    back1->setFont(font);
}

QString Stats::toScore(int sc)
{
    QString score = QString::number(sc);
    QString zero(5-score.size(),'0');
    zero += score;
    return zero;
}

void Stats::setup_layout()
{
    hiscor = new QLabel(this);
    QString ftext;

    if(saveNload().valueString("languages") == "english"){
    ftext = "___________________________\n"
            "|                         |\n"
            "|       !WELCOME!         |\n"
            "|_________________________|\n" "\n" "\n"
            "<<<[YOU GAME STATISTICS]>>>\n" "\n" "\n"
            "[<Classic-high-score>:   "+ toScore(saveNload().score(0)) +"]\n"
            "[<Classic-attempts>:     "+ toScore(saveNload().valueInt("classicAttempts")) +"]\n"
            "[<Survivival-high-score>:"+ toScore(saveNload().score(1)) +"]\n"
            "[<Survival-attempts>:    "+ toScore(saveNload().valueInt("survAttempts")) +"]\n"
            "[<Total-attempts>:       "+ toScore(saveNload().valueInt("survAttempts") + saveNload().valueInt("classicAttempts")) +"]\n";
    }
    else{
        ftext = "___________________________\n"
                "|                         |\n"
                "|   !ДОБРО ПОЖАЛОВАТЬ!    |\n"
                "|_________________________|\n" "\n" "\n"
                "<<<<<[ВАША СТАТИСТИКА]>>>>>\n" "\n" "\n"
                "[<Рекорд-в-Classic>:     "+ toScore(saveNload().score(0)) +"]\n"
                "[<Попыток-в-Classic>:    "+ toScore(saveNload().valueInt("classicAttempts")) +"]\n"
                "[<Рекорд-в-Survival>:    "+ toScore(saveNload().score(1)) +"]\n"
                "[<Попыток-в-Survival>:   "+ toScore(saveNload().valueInt("survAttempts")) +"]\n"
                "[<Всего-попыток>:        "+ toScore(saveNload().valueInt("survAttempts") + saveNload().valueInt("classicAttempts")) +"]\n"
                "x: " + QString().number(fuckinShit::x) + " y: " + QString().number(fuckinShit::y)
                ;
    }


    hiscor->setText( ftext);
    hiscor->setAlignment(Qt::AlignmentFlag::AlignCenter);


    back1 = new QPushButton(this);
    //font.setBold(1);
    back1->setText("<-- " + language().lang(20));

    QSizePolicy sp(QSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored));
    back1->setSizePolicy(sp);
    hiscor->setSizePolicy(QSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred));

    lay = new QVBoxLayout(this);
    lay->setStretch(0,5);
    lay->setStretch(1,1);
    lay->addWidget(hiscor);
    lay->addWidget(back1);
    hiscor->setScaledContents(true);
    setLayout(lay);
}

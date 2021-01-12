#include "stats.h"
#include "save.h"
#include "rett.h"
#include <QFont>
#include "languagesre.h"
#include <statistics.h>
#include <QDebug>
#include <QFontDatabase>
#include "scale.h"

Stats::Stats(QWidget *parent) : QWidget (parent),
    po1(aimcirc, vidx, vidy, rad123, speed)
{
    setup_layout();

    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &Stats::tick);

    timer->start(25);
    game = new Game(result_flag, *native, *score12, *hbr, vidx, vidy, aimcirc, po1, rad123, speed);

    game->setMode(2);

    connect(native, &Widget::game_tapped, [=]{result_flag=1;});

}

Stats::~Stats()
{
    delete hiscor;
    delete back1;
    delete lay;
    delete timer;
    delete game;
    delete native;
    delete hbr;
    delete score12;
}
///not in use so far
void Stats::setGame(Widget *widg)
{
    native = widg;
    //game = gameq;
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

void Stats::tick()
{
    //if(game->updateGame()) death_screen();
    update();
    native->tick();
    hbr->update();
    score12->update();
    game->updateGame();
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

    score12 = new score(this);
    hbr = new healthbar(this);
    score12->hide();
    hbr->hide();
    native = new Widget(vidx, vidy, aimcirc, po1, rad123, result_flag, this);
    native->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    native->setFrameShape(QFrame::WinPanel);
    native->setFrameStyle(QFrame::Sunken);
    native->setLineWidth(1);

    lay = new QGridLayout(this);
    lay->setSpacing(0);
    lay->setContentsMargins(0,0,0,0);
    native->setStyleSheet("background-color: #779BF0;");
    hiscor->setStyleSheet("background-color: rgba(0,0,0,50);");
    back1->setStyleSheet("background-color: rgba(0,0,0,50);");
    lay->addWidget(hiscor,0,0,5,1);
    lay->addWidget(back1,5,0,1,1);
    lay->addWidget(native,0,0,6,1);
    native->lower();
    hiscor->setScaledContents(true);
    setLayout(lay);
    vidx = native->sizeHint().width();
    vidy = native->sizeHint().height();
    native->lateinit();
}

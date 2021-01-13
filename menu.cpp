#include "menu.h"
#include "rett.h"
#include "money.h"
#include <QIcon>
//#include <QImage>
#include <QPixmap>
#include <QColor>
#include <QGraphicsOpacityEffect>
#include <QBrush>
menu::menu(QWidget *parent) : QWidget(parent),
  po1(aimcirc, vidx, vidy, rad123, speed)
{
    setup_layout();

    timer = new QTimer;
    connect(timer, &QTimer::timeout, this, &menu::tick);

    timer->start(25);
    game = new Game(result_flag, *native, *score12, *hbr, vidx, vidy, aimcirc, po1, rad123, speed);
    game->setMode(2);


    connect(native, &Widget::game_tapped, [=]{result_flag=1;});
}

void menu::setup_layout()
{
    to_game = new QPushButton(this);
    to_sets = new QPushButton(this);
    shop_button = new QPushButton(this);
    stats = new QPushButton(this);
   /// money_label  = new QLabel(this);
    animated = new QGraphicsView(this);
    ur_money = new QLCDNumber(this);
///    hint = new QLabel(this);
    money_image = new QPushButton(this);


    QSizePolicy qspol(QSizePolicy::Expanding, QSizePolicy::Expanding);

    native = new Widget(vidx, vidy, aimcirc, po1, rad123, result_flag, this);
    score12 = new score(this);
    hbr = new healthbar(this);
    native->setSizePolicy(qspol);
    score12->setSizePolicy(qspol);
    hbr->hide();
    score12->hide();

    native->setFrameShape(QFrame::WinPanel);
    native->setFrameStyle(QFrame::Sunken);
    native->setLineWidth(1);
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/icons/try_playButton.png"), QSize(), QIcon::Normal, QIcon::Off);
    to_game->setIcon(icon);
    to_game->setIconSize(QSize(150,150));
    icon.addFile(QString::fromUtf8(":/icons/shop.png"), QSize(), QIcon::Normal, QIcon::Off);
    shop_button->setIcon(icon);
    shop_button->setIconSize(QSize(150,150));
    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/icons/setting21.png"), QSize(), QIcon::Normal, QIcon::Off);
    to_sets->setIcon(icon1);
    to_sets->setIconSize(QSize(150,150));
    icon.addFile(QString::fromUtf8(":/icons/Mmoney.png"), QSize(), QIcon::Normal, QIcon::Off);
    money_image->setIcon(icon);
    money_image->setIconSize(QSize(100,100));
  //  QIcon icon2;
    icon.addFile(QString::fromUtf8(":/icons/stats1.png"), QSize(), QIcon::Normal, QIcon::Off);
    stats->setIcon(icon);
    stats->setIconSize(QSize(150,150));

    ur_money->display(money().getMooney());

    animated->setStyleSheet("background-color: #c3c3c3");
    //money_label->setStyleSheet("*{border-image: url(:/icons/money_flat.png);}");

  ///  money_label->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    to_game->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    to_sets->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    shop_button->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    stats->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    ur_money->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    animated->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
///    hint->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    money_image->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));//TODO квадратик

    animated->hide();

    lay = new QGridLayout(this);
    lay->setSpacing(0);
    lay->setContentsMargins(0,0,0,0);
    //QGraphicsOpacityEffect *qgreff;
    //qgreff = new QGraphicsOpacityEffect(this);
    //qgreff->setOpacity(0.3);
    //native->setGraphicsEffect(qgreff);
    ur_money->setStyleSheet("background-color: rgba(0,0,0,50);");
    to_game->setStyleSheet("background-color: rgba(0,0,0,50);");
    to_sets->setStyleSheet("background-color: rgba(0,0,0,50);");
    stats->setStyleSheet("background-color: rgba(0,0,0,50);");
    shop_button->setStyleSheet("background-color: rgba(0,0,0,50);");
    money_image->setStyleSheet("background-color: rgba(0,0,0,50);");
    setStyleSheet("background-color: #779BF0;");
    ur_money->setSegmentStyle(QLCDNumber::Flat);
    lay->addWidget(native, 0, 0, 4, 7);
    lay->addWidget(ur_money, 0, 0, 1, 3);
    lay->addWidget(to_game, 0, 4, 1, 3);
    lay->addWidget(to_sets, 3, 2, 1, 3);
    lay->addWidget(stats, 3, 5, 1, 2);
    lay->addWidget(shop_button, 3, 0, 1, 2);
    lay->addWidget(money_image, 0, 3, 1, 1);
    native->lower();
//    lay->addWidget(hint, 1, 0, 1, 7);//////0,5 // 1,1
    ///lay->setContentsMargins(4, 3, 4, 3);
//setStyleSheet(" background-color:  #a5a5a5;");
    //qDebug() << to_game->size();
   // to_game->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
   // to_game->setFixedWidth(to_game->height());

  //  lay->setAlignment(to_game,Qt::AlignCenter);
   // qDebug() << to_game->size();

///////////////////0/1/2//3/4/5/6
    int rows[7] = {3,1,16,3,0,0,0};
    int cols[7] = {1,1,1 ,1,1,1,1};

    for(int i=0;i<7;i++){
        lay->setRowStretch(i, rows[i]);
        lay->setColumnStretch(i, cols[i]);
    }

    setLayout(lay);

    vidx = native->sizeHint().width();
    vidy = native->sizeHint().height();
    native->lateinit();
}

menu::~menu()
{
    delete to_game; to_game = nullptr;
    delete to_sets; to_sets = nullptr;
    delete shop_button; shop_button = nullptr;
    delete stats; stats = nullptr;
    delete lay; lay= nullptr;
 ///   delete hint;
    delete ur_money; ur_money = nullptr;
    delete animated; animated = nullptr;
    delete money_image; money_image = nullptr;
    ///  delete money_label; money_label = nullptr;
    ///
    delete timer;timer=nullptr;
    delete game;game=nullptr;
    delete native;native=nullptr;
    delete hbr;hbr=nullptr;
    delete score12;score12=nullptr;
}

void menu::tick()
{
    //if(game->updateGame()) death_screen();
    update();
    native->tick();
    hbr->update();
    score12->update();
    game->updateGame();
}


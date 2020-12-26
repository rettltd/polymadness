#include "menu.h"
#include "rett.h"
#include "money.h"
#include <QIcon>
//#include <QImage>
#include <QPixmap>
#include <QColor>
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
   // to_game->setText("Play");
   // to_sets->setText("Settings");
 /*  QPixmap img(":/try_playButton.png");
  qWarning() << !img.isNull();
   QIcon icon;
   icon.addPixmap(img,QIcon::Normal,QIcon::Off);
   to_game->setIcon(icon);*/
  // to_game->setIconSize(to_game->size());
   //qWarning() << img.isNull();
  // QPixmap pix(":/icons/to_settings2.png");
   //pix = pix.scaled(to_game->width(),to_game->height(),Qt::AspectRatioMode::KeepAspectRatioByExpanding);
   //qDebug() << pix.height()<< "     " <<  to_game->height() << "\n";
   //pix = pix.scaled(to_game->height(),to_game->height(),Qt::IgnoreAspectRatio,Qt::FastTransformation);//fromImage(img.scaled(to_game->height(),to_game->height(),Qt::IgnoreAspectRatio,Qt::FastTransformation));
   //pix = pix.scaled(back->width()/pix.width(), back->height()/pix.height());//, Qt::IgnoreAspectRatio, Qt::FastTransformation);/ _kill_->setText("EXIT");
   // to_game->setIcon(QIcon(pix));
    //to_game->setIconSize(QSize(to_game->size()));
    //qDebug() << to_game->size() << to_game->iconSize();
    //qDebug() << pix.height() << pix.width();

    // to_game->setIconSize(QSize(pix.height(), pix.width()));
     //qDebug() <<  to_game->iconSize();
    ///stats->setStyleSheet("*{border-image: url(:/icons/stats.png);}");
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
    ///   to_game->setStyleSheet("*{border-image: url(:/icons/try_playButton.png);}");
///
//  to_game->setIconSize(QSize(to_game->height(),to_game->height()));
   //to_game->setIcon(icon);
                       // ":pressed{ border-image: url(:/icons/play_button_pressed.png);}");
///    shop_button->setStyleSheet("*{border-image: url(:/icons/shop.png);}");
                    //   ":pressed{ border-image: url(:/icons/home_button_flat_pressed.png);}");
///    to_sets->setStyleSheet("*{border-image: url(:/icons/setting2.png);}");
                     //      ":hover{ border-image: url(:/icons/to_settings1_pressed.png);}");
    //ur_money->setFont(QFont("ubuntu-mono",10,QFont::Bold)); //???
///    money_image->setStyleSheet("*{border-image: url(:/icons/Mmoney.png);}");
                              //  "                                   background-color: #a5a5a5;}");
     ///QBrush bru(QColor("#a5a5a5"));
///  money_image->setBackgroundBrush(bru);a5a5a5
  ///   saveNload().save("money",5000);
  ///
    //qDebug() << saveNload().valueInt("money");
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
   // to_game->setFixedWidth(to_game->height());

   // lay->setAlignment(Qt::AlignCenter);

    animated->hide();

    lay = new QGridLayout(this);
    lay->setSpacing(0);
    lay->setContentsMargins(0,0,0,0);
    lay->addWidget(ur_money, 0, 0, 1, 3);
    lay->addWidget(to_game, 0, 4, 1, 3);
    lay->addWidget(to_sets, 3, 2, 1, 3);
    lay->addWidget(stats, 3, 5, 1, 2);
    lay->addWidget(shop_button, 3, 0, 1, 2);
    lay->addWidget(native, 1, 0, 2, 7);

    lay->addWidget(money_image, 0, 3, 1, 1);
//    lay->addWidget(hint, 1, 0, 1, 7);
    lay->setContentsMargins(4, 3, 4, 3);
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

    vidx = native->sizeHint().width();
    vidy = native->sizeHint().height();
    native->lateinit();

    setLayout(lay);
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
    delete timer;
    delete game;
    delete native;
    delete hbr;
    delete score12;
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


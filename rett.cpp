#include "rett.h"
#include <QDir>
#include <QStandardPaths>
#include <QUrl>
#include <QApplication>
#include <QDebug>
#include "languages.h"
#include <QTimer>
#include <QRandomGenerator>
#define qrand() QRandomGenerator::global()->generate()

int fuckinShit::x, fuckinShit::y;
//sound rett::button_pop;
QSoundEffect rett::button_pop;
//audio rett::musixPlayer;

rett::rett(QWidget *parent) : QMainWindow(parent)
{
    //musixPlayer = new audio();
    window = nullptr;
    setObjectName(tr("rett"));
    //button_pop.setSoundSource(":/audio/sonds/button.wav");
    button_pop.setSource(QUrl("qrc:/audio/sounds48/button.wav"));
    lang_change();


    musixPlayer.addToPlaylist(QUrl("qrc:/audio/menu4.ogg"));
    musixPlayer.addToPlaylist(QUrl("qrc:/audio/track3.ogg"));
    musixPlayer.addToPlaylist(QUrl("qrc:/audio/sad1.ogg"));
    musixPlayer.addToPlaylist(QUrl("qrc:/audio/track2.ogg"));

    musixPlayer.setPlaylist();

    musixPlayer.setVolume(settings::MUSIC_VOL);
    musixPlayer.setCurrentTrack(0);
    //volume
    musixPlayer.play();
    musixPlayer.loop();
    //menu1234 = nullptr;
/*    window = nullptr;
    sets = nullptr;
    game_choose = nullptr;
    stats1 = nullptr;
    shop = nullptr;*/
    set_menu();
}

void rett::set_menu()
{
    flag_proc();
    menu1234 = new menu(this);

    connect(menu1234->to_game, &QPushButton::clicked, [=]{button_pop.play();});
    connect(menu1234->to_sets, &QPushButton::clicked, [=]{button_pop.play();});
    connect(menu1234->shop_button, &QPushButton::clicked, [=]{button_pop.play();});
    connect(menu1234->stats, &QPushButton::clicked, [=]{button_pop.play();});
    //connect(menu1234->money_image, &QPushButton::clicked, [=]{button_pop.play();});

    connect(menu1234->to_game, &QPushButton::clicked, this, &rett::set_gamemenu);
    connect(menu1234->to_sets, &QPushButton::clicked, this, &rett::set_sets);
    connect(menu1234->shop_button, &QPushButton::clicked, this, &rett::set_shop);
    connect(menu1234->stats, &QPushButton::clicked, this, &rett::set_stats);
    //connect(menu1234->shop_button, &QPushButton::clicked, this, [=]{shop->setFonts();});
    //connect(menu1234->money_image, &QPushButton::clicked, this, &rett::set_shop);

    QTimer *timer1 = new QTimer();
    timer1->callOnTimeout(menu1234, &menu::setFonts);
    timer1->setTimerType(Qt::TimerType::PreciseTimer);
    timer1->setSingleShot(1);
    timer1->start(3);

    setCentralWidget(menu1234);
    flag=0;
}

void rett::set_game()
{
    flag_proc();
    window = new Window(this, Playmode::MODE_OF_GAME);
    //int x = qrand()%2;
    //x= x*2 + 1;
    musixPlayer.setCurrentTrack((qrand()%2)*2+1);

    connect(window->pause, &QPushButton::clicked, [=]{button_pop.play();});
    connect(window->to_menu, &QPushButton::clicked, [=]{button_pop.play();});

    connect(window->pause, &QPushButton::clicked, window, &Window::flagProc);
    connect(window->to_menu, &QPushButton::clicked, this, &rett::set_gamemenu);

    connect(window, &Window::paused, [=]{musixPlayer.pause(); backgr=2;});
    connect(window, &Window::continued, [=]{musixPlayer.play(); backgr=0;});
    connect(window, &Window::dead, [=]{musixPlayer.setCurrentTrack(2);});
    connect(window, &Window::restarted, [=]{musixPlayer.setCurrentTrack((qrand()%2)*2+1);});

    QTimer *timer1 = new QTimer();
    timer1->callOnTimeout(window, &Window::setFonts);
    timer1->setTimerType(Qt::TimerType::PreciseTimer);
    timer1->setSingleShot(1);
    timer1->start(3);

    setCentralWidget(window);
    flag=1;
}

void rett::set_sets()
{
    flag_proc();
    sets = new settings(this);
    connect(sets->leave_tomenu, &QPushButton::clicked, [=]{button_pop.play();});
    connect(sets->leave_tomenu, &QPushButton::clicked, this, &rett::set_menu);

    connect(sets, &settings::sound_chd, this, &rett::muvol_change);
    connect(sets, &settings::lang_chd, this, &rett::lang_change);

    setCentralWidget(sets);

    QTimer *timer1 = new QTimer();
    timer1->callOnTimeout(sets, &settings::setFonts);
    timer1->setTimerType(Qt::TimerType::PreciseTimer);
    timer1->setSingleShot(1);
    timer1->start(3);

    flag=2;
}

void rett::set_gamemenu()
{
    flag_proc();
    game_choose = new Playmode(this);
    if(musixPlayer.playlist->currentIndex())musixPlayer.setCurrentTrack(0);
    if(!musixPlayer.isActive())musixPlayer.play();

    connect(game_choose->back, &QPushButton::clicked, [=]{button_pop.play();});
    connect(game_choose->game_classic, &QPushButton::clicked, [=]{button_pop.play();});
    connect(game_choose->game_2, &QPushButton::clicked, [=]{button_pop.play();});
    connect(game_choose->game_survival, &QPushButton::clicked, [=]{button_pop.play();});

    connect(game_choose->back, &QPushButton::clicked, this, &rett::set_menu);
    connect(game_choose->game_classic, &QPushButton::clicked, game_choose, &Playmode::buttonProc);
    connect(game_choose->game_2, &QPushButton::clicked, game_choose, &Playmode::buttonProc);
    connect(game_choose->game_survival, &QPushButton::clicked, game_choose, &Playmode::buttonProc);
    connect(game_choose, &Playmode::ready, this, &rett::set_game);
    setCentralWidget(game_choose);

    QTimer *timer1 = new QTimer();
    timer1->callOnTimeout(game_choose, &Playmode::setFonts);
    timer1->setTimerType(Qt::TimerType::PreciseTimer);
    timer1->setSingleShot(1);
    timer1->start(3);

    flag=3;
}

void rett::set_stats()
{
    flag_proc();
    stats1 = new Stats(this);
    connect(stats1->back1, &QPushButton::clicked, [=]{button_pop.play();});
    connect(stats1->back1, &QPushButton::clicked, this, &rett::set_menu);

    QTimer *timer1 = new QTimer();
    timer1->callOnTimeout(stats1, &Stats::setFonts);
    timer1->setTimerType(Qt::TimerType::PreciseTimer);
    timer1->setSingleShot(1);
    timer1->start(3);

    setCentralWidget(stats1);
    stats1->setFonts();
    flag=4;
}


void rett::set_shop()
{
    flag_proc();
    shop = new GameShop();
    connect(shop->back, &QPushButton::clicked, [=]{button_pop.play();});
    connect(shop->back, &QPushButton::clicked, this, &rett::set_menu);//back

    connect(shop->button1, &QPushButton::clicked, shop, &GameShop::buttonProc);
    connect(shop->button2, &QPushButton::clicked, shop, &GameShop::buttonProc);
    connect(shop->button3, &QPushButton::clicked, shop, &GameShop::buttonProc);
    connect(shop->button4, &QPushButton::clicked, shop, &GameShop::buttonProc);
    connect(shop->button5, &QPushButton::clicked, shop, &GameShop::buttonProc);
    QTimer *timer1 = new QTimer();
    timer1->callOnTimeout(shop, &GameShop::setFonts);
    timer1->setTimerType(Qt::TimerType::PreciseTimer);
    timer1->setSingleShot(1);
    timer1->start(10);

    setCentralWidget(shop);
    flag=5;


}

void rett::lang_change()
{
    if(settings().LANGUAGE) saveNload().save("languages","russian");
    else saveNload().save("languages","english");
    /*sets->changeSettsLanguage();
    languages *lang = new languages();
    lang->read(saveNload().valueString("languages"));//ээ ватафак?        /// это чтоб язык инициализировать,мб криво,но работает
    delete lang;
    button_pop.setVolume(settings::SOUND_VOL);
    Game::offf.setVolume(settings::SOUND_VOL);
    Game::poped.setVolume(settings::SOUND_VOL);
    Game::boom12.setVolume(settings::SOUND_VOL);
    saveNload().save("musicVol")*/
}

void rett::muvol_change()
{
    musixPlayer.setVolume(settings::MUSIC_VOL);
}

void rett::go_background()
{
    QApplication* app1 = qobject_cast<QApplication*>(sender());
    backgr = app1->applicationState();
    switch (backgr) {
    case Qt::ApplicationState::ApplicationActive:
        if(window == nullptr)musixPlayer.play();
        break;
    case Qt::ApplicationState::ApplicationHidden:
        musixPlayer.pause();
        if(window)window->pause_menu();
        break;
    case Qt::ApplicationState::ApplicationInactive:
        musixPlayer.pause();
        if(window)window->pause_menu();
        break;
    case Qt::ApplicationState::ApplicationSuspended:
        musixPlayer.pause();
        if(window)window->pause_menu();
        break;
    default:
        break;
    }
}

void rett::keyReleaseEvent(QKeyEvent *e)
{
    //QMainWindow::keyReleaseEvent(e);
    if(e->key() == Qt::Key::Key_Back){
        switch (flag) {
        case 0:

            break;
        case 1:
            window->flagProc();
            break;
        case 2:
            set_menu();
            break;
        case 3:
            set_menu();
            break;
        case 4:
            set_menu();
            break;
        default:
            break;
        }
    }
}

void rett::closeEvent(QCloseEvent *clE)
{
    musixPlayer.pause();
    musixPlayer.unloop();
    //musixPlayer->stop();

    //delete musixPlayer;
    //musixPlayer = nullptr;
    //QCoreApplication::quit();
    //musixPlayer.pause();
    //musixPlayer.unloop();
    //musixPlayer.stop();
    //menu1234 = nullptr;
    //  flag_proc();
    //  clE->accept();
    //  this->close();
}

void rett::flag_proc()
{
    switch(flag){
    case 0:

        delete menu1234;
        menu1234 = nullptr;
        break;
    case 1:
        delete window;
        window = nullptr;
        break;
    case 2:
        saveNload().save("soundVolume", settings::SOUND_VOL);
        saveNload().save("musicVolume", settings::MUSIC_VOL);
        saveNload().save("language", settings::LANGUAGE);
        delete sets;
        sets = nullptr;
        break;
    case 3:
        delete game_choose;
        game_choose = nullptr;
        break;
    case 4:
        delete stats1;
        stats1 = nullptr;
        break;
    case 5:
        delete shop;
        shop = nullptr;
        break;
    default:
        break;
    }
}

/*
rett::~rett(){
    switch(flag){
    case 0:
        delete menu1234;
        menu1234 = nullptr;
        break;
    case 1:
        delete window;
        window = nullptr;
        break;
    case 2:
        delete sets;
        sets = nullptr;
        break;
    case 3:
        delete game_choose;
        game_choose = nullptr;
        break;
    case 4:
        delete stats1;
        stats1 = nullptr;
        break;
    case 5:
        delete shop;
        shop = nullptr;
        break;
    default:
        break;
    }
}
*/

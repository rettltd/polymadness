#ifndef RETT_H
#define RETT_H

#include <QMainWindow>
#include "window.h"
#include "menu.h"
#include "settings.h"
#include "playmode.h"
#include "stats.h"
#include "gameshop.h"

#include "audio.h"

class fuckinShit
{
public:
    static int x, y;
};

class rett : public QMainWindow
{
    Q_OBJECT
public:
    explicit rett(QWidget *parent = nullptr);

    Window *window;
    menu *menu1234;
    settings *sets;
    Playmode *game_choose;
    Stats *stats1;
    GameShop *shop;

    audio musixPlayer;
    //static sound button_pop;
    static QSoundEffect button_pop;

    qint8 flag=0xFF;//0 - menu/ 1 - game/ 2 - settings

public slots:
    void set_menu();
    void set_game();
    void set_sets();
    void set_gamemenu();
    void set_stats();
    void set_shop();
    void lang_change();
    void muvol_change();

    void go_background();
protected:
    void keyReleaseEvent(QKeyEvent* e) override;
    void closeEvent(QCloseEvent* clE) override;
    //~rett() override;

private:
    void flag_proc();

    qint8 backgr = 1;
};

#endif // RETT_H

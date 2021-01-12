#ifndef MENU_H
#define MENU_H
#include "widget.h"
#include "game.h"
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLCDNumber>
#include <QLabel>
#include <QTimer>
#include "score.h"
#include "healthbar.h"
#include <QGraphicsView>

class menu : public QWidget
{
    Q_OBJECT
public:
    menu(QWidget *parent = nullptr);

    virtual ~menu();

    QPushButton *to_game;
    QPushButton *to_sets;
    QPushButton *shop_button;
    QPushButton *stats;
    QLabel *money_label;
    QPushButton *money_image;

    QLCDNumber *ur_money;

    healthbar *hbr;
///    QLabel *hint;

public slots:
    void tick();
private:
    QTimer *timer;
    QGridLayout *lay;
    QGraphicsView *animated;
    Widget *native;
    score *score12;
    void setup_layout();
    Game *game;
    int vidx, vidy;
    QPolygonF aimcirc;
    polyar po1;
    char result_flag=0;
    qreal rad123;
    float speed=1;

};

#endif // MENU_H

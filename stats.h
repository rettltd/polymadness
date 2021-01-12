#ifndef STATS_H
#define STATS_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QTimer>
#include "score.h"
#include "widget.h"
#include "game.h"
#include "healthbar.h"
#include <QGraphicsView>
#include <QGridLayout>

class Stats : public QWidget
{
public:
    Stats(QWidget *parent = nullptr);
    virtual ~Stats();

    QPushButton *back1;
    void setGame(Widget *widg);
    healthbar *hbr;
public slots:
    void setFonts();
    void tick();
private:
    QString toScore(int sc);
    void setup_layout();
    QLabel *hiscor;
    QGridLayout *lay;
    Widget *native;
    Game *game;
    QTimer *timer;
    int vidx, vidy;
    QPolygonF aimcirc;
    polyar po1;
    char result_flag=0;
    qreal rad123;
    score *score12;
    float speed=1;
};

#endif // STATS_H

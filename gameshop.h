#include <QLabel>
#include <QPushButton>
#include <QToolButton>
#include <QBoxLayout>
#include <QLCDNumber>
#include <QGraphicsView>
#include <QFont>
#include <QGraphicsOpacityEffect>
#include "money.h"
#ifndef GAMESHOP_H
#define GAMESHOP_H

#include <QWidget>

struct ShopButton{

};

class GameShop : public QWidget
{
    Q_OBJECT
public:
    GameShop(QWidget* parent = nullptr);
    virtual ~GameShop();



    QPushButton *back;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;

public slots:
    int buttonProc();
    void setFonts();

private:
    QGraphicsOpacityEffect *eff1,*eff2,*eff3,*eff4;
    bool isInform = 0;/// для показа информации(для switch)
    void setButtons(int Nomb);/// аналогично,чтобы короче код был
    money *moneY;


    QGridLayout *MainLay;//0

    QHBoxLayout *topLay;//1
    QLCDNumber *lcdNumber;
    QGraphicsView *coinImg;
    //1

    QGridLayout *gridLayout;//1

    QFrame *area1;//2
    QVBoxLayout *alay1;
    QLabel *cost1;
    QLabel *lvl1;
    //2

    QFrame *area2;//2
    QVBoxLayout *alay2;
    QLabel *cost2;
    QLabel *lvl2;
    //2

    QFrame *area3;//2
    QVBoxLayout *alay3;
    QLabel *cost3;
    QLabel *lvl3;
    //2

    QFrame *area4;//2
    QVBoxLayout *alay4;
    QLabel *cost4;
    QLabel *lvl4;
    //2
    //1
    QHBoxLayout *lowLay;//1
    QSpacerItem *spacer;
    QSpacerItem *spacer1;
    //QPushButton *information;
    //1

    QLabel *info1=nullptr;
    QLabel *info2=nullptr;
    QLabel *info3=nullptr;
    QLabel *info4=nullptr;

    //0
    void setup_layout();
};

#endif // GAMESHOP_H

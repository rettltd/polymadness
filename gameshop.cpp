#include "gameshop.h"
#include <QDebug>
#include <QString>
#include "languagesre.h"
#include "rett.h"
#include <QSize>
#include <QIcon>
#include <QSizeF>
#include <QFontDatabase>
#include "scale.h"
GameShop::GameShop(QWidget* parent) : QWidget (parent)
{
    setup_layout();
}

GameShop::~GameShop()
{
    delete eff1; eff1 = nullptr;
    delete eff2; eff2 = nullptr;
    delete eff3; eff3 = nullptr;
    delete eff4; eff4 = nullptr;
    delete info1;info1= nullptr;
    delete info2;info2= nullptr;
    delete info3;info3= nullptr;
    delete info4;info4= nullptr;
}

void GameShop::setFonts()
{
    qDebug() << "Im here";
    /////////////////////////////////////////
    ///____THIS IS FOR FONT IN RESOURCES___//
    /////////////////////////////////////////
    int id = QFontDatabase::addApplicationFont(":/fonts/UbuntuMono-Bold.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);

    QFont font = QFont(family);
    font.setPixelSize(30);
    font.setBold(true);
    font.setKerning(false);
    //font = scale().textResize(font,"###################",QSize(226,30));
    if(saveNload().valueString("languages") == "russian") font = scale().textResize(font,"Money Boost (10/10)",lvl1->size());
    else font = scale().textResize(font,"Money Boost (10/10)",lvl1->size());
    qDebug() << "kk - -" << lvl1->size();

    lvl1->setFont(font);
    lvl2->setFont(font);
    lvl3->setFont(font);
    lvl4->setFont(font);

    cost1->setFont(font);
    cost2->setFont(font);
    cost3->setFont(font);
    cost4->setFont(font);

    info1->setFont(font);
    info2->setFont(font);
    info3->setFont(font);
    info4->setFont(font);
    font.setPixelSize(font.pixelSize()+ 5);
    button5->setFont(font);


    ///////////////////////////////////////////
    ///____ICONS____________________________///
    ///////////////////////////////////////////
    QIcon icon;
    icon.addFile(QString::fromUtf8(":/icons/back_flat_left1.png"), QSize(), QIcon::Normal, QIcon::Off);
    back->setIcon(icon);
    back->setIconSize(QSize(150,150));

    icon = QIcon();
    icon.addFile(QString::fromUtf8(":/icons/shopHP.png"), QSize(), QIcon::Normal, QIcon::Off);
    button1->setStyleSheet("border-width: 1px;");
    button1->setIcon(icon);
    button1->setIconSize(button1->size());
    icon = QIcon();
    icon.addFile(QString::fromUtf8(":/icons/shop_money.png"), QSize(), QIcon::Normal, QIcon::Off);
    button2->setStyleSheet("border-width: 1px;");
    button2->setIcon(icon);
    button2->setIconSize(button2->size());
    icon = QIcon();
    icon.addFile(QString::fromUtf8(":/icons/shop_polygon.png"), QSize(), QIcon::Normal, QIcon::Off);
    button3->setStyleSheet("border-width: 1px;");
    button3->setIcon(icon);
    button3->setIconSize(button3->size());
    icon = QIcon();
    icon.addFile(QString::fromUtf8(":/icons/shop_heal.png"), QSize(), QIcon::Normal, QIcon::Off);
    button4->setStyleSheet("border-width: 1px;");
    button4->setIcon(icon);
    button4->setIconSize(button4->size());
}

void GameShop::setButtons(int Nomb){
    QString lvlStr,lvlFinal;
    switch (Nomb) {
    case 1:
        lvlStr = QString::number(moneY->getLVLs(1));
        lvlFinal = language().lang(6) +  " (" +lvlStr + "/10)";//+ " : " + languages().level + lvlStr;
        lvl1->setText(lvlFinal);//setNum(moneY->getLVLs(1) );
        if(moneY->getLVLs(1) !=  10){
            QString h,finalStr;
            h = QString::number(moneY->getValues(1));
            finalStr =language().lang(5)+" " + h;
            cost1->setText(finalStr);//setNum(moneY->getValues(1));
        }          // 230 - max Value
        else{ cost1->setText(language().lang(4));}
        break;
    case 2:
        lvlStr = QString::number(moneY->getLVLs(2));
        lvlFinal = language().lang(7)+  " (" +lvlStr + "/10)" ;// + " : "+ languages().level + lvlStr;
        lvl2->setText(lvlFinal);
        if(moneY->getLVLs(2) < 10){
            QString h,finalStr;
            h = QString::number(moneY->getValues(2));
            finalStr =language().lang(5) +" " + h;
            cost2->setText(finalStr);//setNum(moneY->getValues(1));
        }          // 230 - max Value
        else {
           cost2->setText(language().lang(4));
        }
        break;
    case 3:
        lvlStr = QString::number(moneY->getLVLs(3));
        lvlFinal = language().lang(8) +  " (" +lvlStr + "/7)";//+ " : "+ languages().level + lvlStr;
        lvl3->setText(lvlFinal);
        if(moneY->getLVLs(3) < 7){
            QString h,finalStr;
            h = QString::number(moneY->getValues(3));
            finalStr = language().lang(5)+" " + h;
            cost3->setText(finalStr);//setNum(moneY->getValues(1));
        }          // 230 - max Value
        else {
           cost3->setText(language().lang(4));
        }
        break;
    case 4:
        lvlStr = QString::number(moneY->getLVLs(4));
        lvlFinal = language().lang(9)+  " (" +lvlStr + "/2)";// + " : " + languages().level + lvlStr;
        lvl4->setText(lvlFinal);
        if(moneY->getLVLs(4) < 2){
            QString h,finalStr;
            h = QString::number(moneY->getValues(4));
            finalStr = language().lang(5) +" " + h;
            cost4->setText(finalStr);//setNum(moneY->getValues(1));
        }          // 230 - max Value
        else {
           cost4->setText(language().lang(4));
        }
        break;
    default:
        break;
    }
}

int GameShop::buttonProc()
{
    /*
     * 1- HP
     * 2- money_vel
     * 3- addPolygon
     * 4- moreHeal
     *
     */
    int boughtItem=0;
    QPushButton* B = qobject_cast<QPushButton*>(sender());
    if(B){
        boughtItem = QString(B->objectName().at(6)).toInt();
    }
    //emit ready();
    QString lvlStr,lvlFinal;
    //qDebug() << "ok";
    switch (boughtItem) {//TODO
    case 1://hp
        //qDebug() << lvl1->size() << "  " << lvl1->sizeHint() << endl;
        //setFonts();
        lcdNumber->display(moneY->upgrade(1));
        setButtons(1);
        break;//money_vel
    case 2:
        lcdNumber->display(moneY->upgrade(2));
        setButtons(2);
        break;
    case 3://addPolygon
        lcdNumber->display(moneY->upgrade(3));
        setButtons(3);

        break;
    case 4://moreHeal
        lcdNumber->display(moneY->upgrade(4));
        setButtons(4);

        break;
    case 5:

        if(!isInform){
            button5->setStyleSheet("*{border-width: 2px;"
                                   "background-color:#828282;}");
            eff1->setOpacity(0.2);
            eff2->setOpacity(0.2);
            eff3->setOpacity(0.2);
            eff4->setOpacity(0.2);

            button1->setGraphicsEffect(eff1);
            button2->setGraphicsEffect(eff2);
            button3->setGraphicsEffect(eff3);
            button4->setGraphicsEffect(eff4);
            alay1->replaceWidget(button1, info1);
            alay2->replaceWidget(button2, info2);
            alay3->replaceWidget(button3, info3);
            alay4->replaceWidget(button4, info4);

            info1->show();
            info2->show();
            info3->show();
            info4->show();
            cost1->hide();
            cost2->hide();
            cost3->hide();
            cost4->hide();
            lvl1->hide();
            lvl2->hide();
            lvl3->hide();
            lvl4->hide();
            isInform = 1;
        }
        else{
            button5->setStyleSheet("*{border-width: 1px;}");


            eff1->setOpacity(1);
            eff2->setOpacity(1);
            eff3->setOpacity(1);
            eff4->setOpacity(1);


            button1->setGraphicsEffect(eff1);
            button2->setGraphicsEffect(eff2);
            button3->setGraphicsEffect(eff3);
            button4->setGraphicsEffect(eff4);


            alay1->replaceWidget(info1, button1);
            alay2->replaceWidget(info2, button2);
            alay3->replaceWidget(info3, button3);
            alay4->replaceWidget(info4, button4);


            info1->hide();
            info2->hide();
            info3->hide();
            info4->hide();


            cost1->show();
            cost2->show();
            cost3->show();
            cost4->show();


            lvl1->show();
            lvl2->show();
            lvl3->show();
            lvl4->show();

            isInform = 0;
        }
        break;


    default:
        break;
    }
    return boughtItem;
}

void GameShop::setup_layout()
{
    moneY = new money();

    QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(1);
    sizePolicy.setVerticalStretch(1);

    MainLay = new QGridLayout(this);
    MainLay->setSpacing(0);
    MainLay->setContentsMargins(0, 0, 0, 0);

    topLay = new QHBoxLayout();
    lcdNumber = new QLCDNumber(this);
    coinImg = new QGraphicsView(this);
    coinImg->setStyleSheet("*{background-color: #a5a5a5;"
                           "border-style: flat;}");
    back = new QPushButton(this);

    lcdNumber->setSizePolicy(sizePolicy);
    lcdNumber->display(money().getMooney());
    coinImg->setSizePolicy(sizePolicy);
    back->setSizePolicy(sizePolicy);

    topLay->addWidget(lcdNumber);
    topLay->addWidget(coinImg);
    topLay->addWidget(back);


    gridLayout = new QGridLayout();


    QString lvlStr,lvlFinal; // для надписей и цены


    //for info anumation
    eff1 = new QGraphicsOpacityEffect;
    eff2 = new QGraphicsOpacityEffect;
    eff3 = new QGraphicsOpacityEffect;
    eff4 = new QGraphicsOpacityEffect;




    area1 = new QFrame(this);
    alay1 = new QVBoxLayout(area1);
    cost1 = new QLabel(area1);
    lvl1 = new QLabel(area1);
    button1 = new QPushButton(area1);
    info1 = new QLabel(language().lang(21), area1); /// ***== here's this shit
    info1->setWordWrap(true);
    info1->setAlignment(Qt::AlignCenter);


    button1->setObjectName("button1");
    button1->setSizePolicy(sizePolicy);
    area1->setFrameShape(QFrame::StyledPanel);
    lvl1->setSizePolicy(sizePolicy);
    alay1->addWidget(cost1);
    alay1->addWidget(button1);
    alay1->addWidget(lvl1);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///make strigs for cost and lvl
    /// todo : enable translator
    lvl1->setText(lvlFinal);
    setButtons(1);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    area2 = new QFrame(this);
    //area2->setFrameShadow(QFrame::Raised);
    alay2 = new QVBoxLayout(area2);
    cost2 = new QLabel(area2);
    button2 = new QPushButton(area2);
    lvl2 = new QLabel(area2);
    info2 = new QLabel(language().lang(22), area2);
    info2->setWordWrap(true);
    info2->setAlignment(Qt::AlignCenter);
    // sizePolicy2.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
    button2->setSizePolicy(sizePolicy);
    button2->setObjectName("button2");
   // button2->setText("money velocity");
    area2->setFrameShape(QFrame::StyledPanel);


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    lvl2->setText(lvlFinal);
    setButtons(2);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    lvl2->setSizePolicy(sizePolicy);


    alay2->addWidget(cost2);
    alay2->addWidget(button2);
    alay2->addWidget(lvl2);


    area3 = new QFrame(this);
    alay3 = new QVBoxLayout(area3);
    cost3 = new QLabel(area3);
    button3 = new QPushButton(area3);
    lvl3 = new QLabel(area3);
    info3 = new QLabel(language().lang(23), area3);
    info3->setWordWrap(true);
    info3->setAlignment(Qt::AlignCenter);

    button3->setSizePolicy(sizePolicy);
    button3->setObjectName("button3");
    area3->setFrameShape(QFrame::StyledPanel);



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    lvl3->setText(lvlFinal);
    setButtons(3);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    lvl3->setSizePolicy(sizePolicy);

    alay3->addWidget(cost3);
    alay3->addWidget(button3);
    alay3->addWidget(lvl3);


    area4 = new QFrame(this);
    alay4 = new QVBoxLayout(area4);
    cost4 = new QLabel(area4);
    button4 = new QPushButton(area4);
    lvl4 = new QLabel(area4);
    info4 = new QLabel(language().lang(24), area4);
    info4->setAlignment(Qt::AlignCenter);
    info4->setWordWrap(true);


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    lvl4->setText(lvlFinal);
    setButtons(4);
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



    button4->setSizePolicy(sizePolicy);
    button4->setObjectName("button4");
  //  button4->setText("heal");
    area4->setFrameShape(QFrame::StyledPanel);
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    lvl4->setSizePolicy(sizePolicy);

    alay4->addWidget(cost4);
    alay4->addWidget(button4);
    alay4->addWidget(lvl4);

    gridLayout->addWidget(area1, 0, 0, 1, 1);
    gridLayout->addWidget(area2, 0, 1, 1, 1);
    gridLayout->addWidget(area3, 1, 0, 1, 1);
    gridLayout->addWidget(area4, 1, 1, 1, 1);


    info1->hide();
    info2->hide();
    info3->hide();
    info4->hide();


    info1->setSizePolicy(QSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored));
    info2->setSizePolicy(QSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored));
    info3->setSizePolicy(QSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored));
    info4->setSizePolicy(QSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored));


    info1->setStyleSheet("background-color: transparent");
    info2->setStyleSheet("background-color: transparent");
    info3->setStyleSheet("background-color: transparent");
    info4->setStyleSheet("background-color: transparent");
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
    info1->setScaledContents(true);
    info2->setScaledContents(true);
    info3->setScaledContents(true);
    info4->setScaledContents(true);


    lvl1->setScaledContents(true);
    lvl2->setScaledContents(true);
    lvl3->setScaledContents(true);
    lvl4->setScaledContents(true);


    cost1->setScaledContents(true);
    cost2->setScaledContents(true);
    cost3->setScaledContents(true);
    cost4->setScaledContents(true);


    cost1->setSizePolicy(sizePolicy);
    cost2->setSizePolicy(sizePolicy);
    cost3->setSizePolicy(sizePolicy);
    cost4->setSizePolicy(sizePolicy);
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
    lowLay = new QHBoxLayout();
    button5 = new QPushButton(this);


    button5->setObjectName("button5");
    button5->setText(language().lang(25));
    button5->setSizePolicy(sizePolicy1);//хз плохо или хорошо
    //button5->setStyleSheet("border-width: 1px");

    lowLay->addWidget(button5);
    MainLay->addLayout(topLay, 0, 0, 1, 1);
    MainLay->addLayout(gridLayout, 1, 0, 6, 1);
    MainLay->addLayout(lowLay, 2, 7, 1, 1);

    /*
    MainLay->setStretch(0, 1);
    MainLay->setStretch(1, 6);
    MainLay->setStretch(2, 1);
    */
    qDebug() << lvl1->size();
    //font = scale().textResize(font,"Money Boost (10/10)",lvl1->size());
}

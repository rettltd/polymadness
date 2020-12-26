#include "score.h"
//#include <stdlib.h>
#include <QPainter>
#include <QString>
#include "money.h"
#include "statistics.h"
#include "playmode.h"
//int score::whichGame;

score::score(QWidget *parent) : QLCDNumber(parent)
{
    //setText(QString().setNum(m_pts));
    //setAlignment(Qt::AlignmentFlag::AlignCenter);
    display(m_pts);
    setFrameStyle(QFrame::StyledPanel);
    setFrameShadow(QFrame::Sunken);
}

void score::save()
{
    statistics().setAttemps(Playmode::MODE_OF_GAME);
    statistics().highScore(m_pts,Playmode::MODE_OF_GAME);
    money().addMooney(m_pts);
}

void score::inc()
{
    m_pts++;
    //setText(QString().setNum(m_pts));
    display(m_pts);
}

void score::null()
{
    m_pts=0;
    display(0);
}

qint16 score::getHi()
{
    return static_cast<qint16>(saveNload().score(0));//0;//DataRWer::HI_SCORE;
}

void score::paintEvent(QPaintEvent *e)
{
    QLCDNumber::paintEvent(e);
}

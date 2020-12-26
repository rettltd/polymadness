#ifndef SCORE_H
#define SCORE_H

#include <QPainter>
#include <QFrame>
#include <QLabel>
#include <QLCDNumber>
#include <QFile>
#include "save.h"

class score : public QLCDNumber
{
public:
   // static int whichGame;
    score(QWidget *parent = nullptr);
    void save();
    void inc();
    void null();
    qint16 getHi();
    qint32 m_pts = 0;
protected:
    void paintEvent(QPaintEvent* e) override;
private:

    QFile file;
};

#endif // SCORE_H

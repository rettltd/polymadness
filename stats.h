#ifndef STATS_H
#define STATS_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include "score.h"

class Stats : public QWidget
{
public:
    Stats(QWidget *parent = nullptr);
    virtual ~Stats();

    QPushButton *back1;
public slots:
    void setFonts();
private:
    QString toScore(int sc);
    void setup_layout();
    QLabel *hiscor;
    QVBoxLayout *lay;
};

#endif // STATS_H

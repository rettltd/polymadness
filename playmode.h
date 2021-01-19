#ifndef PLAYMODE_H
#define PLAYMODE_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class Playmode : public QWidget
{
    Q_OBJECT
public:
    Playmode(QWidget *parent = nullptr);

    virtual ~Playmode();

    static int MODE_OF_GAME;

    QPushButton *back;
    QPushButton *game_classic;
    QPushButton *game_2;
    QPushButton *game_survival;
public slots:
    void buttonProc();
    void setFonts();
signals:
    void ready();
private:
    void setup_layout();
    QLabel *background;//SHOULD BE FIXED(problems with background ss and global qss)
    QGridLayout *LAY_OUT;
    QLabel *CHOOSE_GAME;
};

#endif // PLAYMODE_H

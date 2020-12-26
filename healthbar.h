#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QPolygonF>
#include <QPainter>
#include <QWidget>
#include <QProgressBar>

class healthbar : public QProgressBar
{
    Q_OBJECT
public:
    int health = 50;
    int addHealth;
    healthbar(QWidget *parent = nullptr);
    void boom();
    void misclick();
    void lifeup();
    void amount_lifeup(int lyf);

protected:

private:
    const int max_health = 100;

};

#endif // HEALTHBAR_H

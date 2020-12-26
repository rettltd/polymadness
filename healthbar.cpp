#include "healthbar.h"
#include <QSizePolicy>
#include <QPolygonF>
#include "money.h"
//#include <QDebug>

healthbar::healthbar(QWidget *parent) : QProgressBar (parent)
{
   // health = 10;
    health = money().hitPoints();
    addHealth = money().getBoost(4);
    //qDebug() << addHealth;
    setMinimum(0);
    setMaximum(max_health);
    setValue(health);
}

void healthbar::boom()
{
    health -= 25;
    health = (health > 0)*health;
    setValue(health);
}

void healthbar::misclick()
{
    health -= 10;
    health = (health > 0)*health;
    setValue(health);
}

void healthbar::lifeup()
{
    health += addHealth;
    if(health > max_health) health = max_health;
    setValue(health);
}

void healthbar::amount_lifeup(int lyf)
{
    health += lyf;
    if(health > 100) health = 100;
    setValue(health);
}


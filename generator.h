#ifndef POLYGONGENERETOR_H
#define POLYGONGENERETOR_H
#include <QPolygon>
#include <QPoint>
#include <QPointF>
class polygonGeneretor
{
public:
    polygonGeneretor();
    static const QPolygonF & polygon(qreal rad123);
private:
    static QPolygonF pol;
};

#endif // POLYGONGENERETOR_H

#ifndef SCALE_H
#define SCALE_H
#include <QFont>
#include <QString>
#include <QSize>
class scale
{
public:
    static int width,height;
    static QFont textResize(QFont font,QString str,QSize bW);
    scale();
};

#endif // SCALE_H

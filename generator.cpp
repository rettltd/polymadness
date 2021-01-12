#include "generator.h"
#include <QTransform>
#include <QRandomGenerator>
#include <math.h>
#include "widget.h"
//#include <QDebug>
#include "money.h"

#define qrand() QRandomGenerator::global()->generate()

QPolygonF polygonGeneretor::pol;

polygonGeneretor::polygonGeneretor()
{
    pol.resize(3);
}

const QPolygonF &polygonGeneretor::polygon(qreal rad123){
    qint8 varitaions = money().getBoost(3);

    qint8 variable = qrand() % varitaions;
   /// qDebug() << variable;
    qreal scale = (qrand()%1000/qreal(800) + 2.3)*rad123*0.22;
   // variable = 7;

    qreal a=0, b=0;

    /*
    int verts;
    qreal k_in;
    */

    pol.clear();
    switch (variable){
    case 0://triangle

        qreal angle1;
        angle1 = (qrand() % 31 + 90.0) / 360.f * 3.1415;
        a = qrand() % 30 + 60;
        b = qrand() % 30 + 60;
        pol << QPointF(0,0) << QPointF(a* cos(angle1),a * sin(angle1)) << QPointF(0,b);
        pol = QTransform().scale(scale, scale).map(pol);
        return pol;


    case 1:
        /*pol << QPointF(0, 0) << QPointF(20, 0) << QPointF(40, 20)
            << QPointF(20, 40) << QPointF(0, 20);*/

        /*verts = qrand()%6+3;

        pol.resize(verts);
        pol[0].setX(0); pol[0].setY(-rad123*10);
        for(int i1=1; i1<verts; i1++){
            //t=X;
            pol[i1].setX(pol.at(i1-1).x()*cos(2*3.1416/double(verts))-pol.at(i1-1).y()*sin(2*3.1416/double(verts)));
            pol[i1].setY(pol.at(i1-1).y()*cos(2*3.1416/double(verts))+pol.at(i1-1).x()*sin(2*3.1416/double(verts)));
        }

        pol = QTransform().scale(0.6*scale, 0.6*scale).map(pol);*/

        // rectang
             a = qrand() % 30 + 60;
             b = qrand() % 30 + 60;
             pol << QPointF(0,0) << QPointF(a, 0) << QPointF(a,b) << QPointF(0,b);
             pol = QTransform().scale(scale, scale).map(pol);
             return pol;

    case 2:
        //sq tri
        pol << QPointF(0, 0) << QPointF(60,60) << QPointF(60, 0);
        pol = QTransform().scale(scale, scale).map(pol);
        return pol;

    case 3:
        //true tri

                pol << QPointF(0, -65.11) << QPointF(56.39, 32.56)
                    << QPointF(-56.39, 32.56);
                pol = QTransform().scale(0.7*scale, 0.7*scale).map(pol);
                return pol;

    case 4:
        //square
        pol << QPointF(0,0) << QPointF(50, 0)
            << QPointF(50,50) << QPointF(0, 50);

        pol = QTransform().scale(scale, scale).map(pol);
        return pol;

    case 5:

        // песочные часы

        pol << QPointF(0, 0) << QPointF(30,30) << QPointF(30, 0) << QPointF(0, 30);
        //pol = QTransform().scale(1.2, 1.2).map(pol);
        pol = QTransform().scale(1.2*scale, 1.2*scale).map(pol);
        return pol;
    case 6:
/*        if(qrand()%2){
            verts = 3;//qrand()%4 + 3;
            k_in = 0.3;//(qrand()%3 + 3)/10.f;
        }
        else {
            verts = 5;//qrand()%4 + 3;
            k_in = 0.4;//(qrand()%3 + 3)/10.f;
        }
        pol.resize(verts*2);
        pol[0].setX(0); pol[0].setY(-rad123*10);//starb.setPoint(0, Vector2f(0, -rad));
        pol[verts].setX(0); pol[verts].setY(rad123*10*k_in);//starb.setPoint(5, Vector2f(0, rad/2.5));
        for(int i1=1; i1<verts; i1++){
            //t=X;
            pol[2*i1].setX(pol.at(i1*2-2).x()*cos(2*3.1416/double(verts))-pol.at(i1*2-2).y()*sin(2*3.1416/double(verts)));//X=X*cos(72*3.1416/180.0) - Y*sin(72*3.1416/180.0);
            pol[2*i1].setY(pol.at(i1*2-2).y()*cos(2*3.1416/double(verts))+pol.at(i1*2-2).x()*sin(2*3.1416/double(verts)));//Y=Y*cos(72*3.1416/180.0) + t*sin(72*3.1416/180.0);
            //starb.setPoint(i*2, Vector2f(X, Y));
            pol[(2*i1+verts)%(verts*2)].setX(-k_in*pol.at(i1*2).x());//starb.setPoint(((i+2)*2+1)%10, Vector2f(-X/2.5, -Y/2.5));
            pol[(2*i1+verts)%(verts*2)].setY(-k_in*pol.at(i1*2).y());////  0/6 | 2
        }
        //pol = QTransform().scale(0.6, 0.6).map(pol);
        pol = QTransform().scale(0.6*scale, 0.6*scale).map(pol);*/

        //penta
        /*
        pol << QPointF(20, 20) << QPointF(60, 20) << QPointF(60, 60)
            << QPointF(40, 80) << QPointF(20, 40);*/
        pol << QPointF(0, -64.52) << QPointF(61.37, -19.94)
            << QPointF(37.93, 52.2) << QPointF(-37.93, 52.2)
            << QPointF(-61.37, -19.94);
        pol = QTransform().scale(0.6*scale, 0.6*scale).map(pol);
        return pol;
    case 7:
        //hexa
                pol << QPointF(0, -69.53) << QPointF(60.22, -34.77)
                    << QPointF(60.22, 34.77) << QPointF(0, 69.53)
                    << QPointF(-60.22, 34.77) << QPointF(-60.22, -34.77);

                pol = QTransform().scale(0.6*scale, 0.6*scale).map(pol);
                return pol;
    case 8://star??
        pol << QPointF(0, -67.63) << QPointF(15.9, -21.89)
            << QPointF(64.32, -20.9) << QPointF(25.73, 8.36)
            << QPointF(39.75, 54.72) << QPointF(0, 27.05)
            << QPointF(-39.75, 54.72) << QPointF(-25.73, 8.36)
            << QPointF(-64.32, -20.9) << QPointF(-15.9, -21.89);

        pol = QTransform().scale(0.6*scale, 0.6*scale).map(pol);
        return pol;
    case 9://tri star
        pol << QPointF(0, -87.16) << QPointF(22.65, -13.07)
            << QPointF(75.48, 43.58) << QPointF(0, 26.15)
            << QPointF(-75.48, 43.58) << QPointF(-22.64, -13.07);
        pol = QTransform().scale(0.6*scale, 0.6*scale).map(pol);
        return pol;
    case 10:
        //stop sign
        pol << QPointF(0, -81.49) << QPointF(57.62, -57.62)
            << QPointF(81.49, 0) << QPointF(57.62, 57.62)
            << QPointF(0, 81.49) << QPointF(-57.62, 57.62)
            << QPointF(-81.49, 0) << QPointF(-57.62, -57.62);

        pol = QTransform().scale(0.4*scale, 0.4*scale).map(pol);

        return pol;
    case 11:

        //mosquito)))
        pol << QPointF( 0 ,  -67.8823 ) <<
        QPointF( 2.55364 ,  -3.51472 ) <<
        QPointF( -25.824 ,  8.39063 ) <<
        QPointF( 4.13182 ,  1.34256 ) <<
        QPointF( 6.38398 ,  8.7869 ) <<
        QPointF( 0 ,  27.1529 ) <<
        QPointF( -6.38411 ,  8.78681 ) <<
        QPointF( 0 ,  0 ) <<
        QPointF( -10.3295 ,  -3.3564 ) <<
        QPointF( 0 ,  0 );
        pol = QTransform().scale(scale, scale).map(pol);
        return pol;

    case 256:

        pol << QPointF( 0 ,  0 ) <<
        QPointF( 10 ,  0 ) <<
        QPointF( 10 ,  8 ) <<
        QPointF( 0 ,  10 );
        pol = QTransform().scale(scale, scale).map(pol);
        return pol;

    default:
        return pol;
    }
}

const QPolygonF &polygonGeneretor::klax(qreal rad123, int type)
{
    const qint8 difffe = 2;
    qint8 variable = qrand() % difffe;
    qreal scale = (qrand()%1000/qreal(800) + 2.3)*rad123*0.22;

    /*
    qreal a=0, b=0;

    int verts;
    qreal k_in;
*/
    pol.clear();

    if(type==1)//plus-cross figure
    {
        pol << QPointF( 2 ,  2 ) <<
        QPointF( 8 ,  2 ) <<
        QPointF( 8 ,  -2 ) <<
        QPointF( 2 ,  -2 ) <<
        QPointF( 2 ,  -8 ) <<
        QPointF( -2 ,  -8 ) <<
        QPointF( -2 ,  -2 ) <<
        QPointF( -8 ,  -2 ) <<
        QPointF( -8 ,  2 ) <<
        QPointF( -2 ,  2 ) <<
        QPointF( -2 ,  8 ) <<
        QPointF( 2 ,  8 );
        pol = QTransform().scale(scale, scale).map(pol);
        return pol;
    }
    else if(type==2)
    {
        /*
        pol << QPointF( 0 ,  0 ) <<
        QPointF( 10 ,  0 ) <<
        QPointF( 10 ,  8 ) <<
        QPointF( 0 ,  10 );
        */
        int verts = qrand()%9+3;
        qreal k_in = 1.4;
        qreal rotA = 2*3.1416/double(verts);

        pol.resize(verts*2);
        pol[0].setX(0);
        pol[0].setY(-rad123*10);

        pol[verts].setX(0);
        pol[verts].setY(rad123*10*k_in);

        for(int i=1; i<verts; i++){
            pol[2*i].setX(pol.at(i*2-2).x() * cos(rotA) - pol.at(i*2-2).y() * sin(rotA));
            pol[2*i].setY(pol.at(i*2-2).y() * cos(rotA) + pol.at(i*2-2).x() * sin(rotA));

            pol[(2*i+verts)%(verts*2)].setX(-k_in*pol.at(i*2).x());
            pol[(2*i+verts)%(verts*2)].setY(-k_in*pol.at(i*2).y());
        }

        pol = QTransform().scale(scale, scale).map(pol);
        return pol;
    }

    switch (variable)
    {
    case 0:
        pol << QPointF( 0 ,  0 ) <<
        QPointF( 10 ,  0 ) <<
        QPointF( 10 ,  8 ) <<
        QPointF( 0 ,  10 );
        pol = QTransform().scale(scale, scale).map(pol);
        return pol;
    case 1:

        pol << QPointF( 6.8 ,  0 ) <<
        QPointF( 12.73,  -2.65 ) <<
        QPointF( 15.17,  -5.32 ) <<
        QPointF( 14.8,  -7.91 ) <<
        QPointF( 12.9,  -11 ) <<
        QPointF( 7.25 ,  -11 ) <<
        QPointF( 6.26 ,  -10.47 ) <<
        QPointF( 5.24,  -6.8 ) <<
        QPointF( 3.52,  -5.2 ) <<
        QPointF( 0.57,  -5.13 ) <<
        QPointF( -0.87,  -6.26 ) <<
        QPointF( -2.81 ,  -9.72 )<<
        QPointF( -7.25 ,  -12.9 )<<
               QPointF( -12 ,  -13.03 )<<
               QPointF( -15.37 ,  -10.22 )<<
               QPointF( -14.83 ,  -6.38 )<<
               QPointF( -11.43 ,  -3.71 )<<
               QPointF( -7.88 ,  -2.44 )<<
               QPointF( -6.41 ,  -0.83 )<<
               QPointF( -8.95 ,  2.64 )<<
               QPointF( -9.09 ,  7.42 )<<
               QPointF( -7.75 ,  8.59 )<<
               QPointF( -4 ,  8.55 )<<
               QPointF( 0 ,  6.58 )<<
               QPointF( 2.2 ,  6.68 )<<
               QPointF( 4.08 ,  9.05 )<<
               QPointF( 5.85 ,  9.69 )<<
               QPointF( 6.35 ,  8.92 )<<
               QPointF( 4.94 ,  5 )<<
               QPointF( 4.88 ,  1.84 );

        pol = QTransform().scale(0.8*scale, 0.8*scale).map(pol);
        return pol;
    case 2:
        pol << QPointF( 0 ,  0 ) <<
        QPointF( 10 ,  0 ) <<
        QPointF( 10 ,  8 ) <<
        QPointF( 0 ,  10 );
        pol = QTransform().scale(scale, scale).map(pol);
        return pol;
    }
    return pol;
}


/*QPointF polygonGeneretor::coords(){
    if(qrand() % 2){
        if(qrand()%2){
            X = -100;
            Y = qrand() % 400 - 100;
        }
        else{
            X = 300;
            Y = qrand() % 400 - 100;
        }

    }
    else{
        if(qrand()%2){
                Y = -100;
                X = qrand() % 400 -100;
            }
        else{
                Y = 300;
                X = qrand() % 400 - 100;
        }
       }
        return QPointF(X,Y);
    }
*/

/*qreal polygonGeneretor::angle(int width,int height){
    if(Y < 300 && Y > -100){
        angl = acos(sqrt((X - width/2) * (X - width/ 2) + (Y - height / 2) * ( Y - height / 2)) / (width / 2));
    }  else {
        angl = acos(sqrt((X - width/2) * (X - width/ 2) + (Y - height / 2) * ( Y - height / 2)) / (height / 2));
    }
    return angl;
}
*/













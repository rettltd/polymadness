#include "polyar_copy.h"
#include "polyn69.h"
#include "widget.h"
#include <QString>
#include <QRandomGenerator>
//#include <klaxlife.h>



polyar::polyar(QPolygonF &ac, int &vx, int &vy, qreal &r123, float &sp)
    : aimcirc(ac), vidx(vx), vidy(vy), rad123(r123), speed(sp)
{

}

polyar::~polyar()
{

}

void polyar::colChk(int it2)
{
    for(int it = 0; it < vec.size(); it++)
    {
        if( (vec.at(it).bombflag==0) && vec[it2].containsP(vec.at(it).poly1) )
        {
            //vec.removeAt(it);
            //let poly turn gray;
            vec[it].bombflag = 3;
            //break;
        }
    }
}

void polyar::append()
{
    polyn69 r(rad123, vidx, vidy, speed);
    vec.append(r);
    //td=0
}

void polyar::appendKlax(qreal x, qreal y, QColor color, int type)
{
    // 1 = heal, 2 = bomb, 3 = norm
    polyn69 r;

    r.poly1 = polygonGeneretor().klax(rad123, type);
    r.setPos(x, y);
    r.setRot(QRandomGenerator::global()->generateDouble()*2*3.142);
    //r.setCol(color);
    switch (type) {
    case 1:
        r.bombflag = 2;
        break;
    case 2:
        r.setCol(QColor(255,200,0));
        break;
    case 3:
        r.setCol(color);
    }
    r.countCentr();

    KlaxLife x11(r);
    to_trash.push_back(x11);
}

void polyar::popAt(int at)
{
    if(at<vec.size())vec.removeAt(at);
}

polyn69 polyar::at(int at_)
{
    return vec.at(at_);
}

void polyar::append(polyn69 RE)
{
    vec.append(RE);
}

void polyar::prepend(polyn69 RE)
{
    vec.prepend(RE);
}

qint8 polyar::popTouched()
{
    int it;
    for(it = 0; it < vec.size(); it++){
        if(vec[it].containsP(aimcirc)) goto label1;
    }
    ///here i should do -3 hp (misclick) (*and return that*)
    return -1;
label1:

    int result=0;


    if(vec.at(it).bombflag==0 || vec.at(it).bombflag==3){
        result = 3;//score ++
        /*
        vec.removeAt(it);
        return 3;
        */
    }
    else if(vec.at(it).bombflag==2){
        result = 1;//hp up
        /*
        vec.removeAt(it);
        return 1;
        */
    }
    else{
        result = 2;///here's boom -6 hp
        /*
        vec.removeAt(it);
        return 2;
        */
    }

    appendKlax(vec.at(it).xcenter, vec.at(it).ycenter, vec[it].getCol(), result);
    vec.removeAt(it);
    return result;
}

qint8 polyar::update()
{
    /*td += 5;
        //необх усл//|||дополнительно влияет на частоту
    if((td > 100) && ((rand()%450 + td/2.2f) > 400)) append(); // связать с бустом (а именно td > 0.5)*/

    for(std::list<KlaxLife>::iterator it = to_trash.begin(); it != to_trash.end(); )
    {
        if(it->cycle())
        {
            to_trash.erase(it++);
        }
        else
        {
            it++;
        }
    }

    for(int it = 0; it < vec.size(); it++){
        vec[it].update();
        if(vec.at(it).bombflag==1) colChk(it);
    }
    for(int it = 0; it < vec.size(); it++){
        if(vec[it].outscreen(vidx, vidy)){
            if(vec.at(it).bombflag==0)
            {
                vec.removeAt(it);/// -2 hp
                return 1;
            }
            else vec.removeAt(it);//ok
        }
    }
    return 0;
}

void polyar::draw(QPainter &w)
{
    for(std::list<KlaxLife>::iterator it = to_trash.begin(); it != to_trash.end(); it++){
        it->draw(w);
    }
    for(int it = 0; it < vec.size(); it++){
        vec[it].draw(w);
    }
}

void polyar::clear()
{
    vec.clear();
}

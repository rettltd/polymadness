#include "statistics.h"
#include "save.h"
int statistics::highSurvScore;
int statistics::highClassicScore;
int statistics::attemps;
statistics::statistics()
{

}
void statistics::setAttemps(int flag){
    switch (flag) {
    case 0:
        saveNload().save("classicAttempts",(saveNload().valueInt("classicAttempts") + 1));
        break;
    case 1:
         saveNload().save("survAttempts",(saveNload().valueInt("survAttempts") + 1));
        break;
    default:break;
    }
    attemps = saveNload().valueInt("Attemps");
    saveNload().save("Attemps",attemps);
}

int statistics::getScore(int flag)
{
    return saveNload().score(flag);
}
void statistics::highScore(int score,int flag){
    if(score > saveNload().score(flag)){
    saveNload().setScore(flag,score);
    }
    ///Already made in healthbar, so it for future
}


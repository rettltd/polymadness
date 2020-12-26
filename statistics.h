#ifndef STATISTICS_H
#define STATISTICS_H


class statistics
{
public:
    statistics();
    static void highScore(int score,int flag);
    static void setAttemps(int flag);
    static int getScore(int flag);
    static int attemps;
    static int highSurvScore;
    static int highClassicScore;


};

#endif // STATISTICS_H

#ifndef JUGDESYS_H
#define JUGDESYS_H


class jugdeSys
{
public:

    int steps;
    int eliminateTimes;

    int getScore();//通过消除次数和剩余步数算分
    bool IsWin();
    jugdeSys();
};

#endif // JUGDESYS_H

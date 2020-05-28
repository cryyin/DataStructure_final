#ifndef PLAYER_H
#define PLAYER_H


class player
{
public:
    player();

    char playerName;
    int score;
    int money;
    int phyAttack;
    int magicAttack;
    int gasVolume;
    int blood;

    void printData();
    void readData();
};

#endif // PLAYER_H

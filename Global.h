#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <thread>
#include <windows.h>
#include <QDialog>
#include <QMouseEvent>
#include <QTimer>

#define CHESS_COUNT 6
#define MAP_SIZE 12
#define ICON_SIZE 40
#define WIN_SIZE 640

using namespace std;



class CGameLogic{
public:
   CGameLogic();
   void disturb();
   int getBoard(int x,int y);
   void setBoard(int x,int y,int value);

private:
   int board[MAP_SIZE][MAP_SIZE];
};

class CAppTool{
public:
   CAppTool();
   void readFile();
   QPixmap pictures[CHESS_COUNT+1];
};


#endif // GLOBAL_H

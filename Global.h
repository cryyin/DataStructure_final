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
#include "audioclip.h"
#include <QtCore/QCoreApplication>
#include <QtMultimedia/QMediaPlayer>
#include <iostream>
#include <string>
#include<fstream>
#include <QInputDialog>
#include <QDate>
#include <QMessageBox>
#include <sstream>
#include <QCloseEvent>


#define CHESS_COUNT 7 //棋子种类
#define ICON_COUNT 2 //图标种类
#define MAP_SIZE 12 //地图单行棋子数量
#define ICON_SIZE 40    //图标大小
#define WIN_SIZE 640    //棋盘大小
#define MONSTER_COUNT 1 //怪物数量
#define MONSTERMOVEMENT_COUNT 20 //怪物图片数量
#define BOSS1_HEALTH 140 //boss1血量
#define BOSS1_STEPS 50//boss1限制步数

using namespace std;


/**
 * @brief The CRoleAttr class
 *
 * 角色类，用于储存各项数值
 */
class CRoleAttr{
public:
   CRoleAttr();
   int health=100;//血量
   int attack=0;//攻击
   int armour=0;//护甲
   int magic=0;//魔法值
   int potion=0;//药水
   int gold=0;//金锭
};

/**
 * @brief The CGameLogic class
 *
 * 游戏逻辑类，用于处理生成棋盘，棋子消除，计算角色数值
 */
class CGameLogic{
public:
   CGameLogic();
   void initBoard();//初始化棋盘
   void disturbBoard(int x,int y,int value);//对指定点位进行不重复分配(半随机，判定重复)
   void constructBoard();//填补棋盘空缺的棋子(全随机，不判定重复)
   int getBoard(int x,int y);//返回指定坐标的图片值
   void setBoard(int x,int y,int value);//设定指定坐标的图片值
   bool checkAdjacent(int x1,int y1,int x2,int y2);//判断两点是否相邻
   bool checkMove(int x1,int y1,int x2,int y2);//检测相邻的两点是否可以交换位置
   bool checkBoard();//检测棋盘是否含有可清除棋子，如果有则填充为1
   void clearBoard();//清除棋盘中可清除的棋子
   void downBoard();//下落棋子
   CRoleAttr role;//玩家角色
   bool isDowning=false;//是否在下落
   bool checkBoardStuck();//检测是否死局
   void remindBoard();//更新可移动棋子的数组
   void choseRemind(int temp_point[2][2]);//从可移动数组中选出一对棋子位置，填入传递数组中
   int bossHealth;//boss1血量
   bool playerWin=false;//玩家胜负
   int playerStep=BOSS1_STEPS;//剩余步数
   QMediaPlayer * player = new QMediaPlayer;//消除音效


private:
   int board[MAP_SIZE][MAP_SIZE];//棋盘数组
   int board_clear[MAP_SIZE][MAP_SIZE];//棋盘消除数组
   int moveable_point[MAP_SIZE][MAP_SIZE];
};

/**
 * @brief The CAppTool class
 *
 * 工具类，用于读取和写入文件
 */
class CAppTool{
public:
   CAppTool();
   void readFile();//读取图片
   QString filePath="./res";
   QPixmap pictures[CHESS_COUNT];//棋子值存储
   QPixmap icon[ICON_COUNT];//图标值存储
   QPixmap monster[MONSTER_COUNT][MONSTERMOVEMENT_COUNT];//怪物值存储
};

class RankInformation{
public:
    QString strName;
    int nTime;
    int nScore;
    int nRank;
};



#endif // GLOBAL_H

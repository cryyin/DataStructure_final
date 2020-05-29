#include "Global.h"


CGameLogic::CGameLogic(){
}


/**
 * @brief CGameLogic::disturb
 *
 * 打乱棋盘函数
 */


void CGameLogic::disturb(){
    int count=1;

    //初始化棋盘数组
    for (int i=0;i<MAP_SIZE;i++){
        for(int k=0;k<MAP_SIZE;k++){
            board[i][k] = 0;
        }
    }


    //填入顺序图片序号
    for (int i=0;i<MAP_SIZE;i++){
        for(int k=0;k<MAP_SIZE;k++){
            if(count<CHESS_COUNT){
                board[i][k] = count;
                count++;
            }else{
                count=1;
                board[i][k] = count;
            }
        }
    }


    //打乱图片序号
    srand((unsigned)time(0));
    for(int i=0;i<MAP_SIZE;i++){
        for(int k=0;k<MAP_SIZE;k++){
            int x1 = rand() % MAP_SIZE;
            int y1 = rand() % MAP_SIZE;
            int x2 = rand() % MAP_SIZE;
            int y2 = rand() % MAP_SIZE;

            int temp = board[x1][y1];
            board[x1][y1] = board[x2][y2];
            board[x2][y2] = temp;
        }
    }

}

/**
 * @brief CGameLogic::getBoard
 * @param x 指定的横坐标
 * @param y 指定的纵坐标
 * @return  返回指定棋盘位置的序号
 */
int CGameLogic::getBoard(int x,int y){
    return board[x][y];
}


/**
 * @brief CGameLogic::setBoard
 * @param x 指定的横坐标
 * @param y 指定的纵坐标
 * @param value 修改的值
 */
void CGameLogic::setBoard(int x,int y,int value){
    board[x][y] = value;
}







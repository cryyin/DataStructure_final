#include "Global.h"





CGameLogic::CGameLogic(){
}


/**
 * @brief CGameLogic::disturb
 *
 * 初始化一个不可消子的棋盘函数
 */

void CGameLogic::initBoard(){
    srand((unsigned)time(0));
    //初始化棋盘数组
    for (int i=0;i<MAP_SIZE;i++){
        for(int k=0;k<MAP_SIZE;k++){
            board[i][k] = 6;
            board_clear[i][k] = 0;
            moveable_point[i][k] = 0;
        }
    }

    //生成各个位置的图片值，保证不可消子
    for (int i=0;i<MAP_SIZE;i++){
        for(int k=0;k<MAP_SIZE;k++){
            int temp_num = rand() % (CHESS_COUNT-1);
            disturbBoard(i,k,temp_num);
        }
    }

    bossHealth=BOSS1_HEALTH;//初始化血量
    //初始化播放器
    player->setMedia(QUrl::fromLocalFile("./res/audio/2.mp3"));
    player->setVolume(50);

}

/**
 * @brief CGameLogic::disturbBoard
 * @param x 指定点的x
 * @param y 指定点的y
 * @param value 初始的设定值
 *
 * 对指定位置生成不与临近产生消子的图片值
 */

void CGameLogic::disturbBoard(int x,int y,int value){
    int x1_num=-1;
    int x2_num=-2;

    int y1_num=-3;
    int y2_num=-4;

    int center_num=-5;

    //对上方进行检测
    if((x-1)!=-1){
        x1_num = board[x-1][y];
        if((x-2)!=-1){
            x2_num = board[x-2][y];
        }
    }

    //对左边进行检测
    if((y-1)!=-1){
        y1_num = board[x][y-1];
        if((y-2)!=-1){
            y2_num = board[x][y-2];
        }
    }

    //对对角线进行检测
    if(((x-1)!=-1) && ((y-1)!=-1)){
        center_num = board[x-1][y-1];
    }

    //上放二连
    if(x1_num == x2_num){
        if(value == x1_num){
            if(y1_num == y2_num){
                value = rand() % (CHESS_COUNT-1);
                while(value==x1_num || value==y1_num){
                    value = rand() % (CHESS_COUNT-1);
                }
            }else{
                value = rand() % (CHESS_COUNT-1);
                while(value==x1_num){
                    value = rand() % (CHESS_COUNT-1);
                }
            }
        }
    }

    //左边二连
    if(y1_num == y2_num){
        //判断新插入的值是否与左边相等
        if(value == y1_num){
            //上边也二连
            if(x1_num == x2_num){
                //获取新的值，直到不与上左相同
                value = rand() % (CHESS_COUNT-1);
                while(value==x1_num || value==y1_num){
                    value = rand() % (CHESS_COUNT-1);
                }
            }else{//上边不二连
                //获取新的值，直到不与左相同
                value = rand() % (CHESS_COUNT-1);
                while(value==y1_num){
                    value = rand() % (CHESS_COUNT-1);
                }
            }
        }
    }


    //对角线形成的三角形
    if(x1_num == center_num  && y1_num == center_num){
        value = rand() % (CHESS_COUNT-1);
        while(value==center_num){
            value = rand() % (CHESS_COUNT-1);
        }
    }


    board[x][y] = value;

}

/**
 * @brief CGameLogic::checkAdjacent
 * @param x1 第一个点的x坐标
 * @param y1 第一个点的y坐标
 * @param x2 第二个点的x坐标
 * @param y2 第二个点的y坐标
 * @return 相邻返回true，不相邻返回false
 *
 *判断两点是否相邻
 */
bool CGameLogic::checkAdjacent(int x1,int y1,int x2,int y2){

    if(x1 == x2){
        if(((y1+1) == y2) || ((y1-1) == y2)){

            return true;
        }
    }

    if(y1 == y2){
        if(((x1+1) == x2) || ((x1-1) == x2)){
            return true;
        }
    }


    return false;
}


/**
 * @brief CGameLogic::checkMove
 * @param x1 第一个点的x坐标
 * @param y1 第一个点的y坐标
 * @param x2 第二个点的x坐标
 * @param y2 第二个点的y坐标
 * @return 可交换返回true，不可交换返回false
 *
 * 判断相邻两点是否可以交换
 */
bool CGameLogic::checkMove(int x1,int y1,int x2,int y2){
    CGameLogic temp;
    //初始化一个新的棋盘
    temp.initBoard();
    //将主棋盘数值赋给新建的棋盘
    for(int i=0;i<MAP_SIZE;i++){
        for(int k=0;k<MAP_SIZE;k++){
            temp.setBoard(i,k,board[i][k]);
        }
    }

    //在新建的棋盘中将相邻的两点交换
    temp.setBoard(x1,y1,board[x2][y2]);
    temp.setBoard(x2,y2,board[x1][y1]);

    //对新棋盘进行消子检测，如果可以消除则可以交换，返回true
    if(temp.checkBoard()){
        return true;
    }else{//交换后不可以消子，返回false
        return false;
    }
}

/**
 * @brief CGameLogic::checkBoard
 * @return 是否存在可以消除的块儿，存在返回true，不存在返回false
 *
 * 检测棋盘是都存在消除，包括四消和三消，并将可消除的对应的消除标志变为1
 */
bool CGameLogic::checkBoard(){

    int flag=0;//棋盘在检测后是否发生改变

    for(int i=0;i<MAP_SIZE;i++){
        for(int k=0;k<MAP_SIZE;k++){
            if(board_clear[i][k] == 0){//是否已经被设定为消除
                //四消
                if(((i-1)!=-1)&&((k-1)!=-1)){//左上
                    if(board[i][k] == board[i-1][k] && board[i][k] == board[i][k-1]){
                        if(board[i][k] == board[i-1][k-1]){
                            board_clear[i][k] = 1;
                            board_clear[i-1][k] = 1;
                            board_clear[i][k-1] = 1;
                            board_clear[i-1][k-1] = 1;
                            flag=1;
                            if((i-2)!=-1){
                                if(board[i][k] == board[i-2][k]){
                                    board_clear[i-2][k] = 1;
                                }
                            }

                            if((k-2)!=-1){
                                if(board[i][k] == board[i][k-2]){
                                    board_clear[i][k-2] = 1;
                                }
                            }
                        }
                    }
                }//左上

                if(((i+1)!=MAP_SIZE)&&((k+1)!=MAP_SIZE)){//右下
                    if(board[i][k] == board[i+1][k] && board[i][k] == board[i][k+1]){
                        if(board[i][k] == board[i+1][k+1]){
                            board_clear[i][k] = 1;
                            board_clear[i+1][k] = 1;
                            board_clear[i][k+1] = 1;
                            board_clear[i+1][k+1] = 1;
                            flag=1;
                            if((i+2)!=MAP_SIZE){
                                if(board[i][k] == board[i+2][k]){
                                    board_clear[i+2][k] = 1;
                                }
                            }

                            if((k+2)!=MAP_SIZE){
                                if(board[i][k] == board[i][k+2]){
                                    board_clear[i][k+2] = 1;
                                }
                            }
                        }
                    }
                }//右下

                if(((i-1)!=-1)&&((k+1)!=MAP_SIZE)){//左下
                    if(board[i][k] == board[i-1][k] && board[i][k] == board[i][k+1]){
                        if(board[i][k] == board[i-1][k+1]){
                            board_clear[i][k] = 1;
                            board_clear[i-1][k] = 1;
                            board_clear[i][k+1] = 1;
                            board_clear[i-1][k+1] = 1;
                            flag=1;
                            if((i-2)!=-1){
                                if(board[i][k] == board[i-2][k]){
                                    board_clear[i-2][k] = 1;
                                }
                            }

                            if((k+2)!=MAP_SIZE){
                                if(board[i][k] == board[i][k+2]){
                                    board_clear[i][k+2] = 1;
                                }
                            }
                        }
                    }
                }//左下

                if(((i+1)!=MAP_SIZE)&&((k-1)!=-1)){//右上
                    if(board[i][k] == board[i+1][k] && board[i][k] == board[i][k-1]){
                        if(board[i][k] == board[i+1][k-1]){
                            board_clear[i][k] = 1;
                            board_clear[i+1][k] = 1;
                            board_clear[i][k-1] = 1;
                            board_clear[i+1][k-1] = 1;
                            flag=1;
                            if((i+2)!=MAP_SIZE){
                                if(board[i][k] == board[i+2][k]){
                                    board_clear[i+2][k] = 1;
                                }
                            }

                            if((k-2)!=-1){
                                if(board[i][k] == board[i][k-2]){
                                    board_clear[i][k-2] = 1;
                                }
                            }
                        }
                    }
                }//右上



                //三消
                int x_count=1,y_count=1;
                if((i-1)!=-1){//左
                    if(board[i][k] == board[i-1][k]){
                        x_count++;
                        if((i-2)!=-1){
                            if(board[i][k] == board[i-2][k]){
                                board_clear[i][k] = 1;
                                board_clear[i-1][k] = 1;
                                board_clear[i-2][k] = 1;
                                flag=1;
                            }
                        }
                    }
                }//左

                if((i+1)!=MAP_SIZE){//右
                    if(board[i][k] == board[i+1][k]){
                        x_count++;
                        if((i+2)!=MAP_SIZE){
                            if(board[i][k] == board[i+2][k]){
                                board_clear[i][k] = 1;
                                board_clear[i+1][k] = 1;
                                board_clear[i+2][k] = 1;
                                flag=1;
                            }
                        }
                    }
                }//右

                if((k-1)!=-1){//上
                    if(board[i][k] == board[i][k-1]){
                        y_count++;
                        if((k-2)!=-1){
                            if(board[i][k] == board[i][k-2]){
                                board_clear[i][k] = 1;
                                board_clear[i][k-1] = 1;
                                board_clear[i][k-2] = 1;
                                flag=1;
                            }
                        }
                    }
                }//上

                if((k+1)!=MAP_SIZE){//下
                    if(board[i][k] == board[i][k+1]){
                        y_count++;
                        if((k+2)!=MAP_SIZE){
                            if(board[i][k] == board[i][k+2]){
                                board_clear[i][k] = 1;
                                board_clear[i][k+1] = 1;
                                board_clear[i][k+2] = 1;
                                flag=1;
                            }
                        }
                    }
                }//下


                //综合判断，即左右各一个或者上下各一个
                if(x_count>=3){
                    board_clear[i][k] = 1;
                    board_clear[i-1][k] = 1;
                    board_clear[i+1][k] = 1;
                    flag=1;
                }
                if(y_count>=3){
                    board_clear[i][k] = 1;
                    board_clear[i][k-1] = 1;
                    board_clear[i][k+1] = 1;
                    flag=1;
                }
            }//是否已经被设定为消除
        }//k循环
    }//i循环
    return flag;
}

/**
 * @brief CGameLogic::clearBoard
 *
 * 将棋盘中消除标记为1的棋子的图片值对应的角色数值增加，然后将图片值变为6（即空白）
 */

void CGameLogic::clearBoard(){





    for(int i=0;i<MAP_SIZE;i++){
        for(int k=0;k<MAP_SIZE;k++){
            if(board_clear[i][k] == 1){
                //播放音频
                if(1){
                    player->play();
                }

                //根据要消除的图片序号增加指定的值
                switch(board[i][k]){
                    case 0:
                     role.health++;
                     break;
                    case 1:
                     role.attack++;
                     bossHealth=bossHealth-1;
                     break;
                    case 2:
                     role.armour++;
                     break;
                    case 3:
                     role.magic++;
                     bossHealth=bossHealth-1;
                     break;
                    case 4:
                     role.potion++;
                     break;
                    case 5:
                     role.gold++;
                     break;
                }
                //将计分后的图片设置为空
                board[i][k] = 6;
                //将消除标记归零
                board_clear[i][k] = 0;
            }
        }
    }
}

/**
 * @brief CGameLogic::downBoard
 *
 * 棋子下落函数
 */
void CGameLogic::downBoard(){
    isDowning = true;
    for(int j=0;j<5;j++){
        for(int k=MAP_SIZE-1;k>0;k--){
            for(int i=MAP_SIZE-1;i>0;i--){
                if(board[k][i] == 6){
                    for(int w=i;w>0;w--){
                        board[k][w] = board[k][w-1];
                        board_clear[k][w] = board_clear[k][w-1];
                    }
                }
            }
        }
    }

    isDowning =false;
    constructBoard();
}

/**
 * @brief CGameLogic::constructBoard
 *
 * 填补棋盘空缺的棋子(全随机，不判定重复)
 */

void CGameLogic::constructBoard(){
    srand((unsigned)time(0));
    for(int i=0;i<MAP_SIZE;i++){
        for(int k=0;k<MAP_SIZE;k++){
            if(board[i][k] == 6){
                int temp = rand() % (CHESS_COUNT-1);
                board[i][k] = temp;
                board_clear[i][k] = 0;
            }
        }
    }

    CGameLogic::checkBoard();
    CGameLogic::clearBoard();
}



/**
 * @brief CGameLogic::checkBoardStuck
 * @return true，棋盘没卡死；false，棋盘卡死
 *
 * 检测棋盘是否卡死
 */

bool CGameLogic::checkBoardStuck(){



    for(int i=0;i<MAP_SIZE;i++){
        for(int k=0;k<MAP_SIZE;k++){
            if((i-1)!=-1){
                if(checkMove(i,k,i-1,k)){
                   return true;
                }
            }
            if((i+1)!=MAP_SIZE){
                if(checkMove(i,k,i+1,k)){
                   return true;
                }
            }
            if((k-1)!=-1){
                if(checkMove(i,k,i,k-1)){
                   return true;
                }
            }
            if((k+1)!=MAP_SIZE){
                if(checkMove(i,k,i,k+1)){
                   return true;
                }
            }
        }
    }

    return false;
}

/**
 * @brief CGameLogic::remindBoard
 * @param moveable_point 可移动点位标记数组
 *
 * 计算出可以动的点位，将他们在数组中对应的位置填为1
 */

void CGameLogic::remindBoard(){


    if(checkBoardStuck()){
        for(int i=0;i<MAP_SIZE;i++){
            for(int k=0;k<MAP_SIZE;k++){

                if((i-1)!=-1){
                    if(checkMove(i,k,i-1,k)){
                        moveable_point[i][k] = 1;
                        moveable_point[i-1][k] = 1;
                    }
                }
                if((i+1)!=MAP_SIZE){
                    if(checkMove(i,k,i+1,k)){
                        moveable_point[i][k] = 1;
                        moveable_point[i+1][k] = 1;
                    }
                }
                if((k-1)!=-1){
                    if(checkMove(i,k,i,k-1)){
                        moveable_point[i][k] = 1;
                        moveable_point[i][k-1] = 1;
                    }
                }
                if((k+1)!=MAP_SIZE){
                    if(checkMove(i,k,i,k+1)){
                        moveable_point[i][k] = 1;
                        moveable_point[i][k+1] = 1;
                    }
                }

            }
        }
    }
}


/**
 * @brief CGameLogic::choseRemind
 * @param temp_point 传递数组
 *
 * 从可移动标记数组中随机选取一对点位
 */
void CGameLogic::choseRemind(int temp_point[2][2]){
    srand((unsigned)time(0));
    int x,y,while1_flag=1;
    while(while1_flag){
        x = rand() % (MAP_SIZE);
        y = rand() % (MAP_SIZE);
        if(moveable_point[x][y] == 1){
            int while2_flag=1;
            temp_point[0][0] = x;
            temp_point[0][1] = y;
            while(while2_flag){
                int count;
                count = rand() % 4;
                switch(count){
                    case 0:
                        if(moveable_point[x-1][y]==1){
                            while2_flag=0;
                            temp_point[1][0] = x-1;
                            temp_point[1][1] = y;
                        }
                        break;
                    case 1:
                        if(moveable_point[x+1][y]==1){
                            while2_flag=0;
                            temp_point[1][0] = x+1;
                            temp_point[1][1] = y;
                        }
                        break;
                    case 2:
                        if(moveable_point[x][y-1]==1){
                            while2_flag=0;
                            temp_point[1][0] = x;
                            temp_point[1][1] = y-1;
                        }
                        break;
                    case 3:
                        if(moveable_point[x][y+1]==1){
                            while2_flag=0;
                            temp_point[1][0] = x;
                            temp_point[1][1] = y+1;
                        }
                        break;
                }//switch
            }//while2

           while1_flag = 0;
        }
    }//while1


    cout<<temp_point[0][0]<<" "<<temp_point[0][1]<<" "<<temp_point[1][0]<<" "<<temp_point[1][1]<<"here\n";
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
 *
 * 设置棋盘点位的数值
 */
void CGameLogic::setBoard(int x,int y,int value){
    board[x][y] = value;
}








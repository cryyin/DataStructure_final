#include "Global.h"

CAppTool::CAppTool(){
}

/**
 * @brief CAppTool::readFile
 *
 * 读取图片
 */
void CAppTool::readFile(){
    //读取图标
    pictures[0] = QPixmap(filePath+"/icon/chess_0.png");
    pictures[1] = QPixmap(filePath+"/icon/chess_1.png");
    pictures[2] = QPixmap(filePath+"/icon/chess_2.png");
    pictures[3] = QPixmap(filePath+"/icon/chess_3.png");
    pictures[4] = QPixmap(filePath+"/icon/chess_4.png");
    pictures[5] = QPixmap(filePath+"/icon/chess_5.png");
    pictures[6] = QPixmap(filePath+"/icon/chess_6.png");
    icon[0] = QPixmap(filePath+"/icon/icon_0.png");
    icon[1] = QPixmap(filePath+"/icon/icon_1.png");

    //读取怪物图片
    int count=0;
    for(int i=0;i<4;i++){
        for(int k=0;k<5;k++){
            QString temp = filePath+"/mobs/001/Mob_1_"+QString::number(i, 10)+"_"+QString::number(k, 10)+".png";
            monster[0][count] = QPixmap(temp);
            count++;
        }
    }
}

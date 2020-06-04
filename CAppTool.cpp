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
    pictures[0] = QPixmap("./res/icon/icon_0.png");
    pictures[1] = QPixmap("./res/icon/icon_1.png");
    pictures[2] = QPixmap("./res/icon/icon_2.png");
    pictures[3] = QPixmap("./res/icon/icon_3.png");
    pictures[4] = QPixmap("./res/icon/icon_4.png");
    pictures[5] = QPixmap("./res/icon/icon_5.png");
    pictures[6] = QPixmap("./res/icon/icon_6.png");
    pictures[7] = QPixmap("./res/icon/icon_7.png");

    //读取怪物图片
    int count=0;
    for(int i=0;i<4;i++){
        for(int k=0;k<5;k++){
            QString temp = "./res/mobs/001/Mob_1_"+QString::number(i, 10)+"_"+QString::number(k, 10)+".png";
            monster[0][count] = QPixmap(temp);
            count++;
        }
    }
}

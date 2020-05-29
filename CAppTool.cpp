#include "Global.h"

CAppTool::CAppTool(){
}

void CAppTool::readFile(){
    pictures[0] = QPixmap("./res/icon_0.png");
    pictures[1] = QPixmap("./res/icon_1.png");
    pictures[2] = QPixmap("./res/icon_2.png");
    pictures[3] = QPixmap("./res/icon_3.png");
    pictures[4] = QPixmap("./res/icon_4.png");
    pictures[5] = QPixmap("./res/icon_5.png");
    pictures[6] = QPixmap("./res/icon_6.png");
}

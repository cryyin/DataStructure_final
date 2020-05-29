#ifndef CGAMEDLG_H
#define CGAMEDLG_H

#include <QDialog>
#include "qpainter.h"
#include "Global.h"

namespace Ui {
class CGameDlg;
}

class CGameDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CGameDlg(QWidget *parent = nullptr);
    ~CGameDlg();

private slots:
    void init();//初始化棋盘、游戏时间计时器、重绘计时器
    void on_pushButton_clicked();//测试按钮，无实际用途
    void paintEvent(QPaintEvent *event);//界面绘制事件
    void mousePressEvent(QMouseEvent *event);//鼠标点击事件
    void countTime();//游戏时间计时方法

private:
    Ui::CGameDlg *ui;
    CGameLogic logic;//游戏操作逻辑对象
    CAppTool tool;//读取文件对象
    int count_time=0;//游戏时间
    QTimer *timer_repaint;//重绘计时器，0.1秒一次
    QTimer *timer_time;//游戏时间计时器，1秒一次
};

#endif // CGAMEDLG_H

#ifndef CGAMEDLG_H
#define CGAMEDLG_H

#include <QDialog>
#include "qpainter.h"
#include "Global.h"
#include "audioclip.h"
#include <QtCore/QCoreApplication>
#include <QtMultimedia/QMediaPlayer>
#include "CGameSetting.h"


namespace Ui {
class CGameDlg;
}

class CGameDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CGameDlg(QWidget *parent = nullptr);
    QMediaPlayer * player = new QMediaPlayer;//音乐播放器
    QMediaPlayer * bgmPlayer = new QMediaPlayer;//音乐播放器
    ~CGameDlg();

public slots:
    void voiceOn();
    void voiceOff();

private slots:
    void init();//初始化棋盘、游戏时间计时器、重绘计时器
    void paintEvent(QPaintEvent *event);//界面绘制事件
    void mousePressEvent(QMouseEvent *event);//鼠标点击事件
    void countTime();//游戏时间计时方法
    void countFlash();//动画计时方法

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

protected:

     //void closeEvent(QCloseEvent *event);
     CGameSetting *settingForm=new CGameSetting;

private:
    Ui::CGameDlg *ui;
    CGameLogic logic;//游戏操作逻辑对象
    CAppTool tool;//读取文件对象
    int count_time=0;//游戏时间
    int count_flash=0;//动画计数

    QTimer *timer_repaint;//重绘计时器，0.1秒一次
    QTimer *timer_time;//游戏时间计时器，1秒一次
    QTimer *timer_flash;//动画计时器，0.25秒一次

    int select_count=0;//选择的数量
    QPoint p1 = {0,0};
    QPoint p2 = {0,0};

    int remind_count=0;//提示框架
    bool remind_click=false;
    QPoint p1_remind = {0,0};
    QPoint p2_remind = {0,0};
};

#endif // CGAMEDLG_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "values.h"
#include <QDebug>
#include <QAction>
#include <QMessageBox>
#include <QPainter>
#include <QLine>
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct IconButton : QPushButton
{
public:
    IconButton(QWidget *parent = Q_NULLPTR) :
        QPushButton(parent),
        xID(-1),
        yID(-1)
    {

    }
    int xID; // x 坐标
    int yID; // y 坐标
};


// --------- 全局变量 --------- //

const int kIconSize = 36;
const int kTopMargin = 70;
const int kLeftMargin = 50;


const QString kIconReleasedStyle = "";
const QString kIconClickedStyle = "background-color: rgba(255, 255, 12, 161)";
const QString kIconHintStyle = "background-color: rgba(255, 0, 0, 255)";



const int kGameTimeTotal = 5 * 60 * 1000; // 总时间
const int kGameTimerInterval = 300;
const int kLinkTimerDelay = 700;

// -------------------------- //



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    IconButton *imageButton[SIZE_OF_VERTICAL * SIZE_OF_LINE]; // 图片button数组
    IconButton *preIcon, *curIcon; // 记录点击的icon


    void initGame();

};
#endif // MAINWINDOW_H

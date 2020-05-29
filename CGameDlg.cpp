#include "CGameDlg.h"
#include "ui_CGameDlg.h"

CGameDlg::CGameDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CGameDlg)
{
    ui->setupUi(this);
    //初始化
    init();
}

CGameDlg::~CGameDlg()
{
    delete ui;
}

//初始化
void CGameDlg::init(){
    //读取图标文件
    tool.readFile();
    //打乱和初始化棋盘数组
    logic.disturb();

    //设置重绘计时器，每0.1秒重绘一次
    timer_repaint = new QTimer(this); //this 为parent类, 表示当前窗口
    connect(timer_repaint, SIGNAL(timeout()), this, SLOT(update())); // SLOT填入一个槽函数
    timer_repaint->start(100); // 1000毫秒, 等于 1 秒

    //设置时间计时器，每1秒递增一次count_time
    timer_time = new QTimer(this); //this 为parent类, 表示当前窗口
    connect(timer_time, SIGNAL(timeout()), this, SLOT(countTime())); // SLOT填入一个槽函数
    timer_time->start(1000); // 1000毫秒, 等于 1 秒
}


//游戏即时函数
void CGameDlg::countTime(){
    count_time++;
    ui->textEdit_2->setText(QString::number(count_time,10));
}


//测试按钮，无实际用途
void CGameDlg::on_pushButton_clicked()
{

}


//鼠标点击事件
void CGameDlg::mousePressEvent(QMouseEvent *event)
{
    // 如果是鼠标左键按下
    if(event->button() == Qt::LeftButton)
    {
        QPoint p1 = event->globalPos();
        QPoint p2 = pos();
        QPoint p = p1-p2;

        //显示点击位置
        ui->textEdit->setText(QString::number(p.x(),10)+" "+QString::number(p.y(),10));

        //计算对应位置的图标
        int x = p.x() / 40;
        int y = (p.y() - 40) / 40;
        logic.setBoard(x,y,0);
    }
}


/**
 * @brief CGameDlg::paintEvent
 * @param event
 *
 * 界面重绘
 */
void CGameDlg::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //绘制背景
    painter.drawPixmap(QRect(0,0,500,500), QPixmap("./res/background.jpg"));

    //绘制棋盘
    for(int i=0;i<MAP_SIZE;i++){
        for(int k=0;k<MAP_SIZE;k++){
            painter.drawPixmap(QRect(i*40,k*40,40,40), tool.pictures[logic.getBoard(i,k)]);
        }
    }
}



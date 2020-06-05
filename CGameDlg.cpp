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

/**
 * @brief CGameDlg::init
 *
 * 初始化棋盘、计时器
 */
void CGameDlg::init(){
    //读取图标文件
    tool.readFile();
    //打乱和初始化棋盘数组
    logic.initBoard();

    for(int i=0;i<MAP_SIZE;i++){
        for(int k=0;k<MAP_SIZE;k++){
            cout<<logic.getBoard(i,k)<<" ";
        }
        cout<<"\n";
    }

    //设置棋盘重绘计时器，每0.01秒重绘一次
    timer_repaint = new QTimer(this); //this 为parent类, 表示当前窗口
    connect(timer_repaint, SIGNAL(timeout()), this, SLOT(update())); // SLOT填入一个槽函数
    timer_repaint->start(10); // 1000毫秒, 等于 1 秒

    //设置BOSS动画重绘计时器，每0.1秒重绘一次
    timer_flash = new QTimer(this); //this 为parent类, 表示当前窗口
    connect(timer_flash, SIGNAL(timeout()), this, SLOT(countFlash())); // SLOT填入一个槽函数
    timer_flash->start(100); // 1000毫秒, 等于 1 秒

    //设置时间计时器，每1秒递增一次count_time
    timer_time = new QTimer(this); //this 为parent类, 表示当前窗口
    connect(timer_time, SIGNAL(timeout()), this, SLOT(countTime())); // SLOT填入一个槽函数
    timer_time->start(1000); // 1000毫秒, 等于 1 秒

    //设置基础图标
    ui->label->setPixmap(tool.pictures[0]);
    ui->label_2->setPixmap(tool.pictures[1]);
    ui->label_3->setPixmap(tool.pictures[2]);
    ui->label_4->setPixmap(tool.pictures[3]);
    ui->label_5->setPixmap(tool.pictures[4]);
    ui->label_6->setPixmap(tool.pictures[5]);
    //设置不可编辑
    ui->lineEdit->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->lineEdit_4->setReadOnly(true);
    ui->lineEdit_5->setReadOnly(true);
    ui->lineEdit_6->setReadOnly(true);
}


/**
 * @brief CGameDlg::countTime
 *
 * 游戏计时函数
 */

void CGameDlg::countTime(){
    count_time++;
    if(remind_count == 1){
        remind_count = 0;
    }
    ui->textEdit_2->setText(QString::number(count_time,10));
}

/**
 * @brief CGameDlg::countFlash
 *
 * 棋盘状态刷新
 */
void CGameDlg::countFlash(){
    count_flash++;

    if(!logic.isDowning){
        logic.downBoard();
    }
    //如果选取了两个点
    if(select_count==2){
        //两个点是否相邻。如果相邻则进行转换判断
        if(logic.checkAdjacent(p1.x(),p1.y(),p2.x(),p2.y())){
            if(logic.checkMove(p1.x(),p1.y(),p2.x(),p2.y())){

                //交换点位
                int temp_point = logic.getBoard(p1.x(),p1.y());
                logic.setBoard(p1.x(),p1.y(),logic.getBoard(p2.x(),p2.y()));
                logic.setBoard(p2.x(),p2.y(),temp_point);

                //清除棋盘
                if(logic.checkBoard()){
                    logic.clearBoard();
                }
            }
            if(count_flash%4 == 0){
                select_count=0;
            }
        }else{
            if(count_flash%4 == 0){
                select_count=0;
            }
        }
    }

    //设置各项数值
    ui->lineEdit->setText(QString::number(logic.role.health, 10));
    ui->lineEdit_2->setText(QString::number(logic.role.attack, 10));
    ui->lineEdit_3->setText(QString::number(logic.role.armour, 10));
    ui->lineEdit_4->setText(QString::number(logic.role.magic, 10));
    ui->lineEdit_5->setText(QString::number(logic.role.potion, 10));
    ui->lineEdit_6->setText(QString::number(logic.role.gold, 10));
}



/**
 * @brief CGameDlg::mousePressEvent
 * @param event
 *
 * 鼠标点击事件处理
 */
void CGameDlg::mousePressEvent(QMouseEvent *event)
{
    // 如果是鼠标左键按下
    if(event->button() == Qt::LeftButton)
    {
        QPoint temp_p1 = event->globalPos();
        QPoint temp_p2 = pos();
        QPoint p = temp_p1-temp_p2;
        //AudioClip ac;


        //播放音频
        player->setMedia(QUrl::fromLocalFile("./res/audio/1.mp3"));
        player->setVolume(50);
        player->play();


        //ac.load("D:/1.mp3");
        //ac.play();
        //system("pause");

        //显示点击位置
        ui->textEdit->setText(QString::number(p.x(),10)+" "+QString::number(p.y(),10));

        //计算对应位置的图标
        int x = p.x() / 40;
        int y = (p.y() - 40) / 40;


        //存入选择的图标
        if(select_count ==0){
            p1 = {x,y};
            select_count++;
        }else if(select_count == 1){
            p2 = {x,y};
            select_count++;
        }

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


    //绘制选择红框
    if(select_count==1){
        painter.drawPixmap(QRect(p1.x()*40,p1.y()*40,40,40), tool.icon[0]);
    }else if(select_count==2){
        painter.drawPixmap(QRect(p1.x()*40,p1.y()*40,40,40), tool.icon[0]);
        painter.drawPixmap(QRect(p2.x()*40,p2.y()*40,40,40), tool.icon[0]);
    }

    //绘制提示绿框
    if(remind_count == 1){
        painter.drawPixmap(QRect(p1_remind.x()*40,p1_remind.y()*40,40,40), tool.icon[1]);
        painter.drawPixmap(QRect(p2_remind.x()*40,p2_remind.y()*40,40,40), tool.icon[1]);
    }

    painter.drawPixmap(QRect(600,100,100,100), tool.monster[0][count_flash%20]);
}



void CGameDlg::on_pushButton_clicked()
{
    int temp_point[2][2] = {-1,-1,-1,-1};
    logic.remindBoard();
    logic.choseRemind(temp_point);
    p1_remind = {temp_point[0][0],temp_point[0][1]};
    p2_remind = {temp_point[1][0],temp_point[1][1]};
    remind_count = 1;
}

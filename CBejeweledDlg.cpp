#include "CBejeweledDlg.h"
#include "ui_CBejeweledDlg.h"


CBejeweledDlg::CBejeweledDlg(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CBejeweledDlg)
{
    ui->setupUi(this);
}

CBejeweledDlg::~CBejeweledDlg()
{
    delete ui;
}


void CBejeweledDlg::on_pushButton_clicked()
{
    //隐藏主界面
    this->hide();
    //显示游戏界面
    game_widget->show();
}

void CBejeweledDlg::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //设置背景
    painter.drawPixmap(rect(), QPixmap("./res/background.jpg"));
}



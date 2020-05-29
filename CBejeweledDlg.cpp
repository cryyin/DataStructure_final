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
    this->hide();
    game_widget->show();
}

void CBejeweledDlg::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(rect(), QPixmap("./res/background.jpg"));
}



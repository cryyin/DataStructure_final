#include "CRankDlg.h"
#include "ui_CRankDlg.h"

CRankDlg::CRankDlg(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CRankDlg)
{
    ui->setupUi(this);


    QStandardItemModel  *model = new QStandardItemModel();
    model->setColumnCount(4);
    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("玩家姓名"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("剩余时间"));
    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("玩家积分"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("玩家排名"));
    ui->tableView->setModel(model);
    //表头信息显示居左
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    for(int i = 0; i < 3; i++)
    {

   model->setItem(i,0,new QStandardItem("2009441676"));

    //设置字符颜色

   model->item(i,0)->setForeground(QBrush(QColor(255, 0, 0)));

    //设置字符位置

   model->item(i,0)->setTextAlignment(Qt::AlignCenter);

   model->setItem(i,1,new QStandardItem(QString::fromLocal8Bit("哈哈")));
    }

}

CRankDlg::~CRankDlg()
{
    delete ui;
}





void CRankDlg::on_tableView_activated(const QModelIndex &index)
{

}

void CRankDlg::on_tableView_clicked(const QModelIndex &index)
{

}

void CRankDlg::on_tableView_entered(const QModelIndex &index)
{

}

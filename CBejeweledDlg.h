#ifndef CBEJEWELEDDLG_H
#define CBEJEWELEDDLG_H

#include <QWidget>
#include "CGameDlg.h"
#include "qpainter.h"
#include "CRankDlg.h"
#include "Global.h"
#include "CHelpDlg.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CBejeweledDlg; }
QT_END_NAMESPACE

class CBejeweledDlg : public QWidget
{
    Q_OBJECT

public:
    CBejeweledDlg(QWidget *parent = nullptr);
    ~CBejeweledDlg();

private slots:
    void on_pushButton_clicked();
    void paintEvent(QPaintEvent *event);//重绘事件

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::CBejeweledDlg *ui;
    CRankDlg *rank_form=new CRankDlg;
    CHelpDlg *help_form=new CHelpDlg;
};
#endif // CBEJEWELEDDLG_H

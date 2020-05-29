#ifndef CBEJEWELEDDLG_H
#define CBEJEWELEDDLG_H

#include <QWidget>
#include "CGameDlg.h"
#include "qpainter.h"


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

private:
    Ui::CBejeweledDlg *ui;
    CGameDlg *game_widget = new CGameDlg;//游戏界面
};
#endif // CBEJEWELEDDLG_H

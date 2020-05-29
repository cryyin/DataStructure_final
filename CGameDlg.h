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
    void on_pushButton_clicked();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void countTime();

private:
    Ui::CGameDlg *ui;
    CGameLogic logic;
    CAppTool tool;
    int count_time=0;
};

#endif // CGAMEDLG_H

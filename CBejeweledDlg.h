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

private:
    Ui::CBejeweledDlg *ui;
    CGameDlg *game_widget = new CGameDlg;
    void paintEvent(QPaintEvent *event);
};
#endif // CBEJEWELEDDLG_H

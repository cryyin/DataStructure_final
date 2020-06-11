#ifndef CRANKDLG_H
#define CRANKDLG_H

#include <QMainWindow>
#include "qstandarditemmodel.h"
#include "Global.h"


namespace Ui {
class CRankDlg;
}

class CRankDlg : public QMainWindow
{
    Q_OBJECT

public:
    explicit CRankDlg(QWidget *parent = nullptr);
    ~CRankDlg();

private slots:
    void on_tableView_entered(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::CRankDlg *ui;
};

#endif // CRANKDLG_H

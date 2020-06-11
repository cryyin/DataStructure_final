#ifndef CHELPDLG_H
#define CHELPDLG_H

#include <QDialog>

namespace Ui {
class CHelpDlg;
}

class CHelpDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CHelpDlg(QWidget *parent = nullptr);
    ~CHelpDlg();

private:
    Ui::CHelpDlg *ui;
};

#endif // CHELPDLG_H

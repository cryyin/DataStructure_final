#ifndef CGAMESETTING_H
#define CGAMESETTING_H

#include <QDialog>

namespace Ui {
class CGameSetting;
}

class CGameSetting : public QDialog
{
    Q_OBJECT

public:
    explicit CGameSetting(QWidget *parent = nullptr);
    ~CGameSetting();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CGameSetting *ui;
};

#endif // CGAMESETTING_H

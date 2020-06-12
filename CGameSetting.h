#ifndef CGAMESETTING_H
#define CGAMESETTING_H

#include <QDialog>
#include "Global.h"

namespace Ui {
class CGameSetting;
}

class CGameSetting : public QDialog
{
    Q_OBJECT

public:
    explicit CGameSetting(QWidget  *parent = nullptr);
    ~CGameSetting();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CGameSetting *ui;

signals:
    void voiceOn();
    void voiceOff();


};

#endif // CGAMESETTING_H

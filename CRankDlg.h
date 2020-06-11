#ifndef CRANKDLG_H
#define CRANKDLG_H

#include <QDialog>
#include "qstandarditemmodel.h"
#include <QtCore/QCoreApplication>
#include "Global.h"
#include "CGameSetting.h"

namespace Ui {
class CRankDlg;
}

class CRankDlg : public QDialog
{
    Q_OBJECT

public:
    explicit CRankDlg(QWidget *parent = nullptr);
    ~CRankDlg();
    CGameSetting * settingForm=new CGameSetting;

private:
    Ui::CRankDlg *ui;
};

#endif // CRANKDLG_H

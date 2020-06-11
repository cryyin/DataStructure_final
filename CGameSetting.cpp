#include "CGameSetting.h"
#include "ui_CGameSetting.h"

CGameSetting::CGameSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CGameSetting)
{
    ui->setupUi(this);
}

CGameSetting::~CGameSetting()
{
    delete ui;
}

void CGameSetting::on_pushButton_clicked()
{
    //Setting::setting_Voice=true;
}

void CGameSetting::on_pushButton_2_clicked()
{
    //Setting::setting_Voice=false;
}

#include "preparewindow.h"
#include "ui_preparewindow.h"

prepareWindow::prepareWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::prepareWindow)
{
    ui->setupUi(this);
}

prepareWindow::~prepareWindow()
{
    delete ui;
}

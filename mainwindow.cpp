#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,preIcon(NULL)
    ,curIcon(NULL)
{
    ui->setupUi(this);
    initGame();
}

void MainWindow::initGame()
{
    for(int i = 0; i < SIZE_OF_LINE * SIZE_OF_VERTICAL; i++)
       {
           imageButton[i] = new IconButton(this);
           imageButton[i]->setGeometry(kLeftMargin + (i % SIZE_OF_LINE) * kIconSize, kTopMargin + (i / SIZE_OF_LINE) * kIconSize, kIconSize, kIconSize);
           // 设置索引
           imageButton[i]->xID = i % SIZE_OF_LINE;
           imageButton[i]->yID = i / SIZE_OF_LINE;
           imageButton[i]->show();
           if (game->getGameMap()[i])
           {
               // 有方块就设置图片
               QPixmap iconPix;
               QString fileString;
               fileString.sprintf(":/res/image/%d.png", game->getGameMap()[i]);
               iconPix.load(fileString);
               QIcon icon(iconPix);
               imageButton[i]->setIcon(icon);
               imageButton[i]->setIconSize(QSize(kIconSize, kIconSize));
               // 添加按下的信号槽
               connect(imageButton[i], SIGNAL(pressed()), this, SLOT(onIconButtonPressed()));
           }
           else
               imageButton[i]->hide();
       }
}

MainWindow::~MainWindow()
{
    delete ui;
}


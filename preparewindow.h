#ifndef PREPAREWINDOW_H
#define PREPAREWINDOW_H

#include <QMainWindow>

namespace Ui {
class prepareWindow;
}

class prepareWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit prepareWindow(QWidget *parent = nullptr);
    ~prepareWindow();

private:
    Ui::prepareWindow *ui;
};

#endif // PREPAREWINDOW_H

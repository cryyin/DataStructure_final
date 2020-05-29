/********************************************************************************
** Form generated from reading UI file 'preparewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREPAREWINDOW_H
#define UI_PREPAREWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_prepareWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *prepareWindow)
    {
        if (prepareWindow->objectName().isEmpty())
            prepareWindow->setObjectName(QString::fromUtf8("prepareWindow"));
        prepareWindow->resize(800, 600);
        menubar = new QMenuBar(prepareWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        prepareWindow->setMenuBar(menubar);
        centralwidget = new QWidget(prepareWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        prepareWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(prepareWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        prepareWindow->setStatusBar(statusbar);

        retranslateUi(prepareWindow);

        QMetaObject::connectSlotsByName(prepareWindow);
    } // setupUi

    void retranslateUi(QMainWindow *prepareWindow)
    {
        prepareWindow->setWindowTitle(QCoreApplication::translate("prepareWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class prepareWindow: public Ui_prepareWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREPAREWINDOW_H

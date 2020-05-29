/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startwindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *startwindow)
    {
        if (startwindow->objectName().isEmpty())
            startwindow->setObjectName(QString::fromUtf8("startwindow"));
        startwindow->resize(800, 600);
        menubar = new QMenuBar(startwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        startwindow->setMenuBar(menubar);
        centralwidget = new QWidget(startwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        startwindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(startwindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        startwindow->setStatusBar(statusbar);

        retranslateUi(startwindow);

        QMetaObject::connectSlotsByName(startwindow);
    } // setupUi

    void retranslateUi(QMainWindow *startwindow)
    {
        startwindow->setWindowTitle(QCoreApplication::translate("startwindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startwindow: public Ui_startwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H

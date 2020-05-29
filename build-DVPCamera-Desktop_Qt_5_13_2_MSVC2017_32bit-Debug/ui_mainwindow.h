/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnOpen;
    QPushButton *btnStart;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *cbCamera;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        btnOpen = new QPushButton(centralwidget);
        btnOpen->setObjectName(QString::fromUtf8("btnOpen"));
        btnOpen->setGeometry(QRect(280, 20, 75, 23));
        btnStart = new QPushButton(centralwidget);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setGeometry(QRect(370, 20, 75, 23));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 20, 256, 22));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        cbCamera = new QComboBox(widget);
        cbCamera->setObjectName(QString::fromUtf8("cbCamera"));
        cbCamera->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(cbCamera);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\347\233\270\346\234\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

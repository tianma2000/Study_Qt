/********************************************************************************
** Form generated from reading UI file 'myplay.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPLAY_H
#define UI_MYPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myPlay
{
public:
    QAction *actionexit;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *myPlay)
    {
        if (myPlay->objectName().isEmpty())
            myPlay->setObjectName(QString::fromUtf8("myPlay"));
        myPlay->resize(800, 600);
        actionexit = new QAction(myPlay);
        actionexit->setObjectName(QString::fromUtf8("actionexit"));
        centralwidget = new QWidget(myPlay);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        myPlay->setCentralWidget(centralwidget);
        menubar = new QMenuBar(myPlay);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        myPlay->setMenuBar(menubar);
        statusbar = new QStatusBar(myPlay);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        myPlay->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(actionexit);

        retranslateUi(myPlay);

        QMetaObject::connectSlotsByName(myPlay);
    } // setupUi

    void retranslateUi(QMainWindow *myPlay)
    {
        myPlay->setWindowTitle(QApplication::translate("myPlay", "MainWindow", nullptr));
        actionexit->setText(QApplication::translate("myPlay", "\351\200\200\345\207\272", nullptr));
        menu->setTitle(QApplication::translate("myPlay", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myPlay: public Ui_myPlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPLAY_H

/********************************************************************************
** Form generated from reading UI file 'myplay.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYPLAY_H
#define UI_MYPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_myPlay
{
public:
    QAction *actionexit;
    QWidget *centralwidget;

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

        retranslateUi(myPlay);

        QMetaObject::connectSlotsByName(myPlay);
    } // setupUi

    void retranslateUi(QMainWindow *myPlay)
    {
        myPlay->setWindowTitle(QCoreApplication::translate("myPlay", "MainWindow", nullptr));
        actionexit->setText(QCoreApplication::translate("myPlay", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class myPlay: public Ui_myPlay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYPLAY_H

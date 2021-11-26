/********************************************************************************
** Form generated from reading UI file 'chooselevelscene.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSELEVELSCENE_H
#define UI_CHOOSELEVELSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_chooselevelscene
{
public:
    QAction *actionexit;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *chooselevelscene)
    {
        if (chooselevelscene->objectName().isEmpty())
            chooselevelscene->setObjectName(QString::fromUtf8("chooselevelscene"));
        chooselevelscene->resize(800, 600);
        actionexit = new QAction(chooselevelscene);
        actionexit->setObjectName(QString::fromUtf8("actionexit"));
        centralwidget = new QWidget(chooselevelscene);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        chooselevelscene->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(chooselevelscene);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        chooselevelscene->setStatusBar(statusbar);

        retranslateUi(chooselevelscene);

        QMetaObject::connectSlotsByName(chooselevelscene);
    } // setupUi

    void retranslateUi(QMainWindow *chooselevelscene)
    {
        chooselevelscene->setWindowTitle(QCoreApplication::translate("chooselevelscene", "MainWindow", nullptr));
        actionexit->setText(QCoreApplication::translate("chooselevelscene", "\347\252\201\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class chooselevelscene: public Ui_chooselevelscene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSELEVELSCENE_H

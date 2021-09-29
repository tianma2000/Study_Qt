/********************************************************************************
** Form generated from reading UI file 'mainscenario.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENARIO_H
#define UI_MAINSCENARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mainscenario
{
public:
    QAction *actionexit;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;

    void setupUi(QMainWindow *Mainscenario)
    {
        if (Mainscenario->objectName().isEmpty())
            Mainscenario->setObjectName(QString::fromUtf8("Mainscenario"));
        Mainscenario->resize(400, 300);
        actionexit = new QAction(Mainscenario);
        actionexit->setObjectName(QString::fromUtf8("actionexit"));
        centralWidget = new QWidget(Mainscenario);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Mainscenario->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Mainscenario);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Mainscenario->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionexit);

        retranslateUi(Mainscenario);

        QMetaObject::connectSlotsByName(Mainscenario);
    } // setupUi

    void retranslateUi(QMainWindow *Mainscenario)
    {
        Mainscenario->setWindowTitle(QApplication::translate("Mainscenario", "Mainscenario", nullptr));
        actionexit->setText(QApplication::translate("Mainscenario", "\351\200\200\345\207\272", nullptr));
        menu->setTitle(QApplication::translate("Mainscenario", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mainscenario: public Ui_Mainscenario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENARIO_H

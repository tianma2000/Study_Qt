/********************************************************************************
** Form generated from reading UI file 'mainscenario.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENARIO_H
#define UI_MAINSCENARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mainscenario
{
public:
    QAction *actionexit;
    QWidget *centralWidget;

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

        retranslateUi(Mainscenario);

        QMetaObject::connectSlotsByName(Mainscenario);
    } // setupUi

    void retranslateUi(QMainWindow *Mainscenario)
    {
        Mainscenario->setWindowTitle(QCoreApplication::translate("Mainscenario", "Mainscenario", nullptr));
        actionexit->setText(QCoreApplication::translate("Mainscenario", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mainscenario: public Ui_Mainscenario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENARIO_H

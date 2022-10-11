/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *vlMain;
    QWidget *shadowWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *mixBtn;
    QPushButton *maxBtn;
    QPushButton *exitBtn;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *btnGetFile;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *listWidgetMd5;
    QListWidget *listWidgetStr;
    QProgressBar *progressBar;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        vlMain = new QVBoxLayout(Widget);
        vlMain->setObjectName(QString::fromUtf8("vlMain"));
        shadowWidget = new QWidget(Widget);
        shadowWidget->setObjectName(QString::fromUtf8("shadowWidget"));
        shadowWidget->setStyleSheet(QString::fromUtf8("#shadowWidget\n"
"{\n"
"background-color: rgb(255, 255, 255);\n"
"border-radius:5px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(shadowWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(shadowWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        mixBtn = new QPushButton(shadowWidget);
        mixBtn->setObjectName(QString::fromUtf8("mixBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mixBtn->sizePolicy().hasHeightForWidth());
        mixBtn->setSizePolicy(sizePolicy1);
        mixBtn->setMinimumSize(QSize(42, 42));
        mixBtn->setMaximumSize(QSize(42, 42));
        mixBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	\n"
"	background-color: rgb(146, 181, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	background-color: rgb(93, 116, 162);\n"
"}"));

        horizontalLayout->addWidget(mixBtn);

        maxBtn = new QPushButton(shadowWidget);
        maxBtn->setObjectName(QString::fromUtf8("maxBtn"));
        maxBtn->setMinimumSize(QSize(42, 42));
        maxBtn->setMaximumSize(QSize(42, 42));
        maxBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	\n"
"	background-color: rgb(146, 181, 255);\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	background-color: rgb(93, 116, 162);\n"
"}"));

        horizontalLayout->addWidget(maxBtn);

        exitBtn = new QPushButton(shadowWidget);
        exitBtn->setObjectName(QString::fromUtf8("exitBtn"));
        exitBtn->setMinimumSize(QSize(42, 42));
        exitBtn->setMaximumSize(QSize(42, 42));
        exitBtn->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border:none;\n"
"	background-color: rgb(255, 0, 0);\n"
"border-top-right-radius:5px;\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	\n"
"	background-color: rgb(255, 79, 67);\n"
"}\n"
"QPushButton:pressed{\n"
"	\n"
"	background-color: rgb(255, 30, 1);\n"
"}"));

        horizontalLayout->addWidget(exitBtn);


        verticalLayout_2->addLayout(horizontalLayout);

        frame = new QFrame(shadowWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy2);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMaximumSize(QSize(0, 0));

        verticalLayout->addWidget(pushButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit = new QLineEdit(frame);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        btnGetFile = new QPushButton(frame);
        btnGetFile->setObjectName(QString::fromUtf8("btnGetFile"));

        horizontalLayout_2->addWidget(btnGetFile);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        listWidgetMd5 = new QListWidget(frame);
        listWidgetMd5->setObjectName(QString::fromUtf8("listWidgetMd5"));

        horizontalLayout_3->addWidget(listWidgetMd5);

        listWidgetStr = new QListWidget(frame);
        listWidgetStr->setObjectName(QString::fromUtf8("listWidgetStr"));

        horizontalLayout_3->addWidget(listWidgetStr);


        verticalLayout->addLayout(horizontalLayout_3);

        progressBar = new QProgressBar(frame);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        verticalLayout->addWidget(progressBar);


        verticalLayout_2->addWidget(frame);


        vlMain->addWidget(shadowWidget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Frameless", nullptr));
        mixBtn->setText(QString());
        maxBtn->setText(QString());
        exitBtn->setText(QString());
        pushButton->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        btnGetFile->setText(QCoreApplication::translate("Widget", "getFile", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H

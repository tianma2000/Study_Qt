#-------------------------------------------------
#
# Project created by QtCreator 2021-09-27T15:44:14
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Goldreverse
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        chooselevelscene.cpp \
        dataconfig.cpp \
        main.cpp \
        mainscenario.cpp \
        mycoin.cpp \
        myplay.cpp \
        mypushbuttons.cpp

HEADERS += \
        chooselevelscene.h \
        chooselevelscene.h \
        dataconfig.h \
        mainscenario.h \
        mycoin.h \
        myplay.h \
        mypushbuttons.h

FORMS += \
        chooselevelscene.ui \
        mainscenario.ui \
        myplay.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qss/qss.qrc \
    res/res.qrc

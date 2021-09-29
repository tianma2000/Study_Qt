#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QTextStream>
#include <QFile>
#include <QPixmap>
#include <QPushButton>
#include <QPainter>
#include "mypushbuttons.h"
#include <QDebug>
#include <QTimer>
#include <QLabel>
#include "myplay.h"

namespace Ui {
class chooselevelscene;
}

class chooselevelscene : public QMainWindow
{
    Q_OBJECT

public:
    explicit chooselevelscene(QWidget * fu,QWidget *parent = nullptr);
    ~chooselevelscene();


    //初始化函数
    void mainInit();

    //关卡按钮
    void levelInit();

    //信号和槽的初始化
    void connectInit();




    void paintEvent(QPaintEvent *);

    QWidget *m_parent; //父类
    MyPushButtons * backBtn; //返回按钮
    myPlay *m_playScena = nullptr; //游戏窗口指针

private:
    Ui::chooselevelscene *ui;

signals:
    //写一个信号
    void chooseBackCenario();

public slots:
    void sotsPlaytoCloose();
    void sotsGotoNext(int index);
};

#endif // CHOOSELEVELSCENE_H


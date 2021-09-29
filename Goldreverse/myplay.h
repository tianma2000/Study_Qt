#ifndef MYPLAY_H
#define MYPLAY_H

#include <QMainWindow>

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
#include "mycoin.h"


namespace Ui {
class myPlay;
}

class myPlay : public QMainWindow
{
    Q_OBJECT

public:
    myPlay(int index,QWidget *parent = nullptr);
    //myPlay(int index);
    ~myPlay();

    //初始化函数
    void mainInit();


    //信号和槽的初始化
    void connectInit();



    MyPushButtons * backBtn; //返回按钮
    //二维数组维护每关关卡的具体数据
    int gameArray[4][4];
    MyCoin * coinBtn[4][4];
    int m_levelIndex;//内部成员属性 记录所选的关卡
    //是否胜利的标志
    bool m_isWin=false;


    void paintEvent(QPaintEvent *);
private:
    Ui::myPlay *ui;


signals:
    //写一个信号
    void playtochoose();
    //下一关
    void gotoNext(int index);

public slots:

};

#endif // MYPLAY_H

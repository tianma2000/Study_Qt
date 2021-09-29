#ifndef MAINSCENARIO_H
#define MAINSCENARIO_H

#include <QMainWindow>
#include "chooselevelscene.h"
#include "MyPushButtons.h"

namespace Ui {
class Mainscenario;
}

class Mainscenario : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mainscenario(QWidget *parent = nullptr);
    ~Mainscenario();
    //初始化的值
    void mainInit();
    //开始按钮初始化
    void StartBtn();
    //信号和槽的初始化
    void connectInit();

    void paintEvent(QPaintEvent *);


    //开始按钮
    MyPushButtons *m_startBtn = nullptr;

    //关卡选择
    chooselevelscene * m_chooseScence = nullptr;

private:
    Ui::Mainscenario *ui;

};

#endif // MAINSCENARIO_H

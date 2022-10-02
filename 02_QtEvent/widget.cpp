#include "widget.h"
#include "ui_widget.h"
#include <QTimer>//定时器的类
#include <QMouseEvent>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //启动计时器
    id1=startTimer(1000);//参数1  间隔  单位  毫秒
    id2=startTimer(2000);
    QTimer *time=new QTimer(this);
    //定时器启动
    time->start(500);
    connect(time,&QTimer::timeout,[=](){
        static int num3=1;
        ui->label_4->setText(QString::number(num3++));
    });
    //点击按钮，停止计时器

    connect(ui->btn,&QPushButton::clicked,[=](){
        time->stop();
    });
    //点击按钮，开始计时器
    connect(ui->btn,&QPushButton::clicked,[=](){
        time->start(500);
        ui->btn->setText("暂停");
    });
    //1.给QLabel安装过滤器
    ui->label->installEventFilter(this);
}
//2.重写过滤器evnetfilter
bool Widget::eventFilter(QObject *obj,QEvent *e){
    if(obj==ui->label){
        if(e->type()==QEvent::MouseButtonPress){
            //QMouseEvent *ev=(QMouseEvent *)e;
            //静态类型转换
            QMouseEvent *ev=static_cast<QMouseEvent *>(e);
            QString str=QString("事件过滤器中鼠标在x=%1,y=%2").arg(ev->globalX()).arg(ev->globalY());
            qDebug()<<str;
            return true;
        }
    }
}

Widget::~Widget()
{
    delete ui;
}
void Widget::timerEvent(QTimerEvent *ev){
    static int num=1;
    static int num2=1;
    if(ev->timerId()==id1){
        ui->label_2->setText(QString::number(num++));
    }
    if(ev->timerId()==id2){
        ui->label_3->setText(QString::number(num2++));
    }
}

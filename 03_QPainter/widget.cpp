#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        x+=20;
        update();
    });
    QTimer *timer=new QTimer(this);
    timer->start(100);
    connect(timer,&QTimer::timeout,this,[=](){
        x+=20;
        update();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event){
//    //实例化画家的对象
//    QPainter painter(this);
//    //设置笔画的颜色
//    painter.setPen(QColor(244,255,233));
//    //划线
//    painter.drawLine(QPoint(0,0),QPoint(100,100));
//    //critle
//    painter.drawEllipse(QPoint(100,100),50,50);
//    //画矩形
//    painter.drawRect(QRect(20,20,50,50));
//    //写字
//    painter.drawText(QRect(100,100,100,100),"hello world!");




    /////////////////////////////////高级设置///////////
//    QPainter painter(this);
//    painter.drawEllipse(QPoint(100,50),50,50);
//    //设置抗锯齿能力
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(200,50),50,50);

/////////////////////////////////利用painter画图片
      QPainter painter(this);
      if(this->width()==x){
          x=0;
      }
      painter.drawPixmap(x,0,QPixmap(":/new/prefix1/image/1.jpg"));

}


#include "mywidget.h"
#include "QPushButton"  //按钮控件的头文件
#include "mypushbutton.h"
#include <QDebug>
//类名 首字母大写，单词之间大写
//变量 变量名称 首字母大写，单词和单词之间首字母大写

//编译 ctrl + b
//查找 ctrl + f
//帮助文档 F1
//自动对齐 Ctrl + i
//同名之间的.h .cpp切换 F4

myWidget::myWidget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个按钮
    QPushButton *btn=new QPushButton;
    //让btn对象 依赖在myWidget中
    btn->setParent(this);
    btn->show();//show以顶层的窗口弹出
    //显示文本
    btn->setText("第一个按钮");
    btn->resize(100,50);
    resize(600,400);

    //创建第二个按钮
    //利用重载版本直接初始化
    QPushButton *btn2=new QPushButton("第二个按钮",this);
    btn2->move(100,100);

    //更改窗口名称
    setWindowTitle("第一个窗口");

    //固定窗口大小
    setFixedSize(600,400);

    //创建一个自己的按钮对象
    MypushButton *btn3=new MypushButton;
    btn3->setText("我的按钮");
    btn3->move(200,0);
    btn3->setParent(this);// 设置到对象树中

    //需求 点击我的按钮 关闭窗口
    //参数1 信号的发送者 参数2 发送的信号signal(函数的地址) 参数3 信号的接受者  参数4 处理的槽函数
    //connect(btn3,&QPushButton::clicked,this,&QPushButton::close);
    connect(btn3,&QPushButton::clicked,this,&QWidget::close);//子类继承 父类
}

myWidget::~myWidget()
{
    qDebug()<<"这是mywidget的析构函数";
}


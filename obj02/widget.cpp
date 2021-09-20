#include "widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //创建一个老师的对象和学生对象
    this->tea = new Teacher(this);
    this->st = new Student(this);

    //老师饿了,学生请客的连接
    //connect(tea,&Teacher::hungry,st,&Student::treat);

    //调用下课函数
    //classIsOver();

    //链接带参数的槽 声明作用域的函数指针
    void(Teacher::*teacherSigna)(QString) = &Teacher::hungry; //告诉他这个信号是有参的
    void(Student::*StudenTreat)(QString) = &Student::treat;

    connect(tea,teacherSigna,st,StudenTreat);
    //classIsOver();

    //点击按钮，然后才下课
    QPushButton * btn = new QPushButton("下课",this);
    this->resize(600,400);

    //按钮按下 触发 下课函数 下课函数 触发老师饿了的信号
    //connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);

    //信号也可以连接信号
    void(Teacher::*teacherSigna2)() = &Teacher::hungry;
    void(Student::*StudenTreat2)() = &Student::treat;
    connect(tea,teacherSigna2,st,StudenTreat2);//信号和槽连接
    //connect(btn,&QPushButton::clicked,tea,teacherSigna2);//信号和信号连接

    //下课，学生主动请老师吃饭
    connect(btn,&QPushButton::clicked,st,StudenTreat2);

    //实现点击按钮关闭操作
    QPushButton *btn1 = new QPushButton("关闭按钮",this);
    btn1->resize(100,30);
    btn1->move(100,0);
    connect(btn1,&QPushButton::clicked,this,[=](){
        //emit tea->hungry("宫保鸡丁");
        //this->close();
        btn1->setText("失败了");
    });
}

void Widget::classIsOver()
{
    //下课函数 调用后触发老师饿了的信号
    //emit tea->hungry();
    emit tea->hungry("宫保鸡丁");
}

Widget::~Widget()
{

}

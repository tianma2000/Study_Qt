#include "widget.h"
#include "ui_widget.h"
#include "QPushButton"
#include <QDebug>
#include "mywidget.h"
//Teacher类 老师类
//Student类 学生类
//下课后 老师触发一个信号，饿了 ，学生响应信号，请老师吃饭
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->zy=new Teacher(this);//生成树，不需要考虑内存回收
    this->zrf=new Student(this);

    //链接
//    connect(zy,&Teacher::hugrry,zrf,&Student::treat);

    //链接带参数的信号和槽
    void(Teacher::* teachersignal)(QString)=&Teacher::hugrry;
    void(Student::* studentslot)(QString)=&Student::treat;

    connect(zy,teachersignal,zrf,studentslot);

    //缺少触发器，先链接再触发
    //this->classIsOver();

    //点击一个下课按钮，再触发下课  （有参版本，信号链接触发信号）
    QPushButton *btn=new QPushButton("下课",this);
    resize(600,400);
    //connect(btn,&QPushButton::clicked,this,&Widget::classIsOver);

    //无参版本，信号链接信号
    void(Teacher::* teachersignal2)(void)=&Teacher::hugrry;
    void(Student::* studentslot2)(void)=&Student::treat;
    connect(zy,teachersignal2,zrf,studentslot2);

    //信号连接信号
    connect(btn,&QPushButton::clicked,zy,teachersignal2);

    //断开链接
    //disconnect(zy,teachersignal2,zrf,studentslot2);


    //拓展
    //1.信号可以链接信号
    //2.一个信号可以链接多个槽函数
    connect(btn,&QPushButton::clicked,this,&QWidget::close);
    //3.多个信号可以链接一个槽函数
    QPushButton *btn2=new QPushButton("第二个按钮",this);
    btn2->move(200,0);
    connect(btn2,&QPushButton::clicked,this,&QWidget::close);
    //4.信号和槽函数的参数 必须类型一一对应
    //5.信号和槽的参数个数  信号的个数>=槽，，但剩下的个数必须一一对应。

    //Qt4 以前的版本 链接不会做参数类型检测，虽直观但是存在隐患
    //connect(zy,SIGNAL(hurry()),zrf,SLOT(treat()));



    //Lambda  表达式
    [=](){
        btn2->setText("退出");//修改控件？值传递和引用传递都可以修改?控件本身就是个this指针，所有可以修改成功？
    }();

    //mutable修改的是拷贝，不是本身。
//    QPushButton *mybtn=new QPushButton("1",this);
//    QPushButton *mybtn2=new QPushButton("2",this);
//    int m=10;
//    mybtn->move(0,200);
//    mybtn2->move(0,300);
//    connect(mybtn,&QPushButton::clicked,this,[m]()mutable{m=100+10;qDebug()<<m;});//m默认是只读状态，想修改必须加mutable
//    connect(mybtn2,&QPushButton::clicked,this,[=](){qDebug()<<m;});
//    qDebug()<<m;
        QPushButton *btn3=new QPushButton("关闭",this);
        btn3->move(0,300);
        connect(btn3,&QPushButton::clicked,this,[=](){
            this->close();
            this->classIsOver();
        });//可以解决，信号里的参数和槽的参数匹配的问题。click 触发有参的槽


        //作业
        QPushButton *btn4=new QPushButton("OPEN",this);
        btn4->move(200,200);
        connect(btn4,&QPushButton::clicked,this,[=](){
            QWidget *mywidget1=new QWidget;
            mywidget1->show();
            btn4->setText("close");
            connect(btn4,&QPushButton::clicked,mywidget1,&QWidget::close);
        });

}

Widget::~Widget()
{
    delete ui;
}

void Widget::classIsOver(){
    //下课函数，调用后 触发老师饿了的信号
    //emit zy->hugrry();
    emit zy->hugrry("鸡腿");
}


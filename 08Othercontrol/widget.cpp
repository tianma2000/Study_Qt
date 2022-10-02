#include "widget.h"
#include "ui_widget.h"
#include <QMovie>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //栈控件使用
//设置当前页面的初始位置
    ui->stackedWidget->setCurrentIndex(1);
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    //下来框
    ui->comboBox->addItem("奔驰1");
    ui->comboBox->addItem("奔驰2");
    ui->comboBox->addItem("奔驰3");
    //点击按钮选中奔驰三
    connect(ui->pushButton_4,&QPushButton::clicked,[=](){
        //ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("奔驰3");
    });
    //利用QLabl显示图片
    ui->label->setPixmap(QPixmap(":/new/prefix1/image/1.jpg"));
    //利用QLabel显示动图 gif
    QMovie *moive=new QMovie(":/new/prefix1/image/1.gif");
    ui->label_9->setMovie(moive);
    moive->start();


}

Widget::~Widget()
{
    delete ui;
}


#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //TableWidget
    //设置列数
    ui->tableWidget->setColumnCount(3);
    //设置表头（水平的）
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");
    //设置行数
    ui->tableWidget->setRowCount(5);
    //设置正文
    //ui->tableWidget->setItem(0,0,new QTableWidgetItem("yase"));
    QStringList name;
    name<<"张飞"<<"关羽"<<"赵云"<<"刘备"<<"貂蝉";
    QList<QString> sex;
    sex<<"男"<<"男"<<"男"<<"男"<<"女";
    for(int i=0;i<5;i++){
        int col=0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(name[i]));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(sex[i]));
        //QSstring转为int
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString::number(i+18)));
    }
}

Widget::~Widget()
{
    delete ui;
}


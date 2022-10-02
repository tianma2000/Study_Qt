#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QListWidget>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->radioButtonMan->setChecked(true);
    //选中女后，打印信息
    connect(ui->radioButtonWomen,&QRadioButton::clicked,this,[=](){
        qDebug()<<"women";
    });
    //勾选口感，打印信息
    //多选按钮 2是选中 1是未选中
    connect(ui->checkBox_taste,&QCheckBox::stateChanged,this,[=](int s){
        qDebug()<<"眼光独到"<<s;
    });

    //利用listWidget写诗
//    QListWidgetItem *item=new QListWidgetItem("锄禾日当午",ui->listWidget);
//    QListWidgetItem *item2=new QListWidgetItem("汗滴禾下土",ui->listWidget);
//    QListWidgetItem *item3=new QListWidgetItem("谁知盘中餐",ui->listWidget);
//    QListWidgetItem *item4=new QListWidgetItem("粒粒皆辛苦",ui->listWidget);
//    ui->listWidget->addItem(item);
//    ui->listWidget->addItem(item2);
//    ui->listWidget->addItem(item3);
//    ui->listWidget->addItem(item4);
//    item->setTextAlignment(Qt::AlignHCenter);
    //QStringList   List<string>
    QStringList list;
    list<<"锄禾日当午"<<"汗滴禾下土"<<"谁知盘中餐"<<"粒粒皆辛苦";
    ui->listWidget->addItems(list);

}

Widget::~Widget()
{
    delete ui;
}


#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //treeWidget控件的使用
    //设置水平头
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");


    QTreeWidgetItem *item= new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem *item2= new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem *item3= new QTreeWidgetItem(QStringList()<<"智力");
//加载顶层节点
    ui->treeWidget->addTopLevelItem(item);
    ui->treeWidget->addTopLevelItem(item2);
    ui->treeWidget->addTopLevelItem(item3);
//追加 子节点
    QTreeWidgetItem *H1=new QTreeWidgetItem(QStringList()<<"刚被猪"<<"吸收伤害的同时造成伤害");
    item->addChild(H1);
}

Widget::~Widget()
{
    delete ui;
}


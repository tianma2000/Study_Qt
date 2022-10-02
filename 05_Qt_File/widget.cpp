#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QColorDialog>
#include <QFontDialog>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //点击按钮，弹出文件对话框
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString path=QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\zhang\\Documents\\QT\\05_Qt_File\\test");
        //将路径信息放入到LineEdit中
        ui->lineEdit->setText(path);

        //改变编码格式
        //QTextCodec *codec=QTextCodec::codecForName("gbk");

        //QFile 默认的格式是utf-8的模式
        //读取内容 放入到textEdit中
        QFile file(path);//参数就是路径
        //设置打开方式
        file.open(QIODevice::ReadOnly);
        //QByteArray arry=file.readAll();
        QByteArray  arry;
        while(!file.atEnd()){
            arry+=file.readLine();
        }
        //将读取的数据放入到textEdit中
        ui->textEdit->setText(arry);
        //ui->textEdit->setText(codec->toUnicode(arry));//利用code的方法，将arry转码。


        file.close();

        //进行文件写入
//        file.open(QIODevice::Append);
//        file.write("哈哈哈哈");
//        file.close();


        //读取文件的信息
        QFileInfo info(path);
        qDebug()<<"文件名称："<<info.fileName()<<"文件路径"<<info.filePath()<<"文件大小："<<info.size()<<"文件后缀："<<info.suffix();
        qDebug()<<"创建时间："<<info.created().toString("yyyy-MM-dd hh:mm:ss ");
        qDebug()<<"最后修改时间："<<info.lastModified().toString("yyyy-MM-dd hh:mm:ss");

    });
    connect(ui->pushButton_2,&QPushButton::clicked,[=](){
        QColorDialog::getColor();
    });
    connect(ui->pushButton_3,&QPushButton::clicked,[=](){
        bool falg=true;
        QFont fot=QFontDialog::getFont(&falg);
    });
}

Widget::~Widget()
{
    delete ui;
}


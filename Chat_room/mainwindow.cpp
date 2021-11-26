#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <QTextEdit>
#include <QString>
#include <QListWidget>
#include <QListWidgetItem>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //1.新建客户端对象
    mSocket = new QTcpSocket(this);
    //2.连接服务器
    mSocket->connectToHost(QHostAddress("127.0.0.1"),8888);
    //3.发送一个消息
    connect(ui->pushserver,&QPushButton::clicked,[=](){
        QString s =  ui->textEdit->toPlainText();
        if(s == "")
        {
            return;
        }
        if(s == "/help")
        {
            /*
             *cout << GREEN << "输入正常消息 群聊" << endl;
            cout << "输入/pm 私聊" << endl;
            cout << "输入/all 广播" << endl;
            cout << "输入/pmall 显示全部在线" << endl;
            cout << "输入/ls 查看全部文件" << endl;
            cout << "输入/upload 文件名 上传文件" << endl;
            cout << "输入/down 文件名 下载文件" << WHITE << endl;
            */
            QStringList list;
            list << "输入/log 用户名 密码 登录" <<
                    "输入/res 用户名 密码 注册" <<
                    "输入正常消息 群聊" <<
                    "输入/pm 私聊" <<
                    "输入/all 广播" <<
                    "输入/pmall 显示全部在线" <<
                    "输入/ls 查看全部文件";
            ui->listWidget->addItems(list);
            return;
        }
        mSocket->write(s.toUtf8());
        ui->textEdit->setText("");
        QStringList list;
        list << s;
        ui->listWidget->addItems(list);
    });



    connect(mSocket, SIGNAL(readyRead()), this, SLOT(ovo()));
}

void MainWindow::ovo()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    qDebug()<<"当前读取前可以读取数据的字节是："<< socket->bytesAvailable();
    QByteArray datagram = socket->readAll();
    qDebug()<<datagram.data();
    QStringList list;
    list << datagram.data();
    ui->listWidget->addItems(list);
}



MainWindow::~MainWindow()
{
    delete ui;
}

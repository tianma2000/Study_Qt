#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <Lession2lib.h>
#include <QFile>
#include <QMessageBox>
#include <QTextCodec>
#include <QCryptographicHash>
#include <QDebug>
#include <QApplication>
#include <QDir>//目录类
#include <QFileInfo>
#include <QPushButton>
#include <QFileDialog>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    //testFunction();
    thread.start();
    md5.moveToThread(&thread);

    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);  //设置无边框

    //设置阴影边框效果
    QGraphicsDropShadowEffect *shadow=new QGraphicsDropShadowEffect(this);

    shadow->setBlurRadius(10);   //设置边角的圆
    shadow->setColor(Qt::black);  //设置阴影颜色
    shadow->setOffset(0);

    ui->shadowWidget->setGraphicsEffect(shadow);//父窗口透明，只留下子窗口
    this->setAttribute(Qt::WA_TranslucentBackground);//设置透明
    //ui->shadowWidget->setGeometry(this->geometry());    太满了，边框噶没了
    //this->setGraphicsEffect(shadow);

    //手动连接信号

    //注册一下类型
    qRegisterMetaType<QHash<QByteArray,QStringList>> ("QHash<QByteArray,QStringList>");//相当于一个模板？

    void(GetMd5::*getmd5signal)(const QHash<QByteArray,QStringList>&)=&GetMd5::giveMd5;//这个&这么关键吗
    void(Widget::*getmd5solt)(const QHash<QByteArray,QStringList>&)=&Widget::ongiveMd5;
    connect(&md5,getmd5signal,this,getmd5solt);

    void(Widget::*chechDemSignal)(const QString &)=&Widget::chechDem;
    void(GetMd5::*checkDumSolt)(const QString &)=&GetMd5::checkDum;
    connect(this,chechDemSignal,&md5,checkDumSolt);

    void(GetMd5::*giveIntSignal)(int,int)=&GetMd5::giveInt;
    void(Widget::*getValueSolt)(int,int)=&Widget::getValue;
    connect(&md5,giveIntSignal,this,getValueSolt);


//    //用户自己选择文件夹
//    connect(ui->btnselect,&QPushButton::clicked,this,[=](){
//        QString path=QFileDialog::getOpenFileName(this,"选择文件夹，查找相同文件","c:\\Users\\zhang\\Desktop");
//        ui->lineEdit->setText(path);

//    });
}

Widget::~Widget()
{
    //程序退出时，关闭线程
    thread.exit();
    thread.wait(10*1000);
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event){
    QWidget::mousePressEvent(event);
    //this->move(event->globalX(),event->globalY());
    QPoint y=event->globalPos();   //鼠标相对于桌面左上角的位置，鼠标全局位置
    this->z=event->pos();         //鼠标相对于窗口左上角的位置
    QPoint x=this->geometry().topLeft();  //拿到窗口左顶点的全局位置
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);
    QPoint y=event->globalPos();   //鼠标相对于桌面左上角的位置，鼠标全局位置
    QPoint x=y-z;                //拿到窗口左顶点的全局位置
    this->move(x);
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
    this->z=QPoint();   //释放鼠标，清空z
}


void Widget::on_exitBtn_clicked()
{
    //关闭窗口
    //程序退出时，关闭线程                            窗口关闭快于线程销毁  或者让他等待一会
    //thread.exit();
    this->close();
}

void Widget::on_maxBtn_clicked()
{
    //最大化或还原
    if(this->isMaximized()){
        //还原
        ui->vlMain->setMargin(9);
        this->showNormal();
    }else{
        //最大化
        ui->vlMain->setMargin(0);//改变距离边框像素
        this->showMaximized();//并没有占满

    }

}

void Widget::on_mixBtn_clicked()
{
    //最小化
    this->showMinimized();
}

void Widget::on_pushButton_clicked()
{
    QFile file("C:\\Users\\zhang\\Desktop\\cad+aspen\\down\\qt-opensource-windows-x86-5.14.2.exe");
    if(file.open(QIODevice::ReadOnly)){
        qDebug()<<"读取成功";
        //如果文件是utf-8，可以直接读取
//        QByteArray arry=file.readAll();
//        QMessageBox::information(this,"",arry);
//        file.close();

        //如果是gbk需要引用头文件QTextCodec  创建对象QTextCodec *codec=QTextCodec::codecForName("gbk");
//        QTextCodec *codec=QTextCodec::codecForName("gbk");
//        QByteArray arry;  //QByteArry 可以创建一个QString的类
//        while(!file.atEnd()){
//            arry+=file.readLine();
//        };
//        QMessageBox::information(this,"诗",codec->toUnicode(arry));

        //小文件读md5
//        QByteArray arry=file.readAll();
//        QByteArray md5=QCryptographicHash::hash(arry,QCryptographicHash::Md5);
//        qDebug()<<md5<<"    "<<md5.toHex();

        //读大文件
        QCryptographicHash hash(QCryptographicHash::Md5);//看看构造函数需要什么
        //QT是基于事件循环的
        while (!file.atEnd()) {
            QByteArray arry=file.read(100*1024*1024);
            hash.addData(arry);
            qApp->processEvents();//让他执行事件
        }
        QByteArray md5=hash.result();
        qDebug()<<md5<< " "<<md5.toHex();
        file.close();

    }
}

void Widget::on_btnGetFile_clicked()
{
//    QStringList info=getFiles("C:\\Users\\zhang\\Desktop\\cad+aspen\\down\\AS_SSD_Benchmark");
//    for(int i=0;i<info.count();i++){
//        QString filename=info.at(i);
//        QByteArray md5=getFileMd5(filename);
//        //qDebug()<<"fileName:"<<filename<<" md5:"<<md5;
//        fileMd5[md5].append(filename);
//    }
    //qDebug()<<info;

    //读取hash内容
//    for(QHash<QByteArray,QStringList>::iterator it=fileMd5.begin();it!=fileMd5.end();it++){
//        qDebug()<<"md5:"<<it.key()<<"count:"<<(*it).count()<<" ";
//        for(int i=0;i<(*it).count();i++){
//            qDebug()<<(*it).at(i);
//        }
//        if((*it).count()>1){
//            qDebug()<<it.value();
//        }
//    }

    //md5.checkDum("C:\\Users\\zhang\\Desktop\\cad+aspen\\down\\AS_SSD_Benchmark");//是直接调用的，在widget线程里面

    //通过信号和槽。。挂接？
    ui->progressBar->setValue(0);
    QString path=QFileDialog::getExistingDirectory(this,"选择文件夹，查找相同文件","c:\\Users\\zhang\\Desktop");
    ui->lineEdit->setText(path);
    emit chechDem(path);
}

void Widget::ongiveMd5(const QHash<QByteArray, QStringList> &dumplates)
{
    this->dumplates=dumplates;
    ui->listWidgetMd5->clear();
    for(QHash<QByteArray,QStringList>::const_iterator it=dumplates.begin();it!=dumplates.end();it++){
        qDebug()<<"md5:"<<it.key()<<"count:"<<(*it).count();
        if((*it).count()>1){
            //qDebug()<<"file:"<<it.value();
            ui->listWidgetMd5->addItem(it.key());
        }
    }
}

void Widget::getValue(int crruent, int total)
{
    ui->progressBar->setValue(crruent);
    ui->progressBar->setMaximum(total);
}




void Widget::on_progressBar_valueChanged(int value)
{

}

void Widget::on_listWidgetMd5_currentTextChanged(const QString &currentText)
{
    //qDebug()<<currentText;
    ui->listWidgetStr->addItems(dumplates[currentText.toLocal8Bit()]);
}

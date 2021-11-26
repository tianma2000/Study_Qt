#include "mainscenario.h"
#include "ui_mainscenario.h"
#include <QPixmap>
#include <QPushButton>
#include <QPainter>
#include "mypushbuttons.h"
#include <QDebug>
#include <QFile>
#include <QTimer>
#include <QSound>


Mainscenario::Mainscenario(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mainscenario)
{
    ui->setupUi(this);

    mainInit();
    StartBtn();
    connectInit();
}
//初始化的值
void Mainscenario::mainInit()
{
    //实例化一个关卡的场景
    this->m_chooseScence = new chooselevelscene(this);
    //固定宽高
    this->setFixedSize(320,588);
    //设置应用图片
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    //设置窗口标题
    this->setWindowTitle("翻金币");

    //设置qss
    QFile file(":/qss/main.qss");
    file.open(QFile::ReadOnly);
    QTextStream filetext(&file);
    QString stylesheet = filetext.readAll();
    this->setStyleSheet(stylesheet);
    file.close();



}
//开始按钮初始化
void Mainscenario::StartBtn()
{

    //开始按钮
    m_startBtn = new MyPushButtons(":/res/MenuSceneStartButton.png");
    m_startBtn->setParent(this);
    m_startBtn->setObjectName("my_index_button");
    m_startBtn->move((int)this->width() * 0.5 - m_startBtn->width() * 0.5 , (int)this->height() * 0.7);

}
//信号和槽的初始化
void Mainscenario::connectInit()
{
    //准备开始按钮音效
    QSound * startSound = new QSound(":/res/TapButtonSound.wav",this);
    //退出按钮实现
    connect(ui->actionexit,&QAction::triggered,[=](){
        this->close();
    });

    //进入选择关卡界面
    connect(m_startBtn,&MyPushButtons::clicked,[=](){
        m_chooseScence->setGeometry(this->geometry());
        //播放开始音效
        startSound->play();
        m_startBtn->zoomBottom();
        m_startBtn->zoomTop();
        //小延时
        QTimer::singleShot(400,this,[=](){
            //进入到选择关卡的场景
            //隐藏自己 显示关卡
            this->hide();
            m_chooseScence->show();
        });
    });

    //关卡界面发送退出信号，主函数响应
    connect(this->m_chooseScence,&chooselevelscene::chooseBackCenario,[=](){
        qDebug() << "关卡界面发送退出信号，主函数响应";
        this->setGeometry(m_chooseScence->geometry());
        this->m_chooseScence->hide();
        this->show();
    });
}





void Mainscenario::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景上的图标
    pix.load(":/res/Title.png");
    pix = pix.scaled((int)pix.width()/2,(int)pix.height()/2);
    painter.drawPixmap(10,30,pix);
}


Mainscenario::~Mainscenario()
{
    delete ui;
}

#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>
#include <QPixmap>
#include <mypushbutton.h>
#include <QTimer>
#include <QSound>

//收获十一 如果#include没法导入，在pro中加入相应模块
//收获三延时进入操作  QTimer::singleShot(500,this,[=]()
//收获八 一个场景里面new下一层场景
mainscene::mainscene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainscene)
{
    ui->setupUi(this);
    //设置主场景
    //设置固定大小
    setFixedSize(320,588);

    //设置图标
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //设置标题
    setWindowTitle("翻金币");

    //退出的实现
    connect(ui->actionexit,&QAction::triggered,[=](){
        this->close();
    });

    //开始按钮
    MyPushButton *startbtn=new MyPushButton(":/res/MenuSceneStartButton.png");
    startbtn->setParent(this);
    startbtn->move(this->width()*0.5-startbtn->width()*0.5,this->height()*0.7);

    //实例化选择关卡场景
    chooseScene =new ChooseLevelScene();

    //监听选择关卡的返回按钮的信号
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=](){
        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();//选择关卡场景，隐藏掉
        this->show();//重新显示主场景
    });

    //准备开始音效资源
    QSound *startSound=new QSound(":/res/TapButtonSound.wav",this);
    //startSound->setLoops(-1);//设置循环  如果是-1，代表无限
    connect(startbtn,&QPushButton::clicked,[=](){
        startSound->play();
        startbtn->zoom1();
        startbtn->zoom2();

        //延时进入
        QTimer::singleShot(500,this,[=](){
            //进入到选择关卡的场景中

            //设置chooseScene的位置
            chooseScene->setGeometry(this->geometry());
            this->hide();
            chooseScene->show();
        });

    });
}

mainscene::~mainscene()
{
    delete ui;
}
void mainscene::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    // 画一个小图标
    QPixmap pix1;
    pix1.load(":/res/Title.png");
    //图片缩放
    pix1=pix1.scaled(pix1.width()*0.5,pix1.height()*0.5);
    painter.drawPixmap(10,30,pix1);
}

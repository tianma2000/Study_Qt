#include "chooselevelscene.h"
#include <QMenuBar>
#include <QPainter>
#include <mypushbutton.h>
#include <QTimer>
#include <QLabel>
#include <QDebug>
#include "playscene.h"
#include <QSound>
//收获四 自定义信号和槽，自定义信号的发送
//收获五 利用一个for循环，创建一个矩阵，利用%和除号
//收获六 如何设置鼠标穿透 setAttribute
//收获七 设置label的水平居中 setAlignment
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //设置选择关卡的场景
    this->setFixedSize(320,588);

    //设置图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    this->setWindowTitle("选择场景");

    //设置菜单栏
    QMenuBar *bar=menuBar();
    setMenuBar(bar);

    //设置开始菜单
    QMenu *startMenu=bar->addMenu("开始");

    //创建菜单项
    QAction *quit=startMenu->addAction("退出");
    connect(quit,&QAction::triggered,[=](){
        this->close();
    });

    //返回按钮
    MyPushButton *backbtn=new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backbtn->setParent(this);
    backbtn->move(this->width()-backbtn->width(),this->height()-backbtn->height());


    //点击返回
    connect(backbtn,&QPushButton::clicked,[=](){
        //this->hide();
//        backbtn->zoom1();
//        backbtn->zoom2();
        //告诉主场景我返回了，主场景监听了ChooseLevelScene的返回按钮

        //延迟发送
        QTimer::singleShot(500,this,[=](){
            emit this->chooseSceneBack();//发送信号
        });

    });
    //添加音乐素材
    QSound *chooselevesSound=new QSound(":/res/TapButtonSound.wav",this);

    //创建关卡按钮
    for(int i=0;i<20;i++){

        MyPushButton *menuBtn=new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25+i%4*70,130+i/4*70);

        //直接设置数字，显示不好
        //menuBtn->setText(QString::number(i+1));

        //监听按钮的数字(监听选择的关卡）
        connect(menuBtn,&MyPushButton::clicked,this,[=](){
            chooselevesSound->play();
            qDebug()<<QString("选择的是第 %1 关").arg(i+1);

            //进入游戏场景
            this->hide();//将选关场景隐藏掉
            play=new PlayScene(i+1);//创建游戏场景

            //设置游戏的初始游戏位置
            play->setGeometry(this->geometry());

            play->show();//显示游戏场景


            //监听paly的back的返回信号
            connect(play,&PlayScene::chooseSceneBack,this,[=](){
                play->setGeometry(this->geometry());
                this->show();
                delete play;
                play=NULL;
            });


        });
        //这个会被QLabel给覆盖住要设置鼠标穿透


        //设置关卡数字
        QLabel * label=new QLabel(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));//label默认的显示位置是在左中，显示效果不好，所以要改对齐方式
        label->move(25+i%4*70,130+i/4*70);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);//设置垂直居中和水平居中

        //设置鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);//需要记一个55 和一个 51
    }


}

//重写画图事件
void ChooseLevelScene::paintEvent(QPaintEvent *e){
    QPainter painter(this);
    //加载背景
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap(this->width()*0.5-pix.width()*0.5,30,pix.width(),pix.height(),pix);

}

#include "playscene.h"
#include <QMenuBar>
#include <QPainter>
#include <mypushbutton.h>
#include <QTimer>
#include <QLabel>
#include <QFont>
#include <mycoin.h>
#include <QDebug>
#include "dataconfig.h"
#include <QPropertyAnimation>
#include <QSound>
#include <QTimer>
#include <QTime>
//PlayScene::PlayScene(QWidget *parent) : QMainWindow(parent)
//{

//}

//收获九  将字体设置到标签中
//收获十  QLabel不指定parent，会显示不出来
PlayScene::PlayScene(int number){
    this->sceneLevel=number;
    //设置大小
    this->setFixedSize(300,588);

    //设置图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));

    //设置标题
    this->setWindowTitle("游戏场景");
    //设置菜单栏
    QMenuBar *bar=menuBar();
    setMenuBar(bar);

    //设置开始菜单
    QMenu *startMenu=bar->addMenu("开始");

    //创建菜单项
    QAction *quit=startMenu->addAction("退出");
    connect(quit,&QAction::triggered,this,[=](){
        this->close();
    });

    //返回按钮
    MyPushButton *backbtn=new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backbtn->setParent(this);
    backbtn->move(this->width()-backbtn->width(),this->height()-backbtn->height());
    //点击返回
    connect(backbtn,&QPushButton::clicked,[=](){
        QTimer::singleShot(500,this,[=](){
            emit this->chooseSceneBack();//发送信号
        });

    });
    //显示当前关卡
    QLabel *label=new QLabel(this);
    label->setGeometry(30,this->height()-50,120,50);

    //设置字体
    QFont font;
    font.setFamily("华文琥珀");
    font.setPointSize(20);
    label->setFont(font);
    label->setText(QString("LEVEl：%1").arg(this->sceneLevel));

    DataConfig config;
    //初始化数组
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            gamearry[i][j]=config.mData[this->sceneLevel][i][j];
        }
    }
    //初始化胜利图片
    QLabel * winGame=new QLabel(this);
    QPixmap pix;
    pix.load(":/res/LevelCompletedDialogBg.png");
    winGame->setGeometry(0,0,pix.width(),pix.height());
    winGame->setPixmap(pix);
    winGame->move(this->width()*0.5-pix.width()*0.5,-pix.height());
    //设置翻金币的音效
    QSound *changeCoinSound=new QSound(":/res/ConFlipSound.wav",this);

    //设置胜利的音效
    QSound *winSound=new QSound(":/res/LevelWinSound.wav",this);

    //添加一个计时器
    //QLabel *showTime=new QLabel(this);写到类内作为成员变量
    showTime=new QLabel(this);
    showTime->setFixedSize(100,100);
    showTime->move(160,100);
//    time=new QTime();//写到类内作为成员变量-----------不需要
    //设置时间初值
    time.setHMS(0,0,0,0);
    QTimer *timer=new QTimer(this);//创建一个定时器
    connect(timer,&QTimer::timeout,this,&PlayScene::update);//链接自定义更新槽函数
    timer->start(1000);


    //显示金币背景
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            QPixmap pix=QPixmap(":/res/BoardNode.png");
            QLabel *label1=new QLabel(this);
            label1->setGeometry(0,0,pix.width(),pix.height());
            label1->setPixmap(pix);
            label1->move(57+i*50,200+j*50);

            //显示是金币还是银币
            QString str;
            if(gamearry[i][j]==1){
                str=":/res/Coin0001.png";
            }else{
                str=":/res/Coin0008.png";
            }
            MyCoin *coin=new MyCoin(str);
            coin->setParent(this);
            coin->move(59+i*50,204+j*50);


            //给金币赋值属性
            coin->posX=i;
            coin->posY=j;
            coin->flag=gamearry[i][j];

            //coin在走完循环之后就找不到了需要用一个数组保存起来
            btnCoin[i][j]=coin;
            //点击coin实现翻转
            connect(coin,&MyCoin::clicked,this,[=](){
                changeCoinSound->play();
                coin->changeFlag();
                gamearry[i][j]=gamearry[i][j]==0?1:0;


                //实现周围金币的延迟翻转；
                QTimer::singleShot(300,this,[=](){
                    //右部翻转
                    if(coin->posX+1<=3){
                        btnCoin[coin->posX+1][coin->posY]->changeFlag();
                        gamearry[coin->posX+1][coin->posY]=gamearry[coin->posX+1][coin->posY]==0?1:0;
                    };
                    //左部翻转
                    if(coin->posX-1>=0){
                        btnCoin[coin->posX-1][coin->posY]->changeFlag();
                        gamearry[coin->posX-1][coin->posY]=gamearry[coin->posX-1][coin->posY]==0?1:0;
                    };
                    //上部翻转
                    if(coin->posY-1>=0){
                        btnCoin[coin->posX][coin->posY-1]->changeFlag();
                        gamearry[coin->posX][coin->posY-1]=gamearry[coin->posX][coin->posY-1]==0?1:0;
                    };
                    //下部翻转
                    if(coin->posY+1<=3){
                        btnCoin[coin->posX][coin->posY+1]->changeFlag();
                        gamearry[coin->posX][coin->posY+1]=gamearry[coin->posX][coin->posY+1]==0?1:0;
                    };

                    //利用标志判断胜利
                    this->isWin=true;
                    for(int i=0;i<4;i++){
                        for(int j=0;j<4;j++){
                            if(gamearry[i][j]==false){
                                this->isWin=false;
                                break;
                            }
                        }
                    }
                    if(isWin==true){
                        qDebug()<<"你赢了";

                        //使计时器停止
                        timer->stop();


                        winSound->play();
                        //胜利之后coin是不可以被点击的，要禁用，可以利用mouseperssevent拦截
//                        for(int i=0;i<4;i++){
//                            for(int j=0;j<4;j++){
//                                    btnCoin[i][j]->isWin=true;
//                                };
//                            };

                        //2
                        //btnCoin[1][1]->isWin=true;  报错isWin的重复定义

                        //3，实现，点击coin和翻转之间的链接
                        for(int i=0;i<4;i++){
                            for(int j=0;j<4;j++){
                                disconnect(btnCoin[i][j],&MyCoin::clicked,this,0);
                            };
                        };

                        //让胜利的图片从上面下来
                        QPropertyAnimation *animation=new QPropertyAnimation(winGame,"geometry");
                        animation->setDuration(1000);
                        animation->setStartValue(QRect(winGame->x(),winGame->y(),winGame->width(),winGame->height()));
                        animation->setEndValue(QRect(winGame->x(),winGame->y()+114,winGame->width(),winGame->height()));
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start();
                    };


                });
            });

        }
    }

}

//重写画家事件
void PlayScene::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    //加载背景
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //加载标题
    pix.load(":/res/Title.png");
    painter.drawPixmap(this->width()*0.5-pix.width()*0.5,30,pix.width(),pix.height(),pix);
}

//自定义更新槽函数
void PlayScene::update(){
    static quint32 time_out=0;
    time_out++;
    time=time.addSecs(1);
    showTime->setText(time.toString("hh:mm:ss"));
    qDebug()<<"自定义槽函数";
}

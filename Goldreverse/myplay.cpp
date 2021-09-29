#include "myplay.h"
#include "ui_myplay.h"
#include "dataconfig.h"
#include <QPropertyAnimation>
#include <QSound>

myPlay::myPlay(int index,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::myPlay)
{
    ui->setupUi(this);
    this->m_levelIndex = index;
    mainInit();
    connectInit();
}


void myPlay::mainInit()
{
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

    //返回按钮
    backBtn = new MyPushButtons(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() , this->height() - backBtn->height());

    //关卡信息
    QLabel * text = new QLabel(this);
    text->resize(200,40);
    text->move(20,this->height() - text->height()-10);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    text->setFont(font);
    text->setText(QString("level:%1").arg(m_levelIndex));

    //初始化每个关卡的二维数组
    dataConfig config;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            this->gameArray[i][j]=config.mData[this->m_levelIndex][i][j];
        }
    }

    //胜利图片显示 默认在背景外
    QLabel * winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move((this->width() - tmpPix.width()) / 2, -400);


    //显示金币的背景图
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            //绘制背景图片
            QPixmap pix=QPixmap(":/res/BoardNode.png");
            QLabel *label=new QLabel;
            label->setGeometry(0,0,50,50);
            label->setPixmap(pix);
            label->setParent(this);
            label->move(57+i*50,200+j*50);

            //创建金币
            QString str;
            if(this->gameArray[i][j]==1)
            {
                str=":/res/Coin0001.png";
            }
            else
            {
                str=":/res/Coin0008.png";
            }

            MyCoin *coin=new MyCoin(str);
            coin->setParent(this);
            coin->move(59+i*50,204+j*50);

            //给金币的属性赋值
            coin->posX=i;
            coin->posY=j;
            coin->flag=this->gameArray[i][j]; //  1正面 0反面
            //将金币放入到金币的二维数组里面
            coinBtn[i][j]=coin;

            //点击金币进行翻转
            connect(coin,&MyCoin::clicked,[=](){
                QSound * soud = new QSound(":/res/ConFlipSound.wav",this);
                soud->play();
                //在翻转金币的时候禁用其他按钮
                for(int i = 0 ; i < 4; i++)
                {
                    for(int j = 0 ; j < 4 ; j++)
                    {
                        this->coinBtn[i][j]->isWin = true;
                    }
                }

                coin->changeFlag();
                this->gameArray[i][j]=this->gameArray[i][j]==0?1:0;

                QTimer::singleShot(100,this,[=](){
                    // 翻转周围硬币的操作，延时翻转
                    if(coin->posX+1<=3)
                    {// 周围的右侧硬币翻转的条件
                        coinBtn[coin->posX+1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX+1][coin->posY]=this->gameArray[coin->posX+1][coin->posY]==0?1:0;

                    }
                    if(coin->posX-1>=0) // 周围左侧硬币的翻转条件
                    {
                        coinBtn[coin->posX-1][coin->posY]->changeFlag();
                        this->gameArray[coin->posX-1][coin->posY]=this->gameArray[coin->posX-1][coin->posY]==0?1:0;
                    }
                    if(coin->posY+1<=3) // 周围下侧硬币的翻转条件
                    {
                        coinBtn[coin->posX][coin->posY+1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY+1]=this->gameArray[coin->posX][coin->posY+1]==0?1:0;
                    }
                    if(coin->posY-1>=0) // 周围上侧硬币的翻转条件
                    {
                        coinBtn[coin->posX][coin->posY-1]->changeFlag();
                        this->gameArray[coin->posX][coin->posY-1]=this->gameArray[coin->posX][coin->posY-1]==0?1:0;
                    }


                    //在翻转完金币的时候释放其他按钮
                    for(int i = 0 ; i < 4; i++)
                    {
                        for(int j = 0 ; j < 4 ; j++)
                        {
                            this->coinBtn[i][j]->isWin = false;
                        }
                    }


                    //判断是否胜利
                    this->m_isWin=true;
                    for(int i=0;i<4;i++)
                    {
                        for(int j=0;j<4;j++){
                            if(coinBtn[i][j]->flag==false){
                                this->m_isWin=false;
                                break;
                            }
                        }
                    }
                    if(this->m_isWin==true){
                        this->backBtn->m_flag = true;
                        //胜利了
                        qDebug() << "胜利了";
                        //将所有按钮胜利的标志改为 true,如果再次点击按钮直接return
                        for(int i=0;i<4;i++)
                        {
                            for(int j=0;j<4;j++){
                                coinBtn[i][j]->isWin=true;
                            }
                        }
                        //将胜利图片砸下来
                        QPropertyAnimation * an = new QPropertyAnimation(winLabel,"geometry");
                        an->setDuration(1000);
                        an->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        an->setEndValue(QRect(winLabel->x(),winLabel->y() + 300,winLabel->width(),winLabel->height()));
                        an->setEasingCurve(QEasingCurve::OutBounce);
                        an->start();

                        QSound * soud1 = new QSound(":/res/LevelWinSound.wav",this);
                        soud1->play();

                        QTimer::singleShot(3000,[=](){
                            this->backBtn->m_flag = false;
                            //发送一个申请下一关的信号
                            soud1->stop();
                            qDebug() << "下一关啦！";
                            emit gotoNext(m_levelIndex);
                        });
                    }

                });

            });

        }
    }


}

void myPlay::connectInit()
{
    //退出按钮实现
    connect(ui->actionexit,&QAction::triggered,[=](){
        this->close();
    });

    //点击返回按钮时发送信号
    connect(backBtn,&QPushButton::clicked,[=](){
        QSound * startSound1 = new QSound(":/res/TapButtonSound.wav",this);
        startSound1->play();
        QTimer::singleShot(500,[=](){
            qDebug() << "发送了从游戏界面返回的信号";
            emit this->playtochoose();
        });

    });
}

//绘图设备
void myPlay::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景上的标题
    pix.load(":/res/Title.png");
    painter.drawPixmap(this->width() * 0.5 - pix.width() * 0.5 , 30, pix.width() ,pix.height() ,pix);


}


myPlay::~myPlay()
{
    delete ui;
}

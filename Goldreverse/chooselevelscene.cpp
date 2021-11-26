#include "chooselevelscene.h"
#include "ui_chooselevelscene.h"
#include <QSound>


chooselevelscene::chooselevelscene(QWidget * fu,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chooselevelscene)
{
    ui->setupUi(this);
    m_parent = fu;
    mainInit();
    levelInit();
    connectInit();
}


//初始化的值
void chooselevelscene::mainInit()
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

}

//关卡按钮
void chooselevelscene::levelInit()
{
    QSound * startSound = new QSound(":/res/TapButtonSound.wav",this);
    //创建选择关卡的按钮
    for(int i = 0 ; i < 20 ;i++)
    {
        MyPushButtons * menuBtn = new MyPushButtons(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        //25是总体和窗口的间距 70是每个间距
        menuBtn->move(25 + i % 4 * 70 ,130 + i / 4 * 70);

        //监听按钮的点击 关卡选择界面
        connect(menuBtn,&MyPushButtons::clicked,[=](){
           startSound->play();
           qDebug() << QString("你选择的是第 %1 关").arg(i + 1);
           this->hide();

           this->m_playScena = new myPlay(i+1);
           this->m_playScena->setGeometry(this->geometry());

           this->m_playScena->show();

           //接收游戏界面返回的信号和处理
           connect(this->m_playScena,&myPlay::playtochoose,this,&chooselevelscene::sotsPlaytoCloose);


           //游戏胜利的情况
           connect(this->m_playScena,&myPlay::gotoNext,this,&chooselevelscene::sotsGotoNext);

        });

        //在上面打上数字
        QLabel * label = new QLabel(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i + 1));
        label->move(25 + i % 4 * 70 ,130 + i / 4 * 70);
        label->setObjectName("my_label_text_center");
        //垂直和水平居中
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //设置让鼠标进行穿透 51号属性
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

//接收游戏界面返回的信号和处理
void chooselevelscene::sotsPlaytoCloose()
{
    this->setGeometry(m_playScena->geometry());
    this->show();
    delete m_playScena;
    m_playScena = nullptr;
}

//游戏胜利的情况
void chooselevelscene::sotsGotoNext(int index)
{
    if(index == 20)
    {
        this->setGeometry(m_playScena->geometry());
        this->show();
        delete m_playScena;
        m_playScena = nullptr;
        return;
    }
    qDebug() << "接收到了信息";
    //this->show();
    QRect a = m_playScena->geometry();
    delete m_playScena;
    m_playScena = nullptr;

    qDebug() << QString("你选择的是第 %1 关").arg(index + 1);
    this->hide();
    this->m_playScena = new myPlay(index+1);
    this->m_playScena->show();
    m_playScena->setGeometry(a);

    //接收游戏界面返回的信号和处理
    connect(this->m_playScena,&myPlay::playtochoose,this,&chooselevelscene::sotsPlaytoCloose);
    //游戏胜利的情况
    connect(this->m_playScena,&myPlay::gotoNext,this,&chooselevelscene::sotsGotoNext);
}




//信号和槽的初始化
void chooselevelscene::connectInit()
{
    //退出按钮实现
    connect(ui->actionexit,&QAction::triggered,[=](){
        this->close();
    });

    //点击按钮返回
    connect(backBtn,&MyPushButtons::clicked,[=](){
        qDebug() << "单机了返回按钮";
        QSound * startSound1 = new QSound(":/res/TapButtonSound.wav",this);
        startSound1->play();
        QTimer::singleShot(100,[=](){
            //第一种解决方法，父类指针
            //this->hide();
            //m_parent->show();

            //第二种解决方法 使用信号和槽 发送信号
            emit this->chooseBackCenario();
        });
    });
}

//绘图
void chooselevelscene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画背景上的标题
    pix.load(":/res/Title.png");
    painter.drawPixmap(this->width() * 0.5 - pix.width() * 0.5 , 30, pix.width() ,pix.height() ,pix);


}

chooselevelscene::~chooselevelscene()
{
    delete ui;
}

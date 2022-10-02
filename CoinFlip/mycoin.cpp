#include "mycoin.h"
#include <QDebug>

//MyCoin::MyCoin(QWidget *parent) : QPushButton(parent)
//{

//}

MyCoin::MyCoin(QString btnImg){
    QPixmap pix;
    bool ret=pix.load(btnImg);
    if(!ret){
        QString str="%1图片加载失败";
        qDebug()<<str.arg(btnImg);
    }
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:none}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));
    timer1=new QTimer(this);
    timer2=new QTimer(this);

    //金币翻成银币
    connect(timer1,&QTimer::timeout,this,[=](){
        QPixmap pix;
        pix.load(QString(":/res/Coin000%1.png").arg(min++));
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:none}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(this->min>this->max){
            timer1->stop();
            isAction=false;
            min=1;
        }
    });

    //银币翻成金币
    connect(timer2,&QTimer::timeout,this,[=](){
        QPixmap pix;
        pix.load(QString(":/res/Coin000%1.png").arg(max--));
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:none}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
        if(this->max<this->min){
            timer2->stop();
            isAction=false;
            max=8;
        }
    });


}
void MyCoin::mousePressEvent(QMouseEvent *e){
    if(isAction){
        return;
    }else{
        QPushButton::mousePressEvent(e);
    }
}

void MyCoin::changeFlag(){
    if(this->flag){
        timer1->start(30);
        isAction=true;
        this->flag=false;
    }else{
        timer2->start(30);
        isAction=true;
        this->flag=true;
    }
}

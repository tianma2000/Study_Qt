#include "mypushbutton.h"
#include <QDebug>
#include <QPropertyAnimation>
//MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
//{

//}
//实现和声明中只需要有一个默认参数   收获一
//设置QPushbutton无边框 setStyleSheet("QPushButton{border:none}")  收获二
MyPushButton::MyPushButton(QString normalImg,QString pressImg){
    this->normalImg=normalImg;
    this->pressImg=pressImg;
    QPixmap pix;
    bool ret=pix.load(normalImg);
    if(!ret){
        qDebug()<<"图片加载失败";
    }
    //设置图片固定大小
    this->setFixedSize(pix.width(),pix.height());

    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:none}");

    //设置图标
    this->setIcon(pix);
    //设置图标大小
    this->setIconSize(QSize(pix.width(),pix.height()));
}

void MyPushButton::zoom1(){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //设置起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //设置结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    //设置运动曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    animation->start();
}
void MyPushButton::zoom2(){
    QPropertyAnimation *animation=new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(200);
    //设置起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //设置结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //设置运动曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e){
    if(this->pressImg!=""){// 传入的按下图片不为空，说明需要有按下状态，切换成释放图片
        QPixmap pix;
        bool ret=pix.load(this->pressImg);
        if(!ret){
            qDebug()<<"图片加载失败";
        }
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());

        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:none}");

        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    //只做了其中的一些拦截，其他的交给父类处理
    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e){
    if(this->pressImg!=""){// 传入的按下图片不为空，说明需要有按下状态，切换成初试图片
        QPixmap pix;
        bool ret=pix.load(this->normalImg);
        if(!ret){
            qDebug()<<"图片加载失败";
        }
        //设置图片固定大小
        this->setFixedSize(pix.width(),pix.height());

        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:none}");

        //设置图标
        this->setIcon(pix);
        //设置图标大小
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    //只做了其中的一些拦截，其他的交给父类处理
    return QPushButton::mouseReleaseEvent(e);
}

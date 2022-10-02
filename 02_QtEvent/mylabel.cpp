#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>


myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    //设置鼠标的追踪状态
    setMouseTracking(true);

}

//鼠标进入事件
void myLabel::enterEvent(QEvent *event){
    //qDebug()<<"鼠标进入";
}
//鼠标退出事件
void myLabel::leaveEvent(QEvent *event){
    //qDebug()<<"鼠标退出";
}

//鼠标移动
void myLabel::mouseMoveEvent(QMouseEvent *ev) {

//    if(ev->buttons()&Qt::LeftButton){
        //qDebug()<<"鼠标移动";
        QString str=QString("1鼠标在x=%1,y=%2").arg(ev->globalX()).arg(ev->globalY());
        qDebug()<<str;
//    }
}
//鼠标按下
void myLabel::mousePressEvent(QMouseEvent *ev) {

//    qDebug()<<"x="<<ev->x();
//    qDebug()<<"y="<<ev->y();
//    if(ev->button()==Qt::LeftButton){
        //qDebug()<<"鼠标按下";
        QString str=QString("2鼠标在x=%1,y=%2").arg(ev->globalX()).arg(ev->globalY());
        qDebug()<<str;
//    }
}
//鼠标释放
void myLabel::mouseReleaseEvent(QMouseEvent *ev){
//    if(ev->button()==Qt::LeftButton){
    qDebug()<<"鼠标释放";
//    }
}

bool myLabel::event(QEvent *e){
    if(e->type()==QEvent::MouseButtonPress){
        //QMouseEvent *ev=(QMouseEvent *)e;
        //静态类型转换
        QMouseEvent *ev=static_cast<QMouseEvent *>(e);
        QString str=QString("event鼠标在x=%1,y=%2").arg(ev->globalX()).arg(ev->globalY());
        qDebug()<<str;
        return true;
    }
    //其他事件交给父类处理，也就是默认处理
    return QLabel::event(e);
}

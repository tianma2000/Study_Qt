#include "mypushbutton.h"
#include <QDebug>

MypushButton::MypushButton(QWidget *parent) : QPushButton(parent)
{
    qDebug()<<"我的按钮类构造";
}
MypushButton::~MypushButton(){
    qDebug()<<"我的按钮类析构";
}

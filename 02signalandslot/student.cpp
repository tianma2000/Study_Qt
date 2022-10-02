#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}
void Student::treat(){
    qDebug()<<"请老师吃饭";
}

void Student::treat(QString foodName1){
    //QString ->char *  先转成 QByteArray 再转成char *
    qDebug()<<"请老师吃饭:"<<foodName1.toUtf8().data();
}

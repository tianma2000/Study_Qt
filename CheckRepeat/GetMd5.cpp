#include "GetMd5.h"
#include <QFile>
#include <QCryptographicHash>
#include <QApplication>
#include <QDir>
#include <QDebug>
GetMd5::GetMd5(QObject *parent) : QObject(parent)
{

}

void GetMd5::checkDum(const QString &path)
{
    //写代码检测文件重复
    QHash<QByteArray,QStringList> ret;
    QStringList strList=getFiles(path);
    for(int i=0;i<strList.count();i++){
        QString filename=strList.at(i);
        QByteArray md5=getMd5(filename);
        ret[md5].append(filename);
        emit giveInt(i+1,strList.count());
    }

    emit giveMd5(ret);
}

QByteArray GetMd5::getMd5(const QString &filename)
{
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly)){
        //qDebug()<<"读取成功";
        QCryptographicHash hash(QCryptographicHash::Md5);//看看构造函数需要什么
        //QT是基于事件循环的
        while (!file.atEnd()) {
            QByteArray arry=file.read(100*1024*1024);
            hash.addData(arry);
            qApp->processEvents();//让他执行事件
        }
        QByteArray md5=hash.result();
        return md5.toHex();
    }else{
        return QByteArray();
    }
}

QStringList GetMd5::getFiles(const QString &path)
{
    QStringList ret;
    QDir dir(path);

    QFileInfoList infolist=dir.entryInfoList(QDir::Files|QDir::Dirs|QDir::NoDotAndDotDot);//把除了.和 ..的文件和目录读进去
    for(int i=0;i<infolist.count();i++){
        //要用QFileInfo来接住QFileInfoList的值
        QFileInfo info=infolist.at(i);
        if(info.isDir()){
             QString subDir=info.absoluteFilePath();
             QStringList files=getFiles(subDir);
             ret.append(files);
        }else{
            QString fileName=info.absoluteFilePath();
            ret.append(fileName);
        }
    }
    return ret;
}

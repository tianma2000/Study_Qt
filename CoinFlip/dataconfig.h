#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QObject>
#include <QMap>
#include <QVector>
class DataConfig : public QObject
{
    Q_OBJECT
public:
    explicit DataConfig(QObject *parent = nullptr);
    //存每一关的初始数据
    QMap<int,QVector<QVector<int>>> mData;

signals:

};

#endif // DATACONFIG_H

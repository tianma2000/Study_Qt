#ifndef GETMD5_H
#define GETMD5_H

#include <QObject>
#include <QHash>

class GetMd5 : public QObject
{
    Q_OBJECT
public:
    explicit GetMd5(QObject *parent = nullptr);
    //槽函数        需要传一个路径进去
    void checkDum(const QString &path);

signals:
    //利用信号来传递信息
    void giveMd5(const QHash<QByteArray,QStringList> &dumplates);
    void giveInt(int crruent,int total);
private:
    QByteArray getMd5(const QString &filename);
    QStringList getFiles(const QString &path);

};

#endif // GETMD5_H

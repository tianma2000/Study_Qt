#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPoint>
#include <QHash>
#include <GetMd5.h>
#include <QThread>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //鼠标点击事件
    void mousePressEvent(QMouseEvent *event);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);
    //鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *event);
    QPoint z;
signals:
    void chechDem(const QString &path);

private slots:
    void on_exitBtn_clicked();

    void on_maxBtn_clicked();

    void on_mixBtn_clicked();

    void on_pushButton_clicked();

    void on_btnGetFile_clicked();
    void ongiveMd5(const QHash<QByteArray,QStringList> &dumplates);
    void on_progressBar_valueChanged(int value);

    void getValue(int crruent,int total);

    void on_listWidgetMd5_currentTextChanged(const QString &currentText);

private:
    Ui::Widget *ui;
    QHash<QByteArray,QStringList> fileMd5;
    GetMd5 md5;
    QThread thread;
    QHash<QByteArray, QStringList> dumplates;
};
#endif // WIDGET_H

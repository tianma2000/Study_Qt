#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

class myWidget : public QWidget
{
    Q_OBJECT//宏，允许类中使用信号和槽的机制

public:
    myWidget(QWidget *parent = nullptr);//QWidget *parent = nullptr默认值
    ~myWidget();
};
#endif // MYWIDGET_H

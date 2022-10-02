#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);
    //鼠标进入事件
    void enterEvent(QEvent *event);
    //鼠标退出事件
    void leaveEvent(QEvent *event);
    //鼠标移动
    void mouseMoveEvent(QMouseEvent *ev) ;
    //鼠标按下
    void mousePressEvent(QMouseEvent *ev) ;
    //鼠标释放
    void mouseReleaseEvent(QMouseEvent *ev);
    //通过事件分发器，拦截鼠标按下操作】
    bool event(QEvent *e);
signals:

};

#endif // MYLABEL_H

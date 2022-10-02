#ifndef MYCOIN_H
#define MYCOIN_H
#include <QTimer>

#include <QWidget>
#include <QPushButton>
class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyCoin(QWidget *parent = nullptr);
    MyCoin(QString btnImg);
    int posX;
    int posY;
    bool flag;
    void changeFlag();
    QTimer *timer1;
    QTimer *timer2;
    //定义图片的最大最小值，便于转换
    int min=1;
    int max=8;
    bool isAction=false;
    void mousePressEvent(QMouseEvent *e);
    //游戏完成之后禁止按金币的方法
    //1.每个金币设置一个标签
    //bool isWin=false;

    //2.静态成员变量
    //static bool isWin;
signals:

};
//bool MyCoin::isWin=false;
#endif // MYCOIN_H

#ifndef PLAYSCENE_H
#define PLAYSCENE_H
#include "mycoin.h"
#include <QMainWindow>
//收获七 信号可以同名
#include <QLabel>
#include <QTime>
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    PlayScene(int number);
    int sceneLevel;
    //重写画家事件
    void paintEvent(QPaintEvent *event);
    int gamearry[4][4];
    MyCoin* btnCoin[4][4];
    bool isWin;
    QLabel *showTime=NULL;
    QTime time;
    void update();
signals:
    void chooseSceneBack();
};

#endif // PLAYSCENE_H

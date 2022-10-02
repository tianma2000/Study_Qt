#include "mywidget.h"

#include <QApplication>  //包含一个应用程序类的头文件

//argc命令行变量的数量，argv命令行变量的数组
int main(int argc, char *argv[])
{
    //a应用程序对象，在Qt中，有且只有一个
    QApplication a(argc, argv);
    //窗口对象 myWinget父类 Qwidget
    myWidget w;
    w.show();
    //让程序对象进入消息循环
    //让代码阻塞到这
    return a.exec();
}

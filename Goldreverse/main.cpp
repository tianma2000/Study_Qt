#include "mainscenario.h"
#include <QApplication>
#include <QSound>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mainscenario w;
    w.show();



    return a.exec();
}

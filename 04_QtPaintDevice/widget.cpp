#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QPicture>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
/*    //Pixmap绘图设备   专门为了平台做了显示优化

    QPixmap pix(300,300);
    //填充颜色
    pix.fill(Qt::white);
    //声明画家
    QPainter painter(&pix);
    QPen pen;
    pen.setColor(QColor(0,0,255));
    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawEllipse(QPoint(150,150),100,100);
    //保存
    pix.save("F:/pix.png")*/;

    //QImage 绘图设备  可以对像素进行访问
//    QImage img(300,300,QImage::Format_RGB32);
//    img.fill(Qt::white);
//    QPainter painter(&img);
//    painter.setPen(QPen(QColor(Qt::green)));
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.drawEllipse(QPoint(150,150),100,100);
//    img.save("F:/img.png");

//     QPainter painter(this);
//     QImage img;
//     img.load(":/image/1.jpg");
//     for(int i=50;i<100;i++){
//         for(int j=50;j<100;j++){
//             QRgb value=qRgb(0,0,255);
//             img.setPixel(i,j,value);
//         }
//     }
//     painter.drawImage(0,0,img);

    //利用QPicture 绘图设备，  可以记录和重新绘图指令
       QPicture pic;
       QPainter painter;
       painter.begin(&pic);
       painter.setPen(Qt::cyan);
       painter.drawEllipse(QPoint(150,150),100,100);
       painter.end();

       //保存到磁盘
       pic.save("F:/pic.zy");


}

void Widget::paintEvent(QPaintEvent *event){
//    QPainter painter(this);
//    //利用QImage对像素点修改
//    QImage img;
//    img.load(":/image/1.jpg");
//    for(int i=50;i<100;i++){
//        for(int j=50;j<100;j++){
//            QRgb value=qRgb(0,0,255);
//            img.setPixel(i,j,value);
//        }
//    }
//    painter.drawImage(0,0,img);

    //重现QPicture的绘图指令
    QPicture pic;
    QPainter painter(this);
    pic.load("F:/pic.zy");
    painter.drawPicture(0,0,pic);
}

Widget::~Widget()
{
    delete ui;
}


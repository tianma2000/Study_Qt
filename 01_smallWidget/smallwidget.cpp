#include "smallwidget.h"
#include "ui_smallwidget.h"

SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);
    //QSpinbox变动 QSlide变动
    void(QSpinBox:: *spSignal)(int)=&QSpinBox::valueChanged;
    connect(ui->spinBox,spSignal,ui->horizontalSlider,&QSlider::setValue);

    //QSlide变动   Qspinbox变动
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);

}

SmallWidget::~SmallWidget()
{
    delete ui;
}

int  SmallWidget::getnum(){
    return ui->spinBox->value();
}
void SmallWidget::setnum(int num){
    ui->spinBox->setValue(num);
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QMenuBar>
#include <QDebug>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(600,400);
    //菜单栏创建      菜单栏最多只有一个
    QMenuBar *bar=menuBar();
    //将栏 放入窗口中
    setMenuBar(bar);//空栏不显示
    //创建菜单
    QMenu *fileMenu=bar->addMenu("文件");
    QMenu *deitMenu=bar->addMenu("编辑");

    //创建菜单项目
    QAction * newFile=fileMenu->addAction("新建");
    fileMenu->addSeparator();//设置分割线
    QAction * open=fileMenu->addAction("打开");

    //工具栏    可以有多个
    QToolBar *toolBar=new QToolBar(this);//需要包含头文件
    //工具栏放到窗口中
    addToolBar(Qt::LeftToolBarArea,toolBar);//可以设置初试停靠位置

    //设置工具栏只允许左右停靠
    toolBar->setAllowedAreas(Qt::LeftToolBarArea);
    //设置浮动
    toolBar->setFloatable(false);
    //设置移动
    toolBar->setMovable(false);

    //工具栏中设置内容
    toolBar->addAction(newFile);
    //添加分割线
    toolBar->addSeparator();
    toolBar->addAction(open);
    toolBar->addSeparator();
    //工具栏中添加控件
    QPushButton *btn=new QPushButton("aa",this);
    toolBar->addWidget(btn);

    //状态栏，最多一个
    QStatusBar *stBar=statusBar();
    setStatusBar(stBar);

    //放标签控件
    QLabel *label=new QLabel("提示信息",this);
    stBar->addWidget(label);
    //标签控件放在右边
    QLabel *label2=new QLabel("右边提示信息",this);
    stBar->addPermanentWidget(label2);

    //铆接部件，也加浮动窗口，可以有多个
    QDockWidget *dockWidget=new QDockWidget("浮动窗口",this);
    addDockWidget(Qt::TopDockWidgetArea,dockWidget);
    //后期设置只允许停靠的位置
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);

    //设置中心部件  只能有一个
    QTextEdit *edit=new QTextEdit(this);
    setCentralWidget(edit);
 }

MainWindow::~MainWindow()
{
    delete ui;
}


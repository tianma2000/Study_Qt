### 什么是QT
* QT是一个跨平台的C++图像用户界面应用程序框架
* QT在1991年由奇趣科技开发
* QT的优点
    + 跨平台,几乎支持所有平台
    + 接口简单，容易上手
    + 一定程度上简化了内存回收机制
    + 有很好的社区氛围
    + 可以进行嵌入式开发

# QWidget
### QT注意事项
* 命名规范
    + 类名 首字母大写，单词和单词之间首字母大写
    + 函数名 变量名称 首字母小写,单词和单词之间首字母大写

* 快捷键
    + 注释 ctrl + /
    + 运行 ctrl + r
    + 编译 ctrl + b
    + 查找 ctrl + f
    + 帮助文档 F1
    + 自动对齐 ctrl + i
    + 同名的.h和.cpp切换 F4

### 按钮
* 按钮常用API
1. show() 以顶层方式弹出窗口控件
2. setParent() 选择依赖方式
3. setText() 设置文本
3. resize() 重置窗口大小
4. move() 移动
5. setWindowTitle() 设置窗口大小
6. setFixedSize() 设置固定窗口大小

### QT中的对象树
1. 当创建的对象在堆区的时候,如果指定的付钱是QObject 派生下来的类或者子类
2. 派生下来的类,可以不需要管理释放操作,会将对象放入对象树
一定程度上简化了内存回收机制

### QT的窗口坐标系
1. 笛卡尔坐标系[左上角为0,0点]

### QT信号和槽
* connect( 信号的发送者 ,信号的具体信息, 信号的接受者,信号的处理[槽])
* 信号槽的优点 松散耦合
    + 信号发送端 和 接收端本身是没有关联的,通过connectl连接,将两者耦合在一起
    + 信号关键字：Signals
        * chlicked(bool) 点击
        * pressed() 按下
        * released() 释放
        * toggled(bool) 切换状态
    + 槽的关键字：Slots
* 自定义信号和槽位函数
    + 自定义信号
        * 写在类的signals下,返回值为void,可以有参数,支持重载,不需要实现
    + 自定义槽函数
        * 不能写在signals下,public slots[公共的槽函数] 5.4版本以后全局函数或者public都行
        * 返回值也是void,需要声明,也需要实现,可以有参数,支持重载
    + 然后用connect连接信号和槽
    + 触发信号 emit
    + 信号和槽重载，需要函数指针，明确指向函数的地址
    + QString 转char * 使用.toUtf8().data()
    + 信号和槽连接：触发这个信号才能触发槽
        * 一个信号可以连接多个槽
        * 多个信号也可以连接同一个槽函数
        * 信号和槽的参数和类型必须对应
        * 信号的参数个数可以多于槽的参数个数
    + 信号和信号连接 触发一个信号也能触发另外一个信号
    + 断开信号 disconnect(参数一样)

### Lambda表达式
* C++11版本特性 [CONFIG += c++11] 匿名函数对象
    * Lambda表达式函数声明 [](){}
        + [=] 允许使用局部变量
        + [&] 允许使用引用传递变量
        + [变量] 允许变量使用值传递
        + mutable 可修改值传递进来的参数[虽然还是局部变量]
            + [m]()mutable{m+=100;打印}; 不加mutable会报错
        + ->类型 带返回值
            + int ret = []()->int{return 1000}();
    * Lambda表达式函数调用 [](){}()
    * 最常见的[=](){}

# MainWindow
### 菜单栏 QMenuBar
    * 菜单栏最多只能有一个
        + QMenuBar * bar = menuBar(); setMenuBar(bar);
        + 创建菜单
            * QMenu * fileMenu = bar->addMenu("文件");
                + 创建菜单栏目
                    * QAction * newAction =  fileMenu->addAction("新建");
                + 添加分隔符 
                    * fileMenu->addSeparator();

### 工具栏 QToolBar
    * 工具栏可以有多个
        + QToolBar * toolBar = new QToolBar(this);  
        + addToolBar(toolBar);
            * 可选参数 默认停靠范围
                + addToolBar(Qt::BottomToolBarArea,toolBar);
            * 只允许左右停靠
                + toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
            * 取消浮动
                + toolBar->setFloatable(false);
            * 设置禁止移动
                + toolBar->setMovable(false);
            * 给工具栏设置栏目
                + toolBar->addAction("绝了"或者QAction);
            * 给工具栏添加控件
                + toolBar->addWidget(QPushButton按钮);

### 状态栏 QStatusBar
    * 状态栏最多只能有一个
        + QStatusBar * stBar = statusBar();
        + setStatusBar(stBar);
            * 添加标签控件
                + QLabel * label = new QLabel("左侧提示的信息",this);
                + QLabel * label1 = new QLabel("右侧提示的信息",this);
                + stBar->addWidget(label);
                + stBar->addPermanentWidget(label1);

### 铆接部件 QDockWidget
    * 铆接部件可以有多个
        + QDockWidget * dockWidget = new QDockWidget("浮动",this);
        + addDockWidget(Qt::BottomDockWidgetArea,dockWidget); 放置位置下面 如果没有中心部件默认占满
            + 只允许上下
                    * dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);  

### 中心部件
    * 中心内容也只能有一个
        + 文本窗口 QTextEdit
            + QTextEdit * edit = new QTextEdit(this);
            + setCentralWidget(edit); //设置中心部件

### 小总结
    + 只能有一个的是set 可以允许多个是add
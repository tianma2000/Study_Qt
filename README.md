# 1 QT概述

## 1.1 什么是QT

+ Qt是一个跨品台的图形用户界面应用程序框架

## 1.2 创建第一个Qt

默认创建窗口类，myWidget，基类有三种：QWidget，QMainWindow，QDialog

<img src="C:\Users\zhang\AppData\Roaming\Typora\typora-user-images\1662345658259.png" alt="1662345658259" style="zoom: 80%;" />

## 1.2 按钮控件常用API

+ 需要包含头文件`#include "QPushButton"`

+ 创建`QPushButton *btn=new QPushButton`重载版本`QPushButton *btn2=new QPushButton("第二个按钮",this)`

+ 设置父亲     setParent(this)
+ 设置文本    setText("文本")
+ 移动          move(weight,hight)
+ 重新制定窗口大小     resize(weight,hight)
+ 设置窗口标题           setWIndowTitle("name")
+ 设置窗口固定大小    setFixSize(weight,hight)

## 1.3 对象树

+ 当创建的对象在堆区，如果指定的父亲是QObject派生下来的类或者QObject子类派生下来的类，可以不用管理释放的操作，将对象放入对象树中，一定程度上简化了内存回收机制。

## 1.4信号（signal）和槽（slot）

+ 通过connect链接

+ ```c++
  //参数1 信号的发送者 参数2 发送的信号signal(函数的地址) 参数3 信号的接受者  参数4 处理的槽函数
  connect(btn3,&QPushButton::clicked,this,&QPushButton::close);
  ```

+ 特点：松散耦合

## 1.5 自定义信号和槽      （触发）

+ 1.自定义槽：

  ```
  //返回值 void，需要声明，也需要实现
  //可以有参数，可以发生重载
  ```

+ 2.自定义信号：

  ```
  //自定义信号 写到signal下
  //返回值是void ，只需要声明，不需要实现
  //可以有参数，可以重载
  ```

+ 3.触发自定义的信号

  `emit 自定义信号`

## 1.6 自定义的信号和槽的重载的解决

+ 补充知识：函数指针`https://blog.csdn.net/qq_41505736/article/details/107877425`

+ 补充知识：Qt信号和槽函数之间的参数传递`https://blog.csdn.net/DAO_HUNG/article/details/122918361`

   **信号函数发出信号后，会将自己接收到的所有参数按照接收到类型、顺序、全部传递给槽函数**，所以我们在定义槽函数的时候是可以去接收信号函数传过来的参数的——槽函数的参数数量可以小于等于信号函数参数，但是剩下的参数应该跟信号函数的参数在类型和顺序上相对应 

+ 需要利用函数指针明确的指向函数的地址

+ ```
  void(Teacher::* teachersignal)(QString)=&Teacher::hugrry;
  void(Student::* studentslot)(QString)=&Student::treat;
  ```

+ Qstring转成char *      

  + .ToUtf8()转为QByteArry
  + .Data()转为Char *

+ 信号链接信号

+ 断开信号    disconnect

+ ```
  //拓展
  //1.信号可以链接信号
  //2.一个信号可以链接多个槽函数
  //3.多个信号可以链接一个槽函数
  //4.信号和槽函数的参数 必须类型一一对应
  //5.信号和槽的参数个数  信号的个数>=槽，，但剩下的个数必须一一对应
  ```

## 1.7 Lambda表达式

+ `[]`标识符
+ `[=]`值传递，`[&]`引用传递
+ `()`参数
+ `{}`实体
+ mutable 修饰，值传递变量，可以修改拷贝的数据，改变不了本体
+ 返回值`[]()->int{}`

## 1.8 QMainWindow

+ 菜单栏 最多一个

  + QMenuBar *bar=MenuBar();
  + setMenuBar(bar);
  + 创建菜单  QMenu *fileMenu=bar->addMenu("文件");
  + 创建菜单项 QAction *newAction=fileMenu->addAction(新建);
  + fileMenu->addSeparator();//设置分割线

+ 工具栏可以有多个

  + QToolBar *toolbar=new QToolBar(this);
  + addToolBar(默认停靠区域,toolBar);
  + 设置 后期停靠区域，设置浮动  设置移动
  + 添加菜单项，添加按钮

+ 状态栏   最多一个

  + ```c++
    //状态栏，最多一个
        QStatusBar *stBar=statusBar();
        setStatusBar(stBar);
        //放标签控件
        QLabel *label=new QLabel("提示信息",this);
        stBar->addWidget(label);
        //标签控件放在右边
        QLabel *label2=new QLabel("右边提示信息",this);
        stBar->addPermanentWidget(label2);
    ```

+ 铆接部件 可以多个

  + ```c++
    //铆接部件，也加浮动窗口，可以有多个
    QDockWidget *dockWidget=new QDockWidget("浮动窗口",this);
    addDockWidget(Qt::TopDockWidgetArea,dockWidget);
    //后期设置只允许停靠的位置
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea|Qt::BottomDockWidgetArea);
    ```

+ 中心部件 只有一个

  + ```c++
    //设置中心部件  只能有一个
        QTextEdit *edit=new QTextEdit(this);
        setCentralWidget(edit);
    ```

## 1.9 资源文件

+ 将图片文件拷贝到项目位置下
+ 添加新文件  Qt recourse file   -》给资源文件起名
+ res 生成 res.qrc
+ 先添加前缀，再添加后缀
+ 使用      ":+前缀名+文件名"

## 1.10 对话框

+ 模态对话框（带有阻塞功能）
+ 非模态对话框

### 1.10.1 标准对话框

+ QMessageBox 静态成员函数 创建对话框

+ 错误，信息，提问，警告

+ ```
  参数1 父亲  参数2 标题 参数3 输出文本  参数4 案件类型  参数5 回车键对应默认按钮
  ```

### 1.10.2 其他标准对话框

+ 颜色对话框   QColorDialog::getColor
+ 文件对话框  QFileDialog::getOpenFileName 参数1 父亲  参数2 标题 参数3 默认打开路径 参数4 过滤文件形式
+ 字体对话框 QFontDialog::getFont

# 2 界面的布局

+ 实现登录窗口
+ 利用布局方式，给窗口进行美化
+ 选取widget  ，进行布局，  ==水平布局、垂直布局、栅格布局==

# 3 控件

## 3.1 按钮组

+ QPushButton 常用工具
+ QToolButton 工具按钮，用于显示图片，如果想显示文字，修改风格，toolButtonStyle，凸起风格autoRaise
+ radioButton   单选按钮，设置默认  ui->rBtnMan->setChecked(true);
+ CheckBox 多选按钮，监听状态， 2  选中，1半选，0 未选中

## 3.2 QListWidget 列表容器

+ QListWIDgetItem  *item 一行内容

+ ```
  ui->listWidget->addItem(item)
  ```

+ 设置居中item->setTextAlignment(Qt::AlignHCenter)
+ 可以利用addItems一次性添加整个诗内容

## 3.3 QTreeWidget 树控件

+ 设置头   ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");
+ 创建根节点QTreeWidgetItem *item= new QTreeWidgetItem(QStringList()<<"力量")
+ 增加根节点  ui->treeWidget->addTopLevelItem(item);
+ 增加子节点  item->addChild(H1);

## 3.4 QTableWidget 表格控件

+ 设置列数    ui->tableWidget->setColumnCount(3)
+ 设置水平表头  ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄")
+ 设置行数     ui->tableWidget->setRowCount(5);
+ 设置正文     ui->tableWidget->setItem(0,0,new QTableWidgetItem("亚瑟"))

## 3.5 其他控件的介绍

+ stackWIdget  栈控件

  + ```
    ui->stackedWidget->setCurrentIndex(1);
    ```

+ comboBox 下拉框

  + ```
    ui->comboBox->addItem("奔驰1")
    ```

+ QLable 显示图片

  + ```
    ui->label->setPixmap(QPixmap(":/new/prefix1/image/1.jpg"))
    ```

+ QLabel 显示动图gif

  + ```c++
    ui->lbl_move->setMovie(movie);
    movie->start();
    ```

## 3.6 自定义控件封装

+ 添加新文件 Qt设计师界面类 （.h  .cpp .ui）
+ .ui中设计 QSpinBox和QSlider两个控件进行组合
+ Widget中如何使用，拖拽一个Widget，电极提升为，点击添加，点击提升
+ 提供getNum和setNum对外接口

# 4Qt中的事件

## 4.1 鼠标事件

+ 鼠标进入事件   enterEvent
+ 鼠标离开事件  leaveEvent
+ 鼠标按下       mousePressEvent(QMouseEvent ev)
+ 鼠标释放       mouseReleaseEvent
+ 鼠标移动       mouseMoveEvent
+ ev->x(),ev->y(),
+ ev->button()，可以判断所有案件Qt::LeftButton,Qt::RightButton
+ ev->buttons()，判断组合按键，判断move时候的左右键  结合&操作符
+ 格式化字符串 QString(%1,%2).arg(1).arg(2);

## 4.1 定时器事件

+ 利用事件 void timerEvent(QTimerEvent *ev)
+ 启动定时器 startTimer(1000)  ==单位毫秒==
+ startTimer 返回唯一的标识符 可以和ev->timerId()来作比较

## 4.2 利用定时器类

+ 利用定时器类QTimer（包含头文件QTimer）
+ 创建定时器对象 QTimer *timer=new QTimer(this);
+ 定时器启动  timer->statrt(500); ==单位毫秒==
+ connect(btn,&QPushButton,[=]\()(label->setText(QString::number(num))));
+ 暂停 timer->stop();

## 4.3 event事件

+ QEvent
+ 通途：用于事件的分发
+ 也可以做拦截操作（不建议）
+ bool event(QEvent *ev);
+ 返回值，如果是true，代表用户会处理这个事，不再向下分发
+ ev->type==QEvent::MouseButtonPress鼠标按下

![1663339250758](C:\Users\zhang\AppData\Roaming\Typora\typora-user-images\1663339250758.png)

## 4.4 事件过滤器

+ 在程序将事件分发到事件分发器之前，可以利用过滤器做拦截
+ 1.给空间安装事件过滤器
+ 2.重写eventfilter（obj，ev）一个判断控件，一个判断具体的事件

## 4.5 Qpainter绘图事件

+ 绘图事件 void painterEvent（）
+ 声明一个画家对象  QPainter painter（this）this指定绘图设备
+ 画线，画圆，画矩形，画文字
+ 设置画笔 QPen，设置画笔宽度，风格
+ 设置刷子QBrush  ，设置风格

==高级设置==：1.抗锯齿，效率低 2.移动画家（painter.translate（100,20））3.保存状态 4.还原状态

5.利用画家画图片 painter.drawPixmap（x，y，QPixmap（地址））

6.如果想手动调整事件，利用==update==

## 4.6 绘图设备QPainterDevice

==QPixmap  QImage  QBitmap(黑白色)  QPicture  QWidget==

### 4.6.1 QPixmap 对平台做了显示优化

+ QPixmap pix(300,300);
+ pix.fill(填充颜色)
+ 利用画在往pix上画画   QPainter painter(&pix)
+ 保存   pix.save(”路径“)

### 4.6.2 QImage 可以对像素进行访问

+ 使用和QPixmap差不多   QImage image(300,300,==QImage;:Fprmat_RGB32==)
+ 使用流程和QPixmap一样
+ 可以对像素进行修改   img.setPixel(i,j,value)   其中QRGB value=qRGB（0，0,0）

### 4.6.3 QPicture  记录和重现 绘图指令

+ QPicture pic
+ painter.begin(&pic);
+ 保存  pic.save(任意后缀名)
+ 重现   利用画家可以重现  painter.drawPicture(0,0,pic);

# 5.QFile对文件的读写操作

> （C:\Users\zhang\Documents\QT\05_Qt_File）

+ QFile file(Path  文件路径)

+ file.open(打开方式)

+ file.readAll()    file.readLine()      file.atEnd()判断是否读完

+ ```C++
  //改变编码格式
  //QTextCodec *codec=QTextCodec::codecForName("gbk");
  //ui->textEdit->setText(codec->toUnicode(arry));//利用code的方法，将arry转码。
  ```

# 6.QFileinfo 读取文件信息

+ QFileinfo info (路径)       ==头文件QFIleinfo==
+ info.size()   info.suffix()   info.filename()    info.filepath
+ info.created( )    是QDateTime类型   需要==info.created().toString()转为string==  ==头文件QDateTIme==

# 7.案例翻金币

>收获一：
>
>==实现和声明中只需要一个默认参数==

>收获二：
>
>==设置QPushbutton无边框 setStyleSheet("QPushButton{border:none}")==
>
>QPushbutton可以设置边框的样式

> 收获三:
>
> ==延时进入操作  QTimer::singleShot(500,this,\[=](){}）==
>
> 500是毫秒  后面用Lambda

> 收获四:
>
> 自定义信号和槽，自定义信号的发送 用==emit==

>收获五:
>
> 利用一个for循环，创建一个矩阵，利用%和\

> 收获六:
>
> 如何设置鼠标穿透 ==**setAttribute**==
>
> 比如一个QLabel罩在一个QPushbutton上，要设置穿透才能点到QPushbutton

>收获七: 
>
>设置label的水平居中 setAlignment

> 收获八:
>
> 一个场景里面new下一层场景,一个场景里面监视new出来的场景的返回信号

> 收获九:  
>
> 将字体设置到标签中，==label->setFont(font);==

> 收获十:  
>
> QLabel不指定parent，会显示不出来

>收获十一: 
>
>如果#include没法导入，在pro中加入相应模块,比如QSound，要先加入QT       += core gui ==multimedia==

> 收获十二:  
>
> ==**利用QTimer 和 QTimer实现简单的计时器**==
>
> ```C++
> //1.在.h文件中加入
> #include <QTimer>
> #include <QTime>
> #include <QLabel>
> QTimer *timer=NULL;
> QTime time;
> QLabel *label=NULL;
> //2.在.cpp文件中
> timer=new QTimer(this);
> time=new Qtime();
> label=new QLabel(this);
> time.setHMS(0,0,0,0);//设置初始值 时分秒毫秒
> connect(timer,&QTimer::timeout,this,&你的类名::自定义的update())；
> timer->start(1000);
> //自定义一个槽函数
> void 类::update(){
>     static quint32 time_out=0;
>     time_out++;
>     time=time.addSecs(1);
>     label->setText(time.toString("hh:mm:ss"));
> }
> ```
>
> 


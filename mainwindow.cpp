#include "mainwindow.h"

/*
    构造函数
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    /*参数初始化*/
    this->ParameterInit();
    /*信号与槽函数联系*/
    this->signalsAndSlots();
    /*获取数据库操作符*/
    QSqlDatabase db = QSqlDatabase::database("connect");
    /* 渲染主页面*/
    this->getFunction(db);
}


/*
    初始化参数列表
*/
void MainWindow::ParameterInit()
{
    /*初始化ui对象*/
    ui->setupUi(this);
    /*初始化布局管理器*/
    this->widgetIndex = 1;
    this->firstLineIndex = 0;
    this->secondLineIndex = 0;
    this->layout = new QGridLayout(ui->mainWidget);
    layout->setContentsMargins(100,100,100,100);//设置与四边距的距离
    layout->setSpacing(50);//组件之间的距离
    /*初始化功能界面列表*/
    //    this->function1 = new class function1(this);
    //    this->function2 = new class function2(this);
    //    this->function3 = new class function3(this);
    this->setting = new class Setting(this);
    //    /*隐藏功能界面*/
    //    this->function1->hide();
    //    this->function2->hide();
    //    this->function3->hide();
    this->setting->hide();
    /*初始化数组*/
    this->functionNum = 0;//数组长度,功能窗口数量
    this->functionName = QVector<functionWidget *>();//存放功能窗口对象
}


/*
    建立信号与槽函数的联系
*/
void MainWindow::signalsAndSlots()
{
    /*
        主页面跳转到功能页面
//    */
    //    connect(this,&MainWindow::jumpFunc1,this->function1,&function1::showPage);
    //    connect(this,&MainWindow::jumpFunc2,this->function2,&function2::showPage);
    //    connect(this,&MainWindow::jumpFunc3,this->function3,&function3::showPage);
    connect(this,&MainWindow::jumpSetting,this->setting,&Setting::showSettingPage);
    /*
        功能页面跳转到主页面
    */
    //    connect(function1,&function1::showMainWidget,this,&MainWindow::showMainWidget);
    //    connect(function2,&function2::showMainWidget,this,&MainWindow::showMainWidget);
    //    connect(function3,&function3::showMainWidget,this,&MainWindow::showMainWidget);
    connect(setting,&Setting::settingToMain,this,&MainWindow::showMainWidget);
}


/*
 * 功能:动态从数据库获取用户所需功能。
 * 创建对象然后展示。
*/
void MainWindow::getFunction(QSqlDatabase &db)
{
    //查询数据库中的功能表
    QSqlQuery query(db);
    query.exec("select * from `function`");
    //从数据库读取信息
    while (query.next()) {
        //创建按钮和标签
        createFunctionButton(query.value(0).toString(),query.value(1).toString());
    }
}


/*
    根据数据库中的信息创建对应按钮和标签
*/
void MainWindow::createFunctionButton(QString functionText, QString imagePath)
{
    //    qDebug() << functionText << "   " << imagePath;
    QLabel *label = new QLabel(functionText);  //标签对象
    QFont font("Microsoft YaHei",10,75);
    label->setFont(font);
    label->setAlignment(Qt::AlignCenter);
    QPushButton *button = new QPushButton(); //按钮对象
    button->setStyleSheet("border-image: url("+imagePath+");");
    button->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    label->setSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
    createFunctionWidget(label,button);   //创建窗口对象
}


/*
    创建功能窗口对象
*/
void MainWindow::createFunctionWidget(QLabel *label, QPushButton *button)
{
    /*创建窗口对象*/
    this->functionName.push_back(new functionWidget(button,label,ui->mainWidget));
    this->functionName[this->functionNum]->setStyleSheet("background:transparent;");//子部件取消父部件的背景色
    /*窗口中按钮触发点击信号，窗口对象发送页面跳转信号，主页面捕获信号进行页面跳转处理*/
    connect(functionName[functionNum],&functionWidget::jumpPage,this,[=] (QLabel *label) {
        UI_Jump(label);
    });
    /*设置主页面布局*/
    createFunctoinLayout(this->functionName[functionNum++]);
}


/*
    对功能窗口进行布局
*/
void MainWindow::createFunctoinLayout(functionWidget *function)
{

    if (this->widgetIndex % 2 == 1) {
        this->layout->addWidget(function,0,this->firstLineIndex++,1,1);
    } else {
        this->layout->addWidget(function,4,this->secondLineIndex++,1,1);
    }
    this->widgetIndex++;
    qDebug() << this->firstLineIndex << "  " << this->secondLineIndex << " "  <<layout->columnCount() << layout->rowCount();
}


/*
    页面跳转
*/
void MainWindow::UI_Jump(QLabel *label)
{
    ui->mainWidget->hide();//隐藏主界面
    if (label->text() == "功能1") {
        //页面1->show()
        emit jumpFunc1();
    } else if (label->text() == "功能2") {
        //页面2->show()
        emit jumpFunc2();
    } else if (label->text() == "功能3") {
        //页面3->show()
        emit jumpFunc3();
    } else if (label->text() == "设置") {
        //页面4->show()
        emit jumpSetting();
    } else {
        QMessageBox::critical(0,tr("失败"),tr("此功能暂时未开放!"),QMessageBox::Cancel);
        ui->mainWidget->show();
    }
}


/*
    返回到主界面
*/
void  MainWindow::showMainWidget()
{
    ui->mainWidget->show();
}


/*
    析构函数
*/
MainWindow::~MainWindow()
{
    delete ui;
}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QVBoxLayout>
#include <QFont>
#include <QLabel>
#include <QPushButton>
#include <QStackedWidget>
#include "connect.h"
#include <QGridLayout>
#include "ui_mainwindow.h"
#include "./FunctionWidgetDisplay/functionwidgets.h"
#include "./FunctionDisplayParts/setting/setting.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void jumpFunc1();
    void jumpFunc2();
    void jumpFunc3();
    void jumpSetting();

private:
    Ui::MainWindow *ui;
    Setting *setting;//设置页面
    QGridLayout *layout;//主页面布局
    int widgetIndex = 0; //窗口序号
    int firstLineIndex = 0; //第一行序号
    int secondLineIndex = 0; //第二行序号
    int functionNum; //功能窗口总数
    QVector<functionWidget *> functionName;//功能按钮对象名数组
    void UI_Jump(QLabel *label); //捕捉功能窗口发出的页面跳转信号，进行页面跳转
    void getFunction(QSqlDatabase &db);//从数据库获取功能列表
    void createFunctionButton(QString functionText,QString imagePath);//从根据数据库中的信息创建相应的按钮和标签
    void createFunctionWidget(QLabel *label,QPushButton *button);//根据创建的按钮构建对应的功能窗口
    void createFunctoinLayout(functionWidget *function);//对创建的窗口对象设置布局
    void showMainWidget();//返回到主界面
    void signalsAndSlots();//信号与槽
    void ParameterInit();//参数初始化
};
#endif // MAINWINDOW_H

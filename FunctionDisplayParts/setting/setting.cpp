#include "setting.h"
#include "ui_setting.h"

Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
}


void Setting::showSettingPage()
{
    qDebug() << "展示设置页面";
    this->show();//展示设置页面
}


Setting::~Setting()
{
    delete ui;
}


void Setting::on_pushButton_clicked()
{
    this->hide();//隐藏设置页面
    emit settingToMain();//发送跳转到主页面的信号
}

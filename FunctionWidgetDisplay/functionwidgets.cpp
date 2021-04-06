#include "functionwidgets.h"
#include "mainwindow.h"
functionWidget::functionWidget(QPushButton * button,QLabel * label,QWidget *parent)
{
    this->button = button;
    this->label = label;
    this->createFunctionLayout();
    //向主界面发送页面跳转信号
    connect(this->button,&QPushButton::clicked,this,[=]() {
        emit jumpPage(this->label);
    });
}

void  functionWidget::createFunctionLayout() {
    //窗口内布局
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(this->button,8);
    layout->addWidget(this->label,1);
    this->setLayout(layout);
}

functionWidget::~functionWidget() {

}

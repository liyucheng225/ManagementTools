#ifndef BASEWIDGET_H
#define BASEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class functionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit functionWidget(QPushButton * button,QLabel * label,QWidget *parent = nullptr);
    QPushButton *button;//按钮
    QLabel *label;//标签
    ~functionWidget();
private:
    void createFunctionLayout();//设置功能窗口内按钮和标签布局
signals:
    void jumpPage(QLabel *label);//页面跳转信号
};

#endif // BASEWIDGET_H

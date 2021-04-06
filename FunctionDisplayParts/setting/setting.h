#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include <QDebug>
namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    void showSettingPage(); //捕捉信号展示设置页面
    ~Setting();

signals:
   void settingToMain(); //发送跳转到主界面的信号
private slots:
   void on_pushButton_clicked();
private:
    Ui::Setting *ui;
};

#endif // SETTING_H

#ifndef CONNECT_H
#define CONNECT_H
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
static bool createConnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL","connect");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("990306");
    db.setDatabaseName("myslqpractice");

    if (!db.open()) {
        QMessageBox::critical(0,"faile","failed to connect!",QMessageBox::Cancel);
        return false;
    }
    qDebug() << "数据库链接成功！";
    return true;
}
#endif // CONNECT_H

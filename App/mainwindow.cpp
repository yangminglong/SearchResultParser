#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "httpmanager.h"

#include <QNetworkReply>
#include <QDebug>
#include <functional>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    HttpManager *manager = new HttpManager(this);

    manager->startRequest(QUrl("http://www.baidu.com"), HttpManager::Get, QByteArray(), [=](QByteArray* datas, QNetworkReply* reply){
        if (QNetworkReply::NoError == reply->error()) {
//            int count = datas->count();
            qDebug() << datas->count();
//            qDebug() << u8"已执行回掉函数" << count;
        } else {
            qDebug() << reply->errorString();
        }
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

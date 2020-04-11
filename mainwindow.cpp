#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // connect(谁，发出什么信号，谁，执行什么操作);把发送者和接收者建立联系。
    // disconnect() 断开信号与槽的连接
}

MainWindow::~MainWindow()
{
    delete ui;
}

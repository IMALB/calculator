#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots: // slots是一个空宏，这样写只是为了方便区分槽函数。与界面元素绑定的函数。

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H

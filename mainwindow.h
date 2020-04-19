#ifndef MAINWINDOW_H
#define MAINWINDOW_H // 防止头文件被重复引用

#include <QMainWindow>
#include "model.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

// slots是一个空宏，这样写只是为了方便区分槽函数。与界面元素绑定的函数。
private slots:
    void getBtnNum0();
    void getBtnNum1();
    void getBtnNum2();
    void getBtnNum3();
    void getBtnNum4();
    void getBtnNum5();
    void getBtnNum6();
    void getBtnNum7();
    void getBtnNum8();
    void getBtnNum9();
    void btnC();
    void btnEql();

    void btnPlus();
    void btnDiv();
    void btnSub();
    void btnMul();
    void btnMod();


private:
    // 编译时会自动生成一个ui_mainwindow.h文件，里面声名了Ui_ManWindow类
    // 下面的ManWindow是Ui域里的ManWindow 类
    // Ui域中的MainWindow是完全继承自类Ui_MainWindow
    // ui，他是一个指向Ui域中MainWindow的指针
    Ui::MainWindow *ui;
    model *mod;
    QString tmp, tmp2;
    bool isNum2, isEql;

    bool checkISFlag();

};
#endif // MAINWINDOW_H

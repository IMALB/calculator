#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>


// 这里的两个:: 是域操作符，因为在ManWindow类的声明中，没有给出定义
// 那么在类外定义函数时，类名::F() 表示F()是类的成员函数。
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) ,ui(new Ui::MainWindow)
{
    this->tmp = "";
    this->tmp2 = "";
    this->isNum2 = false;
    this->isEql = false;
    ui->setupUi(this);
    this->mod = new model;
    // connect(谁，发出什么信号，谁，执行什么操作);把发送者和接收者建立联系。
    // disconnect() 断开信号与槽的连接
    connect(this->ui->btn_0, SIGNAL(clicked(bool)), this, SLOT(getBtnNum0()));
    connect(this->ui->btn_1, SIGNAL(clicked(bool)), this, SLOT(getBtnNum1()));
    connect(this->ui->btn_2, SIGNAL(clicked(bool)), this, SLOT(getBtnNum2()));
    connect(this->ui->btn_3, SIGNAL(clicked(bool)), this, SLOT(getBtnNum3()));
    connect(this->ui->btn_4, SIGNAL(clicked(bool)), this, SLOT(getBtnNum4()));
    connect(this->ui->btn_5, SIGNAL(clicked(bool)), this, SLOT(getBtnNum5()));
    connect(this->ui->btn_6, SIGNAL(clicked(bool)), this, SLOT(getBtnNum6()));
    connect(this->ui->btn_7, SIGNAL(clicked(bool)), this, SLOT(getBtnNum7()));
    connect(this->ui->btn_8, SIGNAL(clicked(bool)), this, SLOT(getBtnNum8()));
    connect(this->ui->btn_9, SIGNAL(clicked(bool)), this, SLOT(getBtnNum9()));

    connect(this->ui->btn_clear, SIGNAL(clicked(bool)), this, SLOT(btnC()));
    connect(this->ui->btn_equal, SIGNAL(clicked(bool)), this, SLOT(btnEql()));

    connect(this->ui->btn_plus, SIGNAL(clicked(bool)), this, SLOT(btnPlus()));
    connect(this->ui->btn_sub, SIGNAL(clicked(bool)), this, SLOT(btnSub()));
    connect(this->ui->btn_mul, SIGNAL(clicked(bool)), this, SLOT(btnMul()));
    connect(this->ui->btn_div, SIGNAL(clicked(bool)), this, SLOT(btnDiv()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete mod;
}

bool MainWindow::checkISFlag()
{
    if (isNum2) return false;
    QCharRef t = this->ui->lbl_display->text()[this->ui->lbl_display->text().length()-1];
    //    qDebug() << t;
    if (this->ui->lbl_display->text() == "0")
    {
        return true;
    }
    else if (t=='+' || t=='-' || t=='*' || t=='/' || t=='%')
    {
        // qDebug() << "****";
        return true;
    }

    return false;
}

void MainWindow::btnC()
{
    this->isNum2 = false;
    this->isEql = false;
    this->tmp = "";
    this->tmp2 = "";
    this->mod->clean();
    this->ui->lbl_display->setText("");
}

void MainWindow::btnEql()
{
    if (checkISFlag())
        return ;
    this->mod->setNum2(this->tmp2.toInt());
    this->ui->lbl_display->setText(this->mod->doExpr());
    this->isEql = true;
    //btnC();
}

void MainWindow::btnPlus()
{
    if (checkISFlag()) {
       //qDebug() << this->tmp;
        return ;
    }

    this->mod->setNum1(this->tmp.toUInt());
    this->mod->setFlag(this->ui->btn_plus->text());
    this->tmp += this->ui->btn_plus->text();
    this->ui->lbl_display->setText(this->tmp);
    isNum2 = true;
}
void MainWindow::btnSub()
{
    if (checkISFlag())
        return ;
    this->mod->setNum1(this->tmp.toUInt());
    this->mod->setFlag(this->ui->btn_sub->text());
    this->tmp += this->ui->btn_sub->text();
    this->ui->lbl_display->setText(this->tmp);
    isNum2 = true;
}
void MainWindow::btnMul()
{
    if (checkISFlag())
        return ;
    this->mod->setNum1(this->tmp.toUInt());
    this->mod->setFlag(this->ui->btn_mul->text());
    this->tmp += this->ui->btn_mul->text();
    this->ui->lbl_display->setText(this->tmp);
    isNum2 = true;
}
void MainWindow::btnDiv()
{
    if (checkISFlag())
        return ;
    this->mod->setNum1(this->tmp.toUInt());
    this->mod->setFlag(this->ui->btn_div->text());
    this->tmp += this->ui->btn_div->text();
    this->ui->lbl_display->setText(this->tmp);
    isNum2 = true;
}
void MainWindow::btnMod()
{
    if (checkISFlag())
        return ;
    this->mod->setNum1(this->tmp.toUInt());
    this->mod->setFlag(this->ui->btn_mod->text());
    this->tmp += this->ui->btn_mod->text();
    this->ui->lbl_display->setText(this->tmp);
    isNum2 = true;
}

void MainWindow::getBtnNum0()
{
    if (this->ui->lbl_display->text() == "0")
        return ;

    if (isEql)
    {
        btnC();
        isEql = false;
    }

    if (isNum2)
    {
        this->tmp2 += this->ui->btn_0->text();
        this->ui->lbl_display->setText(this->tmp + this->tmp2);
    }
    else
    {
        this->tmp += this->ui->btn_0->text();
        this->ui->lbl_display->setText(this->tmp);
    }
}
void MainWindow::getBtnNum1()
{
    if (isEql)
    {
        btnC();
        isEql = false;
    }

    if (isNum2)
    {
        this->tmp2 += this->ui->btn_1->text();
        this->ui->lbl_display->setText(this->tmp + this->tmp2);
    }
    else
    {
        this->tmp += this->ui->btn_1->text();
        this->ui->lbl_display->setText(this->tmp);
    }
}
void MainWindow::getBtnNum2()
{
    if (isEql)
    {
        btnC();
        isEql = false;
    }

    if (isNum2)
    {
        this->tmp2 += this->ui->btn_2->text();
        this->ui->lbl_display->setText(this->tmp + this->tmp2);
    }
    else
    {
        this->tmp += this->ui->btn_2->text();
        this->ui->lbl_display->setText(this->tmp);
    }
}
void MainWindow::getBtnNum3()
{
    if (isEql)
    {
        btnC();
        isEql = false;
    }

    if (isNum2)
    {
        this->tmp2 += this->ui->btn_3->text();
        this->ui->lbl_display->setText(this->tmp + this->tmp2);
    }
    else
    {
        this->tmp += this->ui->btn_3->text();
        this->ui->lbl_display->setText(this->tmp);
    }
}
void MainWindow::getBtnNum4()
{
    if (isEql)
    {
        btnC();
        isEql = false;
    }

    if (isNum2)
    {
        this->tmp2 += this->ui->btn_4->text();
        this->ui->lbl_display->setText(this->tmp + this->tmp2);
    }
    else
    {
        this->tmp += this->ui->btn_4->text();
        this->ui->lbl_display->setText(this->tmp);
    }
}
void MainWindow::getBtnNum5()
{
    if (isEql)
    {
        btnC();
        isEql = false;
    }

    if (isNum2)
    {
        this->tmp2 += this->ui->btn_5->text();
        this->ui->lbl_display->setText(this->tmp + this->tmp2);
    }
    else
    {
        this->tmp += this->ui->btn_5->text();
        this->ui->lbl_display->setText(this->tmp);
    }
}
void MainWindow::getBtnNum6()
{
    if (isEql)
    {
        btnC();
        isEql = false;
    }

    if (isNum2)
    {
        this->tmp2 += this->ui->btn_6->text();
        this->ui->lbl_display->setText(this->tmp + this->tmp2);
    }
    else
    {
        this->tmp += this->ui->btn_6->text();
        this->ui->lbl_display->setText(this->tmp);
    }
}
void MainWindow::getBtnNum7()
{
    if (isEql)
    {
        btnC();
        isEql = false;
    }

    if (isNum2)
    {
        this->tmp2 += this->ui->btn_7->text();
        this->ui->lbl_display->setText(this->tmp + this->tmp2);
    }
    else
    {
        this->tmp += this->ui->btn_7->text();
        this->ui->lbl_display->setText(this->tmp);
    }
}
void MainWindow::getBtnNum8()
{
    if (isEql)
    {
        btnC();
        isEql = false;
    }

    if (isNum2)
    {
        this->tmp2 += this->ui->btn_8->text();
        this->ui->lbl_display->setText(this->tmp + this->tmp2);
    }
    else
    {
        this->tmp += this->ui->btn_8->text();
        this->ui->lbl_display->setText(this->tmp);
    }
}
void MainWindow::getBtnNum9()
{
    if (isEql)
    {
        btnC();
        isEql = false;
    }

    if (isNum2)
    {
        this->tmp2 += this->ui->btn_9->text();
        this->ui->lbl_display->setText(this->tmp + this->tmp2);
    }
    else
    {
        this->tmp += this->ui->btn_9->text();
        this->ui->lbl_display->setText(this->tmp);
    }
}

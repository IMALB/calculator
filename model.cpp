#include "model.h"

model::model()
{
    this->num1 = 0;
    this->num2 = 0;
    this->Flag = "";
}

void model::clean()
{
    this->num1 = 0;
    this->num2 = 0;
    this->Flag = "";
}

void model::setNum1(int num)
{
    this->num1 = num;
}

void model::setNum2(int num)
{
    this->num2 = num;
}

void model::setFlag(QString flag)
{
    this->Flag = flag;
}

QString model::doExpr()
{
    // qDebug() << "FLAG:" << Flag ;
    QString res = "";
    if (this->Flag == "+")
    {
        res = QString::number(num1+num2);
    }
    else if (this->Flag == "-")
    {
        res = QString::number(num1-num2);
    }
    else if (this->Flag == "*")
    {
        res = QString::number(num1*num2);
    }
    else if (this->Flag == "/")
    {
        if (num2 == 0)
            res = "Error";
        else
            res = QString::number(num1/num2);
    }
    else if (this->Flag == "%")
    {
        res = QString::number(num1%num2);
    }
    // qDebug() << "RES:" << res ;
    return res;
}

#ifndef MODEL_H
#define MODEL_H
#include <QString>
#include <QDebug>

class model
{
public:
    model();
    void setNum1(int);
    void setNum2(int);
    void setFlag(QString);
    void clean();
    QString doExpr();



private:
    int num1;
    int num2;
    QString Flag;

};

#endif // MODEL_H

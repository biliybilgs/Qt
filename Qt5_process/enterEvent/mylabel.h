#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QLabel>

class Mylabel : public QLabel
{
    Q_OBJECT
public:
    Mylabel(QWidget* parent);  //重写构造函数，是构造对象的时候，

    //这两个函数都是widget中的虚函数
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);  //重写父类的虚函数实现多态，不过要注意函数名字、参数列表完全一致


};

#endif // MYLABEL_H

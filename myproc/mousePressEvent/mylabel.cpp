#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>

mylabel::mylabel(QWidget *parent) :QLabel(parent)
{

}
//重写这个函数，表示当我们在这个控件上按下鼠标的时候，就会触发函数并执行
void mylabel::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "测试" << event->pos();
    //问题:如何我们自己编写的控件放到ui文件中呢？
    /*
     * 先放置一个它的父控件，比如自己写的控件是mylabel，那就在ui文件中放置一个QLabel控件，
     * 然后将该控件进行提升，提升成自定义的控件
     */

}
//在这个控件上鼠标释放的时候，就会触发这个事件
void mylabel::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        qDebug() << "左键释放";
    }
    else if(event->button() == Qt::RightButton)
    {
        qDebug() << "右键释放";
    }

}
//表示双击控件，触发这个控件
void mylabel::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        qDebug() << "双击左键";
    }
    else if(event->button() == Qt::RightButton)
    {
        qDebug() << "双击右键";
    }

}

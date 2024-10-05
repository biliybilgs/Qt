#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //开启定时器事件,表示给timerID这个定时器设置了1000ms的事件
    timerID = this->startTimer(1000);
}

Widget::~Widget()
{
    delete ui;
}
//定时器事件执行函数
void Widget::timerEvent(QTimerEvent *event)
{
    //这个控件中如果存在多个定时器（startTimer创建的定时器），此时每个定时器都会触发这个事件执行函数
    //所以该函数内部就需要对定时器进行判断
    if(event->timerId() == this->timerID)
    {
       int value =  ui->lcdNumber->intValue();
        if(value<=0 ){
            ui->lcdNumber->display(10);
            return;
        }
        else{
            value -=1;
            ui->lcdNumber->display(value);
        }
    }
}

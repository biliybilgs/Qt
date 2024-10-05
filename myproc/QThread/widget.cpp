#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //连接信号与槽函数
    connect(&qthread,&Mythread::notify,this,&Widget::handler);
    qthread.start(); //启动线程
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handler(int x)
{
    if(x)
    {
        QString number = QString::number(x);
        ui->label->setText("标签：" + number);
    }

}




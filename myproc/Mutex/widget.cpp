#include "widget.h"
#include "ui_widget.h"
#include "mythread.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    Mythread th1;
    Mythread th2;
    th1.start();
    th2.start();
    //等待线程执行完毕
    th1.wait();
    th2.wait();
    qDebug() << Mythread::num;
}

Widget::~Widget()
{
    delete ui;
}


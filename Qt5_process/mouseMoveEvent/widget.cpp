#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //打开鼠标移动事件捕获
    this->setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}
//表示鼠标在该窗口移动的时候，就会触发这个事件函数
//如果使用这个事件，每次鼠标移动都会触发该事件，所以默认情况下该事件并不会捕获
//想不捕获该事件，需要使用setMouseTracking函数
void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << event->x() << "," <<event->y();
}


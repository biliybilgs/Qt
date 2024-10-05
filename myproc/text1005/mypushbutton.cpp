#include "mypushbutton.h"
#include<QMouseEvent>

MyPushButton::MyPushButton(QWidget *parent) :QPushButton(parent)
{}

void MyPushButton::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt:: LeftButton)
    {
        qDebug() << "表示鼠标左键被按下";
    }
    else if(event->button() == Qt::RightButton)
    {
        qDebug() <<"表示鼠标右键被按下";
    }
}

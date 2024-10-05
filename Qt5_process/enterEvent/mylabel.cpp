#include "mylabel.h"
#include <QDebug>

Mylabel::Mylabel(QWidget *parent):QLabel(parent)
{

}

void Mylabel::enterEvent(QEvent *event)
{
    (void)event;
    qDebug() << "enterEvent";
}

void Mylabel::leaveEvent(QEvent *event)
{
    (void)event;
    qDebug() << "leaveEvent";
}

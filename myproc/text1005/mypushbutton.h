#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QDebug>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QWidget* parent);

    //重写事件处理函数
    void mousePressEvent(QMouseEvent *event);
};

#endif // MYPUSHBUTTON_H

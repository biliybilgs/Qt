#ifndef MYLABEL_H
#define MYLABEL_H
#include<QLabel>
#include <QWidget>

class mylabel : public QLabel
{
    Q_OBJECT
public:
    //改写构造函数，指定对应的父控件，通过父控件，来控制该控件的生命周期，会在父控件中显示，并且跟随父控件的大小、位置变化。
    mylabel(QWidget* parent);

    //重写按钮按下的事件函数
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent *event);
};

#endif // MYLABEL_H

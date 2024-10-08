#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "thread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void handler(int x);

private:
    Ui::Widget *ui;

    Mythread qthread;
};
#endif // WIDGET_H

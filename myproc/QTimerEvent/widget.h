#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void timerEvent(QTimerEvent *event);
private:
    Ui::Widget *ui;
    int timerID;
    int timerID2;
};
#endif // WIDGET_H

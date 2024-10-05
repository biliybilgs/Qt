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

private slots:
    void on_pushButton_clicked();

    void on_dial_valueChanged(int value);
    void subValue();
    void addValue();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

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
    void on_checkBox_toggled(bool checked);

    void on_checkBox_2_toggled(bool checked);


    void on_lineEdit_2_textEdited(const QString &arg1);


    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

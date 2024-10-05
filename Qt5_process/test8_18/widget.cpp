#include "widget.h"
#include "ui_widget.h"
#include <QLineEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //将widget控件当做qlineedit控件的父控件
    //QLineEdit* edit = new QLineEdit(this);
    //edit->setText("hello world");
}

Widget::~Widget()
{
    delete ui;
}


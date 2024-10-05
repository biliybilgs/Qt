#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include<QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_lineEdit_textEdited(const QString &arg1)
{
    qDebug() << arg1;
}

void Widget::on_textEdit_textChanged()
{
    const QString s1 = ui->textEdit->toPlainText();
}

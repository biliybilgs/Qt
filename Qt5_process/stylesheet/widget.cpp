#include "widget.h"
#include "ui_widget.h"

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


void Widget::on_pushButton_clicked()
{
    //日间模式
    //将窗口设置成白色
    this->setStyleSheet("background-color:rgb(240,240,240);");
    //将文本框设置成白色，文字设置成黑色
    ui->textEdit->setStyleSheet("background-color:white;color:black;");
    ui->pushButton->setStyleSheet("background-color:rgb(253,253,253);color:black;");
    ui->pushButton_2->setStyleSheet("background-color:rgb(253,253,253);color:balck;");
}

void Widget::on_pushButton_2_clicked()
{
    //夜间模式
    //将窗口设置成白色
    this->setStyleSheet("background-color:rgb(31,32,32);");
    //将文本框设置成白色，文字设置成黑色
    ui->textEdit->setStyleSheet("background-color:rgb(64,65,66);color:white;");
    ui->pushButton->setStyleSheet("background-color:rgb(64,65,66);color:white;");
    ui->pushButton_2->setStyleSheet("background-color:rgb(64,65,66);color:white;");
}

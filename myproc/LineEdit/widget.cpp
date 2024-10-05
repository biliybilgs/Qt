#include "widget.h"
#include "ui_widget.h"
#include "QIntValidator"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    lineEdit = new QLineEdit(this);
    //lineEdit->setText("Enter your name"); //实显文本
    lineEdit->setPlaceholderText("Password"); //虚显文本（当文本框为空时提示用户应输入的内容）
    lineEdit->setEchoMode(QLineEdit::Password);//输入密码模式，输入文本会显示为掩码字符‘•’

}

Widget::~Widget()
{
    delete ui;
}


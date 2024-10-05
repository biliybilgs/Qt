#include "widget.h"
#include "ui_widget.h"
#include <qstring.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //this->setStyleSheet("QPushButton { background-color: red; color: white; }");
    ui->lineEdit->setPlaceholderText("首次密码：");     //设置提示词
    ui->lineEdit->setEchoMode(QLineEdit::Password);   //设置回显模式
    ui->lineEdit->setClearButtonEnabled(true);        //设置清空按钮

    ui->lineEdit_2->setPlaceholderText("再次输入密码：");
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    ui->lineEdit_2->setClearButtonEnabled(true);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_checkBox_toggled(bool checked)
{
    if(checked == true)
    {
        ui->lineEdit->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->lineEdit->setEchoMode(QLineEdit::Password);
    }
}

void Widget::on_checkBox_2_toggled(bool checked)
{
    if(checked == true)
    {
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    }
}



void Widget::on_lineEdit_2_textEdited(const QString &arg1)
{
    (void)arg1;
    const QString s1 = ui->lineEdit->text();
    const QString s2 = ui->lineEdit_2->text();
    if(s1.isEmpty())
    {
        ui->label_3->setText("请输入密码！");
        ui->label_3->setStyleSheet("color:red");
    }
    if(s2.isEmpty())
    {
        ui->label_4->setText("请输入密码！");
        ui->label_4->setStyleSheet("color:red");
    }
    if(s1 == s2)
    {
        ui->pushButton_2->setEnabled(true);
        ui->lineEdit->setStyleSheet("background-color:rgba(0, 181, 0, 100)");
        ui->lineEdit_2->setStyleSheet("background-color:rgba(0, 181, 0, 100)");
        ui->label_4->setText("密码输入正确");
        ui->label_4->setStyleSheet("color:#00aa00");
    }
}


void Widget::on_lineEdit_2_textChanged(const QString &arg1)
{
    (void)arg1;
    const QString s1 = ui->lineEdit->text();
    const QString s2 = ui->lineEdit_2->text();
    if(s1.isEmpty())
    {
        ui->label_3->setText("请输入密码！");
        ui->label_3->setStyleSheet("color:red");
    }
    if(s2.isEmpty())
    {
        ui->label_4->setText("请输入密码！");
        ui->label_4->setStyleSheet("color:red");
    }
    if(s1 == s2)
    {
        ui->pushButton_2->setEnabled(true);
        ui->lineEdit->setStyleSheet("background-color:rgba(0, 181, 0, 100)");
        ui->lineEdit_2->setStyleSheet("background-color:rgba(0, 181, 0, 100)");
        ui->label_4->setText("密码输入正确");
        ui->label_4->setStyleSheet("color:#00aa00");
    }
    else if(s1 != s2)
    {
        ui->lineEdit->setStyleSheet("background-color:#ffffff");
        ui->lineEdit_2->setStyleSheet("background-color:#ffffff");
        ui->label_4->setText("密码不匹配！");
        ui->label_4->setStyleSheet("color:#ff0000");
    }
}

void Widget::on_lineEdit_textChanged(const QString &arg1)
{
    (void)arg1;
    const QString s1 = ui->lineEdit->text();
    const QString s2 = ui->lineEdit_2->text();
    if(!s1.isEmpty() &&s2.isEmpty())
    {
        //1号不为空 2号为空
        ui->label_4->setText("请确认密码！");
        ui->label_4->setStyleSheet("color:black");
    }
    else if(s1 == s2 && !s1.isEmpty())
    {
        ui->pushButton_2->setEnabled(true);
        ui->lineEdit->setStyleSheet("background-color:rgba(0, 164, 151, 130)");
        ui->lineEdit_2->setStyleSheet("background-color:rgba(0, 164, 151, 130)");
        ui->label_4->setText("密码输入正确");
        ui->label_4->setStyleSheet("color:#00aa00");
        //ui->label_3->setText("密码输入正确");
        //ui->label_3->setStyleSheet("color:#00aa00");
    }
    else if(s1 != s2)
    {
        ui->lineEdit->setStyleSheet("background-color:#ffffff");
        ui->lineEdit_2->setStyleSheet("background-color:#ffffff");
        ui->label_4->setText("密码不匹配！");
        ui->label_4->setStyleSheet("color:#ff0000");
    }
    else if(s1.isEmpty() && s2.isEmpty())
    {
        ui->lineEdit->setStyleSheet("background-color:#ffffff");
        ui->lineEdit_2->setStyleSheet("background-color:#ffffff");
        ui->label_3->setText("请输入密码！");
        ui->label_3->setStyleSheet("color:black");
        ui->label_4->setText("");
    }
}

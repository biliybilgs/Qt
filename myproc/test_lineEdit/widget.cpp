#include "widget.h"
#include "ui_widget.h"
#include <QRegExpValidator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("请输入手机号：");
    QRegularExpression regexp ("^1\\d{10}$");  //创建正则表达式规则
    //创建验证器，并将规则进行插入
    //QRegularExpressionValidator validator(regexp);
    //将验证器与LineEdit进行绑定
    ui->lineEdit->setValidator(new QRegularExpressionValidator(regexp));
    //ui->lineEdit->setValidator(&validator);

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_lineEdit_textEdited(const QString &arg1)
{
    //验证我们输入的字符换是否符合规则
    QString str(arg1);  //表示要验证的字符串
    int pos = 0;
    //通过LineEdit验证器验证数据
    if(ui->lineEdit->validator()->validate(str,pos) == QValidator::Acceptable)
    {
        //验证通过
        ui->pushButton->setEnabled(true);
    }
    else
        //验证失败
        ui->pushButton->setEnabled(false);
}

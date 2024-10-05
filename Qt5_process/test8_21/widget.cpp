#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //connect(ui->pushButton_2,&QPushButton::clicked,this,&Widget::enableButton);

}
Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QRect rect = ui ->pushButton->geometry();
    ui->pushButton->setGeometry(rect.x()-5,rect.y(),rect.width(),rect.height());
}

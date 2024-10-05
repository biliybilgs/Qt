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


void Widget::on_pushButtonAdd_clicked()
{
    QString str = ui->lineEdit->text();
    QWidget* wg = new QWidget();
    ui->tabWidget->addTab(wg,str);
    //设置新标签页为被选中状态
    int count = ui->tabWidget->count();
    ui->tabWidget->setCurrentIndex(count-1);
}

void Widget::on_pushButtonDelete_clicked()
{
    int index = ui->tabWidget->currentIndex();
    ui->tabWidget->removeTab(index);
}

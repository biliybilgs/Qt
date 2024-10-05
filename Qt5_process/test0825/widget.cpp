#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>
#include <QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QButtonGroup* group1 = new QButtonGroup(this);
    QButtonGroup* group2 = new QButtonGroup(this);
    group1->addButton(ui->radioButton);
    group1->addButton(ui->radioButton_2);
    group1->addButton(ui->radioButton_3);

    group2->addButton(ui->radioButton_4);
    group2->addButton(ui->radioButton_5);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString result = "你今天的任务是什么：";
    if(ui->checkBox->isChecked())
    {
        result += ui->checkBox->text() + ' ';
    }
    if(ui->checkBox_2->isChecked())
    {
        result += ui->checkBox_2->text() + ' ';
    }
    if(ui->checkBox_3->isChecked())
    {
        result += ui->checkBox_3->text() + ' ';
    }
    ui->label_3->setText(result);
}

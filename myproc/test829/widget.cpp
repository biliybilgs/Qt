#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QShortcut>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* pushbutton = new QPushButton(this);
    (void)pushbutton;

    ui->dial->setWrapping(true);
    ui->dial->setNotchesVisible(true);
    ui->dial->setMaximum(100);
    ui->dial->setMinimum(0);

    //ui->dial->setSliderPosition(100);
    ui->dial->setValue(50);

    //初始化进度条
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(100);
    ui->horizontalSlider->setSingleStep(10);
    ui->horizontalSlider->setValue(0);
    //创建快捷键
    QShortcut* shortcut1 = new QShortcut(this);
    shortcut1->setKey(QKeySequence("-"));
    QShortcut* shortcut2 = new QShortcut(this);
    shortcut2->setKey(QKeySequence("="));

    //使用信号槽，当快捷键被按下的时候，触发槽函数
   connect(shortcut1,&QShortcut::activated,this,&Widget::subValue);
   connect(shortcut2,&QShortcut::activated,this,&Widget::addValue);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
     QDateTime timeOld = ui->dateTimeEdit->dateTime();
     QDateTime timeNew = ui->dateTimeEdit_2->dateTime();
     //计算日期


}

void Widget::on_dial_valueChanged(int value)
{
    //通过旋钮改变窗口的透明度

    this->setWindowOpacity((double)value /100);
}

void Widget::subValue()
{
    int value = ui->horizontalSlider->value();
    if(value <= ui->horizontalSlider->minimum())
        return;
    ui->horizontalSlider->setValue(value-10);
}

void Widget::addValue()
{
    int value = ui->horizontalSlider->value();
    if(value >= ui->horizontalSlider->maximum())
        return;
    ui->horizontalSlider->setValue(value+10);
}

void Widget::on_horizontalSlider_valueChanged(int value)
{
    ui->label_4->setText("当前的值为：" + QString::number(value));
}

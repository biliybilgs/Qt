#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    pushButton = new QPushButton(this);
    pushButton->setText("Button");
    //功能：点击按钮的时候，就会运行ReceiverHandle函数
    connect(pushButton,&QPushButton::clicked,this,&Widget::ReceiverHandler);
//函数讲解：将ui文件中的pushButton的信号 链接到 widget类的ReceiverHandler函数
}

void Widget::ReceiverHandler()
{
    //点击按钮之后，切换按钮中文本
    if(pushButton->text() == QString("Button"))
        pushButton->setText("我是一个按钮");
    else
    {
        pushButton->setText("Button");
    }
}

Widget::~Widget()
{
    delete ui;
}


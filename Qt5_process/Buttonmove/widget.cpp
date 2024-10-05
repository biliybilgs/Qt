#include "widget.h"
#include "ui_widget.h"
#include <cstdlib>
#include <ctime>
#include <QIcon>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    srand((unsigned int)time(NULL));

    QIcon icon(":/new/prefix1/2024-08-21 .png");
    this->setWindowIcon(icon);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_2_clicked()
{
    ui->label->setText("爱你！");
}
//表示鼠标点击松开就会移开
void Widget::on_pushButton_clicked()
{
//    int width = geometry().width();
//    int height = geometry().height();

//    int Buttonwidth =rand() % width;
//    int Buttonheight = rand() % height;

//    ui->pushButton->move(Buttonwidth,Buttonheight);
}
//表示鼠标点击还没有移开就会跑开
void Widget::on_pushButton_pressed()
{
    int width = geometry().width();
    int height = geometry().height();

    int Buttonwidth =rand() % width;
    int Buttonheight = rand() % height;

    ui->pushButton->move(Buttonwidth,Buttonheight);
}
//实际上还能够实现，只要鼠标移动到按钮上（还没有进行点击），按钮就会移动
//但是方式需要通过qt的事件进行编程， 我们后续在进行完善

#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <cstdlib> //srand
#include <ctime>   //time


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    pushbutton = new QPushButton(this);
    pushbutton->setText("不许点");
    pushbutton->move(700,0);

//    connect(pushbutton,&QPushButton::clicked,this,&Widget::buttonHandler);

    //ui->lineEdit->setPlaceholderText("请输入：");
    connect(pushbutton,&QPushButton::clicked,this,&Widget::buttonHandler);
    srand((unsigned int)time(NULL));
    
}

Widget::~Widget()
{
    delete ui;
}

void Widget::buttonHandler()
{
    //窗口移动循环
    int left = rand() % 800;
    int right = rand() % 600;
    pushbutton->move(left,right);
}


void Widget::on_pushButton_clicked()
{
    
}

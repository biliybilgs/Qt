#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
   //创建QMessageBox对话框 -- 提示作用
   QMessageBox *message = new QMessageBox();
   message->setWindowTitle("警告！");
   message->setText("你正在进行违规操作。请尽快停止！");
   message->setIcon(QMessageBox::Critical);

   //设置按钮 1. 内置按钮  2. 自定义按钮
   //1.内置
   /*message->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
   int result = message->exec(); //展示内容
   if (result == QMessageBox::Ok) {
       // 用户点击了“确定”，执行相应操作
   } else if (result == QMessageBox::Cancel) {
       // 用户点击了“取消”，执行取消逻辑
   }*/
   //自定义按钮
   QPushButton* button1 = new QPushButton("确认");
   QPushButton* button2 = new QPushButton("取消");
   message->addButton(button1,QMessageBox::AcceptRole);
   message->addButton(button2,QMessageBox::RejectRole);
   //编写按钮点击之后的逻辑1
   //connect(button1,&QPushButton::clicked,this,&MainWindow::handler1);
   //connect(button2,&QPushButton::clicked,this,&MainWindow::handler2);

   message->exec();
   //逻辑2：判断点击了那个用户
   if (message->clickedButton() == button1) {
       handler1();
   } else if (message->clickedButton() == button2) {
       handler2();
   }
}

void MainWindow::handler1()
{
    qDebug() << " handler1 进行确认";
}

void MainWindow::handler2()
{
    qDebug() << " handler2 进行取消";
}

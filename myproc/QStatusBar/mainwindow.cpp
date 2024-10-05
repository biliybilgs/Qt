#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStatusBar>
#include <qlabel.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建状态栏 ，由于我们创建的项目中带有ui文件，自带状态栏类
    QStatusBar* statusbar = this->statusBar();
    this->setStatusBar(statusbar);   //保险步骤

    //设置一个临时信息,显示时间为6秒钟。 参数二不写默认为0，表示持久信息
    //statusbar->showMessage("this is temporary information",6000);

    QLabel* label = new QLabel(statusbar);
    label->setText("提示消息");
    QLabel* label1 = new QLabel(statusbar);
    label1->setText("提示消息1");
    QLabel* label2 = new QLabel(statusbar);
    label2->setText("提示消息2");
    statusbar->addWidget(label,1);
    statusbar->addWidget(label1,2);
    statusbar->addWidget(label2,3);



}

MainWindow::~MainWindow()
{
    delete ui;
}


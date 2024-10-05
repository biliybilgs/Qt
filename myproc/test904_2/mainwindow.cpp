#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建工具栏的同时指定工具栏的的默认初始位置
    QToolBar* bar = new QToolBar();
    this->addToolBar(Qt::LeftToolBarArea,bar);
    QToolBar* bar2 = new QToolBar();
    this->addToolBar(Qt::RightToolBarArea,bar2);
    //创建选项.将选项添加到两个工具栏中
    QAction* action1 = new QAction("保存");
    QAction* action2 = new QAction("打开");
    bar->addAction(action1);
    bar->addAction(action2);
    bar2->addAction(action1);
    bar2->addAction(action2);
    //表示bar工具栏只能停放在左边或者右边  (或者悬空)
    bar->setAllowedAreas(Qt::LeftToolBarArea |Qt::RightToolBarArea);
    //表示bar工具栏只能停靠在顶部或者底部  （或者悬空）
    bar2->setAllowedAreas(Qt::TopToolBarArea | Qt::BottomToolBarArea);
    //Qt::AllToolBarAreas  四个方向的位置都可以进行停放

}

MainWindow::~MainWindow()
{
    delete ui;
}


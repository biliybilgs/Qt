#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建菜单栏
    QMenuBar * menubar = this->menuBar();
    this->setMenuBar(menubar);
    //创建菜单
    QMenu* menu = new QMenu("文件");
    menubar->addMenu(menu);

    //创建工具栏
    QToolBar * bar = new QToolBar();
    //将工具添加到窗口中
    this->addToolBar(bar);

    //创建两个选项
    QAction* action1 = new QAction("保存");
    QAction* action2 = new QAction("打开");
    action1->setIcon(QIcon(":/save.png"));
    action2->setIcon(QIcon(":/open.png"));
    //将选项添加到菜单和工具栏中
    menu->addAction(action1);
    menu->addAction(action2);
    bar->addAction(action1);
    bar->addAction(action2);

    connect(action1,&QAction::triggered,this,&MainWindow::handler1);
    connect(action2,&QAction::triggered,this,&MainWindow::handler2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handler1()
{
    qDebug() << "this is handler1";
}

void MainWindow::handler2()
{
    qDebug() <<"this is handler2";
}



#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenu>
#include <QAction>
#include <qdebug.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenuBar* menubar = new QMenuBar();

    this->setMenuBar(menubar);

    QMenu* menu1 = new QMenu("选项一(&v)");
    QMenu* menu2 = new QMenu("选项二");
    QMenu* menu3 = new QMenu("选项三");
    QMenu* menu4 = new QMenu("选项四");
    QMenu* menu5 = new QMenu("选项五");

    menubar->addMenu(menu1);
    menubar->addMenu(menu2);
    menubar->addMenu(menu3);
    menubar->addMenu(menu4);
    menubar->addMenu(menu5);

    QAction *action1 =new QAction("新建");
    QAction *action2 =new QAction("打开");
    QAction *action3 =new QAction("保存");
    QAction *action4 =new QAction("另存为");
    QAction *action5 =new QAction("退出");
    menu1->addAction(action1);
    menu1->addAction(action2);
    menu1->addAction(action3);
    menu1->addAction(action4);
    menu1->addAction(action5);


    //给meun1 添加一个功能
    connect(action1,&QAction::triggered,this,&MainWindow::handle);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle()
{
    //功能：打印
    qDebug() << "打印";
}


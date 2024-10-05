#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDockWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <qpushbutton.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建浮动窗口
    QDockWidget* dockwidget = new QDockWidget();
    this->addDockWidget(Qt::LeftDockWidgetArea,dockwidget);
    //设置浮动窗口的位置
    dockwidget->setAllowedAreas(Qt::BottomDockWidgetArea);
    //设置浮动窗口的名字
    dockwidget->setWindowTitle("浮动窗口标题");

    //给浮动窗口内部添加一些其他控件，
    //不能直接给这个浮动窗口添加子控件，而需要创建一个单独的QWidget，
    //把要添加的空间插入到QWidget中，
    //然后再把这个QWidget设置到dockwidget中（理解成浮动窗口添加一个部件）
    QWidget* container = new QWidget();
    dockwidget->setWidget(container);
    QVBoxLayout* layout = new QVBoxLayout(container);
    QLabel* label = new QLabel("这是一个label");
    QPushButton* pushbutton = new QPushButton("这是一个按钮");
    layout->addWidget(label);
    layout->addWidget(pushbutton);


}

MainWindow::~MainWindow()
{
    delete ui;
}


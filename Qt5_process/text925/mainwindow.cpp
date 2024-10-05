#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QKeyEvent>

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
//任何按键按下的时候都会触发这个事件处理函数
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    //qDebug() << event->key();
    if(event->key() == Qt::Key_A && event->key() == Qt::CTRL)
    {
        qDebug() << "你按下了A键";
    }

}


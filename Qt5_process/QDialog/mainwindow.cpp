#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

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
    //创建对话框 -- 创建的同时创建对话框中的空间
    Dialog* dialog = new Dialog(this);

    dialog->resize(400,300);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();


}

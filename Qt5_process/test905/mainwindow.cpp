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


//void MainWindow::on_pushButton_clicked()
//{
//    QDialog* dialog = new QDialog(this);
//    dialog->setWindowTitle("弹出的对话框");
//    dialog->resize(400,300);
//    dialog->show();//独立窗口不会继承父窗口的显示特性
//    //上面这种这是方式，当对话框关闭之后dialog在内存中任然存在（即使没有显示，创建的类也依旧存在堆空间中）
//    //所以当关闭对话框的时候，应该运行delete dialog
//    //由于这种情况非常常见，所以dialog类专门设置了一个成员函数用于这种情况
//    dialog->setAttribute(Qt::WA_DeleteOnClose);
//}
//下面的方式当我们创建对话框的时候同时加载对话框中的空间，所以这是我们就需要重写对话框的类了
void MainWindow::on_pushButton_clicked()
{
    Dialog* dialog = new Dialog(this);
    dialog->resize(400,300);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QDebug>
#include <QFileDevice>
#include <QFileInfo>
#include<QString>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{//功能：弹出文件对话框，并获取文件信息
    QString path = QFileDialog::getOpenFileName(this);
    //通过文件的路径获取文件的信息
    QFileInfo fileInfo(path);
    qDebug() <<fileInfo.fileName() <<'\n' << fileInfo.suffix()<< '\n' <<
           fileInfo.path() << '\n'<<fileInfo.size() <<'\n'<<fileInfo.isFile() <<'\n'
            << fileInfo.isDir() ;
}

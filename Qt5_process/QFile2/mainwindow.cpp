#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPlainTextEdit>
#include <QFileDialog>
#include <qdebug.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenuBar* menubar = this->menuBar();
    //创建菜单，并进行添加
    QMenu* menu = new QMenu("文件");
    menubar->addMenu(menu);
    //创建菜单项
    QAction *action1 = new QAction("打开文件");
    QAction *action2 = new QAction("保存文件");
    menu->addAction(action1);
    menu->addAction(action2);

    //指定一个输入框
    edit = new QPlainTextEdit();
    QFont font;
    font.setPixelSize(20);
    edit->setFont(font);
    this->setCentralWidget(edit);

    //连接信号槽
    connect(action1,&QAction::triggered,this,&MainWindow::handlerAction1);
    connect(action2,&QAction::triggered,this,&MainWindow::handlerAction2);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handlerAction1()
{
    //1. 先弹出“打开文件”对话框，让用户选择所要打开的文件,然后将文件路径进行返回
    QString path = QFileDialog::getOpenFileName(this);
    //2.把文件名显示到状态栏里面
    QStatusBar* statusBar = this->statusBar();
    statusBar->showMessage(path);
    //3.根据返回的路径，构造一个QFile对象
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)) //如果文件存在，则正常读打开；如果文件不存在，则返回false
    {
        qDebug() << "文件打开失败";
        return;
    }
    //4.读取文件,由于string智能识别文本文件，所以如果打开的文件是二进制文件，就不能使用qstring进行接收
//    while (!file.atEnd()) {
//        QByteArray line = file.readLine();  // 读取一行

//        qDebug() << "读取到的行：" << line.trimmed();
//    }
    QString text = file.readAll();
   //5.关闭文件
   file.close();
   //将打开的
   edit->setPlainText(text);
}

void MainWindow::handlerAction2()
{
    //1.首先弹出“保存文件”对话框 -- 就是返回一个路径
    QString path = QFileDialog::getSaveFileName(this);

    //2.在状态栏中显示这个文件名
    QStatusBar* statusbar = this->statusBar();
    statusbar->showMessage(path);

    //3.根据用户选择的路径，构造一个Qfile对象，
    QFile file(path);
    if(!file.open(QFile::WriteOnly)) //写方式打开该文件，如果该文件不存在，则创建一个新文件，如果文件存在则清空文件内容
    {
            qDebug() << "文件打开失败";
            return;
    }

    //4.写文件
    const QString& text = edit->toPlainText();
    file.write(text.toUtf8());

    //5.关闭文件
    file.close();

}


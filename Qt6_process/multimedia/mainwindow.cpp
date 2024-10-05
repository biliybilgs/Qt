#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sound = new QSoundEffect(this);

    //connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::handler);
    connect(ui->pushButton,&QPushButton::clicked,this,&MainWindow::hanler1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{//隐士连接槽函数

}
//功能：播放音频文件
void MainWindow::handler()
{//手动连接槽函数

    sound->setSource(QUrl::fromLocalFile(":/sample-9s.wav"));
    sound->setVolume(0.5);
    sound->play();

}

void MainWindow::hanler1()
{
    QSoundEffect* soundEffect = new QSoundEffect();
    soundEffect->setSource(QUrl::fromLocalFile(":/sample-9s.wav"));
    soundEffect->setVolume(0.5);
    soundEffect->play();

    // 为了防止内存泄漏，在播放完成后手动删除对象

    QTimer::singleShot(1000, [soundEffect]() { // 假设音效持续 5 秒
        delete soundEffect; // 删除音效对象
    });
    //connect(soundEffect, &QSoundEffect::statusChanged,[soundEffect](){});
}


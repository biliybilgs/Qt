#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QResizeEvent>
#include <QTimer>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //将label4设置为显示图片
    QRect windowRect = this->geometry();
    ui->label_4->setGeometry(0,0,windowRect.width(),windowRect.height());
    QPixmap pixmap(":/taitai.jpg");
    ui->label_4->setPixmap(pixmap);       //在label中设置图片
    ui->label_4->setScaledContents(true); //设置自动拉伸填充label大小

    //创建一个qtimer实例
    timer = new QTimer(this);
    //把qtimer的timeout信号和槽函数进行连接
    connect(timer,&QTimer::timeout,this,&Widget::handler);
    //启动定时器，参数是触发timeout的周期，单位是ms
    timer->start(1000);


}
void Widget::resizeEvent(QResizeEvent *event){
    qDebug() << event->size();
    ui->label_4->setGeometry(0,0,event->size().width(),event->size().height());
}

void Widget::handler()
{
    //
    int value = ui->lcdNumber->intValue();
    if(value <= 0)
    {
        timer->stop();
        return ;
    }
    else
    {
        ui->lcdNumber->display(value-1);
    }
}
Widget::~Widget()
{
    delete ui;
}




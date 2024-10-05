#include "widget.h"
#include "ui_widget.h"
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


//    QPixmap pixmap(":/v2.jpg");  //需要通过QPixmap加载图片，先将图片进行优化渲染
//    pixmap = pixmap.scaled(50,50); //修改光标大小
//    //QCursor cursor = Qt::WaitCursor;
//    QCursor cursor(pixmap,0,0);  //创建光标对象
//    //吧光标设置进去
//    this->setCursor(cursor);

    //QIcon Icon(":/v2.jpg");

    QLabel* label = new QLabel(this);
    label->setText("这是一段文本");

    //修改字体属性
    QFont font;
    font.setFamily("仿宋");    //设置字体名称
    font.setPixelSize(30);    //设置字体大小
    font.setBold(true);       //设置粗体
    font.setItalic(true);     //设置斜体
    font.setStrikeOut(true);  //删除线

    label->setFont(font);

    ui->pushButton->setToolTip("我的提示信息！");
    ui->pushButton->setToolTipDuration(3000);  //单位是ms

}

Widget::~Widget()
{
    delete ui;
}


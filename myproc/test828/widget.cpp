#include "widget.h"
#include "ui_widget.h"
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QLabel* label = new QLabel(this);

    label->setText("fjdklsaj fkldjsa lkfjdlska fdlk aj");
    QFont font;
    font.setFamily("仿宋");    //设置字体名称
    font.setPixelSize(30);    //设置字体大小
    font.setBold(true);       //设置粗体
    font.setItalic(true);     //设置斜体
    font.setStrikeOut(true);  //删除线
    font.setUnderline(true);  //设置字体下划线
    font.setStrikeOut(true);  //设置字体删除线
    label->setFont(font);

    //label->show();
}

Widget::~Widget()
{
    delete ui;
}


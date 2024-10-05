#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QGridLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建网格按钮，按照2*3的方式进行排列
    QPushButton *push1 = new QPushButton("按钮1");
    QPushButton *push2 = new QPushButton("按钮2");
    QPushButton *push3 = new QPushButton("按钮3");
    QPushButton *push4 = new QPushButton("按钮4");
    QPushButton *push5 = new QPushButton("按钮5");
    QPushButton *push6 = new QPushButton("按钮6");

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(push1,0,0);
    layout->addWidget(push2,0,1);
    layout->addWidget(push3,0,2);
    layout->addWidget(push4,1,0);
    layout->addWidget(push5,1,1);
    layout->addWidget(push6,1,2);

    this->setLayout(layout);

    //设置列拉伸系数,表示0,1,2这三列按照1:2:3的方式来设置控件大小
    layout->setColumnStretch(0,1);
    layout->setColumnStretch(1,2);
    layout->setColumnStretch(2,3);
    //设置列拉伸系数，表示第一行和第二行的比例1:2
    layout->setRowStretch(0,1);
    layout->setRowStretch(1,2);
}

Widget::~Widget()
{
    delete ui;
}


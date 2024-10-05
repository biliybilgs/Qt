#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QMenuBar *menubar = this->menuBar()

}

Widget::~Widget()
{
    delete ui;
}


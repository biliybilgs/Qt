#include "dialog.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>


Dialog::Dialog(QWidget *parent)
    :QDialog(parent)
{
    //创建一些控件，加入到dialog中（以dialog作为父窗口）
    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* label = new QLabel("内容",this);
    QPushButton* pushbutton = new QPushButton("按钮",this);
    layout->addWidget(label);
    layout->addWidget(pushbutton);
}

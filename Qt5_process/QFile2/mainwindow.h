#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qplaintextedit.h>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void handlerAction1();
    void handlerAction2();

private:
    Ui::MainWindow *ui;
    QPlainTextEdit* edit;
};
#endif // MAINWINDOW_H

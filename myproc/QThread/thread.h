#ifndef THREAD_H
#define THREAD_H

#include <QWidget>
#include <QThread>

class Mythread : public QThread
{
    Q_OBJECT
public:
    Mythread();
    void run() override;
signals:
    void notify(int x);  //自定义信号


};

#endif // THREAD_H

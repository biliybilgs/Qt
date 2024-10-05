#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QWidget>
#include <QThread>
#include <QMutex>

class Mythread : public QThread
{
    Q_OBJECT
public:
    Mythread();

    static int num;       //共享变量
    static QMutex mutex;  //互斥锁

    void run() override;

    static QMutex getMutex();
    static void setMutex(const QMutex &value);
};

#endif // MYTHREAD_H

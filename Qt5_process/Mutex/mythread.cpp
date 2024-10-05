#include "mythread.h"

int Mythread::num = 0;
QMutex Mythread::mutex;


Mythread::Mythread()
{

}

void Mythread::run()
{

    for(int i = 0;i < 5000;i++)
    {
        mutex.lock();
        num++;
        mutex.unlock();
    }
}

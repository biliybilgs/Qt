#include "thread.h"


//这个函数就是线程运行的函数
Mythread::Mythread()
{

}

void Mythread::run()
{ //功能：通过计时，每隔一段时间通过信号来通知主线程来更新控件的变化
    for(int i = 0;i<10;i++)
    {//本身是QThread的成员函数
        sleep(1);
        emit notify(i); //发送信号
    }

}

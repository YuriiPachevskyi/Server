#ifndef _THREAD_H_INCLUDED
#define _THREAD_H_INCLUDED

#include <pthread.h>

class Thread {
private:
    static void* threadStartRoutine(void *arg);
    pthread_t mTid;
    bool mRunning;

public:
    Thread();
    virtual ~Thread();
    virtual void run() = 0;
    long unsigned int getThreadId();
    bool start();
    bool join();
    void stop();
};

#endif //_THREAD_H_INCLUDED

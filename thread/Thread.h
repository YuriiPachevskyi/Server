#ifndef _THREAD_H_INCLUDED
#define _THREAD_H_INCLUDED

#include <pthread.h>

class Thread {
public:
    Thread();
    virtual ~Thread();
    virtual void run() = 0;
    bool start();
    bool join();
    void stop();

private:
    static void* threadStartRoutine(void *arg);
    
    pthread_t mTid;
    bool mRunning;
};

#endif //_THREAD_H_INCLUDED
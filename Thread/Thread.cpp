#include "Thread.h"

#include <iostream>

using namespace std;

Thread::Thread() : mRunning(false) {
}

Thread::~Thread() {
    if (mRunning) {
        stop();
    }
}

bool Thread::start() {
    if (!mRunning) {
        if (!pthread_create(&mTid, NULL, Thread::threadStartRoutine, this)) {
            mRunning = true;
            return true;
        }
        return false;
    }
    return false;
}

bool Thread::join() {
	if (mRunning == true) {
		pthread_join(mTid, NULL);
		return true;
	}
	return false;
}


void Thread::stop() {
    if (mRunning) {
        pthread_cancel(mTid);

        if (pthread_join(mTid, NULL) == 0) {
            mRunning = false;
        }
    }
}

//static
void* Thread::threadStartRoutine(void *arg) {
    Thread *threadToRun = reinterpret_cast<Thread*>(arg);

    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

    threadToRun->run();

    return NULL;
}

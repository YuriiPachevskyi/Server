#ifndef WORKER_H
#define WORKER_H

#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include "Thread.h"
#include "Includes.h"

class Worker: public Thread {
    private:
        int id;
        int socket;
        static int counter;

    public:
        Worker(int socket);
        virtual ~Worker();
        virtual void run();
        void setForWork();
};

#endif //WORKER_H

#ifndef WORKER_H
#define WORKER_H

#include "Listener.h"
#include "Includes.h"

class Worker: public Listener {
    private:
        int id;
        static int counter;

    public:
        Worker(int port);
        virtual ~Worker();
        virtual void run();
        void initWorker();
        void setForWork();
};

#endif //WORKER_H

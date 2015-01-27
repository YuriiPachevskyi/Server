#ifndef WORKER_H
#define WORKER_H

#include "Listener.h"
#include "Includes.h"

class Worker: public Listener {
    private:
        int id;
        int socket;
        static int counter;

    public:
        Worker(int socket);
        virtual ~Worker();
        virtual void run();
        void initWorker();
        void setForWork();
};

#endif //WORKER_H

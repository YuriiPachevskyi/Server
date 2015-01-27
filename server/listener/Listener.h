#ifndef LISTENER_H
#define LISTENER_H

#include "Thread.h"
#include "Includes.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class Listener: public Thread {
    private:
    struct sockaddr_in addr;

    protected:
        int listener;
        int currentPort;
        int maxPort;

    public:
        Listener(int port = 3425);
        virtual ~Listener();
        virtual void run();
        void initListener();
        bool createWorker(int port); //temporary port setting
        void setForListen();
        virtual int getPort();
};


#endif //LISTENER_H

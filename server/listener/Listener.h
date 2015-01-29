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
        int port;
        int listener;
        struct sockaddr_in addr;

    public:
        Listener(int port = 3425);
        virtual ~Listener();
        virtual void run();
        void initListener();
        void setForListen();
        bool createWorker(int socket);
};

#endif //LISTENER_H

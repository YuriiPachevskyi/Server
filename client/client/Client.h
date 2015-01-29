#ifndef CLIENT_H
#define CLIENT_H

#include "Includes.h"
#include <unistd.h>
#include <netinet/in.h>

class Client {
    private:
        int sock;
        int port;
        struct sockaddr_in addr;

    public:
        Client(int port = 3425);
        virtual ~Client();
        virtual void run();
        void initClient();
        void doWork();
};

#endif // CLIENT_H

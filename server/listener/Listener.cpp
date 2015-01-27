#include "Listener.h"
#include "Worker.h"

Listener::Listener(int port): currentPort(port) {
    printf("Listener constructor\n");
}

Listener::~Listener() {
    printf("Listener destructor\n");
}

void Listener::run() {
    initListener();
    setForListen();
}

int Listener::getPort() {
    return currentPort;
}

bool Listener::createWorker(int port) {
    Worker *worker = new Worker(port);
    if ( worker->start() == true ) {
        return true;
    }
    return false;
}

void Listener::initListener() {
    printf("initListener\n");
    listener = socket(AF_INET, SOCK_STREAM, 0);
    if ( listener < 0 ) {
        perror("Listener socket");
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(currentPort);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if ( bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0 ) {
        perror("Listener bind");
    }
    listen(listener, 1);
}

void Listener::setForListen() {
    maxPort = currentPort;
    printf("setForListen threadId = %lu\n", this->getThreadId());
    char buf[1024];
    int bytes_read;

    while(1) {
        int sock = accept(listener, NULL, NULL);

        if ( sock < 0 ) {
            perror("Listener accept");
        }
        while(1) {
            bytes_read = recv(sock, buf, 1024, 0);

            if ( bytes_read <= 0 ) break;
            if ( strcmp(buf, NEW_CONN) == 0 ) {
                maxPort += 1;
                printf("new port = %d\n", maxPort);
                char newbuf[4];
                *((int*)newbuf) = maxPort;
                if ( this->createWorker(maxPort) == true ) {
                    send(sock, newbuf, sizeof(newbuf), 0);
                } else {
                    perror("Listener worker creating");
                }
            }
        }
        close(sock);
    }
}

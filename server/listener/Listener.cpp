#include "Listener.h"
#include "Worker.h"

Listener::Listener(int port): port(port) {
    printf("Listener constructor\n");
}

Listener::~Listener() {
    printf("Listener destructor\n");
}

void Listener::run() {
    initListener();
    setForListen();
}

bool Listener::createWorker(int socket) {
    Worker *worker = new Worker(socket);
    if ( worker->start() == true ) {
        return true;
    }
    return false;
}

void Listener::initListener() {
    listener = socket(AF_INET, SOCK_STREAM, 0);
    if ( listener < 0 ) {
        perror("Listener socket");
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if ( bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0 ) {
        perror("Listener bind");
    }
    listen(listener, 1);
}

void Listener::setForListen() {
    while(1) {
        int sock = accept(listener, NULL, NULL);

        if ( sock < 0 ) {
            perror("Listener accept");
        }
        if ( this->createWorker(sock) != true ) {
            perror("Listener worker creating");
        }
    }
}

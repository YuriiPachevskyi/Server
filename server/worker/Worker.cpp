#include "Worker.h"

int Worker::counter = 0;

Worker::Worker(int port): Listener(port) {
    printf("Worker constructor id = %lu\n", this->getThreadId());
    counter += 1;
    id = counter;
}

Worker::~Worker() {
    printf("worker destrucor colling\n");
}

void Worker::run() {
    initWorker();
    setForWork();
}

void Worker::initWorker() {
    initListener();
}

void Worker::setForWork() {
    printf("setForWork threadId = %lu\n", this->getThreadId());
    char buf[1024];
    int bytes_read;

    while(1) {
        int sock = accept(listener, NULL, NULL);

        if ( sock < 0 ) {
            perror("Worker accept");
        }
        while(1) {
            bytes_read = recv(sock, buf, 1024, 0);
            if ( bytes_read <= 0 ) break;
            printf("worker print result  =  %s\n", buf);
            send(sock, buf, bytes_read, 0);
        }
        if ( strcmp(buf, END_CONN) == 0 ) {
            printf("Worker end of connection threadId = %lu\n", this->getThreadId());
            close(sock);
            delete this;
        }
    }
}

#include "Worker.h"

int Worker::counter = 0;

Worker::Worker(int socket): socket(socket) {
    printf("Worker constructor id = %lu\n", this->getThreadId());
    counter += 1;
    id = counter;
}

Worker::~Worker() {
    printf("worker destrucor colling\n");
}

void Worker::run() {
//    initWorker();
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
        bytes_read = recv(socket, buf, 1024, 0);
        if ( bytes_read <= 0 ) break;
        printf("worker print result  =  %s\n", buf);
        send(socket, buf, bytes_read, 0);
    }
    close(socket);
    delete this;
}

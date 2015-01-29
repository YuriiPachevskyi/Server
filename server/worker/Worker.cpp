#include "Worker.h"
#include "Log.h"

int Worker::counter = 0;

Worker::Worker(int socket): socket(socket) {
    LOGI("constructor socket =  %d", socket);
    counter += 1;
    id = counter;
}

Worker::~Worker() {
    LOGI("destructor");
}

void Worker::run() {
    setForWork();
}

void Worker::setForWork() {
    char buf[1024];
    int bytes_read;

    while(1) {
        bytes_read = recv(socket, buf, 1024, 0);
        if ( bytes_read <= 0 ) break;
        LOGI("content = %s", buf);
        send(socket, buf, bytes_read, 0);
    }
    close(socket);
    delete this;
}

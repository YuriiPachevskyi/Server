#include "Worker.h"

int Worker::counter = 0;

Worker::Worker(int port): Listener(port) {
	printf("Worker constructor\n");
	counter += 1;
	id = counter;
}

void Worker::run() {
    initWorker();
    setForWork();
}

void Worker::initWorker() {
	initListener();
}

void Worker::setForWork() {
	printf("setForWork\n");
    char buf[1024];
    int bytes_read;
	
	while(1) {
        int sock = accept(listener, NULL, NULL);
        if(sock < 0) {
            printf("accept");
        }

        while(1) {
            bytes_read = recv(sock, buf, 1024, 0);
            if(bytes_read <= 0) break;
            if ( strcmp(buf, NEW_CONN) == 0 ) {
                currentPort += 1;

            }
            printf("%s\n", buf);
            send(sock, buf, bytes_read, 0);
        }
        // close(sock);
    }
}

Worker::~Worker() {

}
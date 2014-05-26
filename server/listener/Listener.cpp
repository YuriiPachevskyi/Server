#include "Listener.h"

Listener::Listener(): currentPort(3425) {
	printf("Listener constructor\n");
}

void Listener::run() {
    initListener();
    setForListen();
}

void Listener::initListener() {
    printf("initListener\n");
	listener = socket(AF_INET, SOCK_STREAM, 0);
    if(listener < 0) {
        printf("socket");
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(currentPort);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if(bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        printf("bind");
    }
    listen(listener, 1);
}

void Listener::setForListen() {
	printf("setForListen\n");
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
            // printf("%s\n", buf);
            // send(sock, buf, bytes_read, 0);
        }
        // close(sock);
    }
}

Listener::~Listener() {
    printf("Listener destructor\n");
}

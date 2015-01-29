#include "Client.h"
#include "Log.h"

using namespace std;

Client::Client(int port): port(port) {
    LOGI("constructor");
}

Client::~Client() {
    LOGI("destructor");
}

void Client::run() {
    initClient();
    doWork();
}

void Client::initClient() {
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0 ){
        LOGE("socket valuet = %d", sock);
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if ( connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0 ) {
        LOGE("connect");
    }
}

void Client::doWork() {
    char buf[1024];
    char message[] = "Hello to server!";

    send(sock, NEW_CONN, sizeof(NEW_CONN), 0);
    recv(sock, buf, sizeof(buf), 0);
    LOGI("result = %s", buf);

    send(sock, message, sizeof(message), 0);
    recv(sock, buf, sizeof(buf), 0);
    LOGI("result2 = %s", buf);
}

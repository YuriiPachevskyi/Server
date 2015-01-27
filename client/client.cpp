#include "Includes.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>

char message[] = "Hello there!               ";
char message2[] = "message to worker";
char buf[sizeof(message)];

int main()
{
    int sock1;
    int sock2;
    int port = 3425;
    struct sockaddr_in addr;

    sock1 = socket(AF_INET, SOCK_STREAM, 0);
    sock2 = socket(AF_INET, SOCK_STREAM, 0);
    if (sock1 < 0 ){
        perror("socket");
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if ( connect(sock1, (struct sockaddr *)&addr, sizeof(addr)) < 0 ) {
        perror("connect");
    }

    send(sock1, NEW_CONN, sizeof(NEW_CONN), 0);

    char *newbuf[4];
    recv(sock1, newbuf, sizeof(newbuf), 0);
    port = *((int*)newbuf);

    printf("result after sleep =  %d, sock = %d\n", port, sock1);

    addr.sin_port = htons(port);

    if ( connect(sock2, (struct sockaddr *)&addr, sizeof(addr)) < 0 ) {
        perror("connect");
    }
    send(sock2, message2, sizeof(message2), 0);

    recv(sock2, message, sizeof(message), 0);
    printf("result %s\n", message);

    send(sock2, END_CONN, sizeof(END_CONN), 0);


    return 0;
}

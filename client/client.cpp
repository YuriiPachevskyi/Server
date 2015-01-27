#include "Includes.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>

char message[] = "Hello there!                       111";
char message2[] = "message to worker";
char buf[sizeof(message)];

int main()
{
    int sock;
    int port = 3425;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0 ){
        perror("socket");
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if ( connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0 ) {
        perror("connect");
    }

    send(sock, NEW_CONN, sizeof(NEW_CONN), 0);
    recv(sock, buf, sizeof(buf), 0);
    printf("result = %s\n", buf);

    send(sock, message2, sizeof(message2), 0);
    recv(sock, buf, sizeof(buf), 0);
    sleep(5);
    printf("result second message    = %s\n", buf);

//    printf("before recv message2\n");
//    recv(sock, message, sizeof(message), 0);
//    printf("after recv message2\n");

//    send(sock, END_CONN, sizeof(END_CONN), 0);

//    for ( int i = 0; i < 5; i++ ) {

//    }


    return 0;
}

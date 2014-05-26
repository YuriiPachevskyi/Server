#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

char message[50];
char buf[sizeof(message)];

int main()
{
    int sock;
    struct sockaddr_in addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(3425); // или любой другой порт...
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    if(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("connect");
    }

    for ( int i = 0; i < 5; i++ ) {
        scanf("%s", message);
        send(sock, message, sizeof(message), 0);
        // recv(sock, buf, sizeof(message), 0);
    }
    
    
    // printf("%s\n", buf);
    // close(sock);

    return 0;
}
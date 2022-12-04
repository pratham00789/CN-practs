#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main()
{
    char dataSending[1025];
    char dataReceived[1024];
    char str[50], operand[10];
    char op;
    int clintListn = 0, clintConnt = 0, sockfd = 0, cnt = 0, n = 0, len, a, b, output;
    struct sockaddr_in ipOfServer;
    clintListn = socket(AF_INET, SOCK_STREAM, 0);
    ipOfServer.sin_family = AF_INET;
    ipOfServer.sin_addr.s_addr = htonl(INADDR_ANY);
    ipOfServer.sin_port = htons(2017);
    bind(clintListn, (struct sockaddr *)&ipOfServer, sizeof(ipOfServer));
    listen(clintListn, 20);
    while (clintConnt == 0)
    {
        printf("\n\nHi, I am running server. Some Client hit me\n");
        clintConnt = accept(clintListn, (struct sockaddr *)NULL, NULL);
    }
    n = read(clintConnt, dataReceived, 512);
    printf("\n%s", dataReceived);
    close(clintConnt);
    close(clintListn);
    return 0;
}

// OUTPUT :

// Client :
// Enter a name : Ak

// Server :
// Hi, I am running server. Some Client hit me
// Ak


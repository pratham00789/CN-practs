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
    char buffer[50];
    char str[50], operand[10];
    char op;
    int clintListn = 0, clintConnt = 0, sockfd = 0, cnt = 0, n = 0, len, a, b, output, i, j = 0;
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
    n = read(clintConnt, dataReceived, 1024);
    printf("\nThe received string is: %s", dataReceived);
    len = strlen(dataReceived);
    printf("\nThe length of received string is: %d", len);
    for (i = 0; i < len; i++)
    {
        buffer[i] = dataReceived[len - i - 1];
    }
    buffer[i] = '\0';
    printf("\nThe reversed string is: %s", buffer);
    close(clintConnt);
    close(clintListn);
    return 0;
}

// OUTPUT :


// Client :
// Enter a name : THE_HUMAN_SPIDER

// Server :
// Hi, I am running server. Some Client hit me
// The received string is : THE_HUMAN_SPIDER
// The length of received string is : 16
// The reversed string is : REDIPS_NAHUM_EHT

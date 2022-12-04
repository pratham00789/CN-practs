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
    int CreateSocket = 0, n = 0, cnt = 0, clintConnt = 0, a, b;
    char dataReceived[1024];
    struct sockaddr_in ipOfServer;
    char buf1[50], str[50], oper;
    if ((CreateSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Socket not created \n");
        return 1;
    }
    ipOfServer.sin_family = AF_INET;
    ipOfServer.sin_port = htons(2017);
    ipOfServer.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(CreateSocket, (struct sockaddr *)&ipOfServer, sizeof(ipOfServer)) < 0)
    {
        printf("Connection failed due to port and ip problems\n");
        return 1;
    }
    printf("\nEnter a name: ");
    scanf("%s", &buf1);
    write(CreateSocket, buf1, strlen(buf1) + 1);
    close(CreateSocket);
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

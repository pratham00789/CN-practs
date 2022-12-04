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
    int CreateSocket = 0, n = 0, cnt = 0, a, b;
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
    printf("\nEnter the operand a");
    scanf("%d", &a);
    printf("\nEnter the operand b");
    scanf("%d", &b);
    printf("\nEnter the operator");
    scanf(" %c", &oper);
    sprintf(buf1, "%d %c %d", a, oper, b);
    write(CreateSocket, buf1, strlen(buf1) + 1);
    n = read(CreateSocket, dataReceived, 512);
    printf("%s", dataReceived);
    close(CreateSocket);
    return 0;
}

// OUTPUT :

// Client :
// Enter the operand a
// 10

// Enter the operand b
// 11

// Enter the operator
// +
// 21


// Server :
// Hi, I am running server. Some Client hit me 
// 10 + 11

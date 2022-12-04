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
    char dataReceived[1024];
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
    sscanf(dataReceived, "%d %c %d", &a, &op, &b);
    printf("%d %c %d", a, op, b);
    switch (op)
    {
    case '+':
        output = a + b;
        break;
    case '-':
        output = a - b;
        break;
    case '*':
        output = a * b;
        break;
    case '/':
        if (b == 0)
        {
            printf("\n Invalid input!");
            break;
        }
        output = a / b;
        break;
    default:
        printf("\nInvalid Input!");
    }
    sprintf(dataReceived, "%d", output);
    write(clintConnt, dataReceived, strlen(dataReceived) + 1);
    close(clintConnt);
    close(clintListn);
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


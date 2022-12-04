#include <stdio.h>

int main()
{
    int ip[4],sm[4];

    printf("\nEnter IP : ");
    scanf("%d.%d.%d.%d",&ip[0],&ip[1],&ip[2],&ip[3]);

    printf("\nEnter subnet mask : ");
    scanf("%d.%d.%d.%d",&sm[0],&sm[1],&sm[2],&sm[3]);

    printf("\nNetwork ID : %d.%d.%d.%d",(ip[0]&sm[0]),(ip[1]&sm[1]),(ip[2]&sm[2]),(ip[3]&sm[3]));

    printf("\nHost ID : %d.%d.%d.%d",(ip[0]&~sm[0]),(ip[1]&~sm[1]),(ip[2]&~sm[2]),(ip[3]&~sm[3]));

    if(ip[0]>=1 && ip[0]<127)
    { 
        printf("\nClass A\n");
    }
    else if(ip[0]>=128 && ip[0]<192)
    {
        printf("\nClass B\n");
    }
    else if(ip[0]>=192 && ip[0]<224)
    {
        printf("\nClass C\n");
    }
    else if(ip[0]>=224 && ip[0]<240)
    {
        printf("\nClass D\n");
    }
    else if(ip[0]>=240 && ip[0]<255)
    {
        printf("\nClass E\n");
    }
    else if(ip[0]==127)
    {
        printf("\nReserved for TroubleShooting\n");
    }
    else
    {
        printf("\nInvalid\n");
    }
}

// Enter IP : 192.168.137.2

// Enter subnet mask : 255.255.255.0

// Network ID : 192.168.137.0
// Host ID : 0.0.0.2
// Class C
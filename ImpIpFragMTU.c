#include <stdio.h>
#include <string.h>

struct fragment
{
    int id;
    int offset;
    int mf;
    char data[100];
};

void main()
{
    char str[100],sub[50];
    int flag=0,start=0,cnt=0;
    int mtu,netCap,noofFrag,i,id,offset,mf;
    struct fragment f[10];

    printf("\nEnter a string : ");
    gets(str);

    while(flag==0)
    {
        printf("\nEnter MTU : ");
        scanf("%d",&mtu);
        if((mtu-20) % 8 == 0)
        {
            flag=1;
        }
    }
    
    netCap = mtu - 20;
    noofFrag = strlen(str)/netCap;

    if(strlen(str)%netCap!=0)
    {
        noofFrag++;
    }

    for(i=0;i<noofFrag;i++)
    {
        f[i].id=10;
        f[i].offset=start/8;
        if(i<noofFrag-1)
        {
            f[i].mf=1;
            while(cnt<netCap)
            {
                sub[cnt]=str[start+cnt];
                cnt++;
            }
            sub[cnt]='\0';
            cnt=0;
            strcpy(f[i].data,sub);
            start = start + netCap;
        }

        else
        {
            f[i].mf=0;
            while(cnt<netCap)
            {
                if((start+cnt)==strlen(str))
                {
                    break;
                }
                sub[cnt]=str[start+cnt];
                cnt++;
            }
            sub[cnt]='\0';
            strcpy(f[i].data,sub);
        }
    }

    for(i=0;i<noofFrag;i++)
    {
        printf("\n%d %d %d %s",f[i].id,f[i].offset,f[i].mf,f[i].data);
    }
}

// Enter a string : 1522525252517171711131313131313131313

// Enter MTU : 52

// 10 0 1 15225252525171717111313131313131
// 10 4 0 31313
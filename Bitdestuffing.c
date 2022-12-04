#include <stdio.h>
#include <string.h>
char *destuff(char str[], char stack[])
{

    int n = strlen(str), count = 0, stack_index = 0, i;
    for (i = 0; i < n; i++)
    {
        if (str[i] == '1')
        {
            count++;

            stack[stack_index++] = str[i];

            if (count == 5)
            {

                i++;
                if (str[i] != '0')
                {
                    printf("\n Invalid input");

                    break;
                }
                count = 0;
            }
        }
        else
        {

            stack[stack_index++] = str[i];

            count = 0;
        }
    }
    stack[stack_index] = '\0';
    return stack;
}
void main()
{
    char str[40], stack[40];

    int n = 0, i = 0;
    printf("\nEnter length of string :");
    scanf("\n%d", &n);
    printf("\nEnter the string :");
    for (int i = 0; i < n; i++)
    {
        scanf("\n%c", &str[i]);
    }
    for (i; i < n; i++)
    {

        if (str[i] != '0' && str[i] != '1')
        {
            printf("\n Enter valid input");
        }
    }
    printf("\nInput:\n");
    printf("%s", str);

    printf("\nOutput:\n");
    printf("%s", destuff(str, stack));
}

// Enter length of string :8

// Enter the string :01111101

// Input:        
// 01111101
// Output:       
// 0111111

// or 

// Enter length of string :9

// Enter the string :011111010

// Input:
// 011111010
// Output:
// 01111110


  
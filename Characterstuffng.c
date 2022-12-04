#include <stdio.h>
#include <string.h>
char output[40];
char *stuff(char input[])
{
    int n = strlen(input);
    int j = 1;
    output[0] = '$';
    for (int i = 0; i < n; i++)
    {
        if (input[i] == '$' || input[i] == '#')
        {
            output[j++] = '#';
        }
        output[j++] = input[i];
    }
    output[j++] = '$';
    output[j] = '\0';
    return output;
}
int main()
{
    char input[40];
    int n = 0, i = 0;
    printf("\nEnter length of string :");
    scanf("\n%d", &n);
    printf("\nEnter the string :");
    for (int i = 0; i < n; i++)
    {
        scanf("\n%c", &input[i]);
    }
    printf("\ninput\n");
    printf("%s", input);
    printf("\noutput\n");
    printf("%s", stuff(input));
}

// Enter length of string :6

// Enter the string :Dollar

// input
// Dollar
// output
// $Dollar$

// or

// Enter length of string :7

// Enter the string :Dollar$

// input
// Dollar$
// output
// $Dollar#$$

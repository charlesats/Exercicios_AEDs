#include <stdio.h>
#include <stdlib.h>

int StrLen(char *string)
{

    int i;

    for (i = 0; string[i] != '\0'; ++i);
    return i;
}

int StrCmp(char *string1, char *string2)
{

    int a, i, maior, x, y;

    a = 0;

    x = StrLen(string1);
    y = StrLen(string2);

    maior = x;
    if(maior < y)
        maior = y;

    for (i = 0; i < maior; ++i)
    {
        if(string1[i] != string2[i])
        {
            if(x > y)
                a = 1;
            else
                a = -1;

        }
    }
    return a;
}


int main()
{
    char str1[20] = "asdf";
    char str2[20] = "fdsa";

    printf("\n%d",StrCmp(str1, str2));

    return 0;
}

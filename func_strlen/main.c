#include <stdio.h>
#include <stdlib.h>

int StrLen(char *string)
{

    int i;

    for (i = 0; string[i] != '\0'; ++i);
    return i;
}


int main()
{
    char str1[20] = "abc";
    char str2[20] = "defg";

    printf("\nO tamanho da string: ");
    puts(str2);
    printf("eh: %d", StrLen(str2));

    return 0;
}

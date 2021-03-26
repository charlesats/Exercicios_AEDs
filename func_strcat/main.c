#include <stdio.h>
#include <stdlib.h>

void StrCat(char *destino, char *origem)
{

    int i, j;

    for (i = 0; destino[i] != '\0'; ++i);
    for (j = 0; origem[j] != '\0'; ++j, ++i)
    {
        destino[i] = origem[j];
    }
    destino[i] = '\0';
}


int main()
{
    char str1[20] = "abc";
    char str2[20] = "defg";

    printf("\nPrimeira string: ");
    puts(str1);
    printf("\nSegunda string: ");
    puts(str2);

    StrCat(str1, str2);
    printf("\nStrings concatenadas: ");
    puts(str1);

    return 0;
}

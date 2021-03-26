#include <stdio.h>
#include <stdlib.h>

/*retorna 1 (um) se a cadeia de caracteres t ocorrer no final da cadeia s, e 0 (zero)
 *caso contrário.
 */
int StrLen(char *string)
{

    int i;

    for (i = 0; string[i] != '\0'; ++i);
    return i;
}

int StrEnd(char *s, char *t)
{

    int a, i, x, y;

    a = 1;

    x = StrLen(s);
    y = StrLen(t);


    for (i = y; i > 0; i--, x--, y--)
    {
        if(s[x-1] != t[y-1])
        {
            return 0;
        }
    }
    return a;

}


int main()
{
    char str1[20] = "charles";
    char str2[20] = "les";

    printf("%d", StrEnd(str1,str2));

    return 0;
}

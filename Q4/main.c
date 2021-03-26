#include <stdio.h>
#include <stdlib.h>

typedef struct _record_
{
    float account;
    int count;
    char character;
}TStore;

TStore vp;

int main()
{
    TStore *p, *pt, *ptr;

    p = NULL;
    p =(TStore*)calloc(1,sizeof(TStore));
    p->account = 12.0;
    pt = p;
    vp = *pt;
    free(p);                                // ponteiro pt solto
    p =(TStore*)malloc(sizeof(TStore));
    p = &vp;                                // célulad de memória alocada foi perdida
    (*ptr).account = 0.988;                 // ponteiro ptr foi utilizado sem ser inicializado

    return 0;
}


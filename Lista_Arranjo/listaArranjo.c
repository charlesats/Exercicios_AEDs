#include "listaArranjo.h"

void FLVazia(TLista *pLista)
{
    pLista->primeiro = INICIO;
    pLista->ultimo = pLista->primeiro;
}


int LVazia(TLista *pLista)
{
    return(pLista->ultimo == pLista->primeiro);
}


int LInsere(TLista *pLista, TItem x)
{
    if(pLista->ultimo == MAXTAM)
        return 0; //Lista cheia
    pLista->item[pLista->ultimo++] = x;
    return 1;
}


int LRetira(TLista *pLista, TApontador p, TItem *pX)
{
    if(LVazia(pLista) || p >= pLista->ultimo)
        return 0;
    *pX = pLista->item[p];
    pLista->ultimo--;
    while(p < pLista->ultimo)
        pLista->item[p] = pLista->item[++p];
    return 1;
}


void LImprime(TLista *pLista)
{
    for(int i= pLista->primeiro; i < pLista->ultimo; i++)
        printf("%d\n", pLista->item[i].chave);
}

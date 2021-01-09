#include <stdio.h>
#include <stdlib.h>

#define INICIO 0
#define MAXTAM 1000

typedef int TChave;
typedef int TApontador;

typedef struct
{
    TChave chave;
    // outros componentes
}TItem;

typedef struct
{
    TItem item[MAXTAM];
    TApontador primeiro, ultimo;
}TLista;


void FLVazia(TLista *pLista);
int LVazia(TLista *pLista);
int LInsere(TLista *pLista, TItem x);
int LRetira(TLista *pLista, TApontador p, TItem *pX);
void LImprime(TLista *pLista);

int LMerge(TLista *pLista1, TLista *pLista2);
int LSplit(TLista *pLista);
int LCopy(TLista *pLista1, TLista *pLista2);
int LSort(TLista *pLista);
int LSearch(TLista *pLista, TChave c);

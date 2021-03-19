#include <stdlib.h>
#include <stdio.h>

#define MAX 10

typedef struct
{
    int codigo;
    //outros componentes
}TProduto;

typedef struct celula
{
    TProduto item;
    struct celula *prox;
}TCelula;

typedef struct
{
    TCelula *primeiro;
    TCelula *ultimo;
    int tamanho;
}TLista;

void FLVazia(TLista *Lista);
int Vazia(TLista Lista);
void Inserir(TProduto x, TLista *Lista);
TCelula Pesquisar(TLista Lista, TProduto Item);
void Excluir(TLista *Lista, TProduto *Item);
void Imprimir(TLista Lista);

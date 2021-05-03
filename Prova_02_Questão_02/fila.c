#include "fila.h"


void FFVazia(TFila *Fila)
{
    Fila->frente = (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int Vazia(TFila Fila)
{
    return (Fila.frente == Fila.tras);
}

void Enfileirar(TProduto x, TFila *Fila)
{
    Fila->tras->prox = (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void Desenfileirar(TFila *Fila, TProduto *Item)
{
    TCelula* aux;
    if (!Vazia(*Fila))
    {
        aux = Fila->frente->prox;
        Fila->frente->prox = aux->prox;
        *Item = aux->item;
        free(aux);
        if (Fila->frente->prox == NULL)
            Fila->tras = Fila->frente;
        Fila->tamanho--;
    }
}

/*
    Liberar memória do TAD Fila
*/
void LiberarFila(TFila *Fila)
{
    TProduto auxItem;
    while(!Vazia(*Fila))
    {
        Desenfileirar(Fila, &auxItem);
    }
    free(Fila->frente);
}

/*

Função Imprimir seguindo FIFO para Fila utilizando
uma fila auxiliar.

*/
void Imprimir(TFila *Fila)
{
    TFila FilaAux;
    FFVazia(&FilaAux);
    TProduto auxItem;
    // FIFO: desenfileirar da Fila original
    // e colocar todos elementos na Fila auxiliar
    while(!Vazia(*Fila))
    {
        Desenfileirar(Fila, &auxItem);
        //ImprimirProduto(auxItem);
        Enfileirar(auxItem, &FilaAux);
    }
    // FIFO: desenfileirar todos elementos da Fila
    // auxiliar e enfileirar na Fila original.
    while(!Vazia(FilaAux))
    {
        Desenfileirar(&FilaAux, &auxItem);
        Enfileirar(auxItem, Fila);
    }
    LiberarFila(&FilaAux);
}


void ImprimirFila(TFila *Fila)
{
    TProduto auxItem;
    int N;
    N = Fila->tamanho;
    while(N > 0)
    {
        Desenfileirar(Fila, &auxItem);
        ImprimirProduto(auxItem);
        Enfileirar(auxItem, Fila);
        N--;
    }
}

void ImprimirProduto(TProduto produto)
{
    printf("\nItem: %d", produto.codigo);
}

void RemoveProduto(TFila *Fila, int pos)
{
    int i=1;
    TProduto *Aux2;
    TFila FilaAux;
    FFVazia(&FilaAux);
    TProduto auxItem;
    while(!Vazia(*Fila))
    {
        Desenfileirar(Fila, &auxItem);
        if(i==pos)
        {
            Aux2 = &auxItem;
            Fila->frente = Fila->frente->prox->item;
            free(Aux2);
        }
        Enfileirar(auxItem, &FilaAux);
    }
    while(!Vazia(FilaAux))
    {
        Desenfileirar(&FilaAux, &auxItem);
        Enfileirar(auxItem, Fila);
    }
    LiberarFila(&FilaAux);
}

#ifndef FILA_H
#define FILA_H

#include <stdlib.h>
#include <stdio.h>


typedef struct item
{
    int codigo;
    /* outros campos */
} TProduto;

typedef struct celula
{
    TProduto item;
    struct celula* prox;
} TCelula;

typedef struct fila
{
    TCelula* frente;
    TCelula* tras;
    int tamanho;
} TFila;

void FFVazia(TFila *Fila);
int Vazia(TFila Fila);
void Enfileirar(TProduto x, TFila *Fila);
void Desenfileirar(TFila *Fila, TProduto *Item);
void LiberarFila(TFila *Fila);
void Imprimir(TFila *Fila);
void ImprimirFila(TFila *Fila);
void ImprimirProduto(TProduto produto);

void RemoveProduto(TFila *Fila, int pos);
#endif // FILA_H

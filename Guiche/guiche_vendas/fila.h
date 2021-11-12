#ifndef FILA_H
#define FILA_H

#include <stdlib.h>
#include <stdio.h>

#define MAX_PASSAGENS 10 //numero máximo de passagens
#define MAX_FILA 10//tamanho máximo da fila


typedef struct item
{
    int codigo;
    int num_passagem;
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
    int num_passagens;
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
void IntersecaoFilas(TFila *Fila1, TFila *Fila2, TFila *Fila3);
void DiferencaConjuntos(TFila *Fila1, TFila *Fila2, TFila *Fila3);

#endif

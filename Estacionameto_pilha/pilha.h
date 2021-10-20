#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM 10  /* define o tamanho máximo da pilha*/

typedef struct
{
    int carro; /* numero de identificação do carro*/
    int tempo; /* tempo de permanencia */
} TCarro;

typedef struct celula
{
    TCarro carro;
    struct celula* prox;
} TCelula;

typedef struct
{
    TCelula *fundo;
    TCelula *topo;
    int tamanho;
} TPilha;

void FPVazia(TPilha *Pilha);
int Vazia(TPilha Pilha);
void Empilhar(TCarro x,TPilha *Pilha);
void Desempilhar(TPilha *Pilha,TCarro *Carro);
void Imprimir(TPilha *Pilha);
void ImprimirCarro(TCarro Carro);
void Liberar(TPilha *Pilha);
int Tamanho(TPilha Pilha);
void RemoverCarro(TPilha *Pilha, int excluir);

#endif // PILHA_H

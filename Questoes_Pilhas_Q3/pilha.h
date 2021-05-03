#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct {
  int codigo;
  /* outros componentes */
} TProduto;

typedef struct celula {
  TProduto item;
  struct celula* prox;
} TCelula;

typedef struct {
  TCelula *fundo;
  TCelula *topo;
  int tamanho;
} TPilha;

void FPVazia(TPilha *Pilha);
int Vazia(TPilha Pilha);
void Empilhar(TProduto x,TPilha *Pilha);
void Desempilhar(TPilha *Pilha,TProduto *Item);
void Imprimir(TPilha *Pilha);
void Liberar(TPilha *Pilha);
int Tamanho(TPilha Pilha);

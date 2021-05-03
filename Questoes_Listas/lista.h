#include <stdlib.h>
#include <stdio.h>
#define MAX 10


typedef struct {
  int codigo;
  /*
     outros componentes
     de produto
  */
} TProduto;

typedef struct celula {
  TProduto item;
  struct celula* prox;
} TCelula;

typedef struct {
  TCelula* primeiro;
  TCelula* ultimo;
  int tamanho;
} TLista;

void FLVazia(TLista *Lista);
int Vazia(TLista Lista);
void Inserir(TProduto x, TLista *Lista);
void InserirOrdenado(TProduto Item, TLista *Lista);
TCelula* Pesquisar(TLista Lista, TProduto Item);
void Excluir(TLista *Lista, TProduto *Item);
void Imprimir(TLista Lista);
void ImprimirCelula(TLista Lista, int pos);
void ComparaListas(TLista Lista1, TLista Lista2);
void ConcatenaListas(TLista *Lista1, TLista Lista2);


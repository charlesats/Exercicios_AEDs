#include "lista.h"

void FLVazia(TLista *Lista)
{
    Lista->primeiro = (TCelula *)malloc(sizeof(TCelula));
    Lista->ultimo = Lista->primeiro;
    Lista->primeiro->prox = NULL;
    Lista->tamanho = 0;
}

int Vazia(TLista Lista)
{
    return (Lista.primeiro == Lista.ultimo);
}

void Inserir(TProduto x, TLista *Lista)
{
    Lista->ultimo->prox = (TCelula *)malloc(sizeof(TCelula));
    Lista->ultimo = Lista->ultimo->prox;
    Lista->ultimo->item = x;
    Lista->ultimo->prox = NULL;
    Lista->tamanho++;
}

TCelula *Pesquisar(TLista Lista, TProduto Item)
{
   TCelula *Aux;
   Aux = Lista.primeiro;
   while(Aux->prox != NULL){
      if(Aux->prox->item.codigo == Item.codigo)
         return Aux;
      Aux = Aux->prox;
   }
   return NULL;
}

void Alterar(TLista *Lista, TProduto ItemA, TProduto ItemB)
{
    TCelula *Aux;
    Aux = Pesquisar(*Lista, ItemA);
    Aux->prox->item = ItemB;
}

void Excluir(TLista *Lista, TProduto *Item)
{
    /* --- obs.: o item a ser retirado é o seguinte ao apontado por p ---*/
    TCelula *Aux1, *Aux2;
    Aux1 = Pesquisar(*Lista, *Item);
    if(Aux1 != NULL)
    {
        Aux2 = Aux1->prox;
        Aux1->prox = Aux2->prox;
        *Item = Aux2->item;
        if(Aux1->prox == NULL)
            Lista->ultimo = Aux1;
        free(Aux2);
        Lista->tamanho--;
    }
}

void Imprimir(TLista Lista)
{
    TCelula *Aux;
    Aux = Lista.primeiro->prox;
    while(Aux != NULL)
    {
        printf("%d\n", Aux->item.codigo);
        Aux = Aux->prox;
    }
}

void Liberar(TLista *Lista)
{
    TCelula *Aux1 = Lista->primeiro;
    TProduto *Item;

    while(Lista->primeiro != NULL)
    {
        Lista->primeiro = Lista->primeiro->prox;
        Item = &Aux1->item;
        Excluir(Lista, Item);
        Aux1 = Lista->primeiro;
    }
}

#include "lista.h"


void FLVazia(TLista *Lista)
{
    Lista -> primeiro = (TCelula *) malloc(sizeof(TCelula));
    Lista -> ultimo = Lista -> primeiro;
    Lista -> primeiro -> prox = NULL;
    Lista -> tamanho = 0;
}

int Vazia(TLista Lista)
{
    return (Lista.primeiro == Lista.ultimo);
}

void Inserir(TProduto Item, TLista *Lista)
{
    if(Vazia(*Lista) || (Item.codigo >= Lista->ultimo->item.codigo))
    {
        Lista -> ultimo -> prox = (TCelula *) malloc(sizeof(TCelula));
        Lista -> ultimo = Lista -> ultimo -> prox;
        Lista -> ultimo -> item = Item;
        Lista -> ultimo -> prox = NULL;
        Lista -> tamanho++;
    }
    else
    {
        InserirOrdenado(Item, Lista);
    }
}

void InserirOrdenado(TProduto Item, TLista *Lista)
{
    TCelula* Aux1;
    TCelula* Aux2;

    Aux1 = Lista->primeiro;
    Aux2 = (TCelula *) malloc(sizeof(TCelula));
    Aux2->item = Item;

    while(Lista->primeiro->prox->item.codigo <= Item.codigo)
    {
            Lista->primeiro->prox = Lista->primeiro->prox->prox;
    }

    Aux2->prox = Lista->primeiro->prox;
    Lista->primeiro->prox = Aux2;
    Lista->primeiro = Aux1;

    Lista -> tamanho++;
}

TCelula* Pesquisar(TLista Lista, TProduto Item)
{
    TCelula* Aux;
    Aux = Lista.primeiro;
    while(Aux->prox != NULL)
    {
        if(Aux->prox->item.codigo == Item.codigo)
            return Aux;
        Aux = Aux->prox;
    }
    return NULL;
}

void Excluir(TLista *Lista, TProduto *Item)
{
    /* Obs.: o item a ser retirado e o apontado por p */
    TCelula *Aux1, *Aux2;
    Aux1 = Pesquisar(*Lista, *Item);
    if (Aux1 != NULL)
    {
        Aux2 = Aux1->prox;
        Aux1->prox = Aux2 -> prox;
        *Item = Aux2->item;
        if (Aux1->prox == NULL)
            Lista->ultimo = Aux1;
        free(Aux2);
        Lista->tamanho--;
    }
}

void Imprimir(TLista Lista)
{
    TCelula* Aux;
    int i=1;
    Aux = Lista.primeiro -> prox;
    while (Aux != NULL)
    {
        printf("\nCodigo Item %d: %d\n", i, Aux->item.codigo);
        Aux = Aux -> prox;
        i++;
    }
}

void ComparaListas(TLista Lista1, TLista Lista2)
{
    TCelula* Aux1;
    TCelula* Aux2;
    Aux1 = Lista1.primeiro->prox;
    Aux2 = Lista2.primeiro->prox;
    int x=1;

    while(Aux1 != NULL || Aux2 != NULL)
    {
        if(Aux1->item.codigo != Aux2->item.codigo)
        {
            x=0;
        }
        Aux1=Aux1->prox;
        Aux2=Aux2->prox;
    }
    if(x==0)
        printf("\nAs Listas sao Diferentes!!!\n");
    else
        printf("\nAs Listas sao Iguais!!!\n");
}

void ConcatenaListas(TLista *Lista1, TLista Lista2)
{
    Lista1->ultimo->prox = Lista2.primeiro->prox;
}

void ImprimirCelula(TLista Lista, int pos)
{
    int i;
    TCelula *Aux;
    Aux = Lista.primeiro;
    if(pos<=Lista.tamanho)
    {
        for(i=0; i<pos; i++)
        {
            Aux = Aux->prox;
        }
        printf("\n\n\nCodigo Item %d: %d\n", i, Aux->item.codigo);
    }
    else
        printf("\nCelula nao existe");
}

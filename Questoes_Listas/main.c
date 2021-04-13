#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    int i;
    TLista Lista1, Lista2;
    TProduto Item;



    FLVazia(&Lista1);
    FLVazia(&Lista2);

    for(i=0;i<5;i++)
    {
        printf("\nInsira um codigo: ");
        scanf("%d", &Item.codigo);
        Inserir(Item, &Lista1);
    }
    /*for(i=0;i<5;i++)
    {
        printf("\nInsira um codigo: ");
        scanf("%d", &Item.codigo);
        Inserir(Item, &Lista2);
    }*/

    printf("\n");

    printf("\nLista 1: \n");
    Imprimir(Lista1);
    //printf("\nLista 2: \n");
    //Imprimir(Lista2);

    //printf("\n");
    //Excluir(&Lista1, &Lista1.primeiro->prox->prox->prox->item);
    //Excluir(&Lista1, &Lista1.primeiro->prox->item);
    //Excluir(&Lista1, &Lista1.primeiro->prox->prox->item);
    //Excluir(&Lista1, &Lista1.primeiro->prox->item);
    //printf("\nItens Excluidos da Lista 1!!! \n");

    ConcatenaListas(&Lista1, Lista2);
    printf("\nLista 1: \n");
    Imprimir(Lista1);
    //printf("\nLista 2: \n");
    //Imprimir(Lista2);

    //ComparaListas(Lista1, Lista2);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main()
{
    TLista Lista1;
    TProduto Item;

    FLVazia(&Lista1);

    printf("\nInsira um codigo: ");
    scanf("%d", &Item.codigo);
    Inserir(Item, &Lista1);

    printf("\nInsira um codigo: ");
    scanf("%d", &Item.codigo);
    Inserir(Item, &Lista1);

     printf("\nInsira um codigo: ");
    scanf("%d", &Item.codigo);
    Inserir(Item, &Lista1);

    printf("\n\nLista:");
    Imprimir(Lista1);

    printf("\n\nItem a ser removido: ");
    ImprimirCelula(Lista1, 3); //Imprime o segundo item da lista

    RemoveCelula(&Lista1, 3);
    printf("\n\nItem removido!");

    printf("\n\nLista Atual:");
    Imprimir(Lista1);

    return 0;
}

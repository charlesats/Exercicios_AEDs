#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

int main()
{
    TFila Fila;
    TProduto produto;

    FFVazia(&Fila);

    printf("\nInsira um produto: ");
    scanf("%d", &produto.codigo);
    Enfileirar(produto, &Fila);

    printf("\nInsira um produto: ");
    scanf("%d", &produto.codigo);
    Enfileirar(produto, &Fila);

    printf("\nInsira um produto: ");
    scanf("%d", &produto.codigo);
    Enfileirar(produto, &Fila);

    printf("\n\nFila: \n");
    ImprimirFila(&Fila);

    RemoveProduto(&Fila, 0);


    printf("\n\nFila: \n");
    ImprimirFila(&Fila);

    return 0;
}

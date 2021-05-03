#include "fila.h"


void FFVazia(TFila *Fila)
{
    Fila->frente =
        (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}

int Vazia(TFila Fila)
{
    return (Fila.frente == Fila.tras);
}

void Enfileirar(TProduto x, TFila *Fila)
{
    Fila->tras->prox =
        (TCelula*) malloc(sizeof(TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}

void Desenfileirar(TFila *Fila, TProduto *Item){
    TCelula* aux;
    if (!Vazia(*Fila)){
        aux = Fila->frente->prox;
        Fila->frente->prox = aux->prox;
        *Item = aux->item;
        free(aux);
        if (Fila->frente->prox == NULL)
            Fila->tras = Fila->frente;
        Fila->tamanho--;
    }
}

/*
    Liberar memória do TAD Fila
*/
void LiberarFila(TFila *Fila){
    TProduto auxItem;
    while(!Vazia(*Fila)){
        Desenfileirar(Fila, &auxItem);
    }
    free(Fila->frente);
}

/*

Função Imprimir seguindo FIFO para Fila utilizando
uma fila auxiliar.

*/
void Imprimir(TFila *Fila){
    TFila FilaAux;
    FFVazia(&FilaAux);
    TProduto auxItem;
    // FIFO: desenfileirar da Fila original
    // e colocar todos elementos na Fila auxiliar
    while(!Vazia(*Fila)){
        Desenfileirar(Fila, &auxItem);
        //ImprimirProduto(auxItem);
        Enfileirar(auxItem, &FilaAux);
    }
    // FIFO: desenfileirar todos elementos da Fila
    // auxiliar e enfileirar na Fila original.
    while(!Vazia(FilaAux)){
        Desenfileirar(&FilaAux, &auxItem);
        Enfileirar(auxItem, Fila);
    }
    LiberarFila(&FilaAux);
}

/*

Função Imprimir seguindo FIFO para Fila "sem o uso"
de uma fila auxiliar.

*/
void ImprimirFila(TFila *Fila){
    TProduto auxItem;
    int N;
    N = Fila->tamanho;
    while(N > 0){
        Desenfileirar(Fila, &auxItem);
        ImprimirProduto(auxItem);
        Enfileirar(auxItem, Fila);
        N--;
    }
}

void ImprimirProduto(TProduto produto)
{
    printf("\nItem: %d", produto.codigo);
}

void RemoveProduto(TFila *Fila, int pos)
{
    int i=1;
    TFila FilaAux;
    FFVazia(&FilaAux);
    TProduto auxItem;
    while(!Vazia(*Fila))
    {
        Desenfileirar(Fila, &auxItem);
        if(i!=pos)
        {
            Enfileirar(auxItem, &FilaAux);
        }
        i++;
    }
    while(!Vazia(FilaAux))
    {
        Desenfileirar(&FilaAux, &auxItem);
        Enfileirar(auxItem, Fila);
    }
    LiberarFila(&FilaAux);
}

void IntersecaoFilas(TFila *Fila1, TFila *Fila2, TFila *Fila3)
{
    TProduto Aux1, Aux2, Aux3;
    TFila FilaAux1, FilaAux2, FilaAux3;

    FFVazia(&FilaAux1);
    FFVazia(&FilaAux2);
    FFVazia(&FilaAux3);

    while(!Vazia(*Fila1))
    {
        Desenfileirar(Fila1, &Aux1);
        Enfileirar(Aux1, &FilaAux1);

        if(Aux1.codigo == Aux2.codigo)
        {
            int boolean = 0;

            while(!Vazia(*Fila3))
            {
                Desenfileirar(Fila3, &Aux3);
                Enfileirar(Aux1, &FilaAux1);

                if(Aux2.codigo == Aux3.codigo)
                {
                    boolean = 1;
                    break;

                }
                while(!Vazia(FilaAux3))
                {
                    Desenfileirar(&FilaAux3, &Aux3);
                    Enfileirar(Aux1, &FilaAux1);
                }

                if(!boolean) // se boolean == 0
                {
                    Enfileirar(Aux1, &FilaAux1);
                }
            }
        }
        while(!Vazia(FilaAux2))
        {
            Desenfileirar(&FilaAux2, &Aux2);
            Enfileirar(Aux1, &FilaAux1);
        }
    }
    while(!Vazia(FilaAux1))
    {
        Desenfileirar(&FilaAux1, &Aux1);
        Enfileirar(Aux1, &FilaAux1);
    }
}

void DiferencaConjuntos(TFila *Fila1, TFila *Fila2, TFila *Fila3)
{
    if(Fila1->tamanho == 0 || Fila2->tamanho == 0)
        return;

    TFila FilaAux1, FilaAux2;
    TProduto Aux1, Aux2;

    FFVazia(&FilaAux1);
    FFVazia(&FilaAux2);

    while(!Vazia(*Fila1))
    {
        int boolean = 0;

        Desenfileirar(Fila1, &Aux1);
        Enfileirar(Aux1, &FilaAux1);;

        while(!Vazia(*Fila2))
        {
            Desenfileirar(Fila2, &Aux2);
            Enfileirar(Aux1, &FilaAux1);

            if(Aux2.codigo == Aux1.codigo)
            {
                boolean = 1;
            }
        }

        if(!boolean)
        {
            Enfileirar(Aux1, &FilaAux1);
        }

        while (!Vazia(FilaAux2))
        {
            Desenfileirar(&FilaAux2, &Aux2);
            Enfileirar(Aux1, &FilaAux1);
        }
    }
    while(!Vazia(FilaAux1))
    {
        Desenfileirar(&FilaAux1, &Aux1);
        Enfileirar(Aux1, &FilaAux1);
    }
}

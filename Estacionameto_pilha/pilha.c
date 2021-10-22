#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "pilha.h"


void FPVazia(TPilha *Pilha)
{
    Pilha->topo = (TCelula*)malloc(sizeof(TCelula));
    Pilha->fundo = Pilha->topo;
    Pilha->topo->prox = NULL;
    Pilha->tamanho = 0;
}

int Vazia(TPilha Pilha)
{
    return (Pilha.topo == Pilha.fundo);
}

void Empilhar(TCarro x,TPilha *Pilha)
{
    if(Pilha->tamanho < MAXTAM)
    {
        TCelula* Aux;
        Aux = (TCelula*)malloc(sizeof(TCelula));
        Pilha->topo->carro = x;
        Aux->prox = Pilha->topo;
        Pilha->topo = Aux;
        Pilha->tamanho++;
    }else
    {
        printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<");
        printf("\n\t> ESTACIONAMENTO CHEIO!!                     <\n");
        printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<");
    }
}

void Desempilhar(TPilha *Pilha,TCarro *Carro)
{
    TCelula* q;
    if (Vazia(*Pilha))
    {
        printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<");
        printf("\n\t> ESTACIONAMENTO VAZIO!!                     <\n");
        printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<");
        return;
    }
    q = Pilha->topo;
    Pilha->topo = q->prox;
    *Carro = q->prox->carro;
    free(q);
    Pilha->tamanho--;
}

void Imprimir(TPilha *Pilha)
{
    TPilha PilhaAux;
    FPVazia(&PilhaAux);

    TCarro Carro;

    // Pop de PIlha e Push em Pilha auxiliar
    while(!Vazia(*Pilha))
    {
        Desempilhar(Pilha, &Carro);
        Empilhar(Carro, &PilhaAux);
    }

    while(!Vazia(PilhaAux))
    {
        Desempilhar(&PilhaAux, &Carro);
        ImprimirCarro(Carro);// realizar a impressão de cada campo do Carro
        Empilhar(Carro, Pilha);
    }
    free(PilhaAux.topo);// eliminar a célula cabeça
}

void RemoverCarro(TPilha *Pilha, int excluir)
{
    TPilha PilhaAux;
    FPVazia(&PilhaAux);
    int cont = 0;


    TCarro Carro;

    // Pop de PIlha e Push em Pilha auxiliar
    while(!Vazia(*Pilha))
    {
        Desempilhar(Pilha, &Carro);
        if(Carro.carro != excluir)
        {
            Empilhar(Carro, &PilhaAux);
            cont++;
        }else
            break;
    }

    while(!Vazia(PilhaAux))
    {
        Desempilhar(&PilhaAux, &Carro);
        //ImprimirCarro(Carro);// realizar a impressão de cada campo do Carro
        Empilhar(Carro, Pilha);
    }
    free(PilhaAux.topo);// eliminar a célula cabeça
    printf("\n\n\t>>>> O carro %d foi removido!!                     <<<<\n", excluir);
    printf("\n\n\t>>>> Foram realizadas %d manobras!!                <<<<\n", cont);
}


void Liberar(TPilha *Pilha)
{
    TCarro Carro;
    while(!Vazia(*Pilha))
    {
        Desempilhar(Pilha, &Carro);
    }
    free(Pilha->topo);
}

int Tamanho(TPilha Pilha)
{
    return (Pilha.tamanho);
}

void ImprimirCarro(TCarro Carro)
{

    printf("\n\n\t>>>> Carro: %d\t Tempo de permanencia: %d\t Total a pagar R$%.2f   <\n", Carro.carro, Carro.tempo, Carro.tempo*TARIFA);

}








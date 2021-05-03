#include "ordenacao.h"

void Imprimir(int vet[18], int TAM)
{
    int i;
            printf("\n");
            for(i = 0; i < TAM; i++){
            printf(" [ %c ]", vet[i]);
            }
            printf("\n");
}


//Shellsort
void ShellSort(int *vet, int TAM) {
    int i, j, k;
    int letra;

    int h = 1;
    while(h < TAM) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < TAM; i++) {
            letra = vet[i];
            j = i;

            while (j > h-1 && letra <= vet[j - h]) {
                vet[j] = vet[j - h];
                j = j - h;

            }
            vet[j] = letra;
            Imprimir(vet, 18);
        }
        h = h/3;
    }

}

// Quicksort
int Particao(int  *vet, int p, int r){
    int i, j, x, aux;
    x = vet[r];
    i = p - 1;
    for(j = p; j < r; j++){
        if (vet[j] <= x){
            i = i + 1;
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
        }
    }
    aux = vet[i + 1];
    vet[i + 1] = vet[r];
    vet[r] = aux;

    return i + 1;
}


void Quicksort(int *vet, int p, int r){
    int q;
    if(p < r){
        q = Particao(vet, p, r);
        Quicksort(vet, p, q - 1);
        Quicksort(vet, q + 1, r);

         Imprimir(vet, 18);
    }
}


//Heapsort
/*
void Heapsort(int *A, int *n)
{
    int esq, dir;
    int x;
    constroi(A, n);
    esq = 1;
    dir = n;

    while(dir > 1)
    {
        x = A[1];
        A[1] = A[dir];
        A[dir] = x;
        dir--;
        refaz(A, esq, dir);
    }
}

void insere(int* A, int* n, int* x)
{
    (*n)++;
    A[*n] = *x;
    A[*n] = INT_MIN;
    aumentaChave(A, *n, x->chave);
}

void aumentaChave(int* A, int i, int novo)
{
    int aux;
    if(novo < A[i].chave)
    {
        printf(“Erro: Chave Nova menor que a chave atual”);
        return;
    }

    A[i].chave = novo;
    while( i > 1 && A[i/2].chave < A[i].chave )
    {
        aux = A[i/2];
        A[i/2] = A[i];
        A[i] = aux;
        i /= 2;
    }
}

int retiraMax(int *A, int *n)
{
    int max;
    if (*n < 1) printf(“Erro: heap vazio\n”);
    else
    {
        max = A[1];
        A[1] = A[*n];
        (*n)--;
        refaz(A, 1, *n);
    }
    return max;
}

void constroi(int *A, int *n)
{
    int esq = *n / 2;
    while(esq > 0)
    {
        refaz(A, esq, *n);
        esq--;
    }
}

void refaz(int* A, int esq, int dir)
{
    int i = esq, j = i*2;
    int aux = A[i];
    while( j <= dir )
    {
        if( j < dir )
            if( A[j].chave < A[j+1].chave ) j++;
        if( aux.chave >= A[j].chave ) break;
        A[i] = A[j];
        i = j;
        j = i*2;
    }
    A[i] = aux;
}

int max(int *A)
{
    return (A[1]);
}

*/

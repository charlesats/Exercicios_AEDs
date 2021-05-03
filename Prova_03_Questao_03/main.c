#include <stdio.h>
#include <stdlib.h>

int Particao(int  *vet, int p, int r);
void Quicksort(int *vet, int p, int r);
void Imprimir(int vet[], int TAM);

int main()
{
    int vetor[] = {'A','B','C','D','E','Z','G','H','I','J','G','L'};
    Quicksort(&vetor, 0, 11);
    return 0;
}


int Particao(int  *vet, int p, int r)
{
    int i = p, j = r;
    int q = (p + r)/2;
    do
    {
        while (vet[i] < vet[q]) ++i;
        while (vet[j] > vet[q]) --j;
        if (i <= j)
        {
            int t = vet[i];
            vet[i] = vet[j];
            vet[j] = t;
            ++i;
            --j;
        }
    }
    while (i <= j);
    return i;
}


void Quicksort(int *vet, int p, int r)
{
    int q;
    if(p < r)
    {
        q = Particao(vet, p, r);
        Quicksort(vet, p, q - 1);
        Quicksort(vet, q + 1, r);

        Imprimir(vet, 12);
    }
}

void Imprimir(int vet[], int TAM)
{
    int i;
    printf("\n");
    for(i = 0; i < TAM; i++)
    {
        printf(" [ %c ]", vet[i]);
    }
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>

void Insercao(int *A, int n);

int main()
{
    int vet[] = {2,3,4,5,6,7,8,9,10,1};
    int i;

    for(i=0; i<10; i++)
    {
        printf("%d\t", vet[i]);
    }
    Insercao(vet, 10);
    printf("\n\n");
    for(i=0; i<10; i++)
    {
        printf("%d\t", vet[i]);
    }
    return 0;
}

void Insercao(int *A, int n){
  int i, j, x;
  for (j = 1; j < n; ++j) {
      x = A[j];
      for (i = j-1; i >= 0 && A[i] > x; --i)
         A[i+1] = A[i];
      A[i+1] = x;
   }
}

int buscaBinaria(int vet[], int tam, int chave)
{
    int posIni=0, posFim=tam-1, posMeio;
    while(posIni <= posFim)
    {
        posMeio = (posIni+posFim)/2;
        if(vet[posMeio] == chave)
            return posMeio;
        else if(vet[posMeio] > chave)
            posFim = posMeio - 1;
        else
            posIni = posMeio + 1;
    }
    return -1;
}


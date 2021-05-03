#ifndef ORDENACAO_H
#define ORDENACAO_H



void Imprimir(int vet[], int TAM);

//Shellsort
void ShellSort(int *vet, int TAM);

//Quicksort
void Quicksort(int *vet, int p, int r);
int Particao(int  *vet, int p, int r);

//Heapsort
void Heapsort(int *A, int *n);
void insere(int* A, int* n, int* x);
void aumentaChave(int* A, int i, int novo);
int retiraMax(int *A, int *n);
void constroi(int *A, int *n);
void refaz(int* A, int esq, int dir);
int max(int *A);


#endif

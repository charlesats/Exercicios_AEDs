#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"


int main()
{
    int i;
    int vet[] = {'C','H','A','R','L','E','S','A','S','S','I','S','T','S','I','L','V','A'};

    printf("\nOdenacao por Shellsort\n\n");
    ShellSort(&vet, 18);
    //Quicksort(&vet, 0, 17);

    return 0;
}

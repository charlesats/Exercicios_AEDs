#include "exercicios.h"

int MaisAmigos(TRedeSocial rede)
{
    int i, maior = 0, indiceMaisAmigos;

    for(i=0; i<rede.indice; i++)
    {
        if(rede.vetor[i].total_amigos > maior)
        {
            maior = rede.vetor[i].total_amigos;
            indiceMaisAmigos = i;
        }
    }

    if(maior > 0)
        return indiceMaisAmigos;
    return -1;
}

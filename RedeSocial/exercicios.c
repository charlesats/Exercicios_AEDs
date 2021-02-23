#include "exercicios.h"
#include "amizade.h"

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

int AmigosEmComum(TRedeSocial rede, int id1, int id2)
{
    int i, qtd = 0;

    for(i=0; i< rede.indice; i++)
    {
        if((rede.matrix[id1][i] == 1) && (rede.matrix[id2][i] == 1))
            qtd++;
    }
    return qtd;
}

int AmizadeIndireta1(TRedeSocial rede, TUsuarios userA, TUsuarios userB)
{
    return 0;
}

void MatrizAmigosEmComum(TRedeSocial *rede)
{
    int linha, coluna;

    //Gerar a matriz de amizades em comum
    for(linha = 0; linha < rede->indice; linha++)
    {
        for(coluna = 0; coluna < rede->indice; coluna++)
        {
            if(linha != coluna)
                rede->matriz_amizades_em_comum[linha][coluna] = AmigosEmComum(*rede, linha, coluna);
        }
    }

    //Teste, imprime a matriz de amizades em comum
    for(linha = 0; linha < rede->indice; linha++)
    {
        printf("\n");
        for(coluna = 0; coluna < rede->indice; coluna++)
        {
            printf("%d ", rede->matriz_amizades_em_comum[linha][coluna]);
        }
    }
    printf("\n\n");
}

void SemAmigosEmComum(TRedeSocial rede, TUsuarios userA, TUsuarios userB)
{
    int i, j, k;

    i = Pesquisar(rede, userA);

    if(i>=0)
    {
        j = Pesquisar(rede, userB);

        if(j>=0)
        {
            k = PesquisarAmizades(rede, userA, userB);

            MatrizAmigosEmComum(&rede);



            if((k == 0) && (rede.matriz_amizades_em_comum[i][j] == 0))
            {
                printf("\n\n\t>>>>>>    MSG: Os usuários não possuem amigos em comum!    <<<<<<\n\n");
            }
            else
                printf("\n\n\t>>>>>>    MSG: Os usuários possuem %d amigos em comum!    <<<<<<\n\n", rede.matriz_amizades_em_comum[i][j]);
        }


    }
    else
        printf("\n\n\t>>>>>>    MSG: Os usuários não foram encontrados na rede!!!    <<<<<<\n\n");

}

void AmizadeIndireta2(TRedeSocial rede, TUsuarios userA, TUsuarios userB, int *id1, int *id2)
{

}

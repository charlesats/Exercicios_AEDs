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
    /*for(linha = 0; linha < rede->indice; linha++)
    {
        printf("\n");
        for(coluna = 0; coluna < rede->indice; coluna++)
        {
            printf("%d ", rede->matriz_amizades_em_comum[linha][coluna]);
        }
    }*/
    printf("\n\n");
}

void SemAmigosEmComum(TRedeSocial rede, TUsuarios userA, TUsuarios userB)
{
    int i, j, k;

    i = Pesquisar(rede, userA);
    j = Pesquisar(rede, userB);

    k = PesquisarAmizades(rede, userA, userB);

    MatrizAmigosEmComum(&rede);



    if((k == 0) && (rede.matriz_amizades_em_comum[i][j] == 0))
    {
        printf("\n\n\t> Os usuários %s e %s não possuem amigos em comum!\n\n", userA.nome, userB.nome);
    }
    else
        printf("\n\n\t> Os usuários %s e %s possuem %d amigos em comum!\n\n", userA.nome, userB.nome, rede.matriz_amizades_em_comum[i][j]);
}

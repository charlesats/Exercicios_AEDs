#include "amizade.h"

int PesquisarAmizades(TRedeSocial rede, TUsuarios userA, TUsuarios userB)
{

    int i, j;

    i = Pesquisar(rede, userA);

    if(i>=0)
    {
        system("cls");
        j = Pesquisar(rede, userB);

        if(j>=0)
        {
            if((rede.matrix[i][j] == 1) && (rede.matrix[j][i] == 1))
                return 1;
            return 0;
        }
        else
        {
            printf("\n\n >>>>>>    MSG: O segundo usu�rio n�o est� na rede!    <<<<<<\n\n");
            system("PAUSE");
            return -1;
        }
    }
    else
    {
        printf("\n\n >>>>>>    MSG: O primeiro usu�rio n�o est� na rede!    <<<<<<\n\n");
        system("PAUSE");
        return -1;
    }
}

void CadastrarAmizades(TRedeSocial *rede, TUsuarios userA, TUsuarios userB)
{
    rede->matrix[userA.ID][userB.ID] = 1;
    rede->vetor[userA.ID].total_amigos++;
    rede->matrix[userB.ID][userA.ID] = 1;
    rede->vetor[userB.ID].total_amigos++;
    printf("\n\n >>>>>> MSG: As amizades foram cadastradas! <<<<<<\n\n");
}

void ExcluirAmizades(TRedeSocial *rede, TUsuarios userA, TUsuarios userB)
{
    rede->matrix[userA.ID][userB.ID] = 0;
    rede->vetor[userA.ID].total_amigos --;
    rede->matrix[userB.ID][userA.ID] = 0;
    rede->vetor[userB.ID].total_amigos --;
    printf("\n\n >>>>>> MSG: As amizades foram desfeitas! <<<<<<\n\n");
}

void ImprimirListaAmigos(TRedeSocial rede, TUsuarios user)
{
    int i, j;
    system("cls");

    i = Pesquisar(rede, user);

    if(i>=0)
    {
        for(j=0; j<rede.indice; j++)
        {
            if(rede.matrix[i][j] == 1)
                Imprimir(rede.vetor[j]);
        }
    }
    else
    {
        printf("\n\n >>>>>> MSG: O usu�rio n�o est� na rede!    <<<<<<\n\n");
        printf("\n\n >>>>>> MSG: N�o foi poss�vel imprimir a lista de amigos! <<<<<<\n\n");
    }
}

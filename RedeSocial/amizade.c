#include "amizade.h"

int PesquisarAmizades(TRedeSocial rede, TUsuarios userA, TUsuarios userB)
{

    if((rede.matrix[userA.ID][userB.ID] == 1) && (rede.matrix[userB.ID][userA.ID] == 1))
        return 1;
    else
        return 0;
}

void CadastrarAmizades(TRedeSocial *rede, TUsuarios userA, TUsuarios userB)
{
    rede->matrix[userA.ID][userB.ID] = 1;
    rede->matrix[userB.ID][userA.ID] = 1;
    printf("\n\n >>>>>> MSG: As amizades foram cadastradas! <<<<<<\n\n");
}

void ExcluirAmizades(TRedeSocial *rede, TUsuarios userA, TUsuarios userB)
{
    rede->matrix[userA.ID][userB.ID] = 0;
    rede->matrix[userB.ID][userA.ID] = 0;
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
        printf("\n\n >>>>>> MSG: O usuário não está na rede!    <<<<<<\n\n");
        printf("\n\n >>>>>> MSG: Não foi possível imprimir a lista de amigos! <<<<<<\n\n");
    }
}

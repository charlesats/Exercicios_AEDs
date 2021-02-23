#include "interface.h"

void MSG_REDE()
{
    printf("\n\n\t  AAA	EEEEEEE	DDDDD    SSSSS	");
    printf("\n\t AAAAA	EEEEEEE	DDDDDD  SSSSSSS");
    printf("\n\tAA   AA	EE	DD   DD SS");
    printf("\n\tAAAAAAA	EEEEEEE	DD   DD SSSSSS");
    printf("\n\tAAAAAAA	EEEEEEE	DD   DD  SSSSSS");
    printf("\n\tAA   AA	EE	DD   DD      SS");
    printf("\n\tAA   AA	EEEEEEE	DDDDDD   SSSSSS");
    printf("\n\tAA   AA	EEEEEEE	DDDDD   SSSSSS");
    printf("\n\t                   REDE SOCIAL\n\n");
}
void MSG_MENU()
{
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>    MENU:   <<<<<<<<<<<<<<<<<<<");
    printf("\n\t> 1. M�DULO 1 - GERENCIAMENTO DE USU�RIOS        <");
    printf("\n\t> 2. M�DULO 2 - GERENCIAMENTO DE AMIZADES        <");
    printf("\n\t> 3. M�DULO 3 - EXERC�CIOS                       <");
    printf("\n\t> 4. SAIR                                        <");
    printf("\n\t>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<");
}

void MSG_SUBMENU(int numero_modulo)
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>    M�DULO %d    <<<<<<<<<<<<<<<<<", numero_modulo);
    printf("\n\t> 1. CADASTRAR                                   <");
    printf("\n\t> 2. PESQUISAR                                   <");
    printf("\n\t> 3. ALTERAR                                     <");
    printf("\n\t> 4. EXCLUIR                                     <");
    printf("\n\t> 5. IMPRIMIR                                    <");
    printf("\n\t> 6. SAIR                                        <");
    printf("\n\t>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<");
}

void MSG_SUBMENU2(int numero_modulo)
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>    M�DULO %d    <<<<<<<<<<<<<<<<<", numero_modulo);
    printf("\n\t> 1. CADASTRAR AMIZADES                          <");
    printf("\n\t> 2. PESQUISAR AMIZADES                          <");
    printf("\n\t> 3. EXCLUIR AMIZADES                            <");
    printf("\n\t> 4. IMPRIMIR A LISTA DE AMIGOS                  <");
    printf("\n\t> 5. SAIR                                        <");
    printf("\n\t>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<");

}

void MSG_SUBMENU3(int numero_modulo)
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>    M�DULO %d    <<<<<<<<<<<<<<<<<", numero_modulo);
    printf("\n\t> 1. USU�RIO COM MAIS AMIZADES                   <");
    printf("\n\t> 2. AMIZADES EM COMUM                           <");
    printf("\n\t> 3. MATRIZ DE AMIGOS EM COMUM                   <");
    printf("\n\t> 4. NENHUM AMIGO EM COMUM                       <");
    printf("\n\t> 5. AMIZADE INDIRETA DE UM N�VEL                <");
    printf("\n\t> 6. AMIZADE INDIRETA DE DOIS N�VEIS             <");
    printf("\n\t> 7. SAIR                                        <");
    printf("\n\t>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<");

}

void SubMenuModulo1(TRedeSocial *rede, TUsuarios user)
{
    int i;
    int opcao = 0;

    do
    {
        MSG_SUBMENU(1);
        printf("\n\n\t>>>>>>>>>>>>>    Digite uma op��o:    <<<<<<<<<<<<\n\t>");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
        {
            system("cls");
            printf("\n\n\t>>>>>>>>     MSG: Cadastre um usu�rio:    <<<<<<<<\n\n");
            Ler(&user);
            Cadastrar(rede, user);
            system("PAUSE");
        }
        break;
        case 2:
        {
            system("cls");
            printf("\n MSG: Digite o nome do usu�rio que deseja pesquisar: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            i = Pesquisar(*rede, user);
            if(i>=0)
            {
                printf("\n\n >>>>>> MSG: Usu�rio pesquisado encontrado:  <<<<<<\n\n");
                Imprimir(rede->vetor[i]);
            }
            else
            {
                printf("\n\n >>>>>> MSG: Usu�rio pesquisado n�o est� cadastrado! <<<<<<\n\n");
            }
            system("PAUSE");
        }
        break;
        case 3:
        {
            system("cls");
            printf("\n\n >>>>>> MSG: Digite o nome do usu�rio que deseja alterar: <<<<<<\n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            i = Pesquisar(*rede, user);
            if(i>=0)
            {
                printf("\n\n >>>>>> MSG: Digite os dados para alterar: <<<<<<\n\n");
                Ler(&user);
                Alterar(rede, user, i);
                printf("\n\n >>>>>> MSG: Usu�rio alterado com sucesso! <<<<<<\n\n");
            }
            else
            {
                printf("\n\n >>>>>> MSG: O usu�rio pesquisado n�o est� cadastrado! <<<<<<\n\n");
            }
            system("PAUSE");

        }
        break;
        case 4:
        {
            system("cls");
            printf("\n\n >>>>>> MSG: Digite o nome do usu�rio que deseja excluir: <<<<<< \n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            i = Pesquisar(*rede, user);
            if(i>=0)
            {
                Excluir(rede, i);
                printf("\n\n >>>>>> MSG: Usu�rio exclu�do com sucesso! <<<<<<\n\n");
            }
            else
            {
                printf("\n\n >>>>>> MSG: O usu�rio pesquisado n�o est� cadastrado! <<<<<<\n\n");
            }
            system("PAUSE");

        }
        break;
        case 5:
        {
            system("cls");
            if(rede->indice > 0)
            {
                printf("\n\n >>>>>> MSG: Lista de usu�rios cadastrados: <<<<<< \n\n");
                Imprimir2(*rede);
            }
            else
            {
                printf("\n\n >>>>>> MSG: N�o existem usu�rios cadastrados! <<<<<< \n\n");
            }
            system("PAUSE");
        }
        break;
        case 6:
        {
            system("cls");
            printf("\n\n\n\t>>>>>> MSG: Saindo do M�DULO...!!! <<<<<< \n\n\n");
            system("PAUSE");
        }
        break;
        default:
            system("cls");
            printf("\n\n\n\t>>>>>> MSG: Digite uma op��o v�lida!!! <<<<<< \n\n\n");
            system("PAUSE");
        }
    }
    while(opcao != 6);
}

void SubMenuModulo2(TRedeSocial *rede, TUsuarios user)
{
    int i, j, k;
    int opcao = 0;
    TUsuarios user1;

    do
    {
        MSG_SUBMENU2(2);
        printf("\n\n\t>>>>>>>>>>>>>    Digite uma op��o:    <<<<<<<<<<<<\n\t>");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
        {
            system("cls");
            printf("\n\n >>>>>> MSG: Digite o nome do primeiro usu�rios: <<<<<<\n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            i = Pesquisar(*rede, user);

            if(i>=0)
            {
                system("cls");
                printf("\n\n >>>>>> MSG: Digite o nome do segundo usu�rios:  <<<<<<\n\n");
                fflush(stdin);
                fgets(user.nome, 100, stdin);
                j = Pesquisar(*rede, user);

                if(j>=0)
                {
                    CadastrarAmizades(rede, rede->vetor[i], rede->vetor[j]);
                }
                else
                {
                    printf("\n\n >>>>>> MSG: O segundo usu�rio n�o est� na rede!                <<<<<<\n\n");
                    printf("\n\n >>>>>> MSG: N�o foi poss�vel realizar o cadastro das Amizades! <<<<<<\n\n");
                }
            }
            else
            {
                printf("\n\n >>>>>> MSG: O primeiro usu�rio n�o est� na rede!               <<<<<<\n\n");
                printf("\n\n >>>>>> MSG: N�o foi poss�vel realizar o cadastro das Amizades! <<<<<<\n\n");
            }
            system("PAUSE");
        }
        break;
        case 2:
        {
            system("cls");
            printf("\n\n >>>>>> MSG: Digite o nome do primeiro usu�rios: <<<<<<\n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            system("cls");
            printf("\n\n >>>>>> MSG: Digite o nome do segundo usu�rios:  <<<<<<\n\n");
            fflush(stdin);
            fgets(user1.nome, 100, stdin);

            k = PesquisarAmizades(*rede, user, user1);

            if(k == 1)
                printf("\n\n >>>>>> MSG: Os usu�rios s�o amigos! <<<<<<\n\n");
            else if(k == 0)
                printf("\n\n >>>>>> MSG: Os usu�rios n�o s�o amigos! <<<<<<\n\n");
            else
                printf("\n\n >>>>>> MSG: N�o foi poss�vel realizar a pesquisa das Amizades! <<<<<<\n\n");
            system("PAUSE");

        }
        break;
        case 3:
        {
            system("cls");
            printf("\n\n >>>>>> MSG: Digite o nome do primeiro usu�rios: <<<<<<\n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            i = Pesquisar(*rede, user);

            if(i>=0)
            {
                system("cls");
                printf("\n\n >>>>>> MSG: Digite o nome do segundo usu�rios:  <<<<<<\n\n");
                fflush(stdin);
                fgets(user.nome, 100, stdin);
                j = Pesquisar(*rede, user);

                if(j>=0)
                {
                    ExcluirAmizades(rede, rede->vetor[i], rede->vetor[j]);
                }
                else
                {
                    printf("\n\n >>>>>> MSG: O segundo usu�rio n�o est� na rede!    <<<<<<\n\n");
                    printf("\n\n >>>>>> MSG: N�o foi poss�vel desfazer as Amizades! <<<<<<\n\n");
                }
            }
            else
            {
                printf("\n\n >>>>>> MSG: O primeiro usu�rio n�o est� na rede!   <<<<<<\n\n");
                printf("\n\n >>>>>> MSG: N�o foi poss�vel desfazer as Amizades! <<<<<<\n\n");
            }
            system("PAUSE");
        }
        break;
        case 4:
        {
            system("cls");
            printf("\n\n >>>>>> MSG: Digite o nome do usu�rios: <<<<<<\n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            ImprimirListaAmigos(*rede, user);
            system("PAUSE");
        }
        break;
        case 5:
        {
            system("cls");
            printf("\n\n\n\t>>>>>> MSG: Saindo do M�DULO...!!! <<<<<<\n\n\n");
            system("PAUSE");
        }
        break;
        default:
            system("cls");
            printf("\n\n\n\t>>>>>> MSG: Digite uma op��o v�lida!!! <<<<<<\n\n\n");
            system("PAUSE");
        }
    }
    while(opcao != 5);
}

void SubMenuModulo3(TRedeSocial *rede, TUsuarios user)
{
    int i, j, k, l;
    int opcao = 0;
    TUsuarios user1;

    do
    {
        MSG_SUBMENU3(3);
        printf("\n\n\t>>>>>>>>>>>>>    Digite uma op��o:    <<<<<<<<<<<<\n\t>");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
        {
            system("cls");
            i = MaisAmigos(*rede);
            printf("\n\n\t>>>>>>    MSG: O usu�rio com mais amigos � %s    <<<<<<\n\n", rede->vetor[i].nome);
            system("PAUSE");
        }
        break;
        case 2:
        {
            system("cls");
            printf("\n\n\t>>>>>>    MSG: Digite o nome do primeiro usu�rios:    <<<<<<\n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);

            system("cls");
            printf("\n\n\t>>>>>>     MSG: Digite o nome do segundo usu�rios:    <<<<<<\n\n");
            fflush(stdin);
            fgets(user1.nome, 100, stdin);

            k = PesquisarAmizades(*rede, user, user1);

            if(k == 0)
            {
                i = Pesquisar(*rede, user);
                j = Pesquisar(*rede, user1);

                l = AmigosEmComum(*rede, i, j);
                system("cls");
                printf("\n\n\t>>>>>>     MSG: Os usu�rios possuem %d amigos em comum!    <<<<<<\n\n", l);
                system("PAUSE");
            }
            else
            {
                system("cls");
                printf("\n\n\t>>>>>>    MSG: Os usu�rios s�o amigos!    <<<<<<\n\n");
                system("PAUSE");
            }
        }
        break;
        case 3:
        {
            system("cls");
            MatrizAmigosEmComum(rede);
            system("PAUSE");
        }
        break;
        case 4:
        {
            system("cls");
            printf("\n\n\t>>>>>>    MSG: Digite o nome do primeiro usu�rios:    <<<<<<\n\n\t>");
            fflush(stdin);
            fgets(user.nome, 100, stdin);


            system("cls");
            printf("\n\n\t>>>>>>    MSG: Digite o nome do segundo usu�rios:    <<<<<<\n\n\t>");
            fflush(stdin);
            fgets(user1.nome, 100, stdin);

            SemAmigosEmComum(*rede, user, user1);

            system("PAUSE");
        }
        break;
        case 5:
        {
            system("cls");
            printf("\n\n\t>>>>>>    MSG: Digite o nome do primeiro usu�rios:    <<<<<<\n\n\t>");
            fflush(stdin);
            fgets(user.nome, 100, stdin);


            system("cls");
            printf("\n\n\t>>>>>>    MSG: Digite o nome do segundo usu�rios:    <<<<<<\n\n\t>");
            fflush(stdin);
            fgets(user1.nome, 100, stdin);

            i = Pesquisar(*rede, user);
            j = Pesquisar(*rede, user1);

            if(i>=0)
            {
                if(j>=0)
                {
                    k = AmizadeIndireta1(*rede, user, user1);
                    if(k>=0)
                    {
                        system("cls");
                        printf("\n\n\t>>>>>>    MSG: O ID do usu�rio intermedi�rio �: %d    <<<<<<\n\n", k);
                    }
                    else
                    {
                        system("cls");
                        printf("\n\n\t>>>>>>    MSG: Os usu�rios n�o possuem amigos em comum!!    <<<<<<\n\n");
                    }

                }
                else
                {
                    system("cls");
                    printf("\n\n\t>>>>>>    MSG: O segundo usu�rio n�o foi encontrado na rede!    <<<<<<\n\n");
                }

            }
            else
            {
                system("cls");
                printf("\n\n\t>>>>>>    MSG: O primeiro usu�rio n�o foi encontrado na rede!    <<<<<<\n\n");
            }
            system("PAUSE");
        }
        break;
        case 6:
        {

            //FUN��O N�O CONCLU�DA

            system("cls");
            printf("\n\n\t>>>>>>    MSG: Digite o nome do primeiro usu�rios:    <<<<<<\n\n\t>");
            fflush(stdin);
            fgets(user.nome, 100, stdin);


            system("cls");
            printf("\n\n\t>>>>>>    MSG: Digite o nome do segundo usu�rios:    <<<<<<\n\n\t>");
            fflush(stdin);
            fgets(user1.nome, 100, stdin);

            i = Pesquisar(*rede, user);
            j = Pesquisar(*rede, user1);

            if(i>=0)
            {
                if(j>=0)
                {
                    AmizadeIndireta2(*rede, user, user1, &i, &j);
                    printf("\n\n\t>>>>>>    MSG: Os ID's dos usu�rios intermedi�rios s�o: %d e %d   <<<<<<\n\n", i, j);

                }
                else
                {
                    system("cls");
                    printf("\n\n\t>>>>>>    MSG: O segundo usu�rio n�o foi encontrado na rede!    <<<<<<\n\n");
                }

            }
            else
            {
                system("cls");
                printf("\n\n\t>>>>>>    MSG: O primeiro usu�rio n�o foi encontrado na rede!    <<<<<<\n\n");
            }
            system("PAUSE");
        }
        break;
        case 7:
        {
            system("cls");
            printf("\n\n\n\t>>>>>> MSG: Saindo do M�DULO...!!! <<<<<<\n\n\n");
            system("PAUSE");
        }
        break;
        default:
            system("cls");
            printf("\n\n\n\t>>>>>>    MSG: Digite uma op��o v�lida!!!    <<<<<<\n\n\n");
            system("PAUSE");
        }
    }
    while(opcao != 7);
}

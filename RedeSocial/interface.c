#include "interface.h"

void MSG_REDE()
{
    printf("\n\n\t  AAA	AAAAAAA	AAAAA    AAAAA	");
    printf("\n\t AAAAA	AAAAAAA	AAAAAA  AAAAAAA");
    printf("\n\tAA   AA	AA	AA   AA AA");
    printf("\n\tAAAAAAA	AAAAAAA	AA   AA AAAAAA");
    printf("\n\tAAAAAAA	AAAAAAA	AA   AA  AAAAAA");
    printf("\n\tAA   AA	AA	AA   AA      AA");
    printf("\n\tAA   AA	AAAAAAA	AAAAAA   AAAAAA");
    printf("\n\tAA   AA	AAAAAAA	AAAAA   AAAAAA");
    printf("\n\t                   REDE SOCIAL\n\n");
}
void MSG_MENU()
{
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>    MENU:   <<<<<<<<<<<<<<<<<<<");
    printf("\n\t> 1. MÓDULO 1 - GERENCIAMENTO DE USUÁRIOS        <");
    printf("\n\t> 2. MÓDULO 2 - GERENCIAMENTO DE AMIZADES        <");
    printf("\n\t> 3. SAIR                                        <");
    printf("\n\t>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<");
}

void MSG_SUBMENU(int numero_modulo)
{
    system("cls");
    printf("\n\n\t>>>>>>>>>>>>>>>>>    MÓDULO %d    <<<<<<<<<<<<<<<<<", numero_modulo);
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
    printf("\n\n\t>>>>>>>>>>>>>>>>>    MÓDULO %d    <<<<<<<<<<<<<<<<<", numero_modulo);
    printf("\n\t> 1. CADASTRAR AMIZADES                          <");
    printf("\n\t> 2. PESQUISAR AMIZADES                          <");
    printf("\n\t> 3. EXCLUIR AMIZADES                            <");
    printf("\n\t> 4. IMPRIMIR A LISTA DE AMIGOS                  <");
    printf("\n\t> 5. SAIR                                        <");
    printf("\n\t>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<");

}

void SubMenuModulo1(TRedeSocial *rede, TUsuarios user)
{
    int i;
    int opcao = 0;

    do
    {
        MSG_SUBMENU(1);
        printf("\n\n\t>>>>>>>>>>>>>    Digite uma opção:    <<<<<<<<<<<<\n\t>");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
        {
            system("cls");
            printf("\n\n\t>>>>>>>>     MSG: Cadastre um usuário:    <<<<<<<<\n\n");
            Ler(&user);
            Cadastrar(rede, user);
            system("PAUSE");
        }
        break;
        case 2:
        {
            system("cls");
            printf("\n MSG: Digite o nome do usuário que deseja pesquisar: ");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            i = Pesquisar(*rede, user);
            if(i>=0)
            {
                printf("\n\n >>>>>> MSG: Usuário pesquisado encontrado:  <<<<<<\n\n");
                Imprimir(rede->vetor[i]);
            }
            else
            {
                printf("\n\n >>>>>> MSG: Usuário pesquisado não está cadastrado! <<<<<<\n\n");
            }
            system("PAUSE");
        }
        break;
        case 3:
        {
            system("cls");
            printf("\n\n >>>>>> MSG: Digite o nome do usuário que deseja alterar: <<<<<<\n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            i = Pesquisar(*rede, user);
            if(i>=0)
            {
                printf("\n\n >>>>>> MSG: Digite os dados para alterar: <<<<<<\n\n");
                Ler(&user);
                Alterar(rede, user, i);
                printf("\n\n >>>>>> MSG: Usuário alterado com sucesso! <<<<<<\n\n");
            }
            else
            {
                printf("\n\n >>>>>> MSG: O usuário pesquisado não está cadastrado! <<<<<<\n\n");
            }
            system("PAUSE");

        }
        break;
        case 4:
        {
            system("cls");
            printf("\n\n >>>>>> MSG: Digite o nome do usuário que deseja excluir: <<<<<< \n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            i = Pesquisar(*rede, user);
            if(i>=0)
            {
                Excluir(rede, i);
                printf("\n\n >>>>>> MSG: Usuário excluído com sucesso! <<<<<<\n\n");
            }
            else
            {
                printf("\n\n >>>>>> MSG: O usuário pesquisado não está cadastrado! <<<<<<\n\n");
            }
            system("PAUSE");

        }
        break;
        case 5:
        {
            system("cls");
            if(rede->indice > 0)
            {
                printf("\n\n >>>>>> MSG: Lista de usuários cadastrados: <<<<<< \n\n");
                Imprimir2(*rede);
            }
            else
            {
                printf("\n\n >>>>>> MSG: Não existem usuários cadastrados! <<<<<< \n\n");
            }
            system("PAUSE");
        }
        break;
        case 6:
        {
            system("cls");
            printf("\n\n\n\t>>>>>> MSG: Saindo do MÓDULO...!!! <<<<<< \n\n\n");
            system("PAUSE");
        }
        break;
        default:
            system("cls");
            printf("\n\n\n\t>>>>>> MSG: Digite uma opção válida!!! <<<<<< \n\n\n");
            system("PAUSE");
        }
    }
    while(opcao != 6);
}

void SubMenuModulo2(TRedeSocial *rede, TUsuarios user)
{
    int i, j, k;
    int opcao = 0;

    do
    {
        MSG_SUBMENU2(2);
        printf("\n\n\t>>>>>>>>>>>>>    Digite uma opção:    <<<<<<<<<<<<\n\t>");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
        {
            system("cls");
            system("cls");
            printf("\n\n >>>>>> MSG: Digite o nome do primeiro usuários: <<<<<<\n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            i = Pesquisar(*rede, user);

            if(i>=0)
            {
                system("cls");
                printf("\n\n >>>>>> MSG: Digite o nome do segundo usuários:  <<<<<<\n\n");
                fflush(stdin);
                fgets(user.nome, 100, stdin);
                j = Pesquisar(*rede, user);

                if(j>=0)
                {
                    CadastrarAmizades(rede, rede->vetor[i], rede->vetor[j]);
                }
                else
                {
                    printf("\n\n >>>>>> MSG: O segundo usuário não está na rede!                <<<<<<\n\n");
                    printf("\n\n >>>>>> MSG: Não foi possível realizar o cadastro das Amizades! <<<<<<\n\n");
                }
            }
            else
            {
                printf("\n\n >>>>>> MSG: O primeiro usuário não está na rede!               <<<<<<\n\n");
                printf("\n\n >>>>>> MSG: Não foi possível realizar o cadastro das Amizades! <<<<<<\n\n");
            }
            system("PAUSE");
        }
        break;
        case 2:
        {
            system("cls");
            printf("\n\n >>>>>> MSG: Digite o nome do primeiro usuários: <<<<<<\n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            i = Pesquisar(*rede, user);

            if(i>=0)
            {
                system("cls");
                printf("\n\n >>>>>> MSG: Digite o nome do segundo usuários:  <<<<<<\n\n");
                fflush(stdin);
                fgets(user.nome, 100, stdin);
                j = Pesquisar(*rede, user);

                if(j>=0)
                {
                    k = PesquisarAmizades(*rede, rede->vetor[i], rede->vetor[j]);
                }
                else
                {
                    printf("\n\n >>>>>> MSG: O segundo usuário não está na rede!                <<<<<<\n\n");
                    printf("\n\n >>>>>> MSG: Não foi possível realizar a pesquisa das Amizades! <<<<<<\n\n");
                }
            }
            else
            {
                printf("\n\n >>>>>> MSG: O primeiro usuário não está na rede!               <<<<<<\n\n");
                printf("\n\n >>>>>> MSG: Não foi possível realizar a pesquisa das Amizades! <<<<<<\n\n");
            }

            if(k == 1)
                printf("\n\n >>>>>> MSG: Os usuários são amigos! <<<<<<\n\n");
            else if(k == 0)
                printf("\n\n >>>>>> MSG: Os usuários não são amigos! <<<<<<\n\n");
            system("PAUSE");
        }
        break;
        case 3:
        {
            system("cls");
            system("cls");
            printf("\n\n >>>>>> MSG: Digite o nome do primeiro usuários: <<<<<<\n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            i = Pesquisar(*rede, user);

            if(i>=0)
            {
                system("cls");
                printf("\n\n >>>>>> MSG: Digite o nome do segundo usuários:  <<<<<<\n\n");
                fflush(stdin);
                fgets(user.nome, 100, stdin);
                j = Pesquisar(*rede, user);

                if(j>=0)
                {
                    ExcluirAmizades(rede, rede->vetor[i], rede->vetor[j]);
                }
                else
                {
                    printf("\n\n >>>>>> MSG: O segundo usuário não está na rede!    <<<<<<\n\n");
                    printf("\n\n >>>>>> MSG: Não foi possível desfazer as Amizades! <<<<<<\n\n");
                }
            }
            else
            {
                printf("\n\n >>>>>> MSG: O primeiro usuário não está na rede!   <<<<<<\n\n");
                printf("\n\n >>>>>> MSG: Não foi possível desfazer as Amizades! <<<<<<\n\n");
            }
            system("PAUSE");
        }
        break;
        case 4:
        {
            system("cls");
            printf("\n\n >>>>>> MSG: Digite o nome do usuários: <<<<<<\n\n");
            fflush(stdin);
            fgets(user.nome, 100, stdin);
            ImprimirListaAmigos(*rede, user);
            system("PAUSE");
        }
        break;
        case 5:
        {
            system("cls");
            printf("\n\n\n\t>>>>>> MSG: Saindo do MÓDULO...!!! <<<<<<\n\n\n");
            system("PAUSE");
        }
        break;
        default:
            system("cls");
            printf("\n\n\n\t>>>>>> MSG: Digite uma opção válida!!! <<<<<<\n\n\n");
            system("PAUSE");
        }
    }
    while(opcao != 5);
}

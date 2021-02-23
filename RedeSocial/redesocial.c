#include "redesocial.h"

//Funções Auxiliares
void Imprimir(TUsuarios user)
{
    printf("\n\n\t>>>>>>>>>>>>>>>>    Usuário %d    <<<<<<<<<<<<<<<<", user.ID);
    printf("\n\t> ID: %d", user.ID);
    printf("\n\n\t> Nome do usuário: %s", user.nome);
    printf("\n\t> Email do usuário: %s",user.email);
    printf("\n\t> Login do usuário: %s",user.login);
    printf("\n\t> Senha do usuário: %s",user.senha);
    printf("\n\t> Data de nascimento: %d/ %d/ %d", user.data_nascimento.dia, user.data_nascimento.mes, user.data_nascimento.ano);
    printf("\n\t>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<\n\n");

    /*
    printf("\nID: %d", user.ID);
    printf("\nNome do usuário: ");
    printf("%s",user.nome);
    printf("\nEmail do usuário: ");
    printf("%s",user.email);
    printf("\nLogin do usuário: ");
    printf("%s",user.login);
    printf("\nSenha do usuário: ");
    printf("%s",user.senha);
    printf("\nData de nascimento: %d/ %d/ %d\n\n", user.data_nascimento.dia, user.data_nascimento.mes, user.data_nascimento.ano);
    */
}

void Ler(TUsuarios *user)
{
    printf("\n\t> Digite o nome do usuario:");
    fflush(stdin);
    fgets(user->nome, 100, stdin);

    printf("\n\t> Digite o email do usuario:");
    fflush(stdin);
    fgets(user->email, 200, stdin);

    printf("\n\t> Digite o login do usuario:");
    fflush(stdin);
    fgets(user->login, 50, stdin);

    printf("\n\t> Digite a senha do usuario:");
    fflush(stdin);
    fgets(user->senha, 50, stdin);

    printf("\n\t> Data de nascimento:\n");
    printf("\n\t\t> Digite o dia:");
    fflush(stdin);
    scanf("%d", &user->data_nascimento.dia);

    printf("\n\t\t> Digite o mes:");
    fflush(stdin);
    scanf("%d", &user->data_nascimento.mes);

    printf("\n\t\t> Digite o ano:");
    fflush(stdin);
    scanf("%d", &user->data_nascimento.ano);
}


//Funções Básicas
int Pesquisar(TRedeSocial rede, TUsuarios user)
{
    int i;

    for(i=0; i<rede.indice; i++)
    {
        if(strcmp(rede.vetor[i].nome, user.nome) == 0)
        {
            return i;
        }
    }
    return -1;
}

void Alterar(TRedeSocial *rede, TUsuarios user, int indice)
{
    user.ID = indice;
    rede->vetor[indice] = user;
}

void Cadastrar(TRedeSocial *rede, TUsuarios user)
{
    if(rede->indice == 100)
    {
        printf("\n\n\t>>>>>>>>>>>>>    MSG: Lista Cheia!    <<<<<<<<<<<<\n\n");
    }
    else
    {
        rede->vetor[rede->indice] = user;
        rede->vetor[rede->indice].ID = rede->indice;
        rede->indice++;
        rede->vetor[rede->indice].total_amigos = 0;
    }
}

void Excluir(TRedeSocial *rede, int i)
{
    int coluna;

    rede->vetor[i].ID = -1;

    for(coluna=0; coluna<rede->indice; coluna++)
        if(rede->matrix[i][coluna] == 1)
        {
            rede->matrix[i][coluna] = 0;
            rede->matrix[coluna][i] = 0;
        }
}

void Imprimir2(TRedeSocial rede)
{
    int i;
    for(i=0; i<rede.indice; i++)
    {
        if(rede.vetor[i].ID != -1)
            Imprimir(rede.vetor[i]);
    }
}

void Iniciar(TRedeSocial *rede)
{
    int linha, coluna;
    for(linha = 0; linha < 100; linha++)
    {
        for(coluna = 0; coluna < 100; coluna++)
        {
            rede->matrix[linha][coluna] = 0;
        }
    }

    for(linha = 0; linha < 100; linha++)
    {
        for(coluna = 0; coluna < 100; coluna++)
        {
            rede->matriz_amizades_em_comum[linha][coluna] = 0;
        }
    }

    rede->indice=0;
}


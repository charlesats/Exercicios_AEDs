#include <stdio.h>
#include <stdlib.h>

#include "redesocial.h"

//Funções Auxiliares
void Imprimir(TUsuarios user)
{
    printf("\nID: %d", user.ID);

    printf("\nNome do usuario:");
    printf("\n%s",user.nome);

    printf("\nEmail do usuario:");
    printf("\n%s",user.email);

    printf("\nLogin do usuario:");
    printf("\n%s",user.login);

    printf("\nSenha do usuario:");
    printf("\n%s",user.senha);

    printf("\nData de nascimento:\n");
    printf("\n\tDia:");
    printf("%d", user.data_nascimento.dia);

    printf("\n\tMes:");
    printf("%d", user.data_nascimento.mes);

    printf("\n\tAno:");
    printf("%d", user.data_nascimento.ano);
}

void Ler(TUsuarios *user)
{
    printf("\nDigite o nome do usuario:");
    fflush(stdin);
    fgets(user->nome, 100, stdin);

    printf("\nDigite o email do usuario:");
    fflush(stdin);
    fgets(user->email, 200, stdin);

    printf("\nDigite o login do usuario:");
    fflush(stdin);
    fgets(user->login, 50, stdin);

    printf("\nDigite a senha do usuario:");
    fflush(stdin);
    fgets(user->senha, 50, stdin);

    printf("\nData de nascimento:\n");
    printf("\nDigite o dia:");
    fflush(stdin);
    scanf("%d", &user->data_nascimento.dia);

    printf("\nDigite o mes:");
    fflush(stdin);
    scanf("%d", &user->data_nascimento.mes);

    printf("\nDigite o ano:");
    fflush(stdin);
    scanf("%d", &user->data_nascimento.ano);
}


//Funções Básicas
int Pesquisar(TRedeSocial rede, TUsuarios user)
{
    int i, indice = -1;

    for(i=0; i<rede.indice;i++)
    {
        if(strcmp(rede.vetor[i].nome, user.nome) == 0)
        {
            indice = i;
        }
    }

    return indice;
}

void Alterar(TRedeSocial *rede, TUsuarios user, int indice)
{
    printf("\nO usuario %s", rede->vetor[indice].nome);
    user.ID = indice;
    rede->vetor[indice] = user;
    printf("\nFoi alterado para %s", rede->vetor[indice].nome);

}

void Cadastrar(TRedeSocial *rede, TUsuarios user)
{
   if(rede->indice == 100)
   {
       printf("\nLista Cheia!");
   }
   else
   {
       rede->vetor[rede->indice] = user;
       rede->vetor[rede->indice].ID = rede->indice;
       rede->indice++;
       printf("\nUsuario Cadastrado!");
   }
}

void Imprimir2(TRedeSocial rede)
{
    if(rede.indice == 0)
        printf("\nLista Vazia!");
    else
    {
        int i;
        for(i=0; i<rede.indice;i++)
        {
            Imprimir(rede.vetor[i]);
        }

        printf("\nTodos os usuarios cadastrados foram impressos!");
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

    rede->indice=0;
}


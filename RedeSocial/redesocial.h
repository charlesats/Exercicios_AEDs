#ifndef REDESOCIAL_H_INCLUDED
#define REDESOCIAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct data
{
    int dia;
    int mes;
    int ano;
} TData;

typedef struct usuarios
{
    char nome[100];
    char email[200];
    char login[50];
    char senha[50];
    TData data_nascimento;
    int ID;
} TUsuarios;

typedef struct redeSocial
{
    TUsuarios vetor[100];
    int matrix[100][100];
    int indice;
} TRedeSocial;

// Assinaturas das funções

//Funções Auxiliares
void Imprimir(TUsuarios user);
void Ler(TUsuarios *user);

//Funções Básicas
int Pesquisar(TRedeSocial rede, TUsuarios user);
void Alterar(TRedeSocial *rede, TUsuarios user, int indice);
void Cadastrar(TRedeSocial *rede, TUsuarios user);
void Excluir(TRedeSocial *rede, int indice);
void Imprimir2(TRedeSocial rede);
void Iniciar(TRedeSocial *rede);




#endif // REDESOCIAL_H_INCLUDED

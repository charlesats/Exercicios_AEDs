#ifndef REDESOCIAL_H_INCLUDED
#define REDESOCIAL_H_INCLUDED

#include <stdio.h>

typedef struct data
{
    int dia;
    int mes;
    int ano;
}TData;

typedef struct usuarios
{
    char nome[100];
    char email[200];
    char login[50];
    char senha[50];
    TData data_nascimento;
    int ID;
}TUsuarios;

typedef struct redeSocial
{
    TUsuarios vetor[100];
    int matrix[100][100];
    int indice;
}TRedeSocial;

// Assinaturas das funções
void Ler(TUsuarios *user);
void Imprimir(TUsuarios user);

#endif // REDESOCIAL_H_INCLUDED

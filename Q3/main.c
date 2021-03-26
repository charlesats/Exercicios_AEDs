#include <stdio.h>
#include <stdlib.h>

typedef struct adress
{
    char *avenue;
    int number;
    char *country;
} TAdress;

typedef struct record
{
    char *lastName;
    char *firstName;
    char *middleName;
    TAdress adr;
} TNameAndAdress;

typedef struct recordAll
{
    TNameAndAdress name;
    int employeeNumber;
    float hoursWorked;
} TInputRecord;

TInputRecord *ptrDataInput; // declara��o do ponteiro


/*
 *(a) Escreva a linha de instru��o para alocar uma c�lula de mem�ria ao ponteiro
 *    ptrDataInput por meio da fun��o calloc.
 *(b) Escreva a linha de instru��o para alocar cem c�lulas de mem�ria para o campo
 *    avenue, o que equivale a uma string de 100 caracteres.
 *(c) Escreva a linha de instru��o para alocar cinquenta c�lulas de mem�ria para o
 *    campo country.
 *(d) Escreva a linha de instru��o para alocar dez c�lulas de mem�ria para o campo
 *    lastName.
 *(e) Escreva a linha de instru��o para alocar cem c�lulas de mem�ria para o campo
 *    firstName.
 *(f) Escreva a linha de instru��o para alocar cinquenta c�lulas de mem�ria para o
 *    campo middleName.
 *(g) Escreva o c�digo de acesso ao campo avenue.
 *(h) Escreva a instru��o de leitura de uma string para o campo avenue.
 *(i) Escreva a instru��o de leitura de uma string para o campo firstName.
 *(j) Escreva as linhas de instru��o para imprimir na tela os campos firstName e avenue.
 *(k) Escreva a linha de instru��o para liberar a mem�ria do campo ponteiro firstName
 *    e do campo avenue.
 *(l) Escreva a linha de instru��o para liberar a mem�ria do ponteiro ptrDataInput.
 */

int main()
{
    //(a)
        ptrDataInput = (TInputRecord*)calloc(1,sizeof(TInputRecord));

    //(b)
        ptrDataInput->name.adr.avenue = (char*)calloc(100,sizeof(char));

    //(c)
        //ptrDataInput->name.adr.country = (char*)calloc(50,sizeof(char));

    //(d)
        //ptrDataInput->name.lastName = (char*)calloc(10,sizeof(char));

    //(e)
        ptrDataInput->name.firstName = (char*)calloc(100,sizeof(char));

    //(f)
        //ptrDataInput->name.middleName = (char*)calloc(50,sizeof(char));

    //(g)
        //ptrDataInput->name.adr.avenue

    //(h)
        printf("\nDigite o nome da avenida: ");
        fgets(ptrDataInput->name.adr.avenue, 100, stdin);

    //(i)
        printf("\nDigite o primeiro nome: ");
        fgets(ptrDataInput->name.firstName, 100, stdin);

    //(j)
        printf("\nCampo avenue: ");
        puts(ptrDataInput->name.adr.avenue);
        printf("\nCampo firstName: ");
        puts(ptrDataInput->name.firstName);

    //(k)
        free(ptrDataInput->name.adr.avenue);
        //free(ptrDataInput->name.adr.country);
        free(ptrDataInput->name.firstName);
        //free(ptrDataInput->name.middleName);
        //free(ptrDataInput->name.lastName);

    //(l)
        free(ptrDataInput);
    return 0;
}

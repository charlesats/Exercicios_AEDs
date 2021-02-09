#include <stdio.h>
#include <stdlib.h>

#include "redesocial.h"


int main()
{
    //Declaração de variáveis locais
    TUsuarios user;
    TRedeSocial rede;
    int x;

    //Imprimir(user);
    Iniciar(&rede);

    Ler(&user);
    Cadastrar(&rede, user);
    Ler(&user);
    Cadastrar(&rede, user);

    Imprimir2(rede);

    printf("\nDigite um nome para pesquisar!");
    fflush(stdin);
    fgets(user.nome, 100, stdin);
    x = Pesquisar(rede, user);


    Ler(&user);


    Alterar(&rede, user, x);

    Imprimir2(rede);



    return 0;
}

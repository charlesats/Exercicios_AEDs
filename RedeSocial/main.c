#include <stdio.h>
#include <stdlib.h>

#include "redesocial.h"


int main()
{
    //Declara��o de vari�veis locais
    TUsuarios user;
    TRedeSocial rede;
    int i,j;

    //Imprimir(user);
    Iniciar(&rede);

    Ler(&user);
    Cadastrar(&rede, user);

    Imprimir2(rede);


    return 0;
}

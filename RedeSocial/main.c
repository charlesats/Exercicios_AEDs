#include <stdio.h>
#include <stdlib.h>

#include "redesocial.h"


int main()
{
    //Declaração de variáveis locais
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

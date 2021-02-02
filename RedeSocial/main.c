#include <stdio.h>
#include <stdlib.h>

#include "redesocial.h"


int main()
{
    //Declaração de variáveis locais
    TUsuarios user;
    TRedeSocial rede;

    Ler(&user);
    Imprimir(user);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#include "redesocial.h"
#include "interface.h"
#include "amizade.h"
#include "exercicios.h"

int main()
{
    //Adaptação do programa ao idioma do sistema
    setlocale(LC_ALL,"");

    //Declaração de variáveis locais
    TUsuarios user;
    TRedeSocial rede;
    Iniciar(&rede);

    int opcao = 0;


    MSG_REDE();
    system("PAUSE");
    do
    {
        system("cls");
        MSG_MENU();
        printf("\n\n\t>>>>>>>>>>>>>    Digite uma opção:    <<<<<<<<<<<<\n\t>");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
        {
            SubMenuModulo1(&rede, user);

        }
        break;
        case 2:
        {
            SubMenuModulo2(&rede, user);

        }
        break;
        case 3:
        {
            SubMenuModulo3(&rede, user);
        }
        case 4:
        {
            system("cls");
            printf("\n\n\n\t>>>>>>    MSG: Saindo do programa...!!!    <<<<<<\n\n\n");
        }
        break;
        default:
        {
            system("cls");
            printf("\n\n\n\t>>>>>    MSG: Digite uma opção válida!!!    <<<<<\n\n\n");
            system("PAUSE");

        }
        }
    }
    while(opcao != 4);

    system("PAUSE");



    return 0;
}

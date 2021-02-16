#include <stdio.h>
#include <stdlib.h>

//#include "redesocial.h"
#include "interface.h"

int main()
{
    //Adapta��o do programa ao idioma do sistema
    setlocale(LC_ALL,"");

    //Declara��o de vari�veis locais
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
        printf("\n\n\t>>>>>>>>>>>>>    Digite uma op��o:    <<<<<<<<<<<<\n\t>");
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
            system("cls");
            printf("\n\n\n\t>>>>>>    MSG: Saindo do programa...!!!    <<<<<<\n\n\n");
        }
        break;
        default:
        {
            system("cls");
            printf("\n\n\n\t>>>>>    MSG: Digite uma op��o v�lida!!!    <<<<<\n\n\n");
            system("PAUSE");

        }
        }
    }
    while(opcao != 3);

    system("PAUSE");



    return 0;
}

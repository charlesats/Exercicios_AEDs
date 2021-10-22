#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "interface.h"

int main()
{

    int opcao, num;
    TPilha est;
    FPVazia(&est);
    TCarro carro;


    MSG_AEDS();
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
            system("cls");
            printf("\n\n\t>>>>>>>>>>>>>    Digite o numero do carro:    <<<<<<<<<<<<\n\t>");
            scanf("%d", &carro.carro);
            printf("\n\n\t>>>>>>>>>>>>>    Digite o tempo de permanencia em minutos  <<<<<<<<<<<<\n\t>");
            scanf("%d", &carro.tempo);

            Empilhar(carro, &est);
        }
        break;
        case 2:
        {
            system("cls");
            printf("\n\n\t>>>>>>>>>>>>>    Digite o numero do carro para remover:    <<<<<<<<<<<<\n\t>");
            scanf("%d", &num);
            RemoverCarro(&est, num);

        }
        break;
        case 3:
        {
            system("cls");
            printf("\n\n\t>>>>>>>>>>>>>    Exibindo veículos:    <<<<<<<<<<<<\n\t>");
            Imprimir(&est);
        }
        break;
        case 4:
        {
            system("cls");
            printf("\n\n\n\t>>>>>>    Liberando Estacionameto    <<<<<<\n\n\n");
            Liberar(&est);
            Vazia(est);
        }
        break;
        case 5:
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
    while(opcao != 5);

    system("PAUSE");

    return 0;
}

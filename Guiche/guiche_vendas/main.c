#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "interface.h"

int main()
{

    TFila guiche;
    FFVazia(&guiche);
    TProduto passagem;

    int num, opcao = 0;



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
            printf("\n\n\t>>>>>>>>>>>>>    Entrando na fila    <<<<<<<<<<<<\n\t>");
        }
        break;
        case 2:
        {
            system("cls");
            printf("\n\n\t>>>>>>>>>>>>>    Digite o numero da passagem:    <<<<<<<<<<<<\n\t>");
            scanf("%d", &num);
            //RemoverCarro(&est, num);

        }
        break;
        case 3:
        {
            system("cls");
            printf("\n\n\t>>>>>>>>>>>>>    Exibindo fila de espera    <<<<<<<<<<<<\n\t>");
            ImprimirFila(&guiche);
        }
        break;
        case 4:
        {
            system("cls");
            printf("\n\n\n\t>>>>>>    Exibindo passagens compradas    <<<<<<\n\n\n");
        }
        break;
        case 5:
        {
            system("cls");
            printf("\n\n\n\t>>>>>>    MSG: Saindo da fila...!!!    <<<<<<\n\n\n");
            Desenfileirar(&guiche, &passagem);
        }
        break;
        case 6:
        {
            system("cls");
            printf("\n\n\n\t>>>>>>    MSG: Saindo do programa...!!!    <<<<<<\n\n\n");
            LiberarFila(&guiche);
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
    while(opcao != 6);

    system("PAUSE");


    return 0;
}

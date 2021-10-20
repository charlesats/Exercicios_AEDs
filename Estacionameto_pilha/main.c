#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "interface.h"

int main()
{

    int opcao;
    TPilha est;
    FPVazia(&est);
    TCarro carro;


    MSG_AEDS();
    system("PAUSE");


    /*do
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


    printf("\n>>>> Pilha criada                            <<<<\n");
    TCarro carro1;
    TCarro carro2;
    TCarro carro3;
    TCarro carro4;
    TCarro carro5;
    TCarro carro6;

    printf("\n>>>> Produto criado                          <<<<\n");

    carro1.carro = 1;
    carro2.carro = 2;
    carro3.carro = 3;
    carro4.carro = 4;
    carro5.carro = 5;
    carro6.carro = 6;

    printf("\n>>>> Produto atribuido                       <<<<\n");



    Empilhar(carro1, &est);
    Empilhar(carro2, &est);
    Empilhar(carro3, &est);
    Empilhar(carro4, &est);
    Empilhar(carro5, &est);
    Empilhar(carro6, &est);

    printf("\n>>>> O estacionamento contem %d carros!!     <<<<\n", Tamanho(est));
    Imprimir(&est);


    RemoverCarro(&est, 1);
    printf("\n>>>> O estacionamento contem %d carros!!     <<<<\n", Tamanho(est));

    Imprimir(&est);

    //Liberar(&est);

    //if(Vazia(est))  printf("\nPilha vazia!!");
    //else printf("\nA pilha contem %d elementos!!", Tamanho(est));

    */


    return 0;
}

#include <stdio.h>
#include <stdlib.h>

#define TAM 10       // Defini��o de uma constante

typedef struct produto
{
    char nome[100];
    int quantidade;
    float preco;
}TipoProduto;

int main()
{
    TipoProduto *ptr; // Declara��o de um ponteiro para o TipoProduto
                      // Realiza��o de aloca��o de mem�ria para 10 c�lulas de mem�ria,
                      // cada c�lula de mem�ria tem o tamanho em bytes do tipo produto.
    ptr = (TipoProduto*) calloc(TAM, sizeof(TipoProduto));
    int i;

    // Realizando a leitura dos dados para 10 c�lulas
    // por meio de aritm�tica de ponteiros
    for(i = 0; i < TAM; i++)
    {
        printf(" Digite o nome do produto: ");
        fflush(stdin);
        fgets((ptr + i)->nome, 100, stdin);  // ou (*(ptr + i)).nome
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &(ptr + i)->quantidade); // ou (*(ptr + i)).quantidade
        printf("Digite o valor do produto(R$): ");
        scanf("%f", &(ptr + i)->preco);      // ou (*(ptr + i)).preco
    }

    // Exibindo os dados armazenados
    for(i = 0; i < TAM; i++)
    {
        printf("\nNOME: %s", (ptr + i)->nome);
        printf("\nQUANTIDADE: %d", (ptr + i)->quantidade);
        printf("\nPRECO: R$ %.2f", (ptr + i)->preco);
    }

    // Liberando as 10 c�lulas de mem�ria alocadas
    free(ptr);
    system("PAUSE");

    return 0;
}

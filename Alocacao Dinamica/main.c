#include <stdio.h>
#include <stdlib.h>

#define TAM 10       // Definição de uma constante

typedef struct produto
{
    char nome[100];
    int quantidade;
    float preco;
}TipoProduto;

int main()
{
    TipoProduto *ptr; // Declaração de um ponteiro para o TipoProduto
                      // Realização de alocação de memória para 10 células de memória,
                      // cada célula de memória tem o tamanho em bytes do tipo produto.
    ptr = (TipoProduto*) calloc(TAM, sizeof(TipoProduto));
    int i;

    // Realizando a leitura dos dados para 10 células
    // por meio de aritmética de ponteiros
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

    // Liberando as 10 células de memória alocadas
    free(ptr);
    system("PAUSE");

    return 0;
}

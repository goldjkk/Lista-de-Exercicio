#include <stdio.h>
#include <string.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

int main() {
    struct Produto produtos[100];
    int n, i;
    float valorTotal = 0;

    printf("Digite o número de produtos: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Digite o nome do produto: ");
        scanf("%s", produtos[i].nome);
        printf("Digite o preço do produto: ");
        scanf("%f", &produtos[i].preco);
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &produtos[i].quantidade);
        valorTotal += produtos[i].preco * produtos[i].quantidade;
    }

    printf("\nInformações dos produtos cadastrados:\n");
    for (i = 0; i < n; i++) {
        printf("Nome: %s, Preço: %.2f, Quantidade: %d\n", produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }

    printf("\nValor total em estoque: %.2f\n", valorTotal);
    return 0;
}

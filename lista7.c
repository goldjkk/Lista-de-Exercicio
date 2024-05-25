#include <stdio.h>
#include <stdlib.h>

struct Pessoa {
    char nome[50];
    int idade;
};

int compararIdade(const void *a, const void *b) {
    struct Pessoa *pessoaA = (struct Pessoa *)a;
    struct Pessoa *pessoaB = (struct Pessoa *)b;
    return (pessoaA->idade - pessoaB->idade);
}

int main() {
    struct Pessoa pessoas[100];
    int n, i;

    printf("Digite o número de pessoas: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Digite o nome: ");
        scanf("%s", pessoas[i].nome);
        printf("Digite a idade: ");
        scanf("%d", &pessoas[i].idade);
    }

    qsort(pessoas, n, sizeof(struct Pessoa), compararIdade);

    printf("\nPessoas ordenadas por idade:\n");
    for (i = 0; i < n; i++) {
        printf("Nome: %s, Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
    }

    return 0;
}

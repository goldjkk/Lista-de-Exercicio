#include <stdio.h>
#include <stdlib.h>

struct Funcionario {
    char nome[50];
    int idade;
    float salario;
};

void adicionarRegistro(FILE *file) {
    struct Funcionario func;
    printf("Digite o nome do funcionário: ");
    scanf("%s", func.nome);
    printf("Digite a idade do funcionário: ");
    scanf("%d", &func.idade);
    printf("Digite o salário do funcionário: ");
    scanf("%f", &func.salario);

    fwrite(&func, sizeof(struct Funcionario), 1, file);
}

void listarRegistros(FILE *file) {
    struct Funcionario func;
    rewind(file);

    while (fread(&func, sizeof(struct Funcionario), 1, file)) {
        printf("Nome: %s, Idade: %d, Salário: %.2f\n", func.nome, func.idade, func.salario);
    }
}

void buscarRegistro(FILE *file) {
    char nome[50];
    struct Funcionario func;
    rewind(file);

    printf("Digite o nome do funcionário a ser buscado: ");
    scanf("%s", nome);

    while (fread(&func, sizeof(struct Funcionario), 1, file)) {
        if (strcmp(func.nome, nome) == 0) {
            printf("Registro encontrado: Nome: %s, Idade: %d, Salário: %.2f\n", func.nome, func.idade, func.salario);
            return;
        }
    }
    printf("Registro não encontrado.\n");
}

int main() {
    FILE *file;
    int opcao;

    file = fopen("funcionarios.bin", "a+b");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    do {
        printf("\n1. Adicionar novo registro\n2. Listar todos os registros\n3. Buscar registro por nome\n4. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarRegistro(file);
                break;
            case 2:
                listarRegistros(file);
                break;
            case 3:
                buscarRegistro(file);
                break;
            case 4:
                fclose(file);
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 4);

    return 0;
}

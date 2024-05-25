#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

float calcularMedia(int *array, int tamanho) {
    int i;
    float soma = 0;

    for (i = 0; i < tamanho; i++) {
        soma += array[i];
    }

    return soma / tamanho;
}

float calcularMediana(int *array, int tamanho) {
    if (tamanho % 2 == 0) {
        return (array[tamanho/2 - 1] + array[tamanho/2]) / 2.0;
    } else {
        return array[tamanho/2];
    }
}

int calcularModa(int *array, int tamanho) {
    int i, moda = array[0], maxCount = 1, count = 1;

    for (i = 1; i < tamanho; i++) {
        if (array[i] == array[i - 1]) {
            count++;
        } else {
            if (count > maxCount) {
                maxCount = count;
                moda = array[i - 1];
            }
            count = 1;
        }
    }

    return (count > maxCount) ? array[tamanho - 1] : moda;
}

int main() {
    int n, i;
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int array[n];
    printf("Digite os elementos do array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    qsort(array, n, sizeof(int), comparar);

    float media = calcularMedia(array, n);
    float mediana = calcularMediana(array, n);
    int moda = calcularModa(array, n);

    printf("Média: %.2f\n", media);
    printf("Mediana: %.2f\n", mediana);
    printf("Moda: %d\n", moda);

    return 0;
}


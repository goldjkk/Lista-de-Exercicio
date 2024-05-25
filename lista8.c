#include <stdio.h>
#include <stdlib.h>

int* inverterArray(int *array, int tamanho) {
    int *arrayInvertido = (int *)malloc(tamanho * sizeof(int));
    int i;

    for (i = 0; i < tamanho; i++) {
        arrayInvertido[i] = array[tamanho - i - 1];
    }

    return arrayInvertido;
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

    int *arrayInvertido = inverterArray(array, n);

    printf("Array invertido:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arrayInvertido[i]);
    }
    printf("\n");

    free(arrayInvertido);
    return 0;
}

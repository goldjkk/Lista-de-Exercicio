#include <stdio.h>
#include <stdlib.h>

void multiplicarMatrizes(int **A, int **B, int **C, int n) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = 0;
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transporMatriz(int **A, int **T, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            T[j][i] = A[i][j];
        }
    }
}

int main() {
    int n, i, j;
    printf("Digite a dimensão da matriz: ");
    scanf("%d", &n);

    int **A = (int **)malloc(n * sizeof(int *));
    int **B = (int **)malloc(n * sizeof(int *));
    int **C = (int **)malloc(n * sizeof(int *));
    int **T = (int **)malloc(n * sizeof(int *));
    
    for (i = 0; i < n; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
        B[i] = (int *)malloc(n * sizeof(int));
        C[i] = (int *)malloc(n * sizeof(int));
        T[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Digite os elementos da matriz A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Digite os elementos da matriz B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    multiplicarMatrizes(A, B, C, n);

    printf("Matriz resultante da multiplicação:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    transporMatriz(A, T, n);

    printf("Transposta da matriz A:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(C[i]);
        free(T[i]);
    }
    free(A);
    free(B);
    free(C);
    free(T);

    return 0;
}


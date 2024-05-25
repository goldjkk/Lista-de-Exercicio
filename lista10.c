#include <stdio.h>
#include <time.h>

void funcaoParaTestar() {
    for (long long i = 0; i < 1000000000; i++);
}

int main() {
    clock_t inicio, fim;
    double tempoGasto;

    inicio = clock();

    funcaoParaTestar();

    fim = clock();

    tempoGasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %f segundos\n", tempoGasto);

    return 0;
}

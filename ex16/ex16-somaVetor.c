#include <stdio.h>
#include <stdlib.h>

#define TAM 30

void preencherVetor(int v[], int n);
int somatorioIter(int v[], int n);
int somatorio(int v[], int n);
int somatorioRecursivo(int v[], int n);

int main() {
    int v[TAM];
    preencherVetor(v, TAM);
    printf("Somatorio Iterativo = %d\n", somatorioIter(v, TAM));
    printf("Somatorio Recursivo (aux) = %d\n", somatorio(v, TAM));
    printf("Somatorio Recursivo (pont) = %d\n", somatorioRecursivo(v, TAM));
    return 0;
}

void preencherVetor(int v[], int n) {
    for (int i = 0; i < n; ++i) {
        v[i] = (int)(rand() * 100) + 1;
    }
}

int somatorioIter(int v[], int n) {
    int soma = 0;
    for (int i = 0; i < n; ++i) {
        soma += v[i];
    }
    return soma;
}

// função privada que é recursiva
int somatorioAux(int v[], int inicio, int fim) {
    if (inicio > fim) {
        return 0;
    }

    return v[inicio] + somatorioAux(v, inicio + 1, fim);
}

int somatorio(int v[], int n) {
    return somatorioAux(v, 0, n - 1);
}

int somatorioRecursivo(int v[], int n) {
    if (n == 0) {
        return 0;
    }

    return v[0] + somatorioRecursivo(&v[1], n - 1);
}

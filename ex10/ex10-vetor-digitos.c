#include <stdio.h>

#define TAM 20

void imprimirVetor(int v[], int tam);
void preencherVetorNumero(int v[], int num);

int main() {
    int num;
    int numVetor1[TAM];
    printf("Digite um valor inteiro: ");
    scanf("%d", &num);
    preencherVetorNumero(numVetor1, num);
    imprimirVetor(numVetor1, TAM);
    return 0;
}

void preencherVetorNumero(int v[], int num) {
    for (int i = TAM - 1; i >= 0; --i) {
        v[i] = num % 10;
        num /= 10;
    }
    if (num != 0) {
        printf("Erro: não foi possível inserir esses digitos: %d\n", num);
    }
}

void imprimirVetor(int v[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

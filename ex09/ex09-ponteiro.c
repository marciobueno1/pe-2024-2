#include <stdio.h>

#define TAM 5

void inserirVetor(int v[], int *tam);
void imprimirVetor(int v[], int tam);

int main() {
    int vetor[TAM];
    int tam = 0;
    int opcao;
    do {
        printf("MENU\n\n");
        printf("1 - Inserir elemento no vetor\n");
        printf("2 - Imprimir o vetor atual\n\n");
        printf("Digite sua opção (0 p/ sair): ");
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: inserirVetor(vetor, &tam); break;
            case 2: imprimirVetor(vetor, tam); break;
            default: if (opcao != 0) printf("Opção inválida!\n");
        }
    } while(opcao != 0);
    return 0;
}

void inserirVetor(int v[], int *tam) {
    if (*tam < TAM) {
        printf("Digite um valor: ");
        scanf("%d", &v[*tam]);
        *tam += 1;
    } else {
        printf("Vetor cheio!");
    }
}

void imprimirVetor(int v[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

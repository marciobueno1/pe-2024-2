#include <stdio.h>

#define TAM 8

void inserirVetor(int v[], int *tam);
void imprimirVetor(int v[], int tam);
void inserirOrdenadoVetor(int v[], int *tam);

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
            case 1: inserirOrdenadoVetor(vetor, &tam); break;
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

void inserirOrdenadoVetor(int v[], int *tam) {
    int num, i;
    if (*tam < TAM) {
        printf("Digite um valor: ");
        scanf("%d", &num);
        i = *tam;
        *tam += 1;
        while (i > 0 && v[i - 1] > num) {
            v[i] = v[i - 1];
            --i;
        }
        v[i] = num;
    } else {
        printf("Vetor cheio!\n");
    }
}

void imprimirVetor(int v[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

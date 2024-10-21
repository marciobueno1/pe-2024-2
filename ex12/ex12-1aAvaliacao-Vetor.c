#include <stdio.h>

#define TAM 100

void inserirFinal(int v[], int *tam);
void imprimirVetor(int v[], int tam);
void inserirOrdenado(int v[], int *tam, int valor);
int buscaBinaria(int v[], int tam, int valor);

int main() {
    int vetOrig[TAM], vetOrd[TAM];
    int opcao, tam = 0, tamOrd, valor;
    do {
        printf("MENU\n\n");
        printf("1 - inserir valor\n");
        printf("2 - criar vetor ordenado\n");
        printf("3 - busca binaria\n");
        printf("\nDigite sua opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            inserirFinal(vetOrig, &tam);
            printf("\nvetOrig = ");
            imprimirVetor(vetOrig, tam);
            break;
        case 2:
            tamOrd = 0;
            for (int i = 0; i < tam; ++i) {
                inserirOrdenado(vetOrd, &tamOrd, vetOrig[i]);
            }
            printf("\nvetOrig = ");
            imprimirVetor(vetOrig, tam);
            printf("\nvetOrd = ");
            imprimirVetor(vetOrd, tam);
        case 3:
            printf("Digite o valor a ser buscado: ");
            scanf("%d", &valor);
            int pos = buscaBinaria(vetOrd, tamOrd, valor);
            if (pos != -1) {
                printf("Encontrou na posicao %d\n", pos);
            } else {
                printf("Nao encontrou esse valor no vetor\n");
            }
        default:
            break;
        }
    } while (opcao != 0);
    return 0;
}

void inserirFinal(int v[], int *tam) {
    if (*tam < TAM) {
        printf("Digite o valor a ser inserido: ");
        scanf("%d", &v[*tam]);
        *tam += 1;
    } else {
        printf("\nVetor cheio!\n");
    }
}

void inserirOrdenado(int v[], int *tam, int valor) {
    if (*tam < TAM) {
        int pos = *tam;
        while (pos > 0 && v[pos - 1] > valor) {
            v[pos] = v[pos - 1];
            --pos;
        }
        v[pos] = valor;
        *tam += 1;
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

int buscaBinaria(int v[], int tam, int valor) {
    int inicio = 0, fim = tam - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (valor > v[meio]) {
            inicio = meio + 1;
        } else if (valor < v[meio]) {
            fim = meio - 1;
        } else {
            return meio;
        }
    }
    return -1;
}

#include <stdio.h>
#include <stdlib.h>

#define M 6
#define N 4
#define MAX_VALOR 5

void preencherMatriz(int m[][N], int lin, int col);
void imprimirMatriz(int m[][N], int lin, int col);
void maiorCadaColuna(int m[][N], int lin, int col, int v[]);
void imprimirVetor(int v[], int tam);
void imprimirMaisRepetidos(int m[][N], int lin, int col);

int main() {
    int matriz[M][N];
    int vetor[N];
    int opcao;
    do {
        printf("\nMENU\n\n");
        printf("1 - preencher matriz com aleatorios\n");
        printf("2 - Maior cada coluna\n");
        printf("3 - Linha ou Coluna com mais repetidos\n\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            preencherMatriz(matriz, M, N);
            imprimirMatriz(matriz, M, N);
            break;
        case 2:
            maiorCadaColuna(matriz, M, N, vetor);
            imprimirVetor(vetor, N);
        default:
            imprimirMaisRepetidos(matriz, M, N);
            break;
        }
    } while (opcao != 0);
    return 0;
}

void preencherMatriz(int m[][N], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            m[i][j] = rand() % MAX_VALOR + 1;
        }
    }
}

void imprimirMatriz(int m[][N], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}

void maiorCadaColuna(int m[][N], int lin, int col, int v[]) {
    for (int j = 0; j < col; ++j) {
        int maior = m[0][j];
        for (int i = 1; i < lin; ++i) {
            if (m[i][j] > maior) {
                maior = m[i][j];
            }
        }
        v[j] = maior;
    }
}

void imprimirVetor(int v[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void zerarVetor(int v[], int tam) {
    for (int i = 0; i < tam; ++i) {
        v[i] = 0;
    }
}

int qtdRepetidosVetor(int v[], int tam) {
    int qtd = 0;
    for (int i = 0; i < tam; ++i) {
        if (v[i] > 1) {
            qtd += v[i];
        }
    }
    return qtd;
}

void imprimirMaisRepetidos(int m[][N], int lin, int col) {
    int v[MAX_VALOR];
    int qtdReptidos, qtdMaisRepetidos = 0, indiceMaisRepetidos = 0, ehColuna = 0;
    for (int i = 0; i < lin; ++i) {
        zerarVetor(v, MAX_VALOR);
        for (int j = 0; j < col; ++j) {
            v[m[i][j] - 1] += 1;
        }
        qtdReptidos = qtdRepetidosVetor(v, MAX_VALOR);
        if (qtdReptidos > qtdMaisRepetidos) {
            qtdMaisRepetidos = qtdReptidos;
            indiceMaisRepetidos = i;
            ehColuna = 0;
        }
    }

    for (int j = 0; j < col; ++j) {
        zerarVetor(v, MAX_VALOR);
        for (int i = 0; i < lin; ++i) {
            v[m[i][j] - 1] += 1;
        }
        qtdReptidos = qtdRepetidosVetor(v, MAX_VALOR);
        if (qtdReptidos > qtdMaisRepetidos) {
            qtdMaisRepetidos = qtdReptidos;
            indiceMaisRepetidos = j;
            ehColuna = 1;
        }
    }

    printf("\nA %s com mais elementos repetidos e %d\n\n",
        ehColuna ? "coluna" : "linha",
        indiceMaisRepetidos
    );
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_LINHAS 100
#define QTD_COLUNAS 100

void lerMatriz(int mat[][QTD_COLUNAS], int lin, int col);
void preencherMatrizAleatoria(int mat[][QTD_COLUNAS], int lin, int col);
void imprimirMatriz(int mat[][QTD_COLUNAS], int lin, int col);
void imprimirVetorInt(int v[], int tam);
void imprimirVetorDouble(double v[], int tam);
void calcularSomatorioMediaColuna(int mat[][QTD_COLUNAS], int lin, int col, int soma[], double media[]);
void buscaMatriz(int mat[][QTD_COLUNAS], int lin, int col, int valor, int pos[2]);
void transposta(int mat[][QTD_COLUNAS], int lin, int col, int matTrasp[][QTD_LINHAS]);
void transpostaInPlace(int mat[][QTD_COLUNAS], int ordem);
int lerDentroIntervalo(int min, int max);
int ehDiagonal(int mat[][QTD_COLUNAS], int ordem);

int main() {
    int qtdLinhas, qtdColunas;
    int matriz[QTD_LINHAS][QTD_COLUNAS];
    int matrizTransposta[QTD_COLUNAS][QTD_LINHAS];
    int somatorio[QTD_COLUNAS];
    double media[QTD_COLUNAS];

    // deve ser utilizado quando você quiser que a cada execução gere uma sequência diferente
    // de números aleatórios
    // srand(time(0)); 

    printf("Digite a quantidade de linhas (1-%d): ", QTD_LINHAS);
    qtdLinhas = lerDentroIntervalo(1, QTD_LINHAS);
    printf("Digite a quantidade de colunas (1-%d): ", QTD_COLUNAS);
    qtdColunas = lerDentroIntervalo(1, QTD_COLUNAS);

    lerMatriz(matriz, qtdLinhas, qtdColunas);
    // preencherMatrizAleatoria(matriz, qtdLinhas, qtdColunas);
    printf("\n--------------------\n");
    imprimirMatriz(matriz, qtdLinhas, qtdColunas);
    printf("\n--------------------\n");
    if (qtdLinhas == qtdColunas && ehDiagonal(matriz, qtdLinhas)) {
        printf("É uma matriz diagonal!\n");
    } else {
        printf("Não é uma matriz diagonal!\n");
    }
    calcularSomatorioMediaColuna(matriz, qtdLinhas, qtdColunas, somatorio, media);
    printf("Somatório por coluna: ");
    imprimirVetorInt(somatorio, qtdColunas);
    printf("Média por coluna: ");
    imprimirVetorDouble(media, qtdColunas);
    printf("\n--------------------\n");
    transposta(matriz, qtdLinhas, qtdColunas, matrizTransposta);
    imprimirMatriz(matrizTransposta, qtdColunas, qtdLinhas);
    if (qtdLinhas == qtdColunas) {
        printf("\n--------------------\n");
        transpostaInPlace(matriz, qtdLinhas);
        imprimirMatriz(matriz, qtdColunas, qtdLinhas);
    }
    return 0;
}

void lerMatriz(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("Digite mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void preencherMatrizAleatoria(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            mat[i][j] = rand() % 100 + 1;
        }
    }
}

void imprimirMatriz(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void imprimirVetorInt(int v[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%d\t", v[i]);
    }
    printf("\n");
}

void imprimirVetorDouble(double v[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%.2f\t", v[i]);
    }
    printf("\n");
}


int lerDentroIntervalo(int min, int max) {
    int valor;
    scanf("%d", &valor);
    while (valor < min || valor > max) {
        printf("Valor invalido! Digite valor entre %d e %d: ", min, max);
        scanf("%d", &valor);
    }
    return valor;
}

void calcularSomatorioMediaColuna(int mat[][QTD_COLUNAS], int lin, int col, int soma[], double media[]) {
    for (int j = 0; j < col; ++j) {
        soma[j] = 0;
        for (int i = 0; i < lin; ++i) {
            soma[j] += mat[i][j];
        }
        media[j] = (double) soma[j] / (double) lin;
    }
}

void buscaMatriz(int mat[][QTD_COLUNAS], int lin, int col, int valor, int pos[2]) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            if (mat[i][j] == valor) {
                pos[0] = i;
                pos[1] = j;
                return;
            }
        }
    }
    pos[0] = -1;
    pos[1] = -1;
}

void transposta(int mat[][QTD_COLUNAS], int lin, int col, int matTransp[][QTD_LINHAS]) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            matTransp[j][i] = mat[i][j];
        }
    }
}

void transpostaInPlace(int mat[][QTD_COLUNAS], int ordem) {
    int aux;
    for (int i = 0; i < ordem - 1; ++i) {
        for (int j = i + 1; j < ordem; ++j) {
            aux = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = aux;
        }
    }
}

int ehDiagonalPrincSec(int mat[][QTD_COLUNAS], int ordem, int princ) {
    int difZero = 0;
    for (int i = 0; i < ordem; ++i) {
        for (int j = 0; j < ordem; ++j) {
            if (mat[i][j] != 0) {
                if ((princ && i != j) || (!princ && i + j != ordem - 1)) {
                    return 0;
                } else {
                    difZero = 1;
                }
            }
        }
    }
    return difZero;
}

int ehDiagonal(int mat[][QTD_COLUNAS], int ordem) {
    return ehDiagonalPrincSec(mat, ordem, 1) ||
        ehDiagonalPrincSec(mat, ordem, 0);
}
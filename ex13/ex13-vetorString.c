#include <stdio.h>
#include <string.h>

#define QTD_NOMES 5
#define TAM_NOME 50

void lerStr(char *str, int tam);
void substEspacos(char *str);
void inserirOrdenado(char v[][TAM_NOME], int tam, char *valor);
int buscaBinaria(char v[][TAM_NOME], int tam, char *valor);

int main() {
    char nomes[QTD_NOMES][TAM_NOME];
    char nome[TAM_NOME];
    for (int i = 0; i < QTD_NOMES; ++i) {
        printf("Digite o %do. nome: ", i+1);
        lerStr(nome, TAM_NOME);
        inserirOrdenado(nomes, i, nome);
    }

    for (int i = 0; i < QTD_NOMES; ++i) {
        substEspacos(nomes[i]);
    }

    for (int i = 0; i < QTD_NOMES; ++i) {
        printf("nomes[%d]: %s\n", i+1, nomes[i]);
    }

    printf("Digite string a ser buscada: ");
    lerStr(nome, TAM_NOME);
    while (strcmp(nome, "") != 0) {
        int pos = buscaBinaria(nomes, QTD_NOMES, nome);
        if (pos != -1) {
            printf("Encontrado na posicao %d\n", pos + 1);
        } else {
            printf("Nao encontrado\n");
        }

            printf("Digite string a ser buscada: ");
            lerStr(nome, TAM_NOME);
    }
    return 0;
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void substEspacos(char *str) {
    int tam = strlen(str);
    for (int i = 0; i < tam; ++i) {
        if (str[i] == ' ') {
            str[i] = '-';
        }
    }
}

void inserirOrdenado(char v[][TAM_NOME], int tam, char *valor) {
    int pos = tam;
    while (pos > 0 && strcmp(v[pos - 1], valor) > 0) {
        strcpy(v[pos], v[pos - 1]);
        --pos;
    }
    strcpy(v[pos], valor);
}

int buscaBinaria(char v[][TAM_NOME], int tam, char *valor) {
    int inicio = 0, fim = tam - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (strcmp(valor, v[meio]) > 0) {
            inicio = meio + 1;
        } else if (strcmp(valor, v[meio]) < 0) {
            fim = meio - 1;
        } else {
            return meio;
        }
    }
    return -1;
}
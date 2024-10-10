#include <stdio.h>
#include <string.h>

#define QTD_NOMES 5
#define TAM_NOME 50

void lerStr(char *str, int tam);
void substEspacos(char *str);

int main() {
    char nomes[QTD_NOMES][TAM_NOME];
    for (int i = 0; i < QTD_NOMES; ++i) {
        printf("Digite o %do. nome: ", i+1);
        lerStr(nomes[i], TAM_NOME);
    }

    for (int i = 0; i < QTD_NOMES; ++i) {
        substEspacos(nomes[i]);
    }

    for (int i = 0; i < QTD_NOMES; ++i) {
        printf("nomes[%d]: %s\n", i+1, nomes[i]);
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
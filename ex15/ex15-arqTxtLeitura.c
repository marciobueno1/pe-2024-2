#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STR 256

char *lerStr(char *str, int tam, FILE *arq);

int main() {
    FILE *arq = fopen ("teste.txt", "rt");
    char texto[TAM_STR];
    char *status;

    if (arq == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return 1;
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    if (feof(arq)) {
        printf("Tem erro de fim de arquivo!\n");
    } else {
        printf("Nao tem erro de fim de arquivo!\n");
    }

    status = lerStr(texto, TAM_STR, arq);

    if (feof(arq)) {
        printf("Tem erro de fim de arquivo!\n");
    } else {
        printf("Nao tem erro de fim de arquivo!\n");
    }

    while (!feof(arq)) {
        if (status != NULL) {
            printf("Leitura feita com sucesso!\n");
            printf("texto: %s\n", texto);
        } else {
            printf("Erro de leitura!\n");
            break;
        }
        status = lerStr(texto, TAM_STR, arq);
        // printf("status = -->%s<--\n", status);
    }

    if (status != NULL) {
        printf("Leitura feita com sucesso!\n");
        printf("texto: %s\n", texto);
    }

    if (!fclose(arq)) {
        printf("Arquivo fechado com sucesso!");
    } else {
        printf("Erro ao tentar fechar o arquivo!");
    }

    return 0;
}

char *lerStr(char *str, int tam, FILE *arq) {
    char *status = fgets(str, tam, arq);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
    return status;
}
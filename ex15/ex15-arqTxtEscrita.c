#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_STR 256

void lerStr(char *str, int tam, FILE *arq);

int main() {
    FILE *arq = fopen ("teste.txt", "at");
    char texto[TAM_STR];
    // system("chcp 1252"); // serve para poder imprimir acentuação no Windows!
    if (arq == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return 1;
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    printf("Digite um texto para inserir no arquivo: ");
    lerStr(texto, TAM_STR, stdin);

    int qtd = fprintf(arq, "%s\n", texto);
    printf("qtd = %d\n", qtd);

    if (!fclose(arq)) {
        printf("Arquivo fechado com sucesso!");
    } else {
        printf("Erro ao tentar fechar o arquivo!");
    }

    return 0;
}

void lerStr(char *str, int tam, FILE *arq) {
    fgets(str, tam, arq);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
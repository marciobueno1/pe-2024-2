#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arq = fopen ("teste.txt", "wt");
    if (arq == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return 1;
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    int qtd = fprintf(arq, "Olá Mundo!\n");
    printf("qtd = %d\n", qtd);

    if (!fclose(arq)) {
        printf("Arquivo fechado com sucesso!");
    } else {
        printf("Erro ao tentar fechar o arquivo!");
    }

    return 0;
}
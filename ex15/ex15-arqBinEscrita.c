#include <stdio.h>
#include <stdlib.h>

int main() {
    int status;
    double pi = 3.14159;
    FILE *arq = fopen ("teste.bin", "ab");
    if (arq == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return 1;
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    status = fwrite(&pi, sizeof(double), 1, arq);
    printf("status = %d\n", status);
    if (status == 1) {
        printf("Sucesso na escrita!\n");
    } else {
        printf("Erro na escrita!\n");
    }

    if (!fclose(arq)) {
        printf("Arquivo fechado com sucesso!");
    } else {
        printf("Erro ao tentar fechar o arquivo!");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int status;
    double pi;
    FILE *arq = fopen ("teste.bin", "rb");
    if (arq == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return 1;
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    status = fread(&pi, sizeof(double), 1, arq);
    while (!feof(arq)) {
        printf("status = %d\n", status);
        if (status == 1) {
            printf("Sucesso na leitura!\n");
            printf("Double lido = %f\n", pi);
        } else {
            printf("Erro na escrita!\n");
        }
        status = fread(&pi, sizeof(double), 1, arq);
    }

    if (!fclose(arq)) {
        printf("Arquivo fechado com sucesso!");
    } else {
        printf("Erro ao tentar fechar o arquivo!");
    }

    return 0;
}
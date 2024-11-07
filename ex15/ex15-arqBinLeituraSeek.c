#include <stdio.h>
#include <stdlib.h>

int main() {
    int status;
    double num;
    FILE *arq = fopen ("teste.bin", "r+b");
    if (arq == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return 1;
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    fseek(arq, 1 * (long long) sizeof(double), SEEK_SET);
    status = fread(&num, sizeof(double), 1, arq);
    printf("status = %d\n", status);
    if (status == 1) {
        printf("Sucesso na leitura!\n");
        printf("Double lido = %f\n", num);
    } else {
        printf("Erro na leitura!\n");
    }

    if (!fclose(arq)) {
        printf("Arquivo fechado com sucesso!");
    } else {
        printf("Erro ao tentar fechar o arquivo!");
    }

    return 0;
}
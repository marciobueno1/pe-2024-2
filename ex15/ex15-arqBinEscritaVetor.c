#include <stdio.h>
#include <stdlib.h>

#define TAM_VET 3

int main() {
    int status;
    double numeros[TAM_VET] = { 3.14159, 2.71, 4.88 };
    FILE *arq = fopen ("teste.bin", "wb");
    if (arq == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return 1;
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    status = fwrite(numeros, sizeof(double), TAM_VET, arq);
    printf("status = %d\n", status);
    if (status == TAM_VET) {
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
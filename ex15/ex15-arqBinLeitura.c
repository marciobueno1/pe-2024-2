#include <stdio.h>
#include <stdlib.h>

int main() {
    int status, posBytes;
    double num;
    FILE *arq = fopen ("teste.bin", "rb");
    if (arq == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return 1;
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }
    
    posBytes = ftell(arq);
    printf("Posicao em bytes do arquivo: %d\n", posBytes);

    status = fread(&num, sizeof(double), 1, arq);
    while (!feof(arq)) {
        posBytes = ftell(arq);
        printf("Posicao em bytes do arquivo: %d\n", posBytes);
        printf("status = %d\n", status);
        if (status == 1) {
            printf("Sucesso na leitura!\n");
            printf("Double lido = %f\n", num);
        } else {
            printf("Erro na leitura!\n");
        }
        status = fread(&num, sizeof(double), 1, arq);
    }

    posBytes = ftell(arq);
    printf("Posicao em bytes do arquivo: %d\n", posBytes);

    if (!fclose(arq)) {
        printf("Arquivo fechado com sucesso!");
    } else {
        printf("Erro ao tentar fechar o arquivo!");
    }

    return 0;
}
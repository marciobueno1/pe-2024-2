#include <stdio.h>
#include <stdlib.h>

#define TAM_VETOR 5

void imprimirVetor(double v[], int tam);

int main() {
    int status;
    double numeros[TAM_VETOR];
    FILE *arq = fopen ("teste.bin", "rb");
    if (arq == NULL) {
        printf("Erro na abertura do arquivo!\n");
        return 1;
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    status = fread(numeros, sizeof(double), TAM_VETOR, arq);
    printf("status = %d\n", status);
    if (status != 0) {
        printf("Sucesso na leitura!\n");
        imprimirVetor(numeros, status);
    } else {
        printf("Erro na escrita!\n");
    }

    if (feof(arq)) {
        printf("Tem erro de fim de arquivo!\n");
    } else {
        printf("Nao tem erro de fim de arquivo!\n");
    }


    if (!fclose(arq)) {
        printf("Arquivo fechado com sucesso!");
    } else {
        printf("Erro ao tentar fechar o arquivo!");
    }

    return 0;
}

void imprimirVetor(double v[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("%f ", v[i]);
    }
    printf("\n");
}

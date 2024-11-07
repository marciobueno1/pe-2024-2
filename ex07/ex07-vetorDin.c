#include <stdio.h>
#include <stdlib.h>

#define TAM 10000000

int main() {
    int *numeros = (int *) malloc(TAM * sizeof(int));

    if (numeros == NULL) {
        printf("Falha na alocação da memoria!\n");
        return 1;
    }

    // resto do código normal, use o array numeros, como você usaria se ele tivesse sido criado estaticamente

    free(numeros); // tudo que eh alocado com malloc, precisa ser desalocado com free
    return 0;
}

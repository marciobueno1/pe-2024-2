#include <stdio.h>

#define TAM_NOME 50

struct Conta {
    int numero;
    char nome[TAM_NOME];
    int cpf; // char cpf[15];
    int telefone;
    double saldo;
};

int main() {
    struct Conta *conta1 = (struct Conta *) malloc(sizeof(struct Conta));
    struct Conta conta2;

    scanf("%d", &conta1->cpf);
    scanf("%d", &(*conta1).cpf);
    scanf("%d", &conta2.cpf);

    free(conta1);
    return 0;
}
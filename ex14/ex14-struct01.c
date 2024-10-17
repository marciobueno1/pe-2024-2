#include <stdio.h>
#include <math.h>
#include <string.h>

#define TAM_NOME 50

struct Pessoa {
    char nome[TAM_NOME];
    int idade;
    double altura, peso;
};

void lerStr(char *str, int tam);
double calcularIMC(struct Pessoa pessoa);
void imprimirInterpretacaoIMC(double imc);
void imprimirPessoa(struct Pessoa pessoa);
void lerPessoa(struct Pessoa *pessoa);

int main() {
    struct Pessoa pessoa;
    lerPessoa(&pessoa);
    printf("\nPESSOA\n\n");
    imprimirPessoa(pessoa);

    double imc = calcularIMC(pessoa);
    printf("\nO seu IMC e %f\n", imc);
    imprimirInterpretacaoIMC(imc);
    return 0;
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void lerPessoa(struct Pessoa *pessoa) {
    printf("Digite seu nome: ");
    lerStr(pessoa->nome, TAM_NOME);
    printf("Digite sua idade: ");
    scanf("%d", &pessoa->idade);
    printf("Digite sua altura: ");
    scanf("%lf", &pessoa->altura);
    printf("Digite seu peso: ");
    scanf("%lf", &pessoa->peso);
}

void imprimirPessoa(struct Pessoa pessoa) {
    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    printf("Altura: %f\n", pessoa.altura);
    printf("Peso: %f\n", pessoa.peso);
}

double calcularIMC(struct Pessoa pessoa) {
    return pessoa.peso / pow(pessoa.altura, 2);
}

void imprimirInterpretacaoIMC(double imc) {
    char classificacao[16];
    if (imc < 18.5) {
        strcpy(classificacao, "Magreza");
    } else if (imc < 25.0) {
        strcpy(classificacao, "Normal");
    } else if (imc < 30.0) {
        strcpy(classificacao, "Sobrepeso");
    } else if (imc < 40.0) {
        strcpy(classificacao, "Obesidade");
    } else {
        strcpy(classificacao, "Obesidade Grave");
    }
    printf("Classificacao: %s\n", classificacao);
}

/* formato MENOS utilizado
void lerPessoa(struct Pessoa *pessoa) {
    printf("Digite seu nome: ");
    lerStr((*pessoa).nome, TAM_NOME);
    printf("Digite sua idade: ");
    scanf("%d", &(*pessoa).idade);
    printf("Digite sua altura: ");
    scanf("%lf", &(*pessoa).altura);
    printf("Digite seu peso: ");
    scanf("%lf", &(*pessoa).peso);
}
*/
#include <stdio.h>
#include <math.h>
#include <string.h>

#define QTD_PESSOAS 5
#define TAM_NOME 50
#define TEMP_CHAR 256

struct Pessoa {
    char nome[TAM_NOME];
    int idade;
    double altura, peso;
};

void lerStr(char *str, int tam);
double calcularIMC(struct Pessoa pessoa);
void imprimirInterpretacaoIMC(double imc);
void imprimirPessoa(struct Pessoa pessoa);
void imprimirPessoas(struct Pessoa pessoas[], int tam);
void lerPessoa(struct Pessoa *pessoa);
void lerPessoas(struct Pessoa pessoas[], int tam);
void inserirOrdenado(struct Pessoa v[], int tam, struct Pessoa valor);
void imprimirTodosIMC(struct Pessoa pessoas[], int tam);
int buscaBinariaNome(struct Pessoa v[], int tam, char *valor);
void bubblesort (struct Pessoa v[ ], int n);

int main() {
    struct Pessoa pessoas[QTD_PESSOAS];
    lerPessoas(pessoas, QTD_PESSOAS);
    bubblesort(pessoas, QTD_PESSOAS);
    printf("\nLISTAGEM DE PESSOAS\n\n");
    imprimirPessoas(pessoas, QTD_PESSOAS);
    imprimirTodosIMC(pessoas, QTD_PESSOAS);

    char nome[TAM_NOME];
    printf("Digite um nome para a busca: ");
    lerStr(nome, TAM_NOME);
    while (strlen(nome) != 0) {
        int pos = buscaBinariaNome(pessoas, QTD_PESSOAS, nome);
        if (pos != -1) {
            printf("Achou %s na posicao %d!\n", pessoas[pos].nome, pos + 1);
        } else {
            printf("Nao achou essa pessoa\n");
        }
        printf("Digite um nome para a busca: ");
        lerStr(nome, TAM_NOME);
    }

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
    char temp[TEMP_CHAR];
    printf("Digite seu nome: ");
    lerStr(pessoa->nome, TAM_NOME);
    printf("Digite sua idade: ");
    scanf("%d", &pessoa->idade);
    printf("Digite sua altura: ");
    scanf("%lf", &pessoa->altura);
    printf("Digite seu peso: ");
    scanf("%lf", &pessoa->peso);
    lerStr(temp, TEMP_CHAR);
}

void lerPessoas(struct Pessoa pessoas[], int tam) {
    // struct Pessoa pessoa;
    for (int i = 0; i < tam; ++i) {
        printf("\nDados da %da pessoa\n", i + 1);
        lerPessoa(&pessoas[i]);
        // inserirOrdenado(pessoas, i, pessoa);
    }
}

void bubblesort (struct Pessoa v[ ], int n) {
    int i, fim, pos, troca;
    struct Pessoa aux;
    troca = 1; fim = n - 2; pos = 0;
    while (troca == 1) {
        troca = 0;
        for (i = 0; i <= fim; i++) {
            if (strcmp(v[i].nome, v[i+1].nome) > 0) {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                pos = i; troca = 1;
            }
        }
        fim = pos-1;
    }
}

void inserirOrdenado(struct Pessoa v[], int tam, struct Pessoa valor) {
    int pos = tam;
    while (pos > 0 && strcmp(v[pos - 1].nome, valor.nome) > 0) {
        v[pos] = v[pos - 1];
        --pos;
    }
    v[pos] = valor;
}

void imprimirPessoa(struct Pessoa pessoa) {
    printf("Nome: %s\n", pessoa.nome);
    printf("Idade: %d\n", pessoa.idade);
    printf("Altura: %f\n", pessoa.altura);
    printf("Peso: %f\n", pessoa.peso);
}

void imprimirPessoas(struct Pessoa pessoas[], int tam) {
    for (int i = 0; i < tam; ++i) {
        printf("\nDados da %da pessoa\n", i + 1);
        imprimirPessoa(pessoas[i]);
    }
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

void imprimirTodosIMC(struct Pessoa pessoas[], int tam) {
    for (int i = 0; i < tam; ++i) {
        double imc = calcularIMC(pessoas[i]);
        printf("\nO seu IMC da %da pessoa e %f\n", i + 1, imc);
        imprimirInterpretacaoIMC(imc);
    }
}

int buscaBinariaNome(struct Pessoa v[], int tam, char *valor) {
    int inicio = 0, fim = tam - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (strcmp(valor, v[meio].nome) > 0) {
            inicio = meio + 1;
        } else if (strcmp(valor, v[meio].nome) < 0) {
            fim = meio - 1;
        } else {
            return meio;
        }
    }
    return -1;
}

/* Dados para Digitação - OBS: copie também a linha em branco antes do fim do comentário
Ana
18
1.7
60
Marcos
20
1.8
90
Joao
22
1.75
82
Jose
19
1.6
50
Fernanda
21
1.65
57
Joao
Joaquim
Ana

*/

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
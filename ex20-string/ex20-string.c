#include <stdio.h>
#include <string.h>

#define TAM 51

void lerStr(char *str, int tam);
void gerarNomeCompleto(char *nome, char *sobrenome, char *nomeCompleto);
void todasMaiusculas(char *str);
void todasMinusculas(char *str);
void maiusculaCadaPalavra(char *str);

int main() {
    char nome[TAM];
    char sobrenome[TAM];
    char nomeCompleto[2 * TAM - 1];

    printf("Digite seu nome: ");
    // scanf("%s", nome);
    lerStr(nome, TAM);

    printf("Digite seu sobrenome: ");
    // scanf("%s", sobrenome);
    lerStr(sobrenome, TAM);

    printf("nome: %s\n", nome);
    printf("sobrenome: %s\n", sobrenome);

    gerarNomeCompleto(nome, sobrenome, nomeCompleto);
    printf("Nome completo: %s\n", nomeCompleto);

    strcpy(nomeCompleto, "sem nome");
    printf("Nome completo: %s\n", nomeCompleto);

    // strcpy(nomeCompleto, "");
    nomeCompleto[0] = '\0';
    strcat(nomeCompleto, nome);
    strcat(nomeCompleto, " ");
    strcat(nomeCompleto, sobrenome);
    printf("Nome completo: %s\n", nomeCompleto);

    todasMinusculas(nomeCompleto);
    printf("Nome completo: %s\n", nomeCompleto);

    todasMaiusculas(nomeCompleto);
    printf("Nome completo: %s\n", nomeCompleto);

    maiusculaCadaPalavra(nomeCompleto);
    printf("Nome completo: %s\n", nomeCompleto);

    return 0;
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void gerarNomeCompleto(char *nome, char *sobrenome, char *nomeCompleto) {
    int tamNome = strlen(nome);
    int tamSobrenome = strlen(sobrenome);
    int indiceNomeCompleto = 0;

    for (int i = 0; i < tamNome; ++i) {
        nomeCompleto[indiceNomeCompleto] = nome[i];
        ++indiceNomeCompleto;
    }

    nomeCompleto[indiceNomeCompleto] = ' ';
    ++indiceNomeCompleto;

    for (int i = 0; i < tamSobrenome; ++i) {
        nomeCompleto[indiceNomeCompleto] = sobrenome[i];
        ++indiceNomeCompleto;
    }

    nomeCompleto[indiceNomeCompleto] = '\0';
}

void todasMaiusculas(char *str) {
    int tam = strlen(str);
    for (int i = 0; i < tam; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}

void todasMinusculas(char *str) {
    int tam = strlen(str);
    for (int i = 0; i < tam; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += 32;
        }
    }
}

void maiusculaCadaPalavra(char *str) {
    int tam = strlen(str);
    for (int i = 0; i < tam; ++i) {
        if (i == 0 || str[i - 1] == ' ' || str[i - 1] == '.' || str[i - 1] == ',') {
            if (str[i] >= 'a' && str[i] <= 'z') {
                str[i] -= 32;
            }
        } else {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] += 32;
            }
        }
    }
}
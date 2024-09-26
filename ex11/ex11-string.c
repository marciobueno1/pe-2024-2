#include <stdio.h>
#include <string.h>

#define TAM 20

void imprimirVetorChar(char *str);
void lerStr(char *str, int tam);

int main() {
    char nome[TAM];
    printf("Digite o seu nome: ");
    // gets(nome); // deprecated por ser insegura...
    lerStr(nome, TAM);
    printf("Nome digitado: -->%s<--\n", nome);
    printf("Tamanho da string: %d\n", strlen(nome));
    imprimirVetorChar(nome);
    return 0;
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}


// na prática só utilize o printf com %s
void imprimirVetorChar(char *str) {
    int i;
    printf("-->");
    for (i = 0; str[i] != '\0'; ++i) {
        printf("(%d, 0x%03X, %c)", str[i], str[i], str[i]);
    }
    printf("(%d, 0x%03X, %c)", str[i], str[i], str[i]);
    printf("<--\n");
}
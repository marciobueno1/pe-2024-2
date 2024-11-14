#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTD_ALUNOS 5
#define TAM_NOME 50

struct Aluno {
    char nome[TAM_NOME];
    double nota1, nota2, nota3;
    double media; // cuidado para não deixar esse campo desatualizado
};

void lerStr(char *str, int tam);
void preencherAluno(struct Aluno *aluno);
void preencherAlunos(struct Aluno alunos[], int n);
void imprimirAluno(struct Aluno aluno);
void imprimirAlunos(struct Aluno alunos[], int n);
int maiorPrimeiraNota(struct Aluno alunos[], int n);
int maiorMediaGeral(struct Aluno alunos[], int n);
int menorMediaGeral(struct Aluno alunos[], int n);

int main() {
    struct Aluno alunos[QTD_ALUNOS];
    preencherAlunos(alunos, QTD_ALUNOS);
    imprimirAlunos(alunos, QTD_ALUNOS);
    int maiorPrimNotaIndex = maiorPrimeiraNota(alunos, QTD_ALUNOS);
    printf("Aluno com a maior primeira nota: ");
    imprimirAluno(alunos[maiorPrimNotaIndex]);
    int maiorMediaGeralIndex = maiorMediaGeral(alunos, QTD_ALUNOS);
    printf("Aluno com a maior media geral: ");
    imprimirAluno(alunos[maiorMediaGeralIndex]);
    int menorMediaGeralIndex = menorMediaGeral(alunos, QTD_ALUNOS);
    printf("Aluno com a menor media geral: ");
    imprimirAluno(alunos[menorMediaGeralIndex]);
    return 0;
}

void lerStr(char *str, int tam) {
    fgets(str, tam, stdin);
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

double calcularMedia(struct Aluno aluno) {
    return (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3;
}

void preencherAluno(struct Aluno *aluno) {
    char tempStr[TAM_NOME];
    printf("Digite o nome: ");
    lerStr(aluno->nome, TAM_NOME);
    printf("Digite a primeira nota: ");
    scanf("%lf", &aluno->nota1);
    printf("Digite a segunda nota: ");
    scanf("%lf", &aluno->nota2);
    printf("Digite a terceira nota: ");
    scanf("%lf", &aluno->nota3);
    aluno->media = calcularMedia(*aluno);
    lerStr(tempStr, TAM_NOME);
}

void preencherAlunos(struct Aluno alunos[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("Digite informacoes do aluno %d\n", i + 1);
        preencherAluno(&alunos[i]);
    }
}

void imprimirAluno(struct Aluno aluno) {
    printf("%s (%.2f, %.2f, %.2f) [%.2f]\n",
        aluno.nome, aluno.nota1, aluno.nota2, aluno.nota3, aluno.media
    );
}

void imprimirAlunos(struct Aluno alunos[], int n) {
    printf("Listagem de Alunos\n");
     for (int i = 0; i < n; ++i) {
        imprimirAluno(alunos[i]);
    }
}

int maiorPrimeiraNota(struct Aluno alunos[], int n) {
    int maior = 0;
    for (int i = 1; i < n; ++i) {
        if (alunos[i].nota1 > alunos[maior].nota1) {
            maior = i;
        }
    }
    return maior;
}

int maiorMediaGeral(struct Aluno alunos[], int n) {
    int maior = 0;
    for (int i = 1; i < n; ++i) {
        if (alunos[i].media > alunos[maior].media) {
            maior = i;
        }
    }
    return maior;
}

int menorMediaGeral(struct Aluno alunos[], int n) {
    int menor = 0;
    for (int i = 1; i < n; ++i) {
        if (alunos[i].media < alunos[menor].media) {
            menor = i;
        }
    }
    return menor;
}
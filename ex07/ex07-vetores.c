#include <stdio.h>

#define QTD_ALUNOS 5

double media(double notas[], int tam);
void imprimirValoresMaioresValor(double notas[], int tam, double valor);
int busca(double v[], int tam, double valor);

int main() {
    double notas[QTD_ALUNOS];

    for (int i = 0; i < QTD_ALUNOS; ++i) {
        printf("Digite a %da nota: ", i + 1);
        scanf("%lf", &notas[i]);
    }

    for (int i = 0; i < QTD_ALUNOS; ++i) {
        printf("notas[%d] = %.1f\n", i, notas[i]);
    }

    double mediaTurma = media(notas, QTD_ALUNOS);
    printf("\nMedia da turma = %.2f\n", mediaTurma);

    imprimirValoresMaioresValor(notas, QTD_ALUNOS, mediaTurma);

    double nota;
    printf("Digite uma nota para realizar a busca: ");
    scanf("%lf", &nota);
    while (nota >= 0) {
        int pos = busca(notas, QTD_ALUNOS, nota);
        if (pos != -1) {
            printf("Nota encontrada no indice %d\n", pos);
        } else {
            printf("Nota não encontrada!\n");
        }
        printf("Digite uma nota para realizar a busca (negativo para encerrar): ");
        scanf("%lf", &nota);
    }

    return 0;
}

double media(double notas[], int tam) {
    if (tam == 0) {
        printf("Não é possível calcular a média!\n");
        return 0.0;
    }

    double soma = 0.0;
    for (int i = 0; i < tam; ++i) {
        soma += notas[i];
    }
    return soma / tam;
}

void imprimirValoresMaioresValor(double notas[], int tam, double valor) {
    printf("\nNotas maiores que %.2f\n", valor);
    for (int i = 0; i < tam; ++i) {
        if (notas[i] > valor) {
            printf("notas[%d] = %.1f\n", i, notas[i]);
        }
    }
}

// int busca(double v[], int tam, double valor) {
//     int result = -1;
//     for (int i = 0; i < tam; ++i) {
//         if (v[i] == valor) {
//             result = i;
//             break;
//         }
//     }
//     return result;
// }

int busca(double v[], int tam, double valor) {
    for (int i = 0; i < tam; ++i) {
        if (v[i] == valor) {
            return i;
        }
    }
    return -1;
}

// double media(double notas[QTD_ALUNOS]) {
//     double soma = 0.0;
//     for (int i = 0; i < QTD_ALUNOS; ++i) {
//         soma += notas[i];
//     }
//     return soma / QTD_ALUNOS;
// }

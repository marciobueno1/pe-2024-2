#include <stdio.h> //header files

/*
  O seu main deverá chamar 4 funções, onde cada função irá imprimir os seguintes valores:
  Os números de 1 a 100 (separados por vírgula)
  O somatório de todos os números ímpares entre 10 e 1000
  Todos os números múltiplos de 3 que não terminem em 3 entre 1 e 200 (separados por vírgula)
*/

void imprimirNumeros1a100(); // protótipo da função
int calcularSomatorioImparesIntervalo(int min, int max);
void imprimirMultiplos3queNaoTerminamEm3();

int main() {
  int min, max;
  imprimirNumeros1a100();
  printf("\nDigite o menor valor do intervalo: ");
  scanf("%d", &min);
  do {
    printf("\nDigite o maior valor do intervalo (tem que ser maior ou igual a %d): ", min);
    scanf("%d", &max);
  } while (max < min);
  int somatorio = calcularSomatorioImparesIntervalo(min, max);
  printf("O somatorio dos impares entre %d e %d e %d\n", min, max, somatorio);
  imprimirMultiplos3queNaoTerminamEm3();
  return (0); // returning value to int main()
}

void imprimirNumeros1a100() {
  for (int num = 1; num <= 100; ++num) {
    printf("%d, ", num);
  }
  printf("\n");
}

int calcularSomatorioImparesIntervalo(int min, int max) {
  int soma = 0;
  for (int num = min; num <= max; num += 1) {
    if (num % 2 == 0) {
      soma += num;
    }
  }
  return soma;
}

void imprimirMultiplos3queNaoTerminamEm3() {
  for (int num = 1; num <= 200; ++num) {
    if (num % 3 == 0 && num % 10 != 3) {
      printf("%d, ", num);
    }
  }
  printf("\n");
}

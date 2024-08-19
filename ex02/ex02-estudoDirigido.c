#include <stdio.h> //header files

/*
  O seu main deverá chamar 4 funções, onde cada função irá imprimir os seguintes valores:
  Os números de 1 a 100 (separados por vírgula)
  O somatório de todos os números ímpares entre 10 e 1000
  Todos os números múltiplos de 3 que não terminem em 3 entre 1 e 200 (separados por vírgula)
*/

void imprimirNumeros1a100(); // protótipo da função
int calcularSomatorioImpares10e100();
void imprimirMultiplos3queNaoTerminamEm3();

int main() {
  imprimirNumeros1a100();
  int somatorio = calcularSomatorioImpares10e100();
  printf("O somatorio dos impares entre 10 e 1000 e %d\n", somatorio);
  imprimirMultiplos3queNaoTerminamEm3();
  return (0); // returning value to int main()
}

void imprimirNumeros1a100() {
  for (int num = 1; num <= 100; ++num) {
    printf("%d, ", num);
  }
  printf("\n");
}

int calcularSomatorioImpares10e100() {
  int soma = 0;
  for (int num = 11; num <= 1000; num += 2) {
    soma += num;
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

#include <stdio.h>

void troca(int *a, int *b);

int main() {
  int num1 = 10, num2 = 20;
  printf("num1 = %d - num2 = %d\n", num1, num2);
  troca(&num1, &num2);
  printf("num1 = %d - num2 = %d\n", num1, num2);
  return 0;
}

void troca(int *a, int *b) {
  printf("a = %d - b = %d\n", *a, *b);
  int aux = *a;
  *a = *b;
  *b = aux;
  printf("a = %d - b = %d\n", *a, *b);
}
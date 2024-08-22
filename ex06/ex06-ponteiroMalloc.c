#include <stdio.h>
#include <stdlib.h>

int main() {
  int *ptr = (int *) malloc(sizeof(int));
  
  if (!ptr) {
    printf("Memória não alocada!\n");
    return 1;
  }
  printf("Memória alocada com sucesso!\n");

  *ptr = 20;
  printf("ptr = %p - *ptr = %d\n", ptr, *ptr);
  *ptr *= 4;
  printf("ptr = %p - *ptr = %d\n", ptr, *ptr);

  free(ptr);
  return 0;
}
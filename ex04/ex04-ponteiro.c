#include <stdio.h>

int main() {
  double num1 = 10.0, num2 = 15.7;
  double *ptrDouble = &num1;
  int min = 10, max = 20;
  int *ptr = NULL;
  printf("min = %d - max = %d - ptr = %p\n", min, max, ptr);

  ptr = &min;

  printf("\n*ptr = %d - ptr = %p - tam int = %d\n", *ptr, ptr, sizeof(min));
  ptr = ptr + 1;
  printf("*ptr = %d - ptr = %p\n", *ptr, ptr);
  ptr = ptr + 1;
  printf("*ptr = %d - ptr = %p\n", *ptr, ptr);
  ptr = ptr + 1;
  printf("*ptr = %d - ptr = %p\n", *ptr, ptr);

  printf("\n*ptrDouble = %f - ptrDouble = %p - tam double = %d\n", *ptrDouble, ptrDouble, sizeof(num1));
  ptrDouble = ptrDouble + 1;
  printf("*ptrDouble = %f - ptrDouble = %p - tam double = %d\n", *ptrDouble, ptrDouble, sizeof(num1));
  ptrDouble = ptrDouble + 1;
  printf("*ptrDouble = %f - ptrDouble = %p - tam double = %d\n", *ptrDouble, ptrDouble, sizeof(num1));
  ptrDouble = ptrDouble + 200;
  printf("*ptrDouble = %f - ptrDouble = %p - tam double = %d\n", *ptrDouble, ptrDouble, sizeof(num1));


  ptr = &min;
  *ptr = 15;
  printf("\nmin = %d - max = %d - ptr = %p\n", min, max, ptr);

  ptr = &max;
  *ptr = 25;
  printf("min = %d - max = %d - ptr = %p\n", min, max, ptr);

  return 0;
}
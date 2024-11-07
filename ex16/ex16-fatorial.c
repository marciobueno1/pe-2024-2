#include <stdio.h>

int fatorialRecursivo(int n);
int fatorialIterativo(int n);

int main() {
    printf("Fatorial Recursivo\n");
    for (int n = 0; n <= 10; ++n) {
        printf("fat(%d) = %d\n", n, fatorialRecursivo(n));
    }
    printf("\nFatorial Iterativo\n");
    for (int n = 0; n <= 10; ++n) {
        printf("fat(%d) = %d\n", n, fatorialIterativo(n));
    }

    return 0;
}

int fatorialRecursivo(int n) {
    if (n == 0) {
        return 1;
    }

    return n * fatorialRecursivo(n - 1);
}

int fatorialIterativo(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

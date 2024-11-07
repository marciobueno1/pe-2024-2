#include <stdio.h>

long long fib(int n);
unsigned long long fibIter(int n);

int main() {
    for (int n = 0; n <= 42; ++n) {
        printf("fib(%d) = %lld\n", n, fib(n));
    }

    for (int n = 0; n < 94; ++n) {
        printf("fib(%d) = %llu\n", n, fibIter(n));
    }

    return 0;
}

long long fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    return fib(n - 1) + fib(n - 2);    
}

unsigned long long fibIter(int n) {
    unsigned long long atual, ultimo = 1, penultimo = 0;

    if (n == 0 || n == 1) {
        return n;
    }

    for (int i = 2; i <= n; ++i) {
        atual = ultimo + penultimo;
        penultimo = ultimo;
        ultimo = atual;
    }

    return atual;
}
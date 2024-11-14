#include <stdio.h>

double potencia(double x, int n);

int main() {
    int x = 2;
    for (int n = -10; n <= 10; ++n) {
        printf("%d^%d = %.7f\n", x, n, potencia(x, n));
    }
    return 0;
}

double potencia(double x, int n) {
    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        return potencia(1.0/x, -n);
    }

    return x * potencia(x, n - 1);
}

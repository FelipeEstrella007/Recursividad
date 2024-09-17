#include <stdio.h>

// Factorial decremental
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int num = 0;

    // El usuario ingresa el numero
    printf("Ingresa el numero que quieres cionvertir a binario: ");
    scanf ("%d", &num);

    // Mensaje con el resultado
    printf("El factorial de %d es: %d\n", num, factorial(num));
    getch();
    return 0;
}
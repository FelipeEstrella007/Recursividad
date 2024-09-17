#include <stdio.h>

// Función que calcula el término de Fibonacci en la posición n
int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Función recursiva para imprimir la serie de Fibonacci
void imprimir_fibonacci(int n, int actual) {
    // Caso base: si hemos llegado al término actual igual a n, no seguimos
    if (actual > n) {
        return;
    }

    // Imprimir el valor de fibonacci en la posición actual
    printf("%d", fibonacci(actual));

    // Si el término actual no es el último, imprimimos una coma y un espacio
    if (actual < n) {
        printf(", ");
    }

    // Llamada recursiva para imprimir el siguiente término
    imprimir_fibonacci(n, actual + 1);
}

int main() {
    int num = 10;  // Definir hasta qué posición de la serie queremos imprimir

    printf("Serie Fibonacci hasta la posición %d:\n", num);
    
    // Llamar a la función recursiva para imprimir desde el término 1 hasta num
    imprimir_fibonacci(num, 1);

    printf("\n");  // Salto de línea al final

    return 0;
}

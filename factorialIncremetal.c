#include <stdio.h>

// Factorial incremental
int factorialIncremental(int i, int resultado, int num) {
    if (i > num)
    {
        return resultado;
    }
    
    resultado *= i;
    factorialIncremental(i+1, resultado, num);
}

int main() {
    int num = 0;

    // El susuario ingresa el numero
    printf("Ingresa el numero para calcular su factorial: ");
    scanf("%d", &num);

    // Factorial incremental
    printf("El factorial incremental de %d es: %d\n", num, factorialIncremental(1, 1, num));

    getch();
    return 0;
}

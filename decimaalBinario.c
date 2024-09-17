#include <stdio.h>

void decimlaBinario(int n){
    if (n == 0)
    {
    return;
    }
    decimlaBinario(n/2);
    printf("%d", n % 2);
}

int main() {
    int num = 0;
    printf("Ingresa el numero que quieres cionvertir a binario: ");
    scanf ("%d", &num);
    printf("La representacion binaria %d es: ", num);
    if (num > 0)
    {
        printf("La representacion binaria %d es: ", num);
        decimlaBinario(num);
    }
    else
    {
        printf("El numero debe de ser mayor a 0");
    }
    printf("\n");
    getch();
    return 0;
}
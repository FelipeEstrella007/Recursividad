#include <stdio.h>
#include <unistd.h>

#define MAX_DISCOS 10  // Definir el máximo número de discos

// Definir las torres
int torreA[MAX_DISCOS], torreB[MAX_DISCOS], torreC[MAX_DISCOS];

// Inicializar las torres con los discos en A recursivamente
void inicializarRecursivo(int n, int i) {
    if (i < n) {
        torreA[i] = n - i;
        torreB[i] = 0;
        torreC[i] = 0;
        inicializarRecursivo(n, i + 1);
    }
}

// Mostrar las torres recursivamente
void mostrarTorresRecursivo(int n, int i) {
    if (i >= 0) {
        printf("  %d   |   %d   |   %d\n", torreA[i], torreB[i], torreC[i]);
        mostrarTorresRecursivo(n, i - 1);
    }
}

// Función para mostrar las torres gráficamente con el encabezado
void mostrarTorres(int n) {
    printf("\n");
    mostrarTorresRecursivo(n, n - 1);
    printf("------|-------|------\n");
    printf("  A   |   B   |   C\n");
    printf("\n");
    sleep(1);  // Añadir una pausa para ver los cambios
}

// Buscar el disco en la torre de origen recursivamente
int buscarDisco(int torre[], int n, int i) {
    if (i < 0) {
        return 0;
    } else if (torre[i] != 0) {
        int disco = torre[i];
        torre[i] = 0;
        return disco;
    } else {
        return buscarDisco(torre, n, i - 1);
    }
}

// Colocar el disco en la torre de destino recursivamente
void colocarDisco(int torre[], int disco, int n, int i) {
    if (i < n) {
        if (torre[i] == 0) {
            torre[i] = disco;
        } else {
            colocarDisco(torre, disco, n, i + 1);
        }
    }
}

// Función para mover discos entre las torres recursivamente
void moverDisco(int origen[], int destino[], int n) {
    int disco = buscarDisco(origen, n, n - 1);  // Buscar el disco en la torre de origen
    colocarDisco(destino, disco, n, 0);         // Colocar el disco en la torre de destino
    mostrarTorres(n);                           // Mostrar el estado actual de las torres
}

// Función recursiva para resolver las Torres de Hanoi
void hanoi(int n, int origen[], int destino[], int auxiliar[], int numDiscos) {
    if (n == 1) {
        moverDisco(origen, destino, numDiscos);  // Mover un disco directamente
        return;
    }

    // Mover n-1 discos de origen a auxiliar
    hanoi(n - 1, origen, auxiliar, destino, numDiscos);

    // Mover el disco más grande de origen a destino
    moverDisco(origen, destino, numDiscos);

    // Mover n-1 discos de auxiliar a destino
    hanoi(n - 1, auxiliar, destino, origen, numDiscos);
}

int main() {
    int n = 3;

    if (n > MAX_DISCOS) {
        printf("Error: el número máximo de discos es %d\n", MAX_DISCOS);
        return 1;
    }

    // Inicializar las torres con los discos en la torre A recursivamente
    inicializarRecursivo(n, 0);
    mostrarTorres(n);

    // Resolver las Torres de Hanoi recursivamente
    hanoi(n, torreA, torreC, torreB, n);
    return 0;
}

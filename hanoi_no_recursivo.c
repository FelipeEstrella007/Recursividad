#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_DISCOS 10  // Definir el máximo número de discos

// Definir las torres
int torreA[MAX_DISCOS], torreB[MAX_DISCOS], torreC[MAX_DISCOS];

// Inicializar las torres sin recursividad
void inicializarIterativo(int n) {
    for (int i = 0; i < n; i++) {
        torreA[i] = n - i;
        torreB[i] = 0;
        torreC[i] = 0;
    }
}

// Mostrar las torres sin recursividad
void mostrarTorresIterativo(int n) {
    printf("\n");
    for (int i = n - 1; i >= 0; i--) {
        printf("  %d   |   %d   |   %d\n", torreA[i], torreB[i], torreC[i]);
    }
    printf("------|-------|------\n");
    printf("  A   |   B   |   C\n");
    printf("\n");
    sleep(1);  // Añadir una pausa para ver los cambios
}

// Buscar el disco en la torre de origen sin recursividad
int buscarDiscoIterativo(int torre[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (torre[i] != 0) {
            int disco = torre[i];
            torre[i] = 0;
            return disco;
        }
    }
    return 0;  // No se encontró ningún disco
}

// Colocar el disco en la torre de destino sin recursividad
void colocarDiscoIterativo(int torre[], int disco, int n) {
    for (int i = 0; i < n; i++) {
        if (torre[i] == 0) {
            torre[i] = disco;
            break;
        }
    }
}

// Función para mover discos entre las torres sin recursividad
void moverDiscoIterativo(int origen[], int destino[], int n) {
    int disco = buscarDiscoIterativo(origen, n);  // Buscar el disco en la torre de origen
    colocarDiscoIterativo(destino, disco, n);     // Colocar el disco en la torre de destino
    mostrarTorresIterativo(n);                    // Mostrar el estado actual de las torres
}

// Función iterativa para resolver las Torres de Hanoi utilizando una pila de operaciones
void hanoiIterativo(int n, int origen[], int destino[], int auxiliar[], int numDiscos) {
    int totalMoves = (1 << n) - 1;  // Total de movimientos es 2^n - 1

    // Identificar las torres de origen, destino y auxiliar dependiendo de si el número de discos es par o impar
    int torres[3][MAX_DISCOS]; // Array bidimensional para las tres torres
    for (int i = 0; i < numDiscos; i++) {
        torres[0][i] = origen[i];
        torres[1][i] = auxiliar[i];
        torres[2][i] = destino[i];
    }

    int from = 0, to = 2, aux = 1;
    if (n % 2 == 0) { // Si es par, intercambiar destino y auxiliar
        to = 1;
        aux = 2;
    }

    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            moverDiscoIterativo(torres[from], torres[to], numDiscos);  // Mover de origen a destino
        } else if (i % 3 == 2) {
            moverDiscoIterativo(torres[from], torres[aux], numDiscos); // Mover de origen a auxiliar
        } else {
            moverDiscoIterativo(torres[aux], torres[to], numDiscos);   // Mover de auxiliar a destino
        }
    }
}

int main() {
    int n = 3;

    if (n > MAX_DISCOS) {
        printf("Error: el número máximo de discos es %d\n", MAX_DISCOS);
        return 1;
    }

    // Inicializar las torres sin recursividad
    inicializarIterativo(n);
    mostrarTorresIterativo(n);

    // Resolver las Torres de Hanoi sin recursividad
    hanoiIterativo(n, torreA, torreC, torreB, n);
    return 0;
}

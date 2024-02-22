#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

// Función para llenar la matriz con valores proporcionados por el usuario o aleatorios
void llenarMatriz(int matriz[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    int i, j;
    char opcion;

    printf("¿Quieres llenar las matrices con numeros aleatorios? (s/n): ");
    scanf(" %c", &opcion);

    if (opcion == 's' || opcion == 'S') {
        // Llenar la matriz con valores aleatorios entre -100 y 100
        srand(time(NULL));
        for (i = 0; i < filas; ++i) {
            for (j = 0; j < columnas; ++j) {
                matriz[i][j] = rand() % 201 - 100;
            }
        }
    } else {
        // Llenar la matriz con valores proporcionados por el usuario
        printf("Ingrese los valores de la matriz:\n");
        for (i = 0; i < filas; ++i) {
            for (j = 0; j < columnas; ++j) {
                printf("Matriz[%d][%d]: ", i + 1, j + 1);
                scanf("%d", &matriz[i][j]);
            }
        }
    }
}

// Función para mostrar la matriz
void mostrarMatriz(int matriz[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    int i, j;
    for (i = 0; i < filas; ++i) {
        for (j = 0; j < columnas; ++j) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para sumar dos matrices
void sumarMatrices(int matrizA[MAX_SIZE][MAX_SIZE], int matrizB[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    int i, j;
    for (i = 0; i < filas; ++i) {
        for (j = 0; j < columnas; ++j) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

// Función para restar dos matrices
void restarMatrices(int matrizA[MAX_SIZE][MAX_SIZE], int matrizB[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    int i, j;
    for (i = 0; i < filas; ++i) {
        for (j = 0; j < columnas; ++j) {
            resultado[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
}

// Función para multiplicar dos matrices
void multiplicarMatrices(int matrizA[MAX_SIZE][MAX_SIZE], int matrizB[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int filasA, int columnasA, int columnasB) {
    int i, j, k;
    for (i = 0; i < filasA; ++i) {
        for (j = 0; j < columnasB; ++j) {
            resultado[i][j] = 0;
            for (k = 0; k < columnasA; ++k) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

// Función principal
int main() {
    int filas, columnas;

    // Obtener el tamaño de la matriz
    do {
        printf("Ingrese el numero de filas y columnas de la matriz (entre 2 y %d): ", MAX_SIZE);
        scanf("%d", &filas);
        columnas = filas;

        if (filas < 2 || filas > MAX_SIZE) {
            printf("Por favor, ingrese un tamaño válido.\n");
        }
    } while (filas < 2 || filas > MAX_SIZE);

    int matrizA[MAX_SIZE][MAX_SIZE], matrizB[MAX_SIZE][MAX_SIZE], resultado[MAX_SIZE][MAX_SIZE];

    // Llenar la primera matriz
    printf("Llenar la primera matriz:\n");
    llenarMatriz(matrizA, filas, columnas);

    // Mostrar la primera matriz
    printf("Matriz A:\n");
    mostrarMatriz(matrizA, filas, columnas);

    // Llenar la segunda matriz
    printf("Llenar la segunda matriz:\n");
    llenarMatriz(matrizB, filas, columnas);

    // Mostrar la segunda matriz
    printf("Matriz B:\n");
    mostrarMatriz(matrizB, filas, columnas);

    // Realizar operaciones
    int opcion;
    do {
        printf("\nOperaciones disponibles:\n");
        printf("1. Sumar matrices\n");
        printf("2. Restar matrices\n");
        printf("3. Multiplicar matrices\n");
        printf("4. Salir\n");
        printf("Ingrese el número de la operación que desea realizar: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                sumarMatrices(matrizA, matrizB, resultado, filas, columnas);
                printf("Resultado de la suma:\n");
                mostrarMatriz(resultado, filas, columnas);
                break;
            case 2:
                restarMatrices(matrizA, matrizB, resultado, filas, columnas);
                printf("Resultado de la resta:\n");
                mostrarMatriz(resultado, filas, columnas);
                break;
            case 3:
                // Verificar que el número de columnas de la primera matriz sea igual al número de filas de la segunda matriz
                if (columnas != filas) {
                    printf("No se puede multiplicar las matrices debido a dimensiones incompatibles.\n");
                } else {
                    multiplicarMatrices(matrizA, matrizB, resultado, filas, columnas, columnas);
                    printf("Resultado de la multiplicación:\n");
                    mostrarMatriz(resultado, filas, columnas);
                }
                break;
            case 4:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Por favor, ingrese un número válido.\n");
        }
    } while (opcion != 4);

    return 0;
}


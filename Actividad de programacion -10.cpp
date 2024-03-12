#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definición del tamaño maximo de las matrices
#define MAX_SIZE 15

// Prototipos de funciones
void llenarMatrizManual(int matriz[MAX_SIZE][MAX_SIZE], int filas, int columnas, char nombre);
void llenarMatrizAleatoria(int matriz[MAX_SIZE][MAX_SIZE], int filas, int columnas);
void mostrarMatriz(int matriz[MAX_SIZE][MAX_SIZE], int filas, int columnas, char nombre);
void sumarMatrices(int matrizA[MAX_SIZE][MAX_SIZE], int matrizB[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int filas, int columnas);
void restarMatrices(int matrizA[MAX_SIZE][MAX_SIZE], int matrizB[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int filas, int columnas);
void multiplicarMatrices(int matrizA[MAX_SIZE][MAX_SIZE], int matrizB[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int filas, int columnas);
void dividirMatrices(int matrizNumerador[MAX_SIZE][MAX_SIZE], int matrizDenominador[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int filas, int columnas);
void borrarElemento(int matriz[MAX_SIZE][MAX_SIZE], int fila, int columna);
void editarElemento(int matriz[MAX_SIZE][MAX_SIZE], int fila, int columna);
void vaciarMatriz(int matriz[MAX_SIZE][MAX_SIZE], int filas, int columnas);

int main() {
    srand(time(NULL)); // Inicializar la semilla para generar valores aleatorios diferentes en cada ejecución

    int filas, columnas;

    //dimensiones de las matrices
    do {
        printf("Ingrese el numero de filas (entre 2 y %d): ", MAX_SIZE);
        scanf("%d", &filas);
    } while (filas < 2 || filas > MAX_SIZE);

    do {
        printf("Ingrese el numero de columnas (entre 2 y %d): ", MAX_SIZE);
        scanf("%d", &columnas);
    } while (columnas < 2 || columnas > MAX_SIZE);

    int matrizA[MAX_SIZE][MAX_SIZE];
    int matrizB[MAX_SIZE][MAX_SIZE];
    int resultado[MAX_SIZE][MAX_SIZE];

    char opcion;

    printf("¿Desea llenar la matriz A manualmente o con valores aleatorios? (m/a): ");
    scanf(" %c", &opcion);

    if (opcion == 'm') {
        llenarMatrizManual(matrizA, filas, columnas, 'A'); // Llenar la matriz A manualmente
    } else {
        llenarMatrizAleatoria(matrizA, filas, columnas); // Llenar la matriz A con valores aleatorios
    }

    printf("\n");

    printf("¿Desea llenar la matriz B manualmente o con valores aleatorios? (m/a): ");
    scanf(" %c", &opcion);

    if (opcion == 'm') {
        llenarMatrizManual(matrizB, filas, columnas, 'B'); // Llenar la matriz B manualmente
    } else {
        llenarMatrizAleatoria(matrizB, filas, columnas); // Llenar la matriz B con valores aleatorios
    }

    mostrarMatriz(matrizA, filas, columnas, 'A'); // Mostrar la matriz A
    mostrarMatriz(matrizB, filas, columnas, 'B'); // Mostrar la matriz B

    // Menú de operaciones
    do {
        printf("\nSeleccione la operación a realizar:\n");
        printf("1. Suma\n");
        printf("2. Resta\n");
        printf("3. Multiplicacion\n");
        printf("4. División\n");
        printf("5. Borrar Elemento\n");
        printf("6. Editar Elemento\n");
        printf("7. Vaciar Matriz\n");
        printf("8. Salir\n");
        printf("Opcion: ");
        scanf(" %c", &opcion);

        switch (opcion) {
            case '1':
                sumarMatrices(matrizA, matrizB, resultado, filas, columnas); // Realizar la suma de matrices
                mostrarMatriz(resultado, filas, columnas, "Suma"); // Mostrar el resultado de la suma
                break;
            case '2':
                restarMatrices(matrizA, matrizB, resultado, filas, columnas); // Realizar la resta de matrices
                mostrarMatriz(resultado, filas, columnas, "Resta"); // Mostrar el resultado de la resta
                break;
            case '3':
                multiplicarMatrices(matrizA, matrizB, resultado, filas, columnas); // Realizar la multiplicación de matrices
                mostrarMatriz(resultado, filas, columnas, "Multiplicacion"); // Mostrar el resultado de la multiplicación
                break;
            case '4':
                // División
                printf("¿Cual matriz sera el numerador? (A/B): ");
                scanf(" %c", &opcion);
                if (opcion == 'A') {
                    dividirMatrices(matrizA, matrizB, resultado, filas, columnas); // Realizar la división (A/B)
                    mostrarMatriz(resultado, filas, columnas, "Division (A/B)"); // Mostrar el resultado de la división (A/B)
                } else if (opcion == 'B') {
                    dividirMatrices(matrizB, matrizA, resultado, filas, columnas); // Realizar la división (B/A)
                    mostrarMatriz(resultado, filas, columnas, "Division (B/A)"); // Mostrar el resultado de la división (B/A)
                } else {
                    printf("Opcion no valida.\n");
                }
                break;
            case '5':
                // Borrar Elemento
                printf("Ingrese la posicion a borrar (fila columna): ");
                int fila, columna;
                scanf("%d %d", &fila, &columna);
                borrarElemento(matrizA, fila - 1, columna - 1); // Borrar un elemento de la matriz A
                mostrarMatriz(matrizA, filas, columnas, 'A'); // Mostrar la matriz A actualizada
                break;
            case '6':
                // Editar Elemento
                printf("Ingrese la posicion a editar (fila columna): ");
                scanf("%d %d", &fila, &columna);
                editarElemento(matrizA, fila - 1, columna - 1); // Editar un elemento de la matriz A
                mostrarMatriz(matrizA, filas, columnas, 'A'); // Mostrar la matriz A actualizada
                break;
            case '7':
                // Vaciar Matriz
                vaciarMatriz(matrizA, filas, columnas); // Vaciar la matriz A
                mostrarMatriz(matrizA, filas, columnas, 'A'); // Mostrar la matriz A vacía
                break;
            case '8':
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida.\n");
        }

    } while (opcion != '8');

    return 0;
}

// Función para llenar la matriz manualmente
void llenarMatrizManual(int matriz[MAX_SIZE][MAX_SIZE], int filas, int columnas, char nombre) {
    printf("\nLlenando la matriz %c:\n", nombre);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el valor para la posición [%d, %d]: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Función para llenar la matriz con valores aleatorios
void llenarMatrizAleatoria(int matriz[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    printf("\nLlenando la matriz con valores aleatorios:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 601 - 200; // Valores aleatorios entre -200 y 400
        }
    }
}

// Función para mostrar la matriz
void mostrarMatriz(int matriz[MAX_SIZE][MAX_SIZE], int filas, int columnas, char nombre) {
    printf("\nMatriz %c:\n", nombre);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para realizar la suma de matrices
void sumarMatrices(int matrizA[MAX_SIZE][MAX_SIZE], int matrizB[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

// Función para realizar la resta de matrices
void restarMatrices(int matrizA[MAX_SIZE][MAX_SIZE], int matrizB[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
}

// Función para realizar la multiplicación de matrices
void multiplicarMatrices(int matrizA[MAX_SIZE][MAX_SIZE], int matrizB[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < columnas; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

// Función para realizar la división de matrices
void dividirMatrices(int matrizNumerador[MAX_SIZE][MAX_SIZE], int matrizDenominador[MAX_SIZE][MAX_SIZE], int resultado[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            // Implementar validación para evitar división por cero
            resultado[i][j] = matrizNumerador[i][j] / matrizDenominador[i][j];
        }
    }
}

// Función para borrar un elemento de la matriz
void borrarElemento(int matriz[MAX_SIZE][MAX_SIZE], int fila, int columna) {
    matriz[fila][columna] = 0;
}

// Función para editar un elemento de la matriz
void editarElemento(int matriz[MAX_SIZE][MAX_SIZE], int fila, int columna) {
    printf("Ingrese el nuevo valor para la posición [%d, %d]: ", fila + 1, columna + 1);
    scanf("%d", &matriz[fila][columna]);
}

// Función para vaciar la matriz (todos los elementos a cero)
void vaciarMatriz(int matriz[MAX_SIZE][MAX_SIZE], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = 0;
        }
    }
}

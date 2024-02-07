#include <stdio.h>

int main() {
    int numero;
    int contador = 0;
    char respuesta;

    do {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);

        if (numero > 0 && numero < 500) {
            for (int i = 0; i < 100; i++) {
                numero += 5;
                printf("Nuevo valor: %d\n", numero);
                contador++;
            }
        } else if (numero > 500 && numero < 1000) {
            for (int i = 0; i < 50; i++) {
                numero += 10;
                printf("Nuevo valor: %d\n", numero);
                contador++;
            }
        } else if (numero > 1000) {
            printf("No se puede calcular el valor\n");
        }

        printf("Nunmero de operaciones realizada : %d\n", contador);

        printf("¿Deseas terminar el programa? (s/n): ");
        scanf(" %c", &respuesta);
    } while (respuesta != 'S');

    return 0;
}

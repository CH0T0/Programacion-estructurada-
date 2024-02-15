#include <stdio.h>

int main() {
    int arreglo[10] = {0};
    int opcion, posicion, valor, suma, i;

    do {
        printf("1. Agregar valor al arreglo\n");
        printf("2. Mostrar lista de valores\n");
        printf("3. Mostrar sumatoria de todos los elementos\n");
        printf("4. Borrar un elemento\n");
        printf("5. Editar un elemento\n");
        printf("6. Vaciar el arreglo\n");
        printf("7. Salir\n");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                printf("Ingrese la posición (0-9):\n");
                scanf("%d", &posicion);
                printf("Ingrese el valor:\n");
                scanf("%d", &valor);
                arreglo[posicion] = valor;
                break;
            case 2:
                for(i = 0; i < 10; i++) {
                    printf("Posición %d: %d\n", i, arreglo[i]);
                }
                break;
            case 3:
                suma = 0;
                for(i = 0; i < 10; i++) {
                    suma += arreglo[i];
                }
                printf("La sumatoria de todos los elementos es: %d\n", suma);
                break;
            case 4:
                printf("Ingrese la posición del elemento a borrar (0-9):\n");
                scanf("%d", &posicion);
                arreglo[posicion] = 0;
                break;
            case 5:
                printf("Ingrese la posición del elemento a editar (0-9):\n");
                scanf("%d", &posicion);
                printf("Ingrese el nuevo valor:\n");
                scanf("%d", &valor);
                arreglo[posicion] = valor;
                break;
            case 6:
                for(i = 0; i < 10; i++) {
                    arreglo[i] = 0;
                }
                break;
        }
    } while(opcion != 7);

    return 0;
}

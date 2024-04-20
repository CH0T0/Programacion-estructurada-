#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Función para dibujar el ahorcado
void dibujarAhorcado(int intentos) {
    printf("\n  +---+\n  |   |\n");
    // Dibuja la cabeza si los intentos son 6 o menos
    if (intentos <= 6) printf("  O   |\n"); else printf("      |\n");
    // Dibuja el cuerpo si los intentos son 4 o menos
    if (intentos <= 4) printf(" /|\\  |\n"); else if (intentos == 5) printf(" /|   |\n"); else printf("      |\n");
    // Dibuja las piernas si los intentos son 2 o menos
    if (intentos <= 2) printf(" / \\  |\n"); else if (intentos == 3) printf(" /    |\n"); else printf("      |\n");
    printf("      |\n=========\n\n");
}

int main() {
    // Inicializa la semilla para la generación de números aleatorios
    srand(time(0));

    // Define un array de palabras para el juego
    char* palabras[20] = {"manzana", "banana", "cereza", "durazno", "elefante", "fresa", "guitarra", "helado", "iglu", "jirafa", "kilo", "limon", "mango", "naranja", "oso", "piano", "queso", "raton", "sandia", "tortuga"};

    // Selecciona una palabra al azar del array
    char* palabra_secreta = palabras[rand() % 20];

    // Obtiene la longitud de la palabra secreta
    int longitud = strlen(palabra_secreta);

    // Crea una cadena para almacenar la palabra adivinada por el usuario
    char palabra_adivinada[longitud + 1];

    // Inicializa la palabra adivinada con guiones bajos
    for (int i = 0; i < longitud; ++i) {
        palabra_adivinada[i] = '_';
    }
    palabra_adivinada[longitud] = '\0';

    // Define el número de intentos que tiene el usuario
    int intentos = 7;

    // Comienza el juego
    while (intentos > 0 && strcmp(palabra_adivinada, palabra_secreta) != 0) {
        printf("Palabra: %s\nIntentos restantes: %d\n", palabra_adivinada, intentos);
        dibujarAhorcado(intentos);
        printf("Ingresa una letra: ");
        char letra;
        scanf(" %c", &letra);

        // Verifica si la letra ingresada por el usuario está en la palabra secreta
        int letra_encontrada = 0;
        for (int i = 0; i < longitud; ++i) {
            if (palabra_secreta[i] == letra) {
                palabra_adivinada[i] = letra;
                letra_encontrada = 1;
            }
        }

        // Si la letra no está en la palabra secreta, reduce el número de intentos
        if (!letra_encontrada) {
            --intentos;
            // Penaliza con un intento adicional si la letra es una vocal
            if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
                --intentos;
            }
            printf("La letra no está en la palabra secreta.\n");
        }
    }

    // Al final del juego, revela si el usuario ha ganado o perdido
    if (strcmp(palabra_adivinada, palabra_secreta) == 0) {
        printf("¡Felicidades! Has adivinado la palabra secreta: %s\n", palabra_secreta);
    } else {
        printf("Has perdido. La palabra secreta era: %s\n", palabra_secreta);
    }

    return 0;
}

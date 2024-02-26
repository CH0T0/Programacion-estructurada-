#include <stdio.h>

#define MAX 100

// Funciones para las operaciones de conjuntos
void union_conjuntos(int conjunto1[], int conjunto2[], int m, int n);
void interseccion_conjuntos(int conjunto1[], int conjunto2[], int m, int n);
void diferencia_conjuntos(int conjunto1[], int conjunto2[], int m, int n);
void complemento_conjuntos(int universal[], int conjunto[], int m, int n);

int main() {
    int conjunto1[MAX], conjunto2[MAX], m, n, i;

    printf("Introduce el numero de elementos en el primer conjunto: ");
    scanf("%d", &m);
    printf("Introduce los elementos del primer conjunto: ");
    for(i = 0; i < m; i++)
        scanf("%d", &conjunto1[i]);

    printf("Introduce el numero de elementos en el segundo conjunto: ");
    scanf("%d", &n);
    printf("Introduce los elementos del segundo conjunto: ");
    for(i = 0; i < n; i++)
        scanf("%d", &conjunto2[i]);

    union_conjuntos(conjunto1, conjunto2, m, n);
    interseccion_conjuntos(conjunto1, conjunto2, m, n);
    diferencia_conjuntos(conjunto1, conjunto2, m, n);
    // Para el complemento, necesitamos un conjunto universal
    // Aquí asumimos que el conjunto universal es {0, 1, 2, ..., 9}
    int universal[10];
    for(i = 0; i < 10; i++)
        universal[i] = i;
    complemento_conjuntos(universal, conjunto1, 10, m);

    return 0;
}

void union_conjuntos(int conjunto1[], int conjunto2[], int m, int n) {
    int i = 0, j = 0;
    printf("Union: ");
    while(i < m && j < n) {
        if(conjunto1[i] < conjunto2[j])
            printf("%d ", conjunto1[i++]);
        else if(conjunto2[j] < conjunto1[i])
            printf("%d ", conjunto2[j++]);
        else {
            printf("%d ", conjunto2[j++]);
            i++;
        }
    }
    while(i < m)
        printf("%d ", conjunto1[i++]);
    while(j < n)
        printf("%d ", conjunto2[j++]);
    printf("\n");
}

void interseccion_conjuntos(int conjunto1[], int conjunto2[], int m, int n) {
    int i = 0, j = 0;
    printf("Interseccion: ");
    while(i < m && j < n) {
        if(conjunto1[i] < conjunto2[j])
            i++;
        else if(conjunto2[j] < conjunto1[i])
            j++;
        else {
            printf("%d ", conjunto2[j++]);
            i++;
        }
    }
    printf("\n");
}

void diferencia_conjuntos(int conjunto1[], int conjunto2[], int m, int n) {
    int i = 0, j = 0;
    printf("Diferencia (Conjunto1 - Conjunto2): ");
    while(i < m && j < n) {
        if(conjunto1[i] < conjunto2[j])
            printf("%d ", conjunto1[i++]);
        else if(conjunto2[j] < conjunto1[i])
            j++;
        else {
            i++;
            j++;
        }
    }
    while(i < m)
        printf("%d ", conjunto1[i++]);
    printf("\n");
}

void complemento_conjuntos(int universal[], int conjunto[], int m, int n) {
    int i = 0, j = 0;
    printf("Complemento (Universal - Conjunto1): ");
    while(i < m && j < n) {
        if(universal[i] < conjunto[j])
            printf("%d ", universal[i++]);
        else if(conjunto[j] < universal[i])
            j++;
        else {
            i++;
            j++;
        }
    }
    while(i < m)
        printf("%d ", universal[i++]);
    printf("\n");
}

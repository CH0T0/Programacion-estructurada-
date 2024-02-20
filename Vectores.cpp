#include <iostream>  // Incluye la biblioteca iostream que permite la entrada y salida de datos.
#include <vector>    // Incluye la biblioteca vector que permite el uso de vectores.

using namespace std; // Usa el espacio de nombres estándar.

int main() {         // Inicio de la función principal.
    vector<int> arr; // Declara un vector de enteros llamado arr.
    int opcion, indice, valor; // Declara tres variables enteras: opcion, indice y valor.

    while (true) {   // Inicia un bucle infinito.
        cout << "1. Agregar valor\n2. Editar valor\n3. Eliminar valor\n4. Vaciar vector\n5. Mostrar vector y sumatoria\n6. Salir\n"; // Imprime el menú de opciones.
        cin >> opcion; // Lee la opción del usuario.

        switch (opcion) { // Inicia una estructura switch basada en la opción del usuario.
            case 1: // Caso 1: Agregar valor.
                cout << "Valor: "; // Pide al usuario que ingrese un valor.
                cin >> valor; // Lee el valor del usuario.
                arr.push_back(valor); // Agrega el valor al final del vector.
                break; // Rompe el caso.

            case 2: // Caso 2: Editar valor.
                cout << "Indice: "; // Pide al usuario que ingrese un índice.
                cin >> indice; // Lee el índice del usuario.
                if (indice < 0 || indice >= arr.size()) { // Si el índice es inválido...
                    cout << "Indice fuera de rango.\n"; // Imprime un mensaje de error.
                    continue; // Continúa con la siguiente iteración del bucle.
                }
                cout << "Nuevo valor: "; // Pide al usuario que ingrese un nuevo valor.
                cin >> valor; // Lee el nuevo valor del usuario.
                arr[indice] = valor; // Asigna el nuevo valor al índice especificado en el vector.
                break; // Rompe el caso.

            case 3: // Caso 3: Eliminar valor.
                cout << "Indice: "; // Pide al usuario que ingrese un índice.
                cin >> indice; // Lee el índice del usuario.
                if (indice < 0 || indice >= arr.size()) { // Si el índice es inválido...
                    cout << "Indice fuera de rango.\n"; // Imprime un mensaje de error.
                    continue; // Continúa con la siguiente iteración del bucle.
                }
                arr.erase(arr.begin() + indice); // Elimina el valor en el índice especificado del vector.
                break; // Rompe el caso.

            case 4: // Caso 4: Vaciar vector.
                arr.clear(); // Elimina todos los valores del vector.
                break; // Rompe el caso.

            case 5: // Caso 5: Mostrar vector y sumatoria.
                int sum = 0; // Inicializa una variable para la suma.
                for (int i = 0; i < arr.size(); ++i) { // Para cada índice en el vector...
                    cout << arr[i] << ' '; // Imprime el valor en ese índice.
                    sum += arr[i]; // Agrega el valor a la suma.
                }
                cout << "\nSumatoria: " << sum << '\n'; // Imprime la suma de los valores en el vector.
                break; // Rompe el caso.
        }
    }
    return 0; // Finaliza la función principal y devuelve 0.
}

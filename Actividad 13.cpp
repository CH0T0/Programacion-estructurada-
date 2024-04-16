#include <iostream>
#include <algorithm>
#include <cctype>

int main() {
    std::string frase, otraFrase, fraseMinuscula, fraseMayuscula, fraseReversa;

    // Pedir al usuario una palabra o frase
    std::cout << "Por favor, introduce una palabra o frase: ";
    std::getline(std::cin, frase);

    // Contar el número de vocales, consonantes y espacios
    int vocales = 0, consonantes = 0, espacios = 0;
    for (char c : frase) {
        if (std::isspace(c)) espacios++;
        else if (std::isalpha(c)) {
            if (std::tolower(c) == 'a' || std::tolower(c) == 'e' || std::tolower(c) == 'i' || std::tolower(c) == 'o' || std::tolower(c) == 'u') vocales++;
            else consonantes++;
        }
    }

    std::cout << "Vocales: " << vocales << "\n";
    std::cout << "Consonantes: " << consonantes << "\n";
    std::cout << "Espacios: " << espacios << "\n";

    // Determinar si es una palabra palíndromo
    fraseReversa = frase;
    std::reverse(fraseReversa.begin(), fraseReversa.end());
    if (frase == fraseReversa) std::cout << "La frase es un palíndromo.\n";
    else std::cout << "La frase no es un palíndromo.\n";

    // Convertir palabra o frase a Mayúsculas y minúsculas
    fraseMinuscula = frase;
    std::transform(fraseMinuscula.begin(), fraseMinuscula.end(), fraseMinuscula.begin(), ::tolower);
    fraseMayuscula = frase;
    std::transform(fraseMayuscula.begin(), fraseMayuscula.end(), fraseMayuscula.begin(), ::toupper);

    std::cout << "Frase en minúsculas: " << fraseMinuscula << "\n";
    std::cout << "Frase en mayúsculas: " << fraseMayuscula << "\n";

    // Solicitar otra palabra o frase y que se concatene con la anterior
    std::cout << "Por favor, introduce otra palabra o frase: ";
    std::getline(std::cin, otraFrase);

    frase += " " + otraFrase;
    std::cout << "Frase concatenada: " << frase << "\n";

    return 0;
}


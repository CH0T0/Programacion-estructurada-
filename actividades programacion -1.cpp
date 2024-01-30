#include <iostream>
#include <string>

int main() {
    std::string nombre;
    int edad;
    std::string lugarDeResidencia;
    std::string fecha;
    std::string carrera;
    int semestre;

    std::cout << "Introduce tu nombre: ";
    std::getline(std::cin, nombre);

    std::cout << "Introduce tu edad: ";
    std::cin >> edad;

    std::cin.ignore();
    std::cout << "Introduce tu lugar de residencia: ";
    std::getline(std::cin, lugarDeResidencia);

    std::cout << "Introduce la fecha: ";
    std::getline(std::cin, fecha);

    std::cout << "Introduce tu carrera: ";
    std::getline(std::cin, carrera);

    std::cout << "Introduce tu semestre: ";
    std::cin >> semestre;

    std::cout << "\nNombre: " << nombre << "\n";
    std::cout << "Edad: " << edad << "\n";
    std::cout << "Lugar de residencia: " << lugarDeResidencia << "\n";
    std::cout << "Fecha: " << fecha << "\n";
    std::cout << "Carrera: " << carrera << "\n";
    std::cout << "Semestre: " << semestre << "\n";

    return 0;
}

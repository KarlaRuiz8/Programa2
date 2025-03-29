#include <iostream>
#include <cmath> // Para usar la función floor

int main() {
    double x; // Variable para el número original
    double y; // Variable para el número redondeado

    // Solicitar al usuario que ingrese un número
    std::cout << "Ingresa un número: ";
    std::cin >> x;

    // Redondear el número al entero más cercano
    y = floor(x + 0.5);

    // Mostrar el resultado
    std::cout << "Número original: " << x << std::endl;
    std::cout << "Número redondeado: " << y << std::endl;

    return 0;
}
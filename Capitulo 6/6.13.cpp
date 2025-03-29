#include <iostream>
#include <cmath> // Para usar la funci�n floor

int main() {
    double x; // Variable para el n�mero original
    double y; // Variable para el n�mero redondeado

    // Solicitar al usuario que ingrese un n�mero
    std::cout << "Ingresa un n�mero: ";
    std::cin >> x;

    // Redondear el n�mero al entero m�s cercano
    y = floor(x + 0.5);

    // Mostrar el resultado
    std::cout << "N�mero original: " << x << std::endl;
    std::cout << "N�mero redondeado: " << y << std::endl;

    return 0;
}
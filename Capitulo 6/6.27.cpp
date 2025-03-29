#include <iostream>

// Función que retorna el menor de dos números
double menorNumero(double num1, double num2) {
    return (num1 < num2) ? num1 : num2; 
}

int main() {
    double numero1, numero2;

    // Solicitar al usuario que ingrese dos números
    std::cout << "Ingresa el primer número: ";
    std::cin >> numero1;
    std::cout << "Ingresa el segundo número: ";
    std::cin >> numero2;

    // Llamar a la función para encontrar el menor número
    double menor = menorNumero(numero1, numero2);

    // Mostrar el resultado
    std::cout << "El número más pequeño es: " << menor << std::endl;

    return 0;
}
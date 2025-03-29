#include <iostream>

// Función para calcular el máximo común divisor (MCD)
int MCD(int a, int b) {
    // Asegurarse de que los números sean positivos
    a = std::abs(a);
    b = std::abs(b);

    // Algoritmo de Euclides
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Programa de prueba
int main() {
    int num1, num2;

    // Solicitar al usuario la entrada de dos números
    std::cout << "Ingrese el primer número: ";
    std::cin >> num1;
    std::cout << "Ingrese el segundo número: ";
    std::cin >> num2;

    // Calcular y mostrar el MCD
    int resultado = MCD(num1, num2);
    std::cout << "El MCD de " << num1 << " y " << num2 << " es: " << resultado << std::endl;

    return 0;
}
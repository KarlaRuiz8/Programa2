#include <iostream>
#include <cmath>

bool esPrimo(int numero) {
    if (numero <= 1) return false; // Números menores o iguales a 1 no son primos
    for (int i = 2; i <= sqrt(numero); i++) {
        if (numero % i == 0) return false; // Si es divisible por i, no es primo
    }
    return true; 
}

// Función para contar y mostrar números primos entre 2 y 10,000
void encontrarPrimos(int limite) {
    int contador = 0;

    std::cout << "Números entre 2 y " << limite << ":\n";
    for (int i = 2; i <= limite; i++) {
        std::cout << i << " "; // Imprimir todos los números del 2 al límite
        if (esPrimo(i)) {
            contador++;
        }
    }
    std::cout << "\nTotal de números primos encontrados: " << contador << std::endl;
}

// Función para estimar el número de divisiones
int estimarDivisiones(int numero) {
    return static_cast<int>(sqrt(numero)) - 1; 
}

int main() {
    int limite = 10000;

    encontrarPrimos(limite);

    // Ejemplo de estimación de divisiones para el número 10,000
    int estimacion = estimarDivisiones(10000);
    std::cout << "Estimación de divisiones para verificar si 10,000 es primo: " << estimacion << std::endl;

    return 0;
}
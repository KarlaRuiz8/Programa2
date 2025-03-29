#include <iostream>

// Función que verifica si un número es par o impar
int verificaPar(int numero) {
    if (numero % 2 == 0) {
        return numero; // Si es par, devuelve el mismo número
    } else {
        return numero + 1; // Si es impar, devuelve el número + 1
    }
}

int main() {
    int cantidad;

    // Solicitar al usuario la cantidad de números
    std::cout << "¿Cuantos nmeros deseas ingresar? ";
    std::cin >> cantidad;

    // Arreglo para almacenar los números ingresados
    int numeros[cantidad];

    for (int i = 0; i < cantidad; i++) {
        std::cout << "Ingresa el número " << (i + 1) << ": ";
        std::cin >> numeros[i];
    }

    // Procesar y mostrar los resultados
    std::cout << "\nResultados:\n";
    for (int i = 0; i < cantidad; i++) {
        int resultado = verificaPar(numeros[i]);
        std::cout << "Número ingresado: " << numeros[i] << ", Resultado: " << resultado << std::endl;
    }

    return 0;
}
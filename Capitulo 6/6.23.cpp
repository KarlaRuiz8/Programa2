#include <iostream>

// Función que imprime un cuadrado de un carácter específico
void imprimirCuadrado(int lado, char caracterRelleno) {
    for (int i = 0; i < lado; i++) {
        for (int j = 0; j < lado; j++) {
            std::cout << caracterRelleno;
        }
        std::cout << std::endl; 
    }
}

int main() {
    int lado;
    char caracterRelleno;

    // Solicitar al usuario el tamaño del lado y el carácter
    std::cout << "Ingresa el tamaño del lado del cuadrado: ";
    std::cin >> lado;
    std::cout << "Ingresa el carácter para rellenar el cuadrado: ";
    std::cin >> caracterRelleno;

    // Llamar a la función para imprimir el cuadrado
    imprimirCuadrado(lado, caracterRelleno);

    return 0;
}
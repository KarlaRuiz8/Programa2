#include <iostream>
#include <cmath>
#include <stack>
#include <tuple>

// Estructura para representar un movimiento
struct Movimiento {
    int n;       
    char origen; 
    char destino; 
    char auxiliar; 
};

// Función iterativa para resolver las Torres de Hanoi
void hanoiIterativo(int n, char origen, char destino, char auxiliar) {
    // Calcular el número total de movimientos
    int totalMovimientos = pow(2, n) - 1;

    // Si n es par, intercambiar destino y auxiliar
    if (n % 2 == 0) {
        std::swap(destino, auxiliar);
    }

    for (int i = 1; i <= totalMovimientos; i++) {
        if (i % 3 == 1) {
            // Mover disco entre origen y destino
            std::cout << "Mover disco " << ((i % 2 == 1) ? 1 : n) << " de " << origen << " a " << destino << std::endl;
        } else if (i % 3 == 2) {
            // Mover disco entre origen y auxiliar
            std::cout << "Mover disco " << ((i % 2 == 1) ? 1 : n) << " de " << origen << " a " << auxiliar << std::endl;
        } else {
            // Mover disco entre destino y auxiliar
            std::cout << "Mover disco " << ((i % 2 == 1) ? 1 : n) << " de " << destino << " a " << auxiliar << std::endl;
        }
    }
}

// Función principal
int main() {
    int n;

    std::cout << "Ingrese el número de discos: ";
    std::cin >> n;

    std::cout << "Solución Iterativa para " << n << " discos:\n";
    hanoiIterativo(n, 'A', 'C', 'B'); 

    return 0;
}
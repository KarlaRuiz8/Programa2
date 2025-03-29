#include <iostream>

// Función recursiva para calcular el máximo común divisor (MCD)
int mcd(int x, int y) {
    if (y == 0) {
        return x; // Base case: MCD(x, 0) es x
    }
    return mcd(y, x % y); // Recursión: MCD(x, y) = MCD(y, x % y)
}

// Programa principal
int main() {
    int x, y;

    std::cout << "Ingrese el primer numero (x): ";
    std::cin >> x;
    std::cout << "Ingrese el segundo numero (y): ";
    std::cin >> y;

    int resultado = mcd(x, y);
    std::cout << "El maximo comun divisor de " << x << " y " << y << " es: " << resultado << std::endl;

    return 0;
}
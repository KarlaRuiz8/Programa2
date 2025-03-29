#include <iostream>
using namespace std;

// Plantilla de función para encontrar el menor de dos valores
template <typename T>
T menor(T a, T b) {
    return (a < b) ? a : b; // Devuelve el menor de los dos
}

int main() {
    int num1, num2;
    float f1, f2;

    // Ejemplo con enteros
    cout << "Ingrese dos números enteros: ";
    cin >> num1 >> num2;
    cout << "El menor es: " << menor(num1, num2) << endl;

    // Ejemplo con flotantes
    cout << "Ingrese dos números flotantes: ";
    cin >> f1 >> f2;
    cout << "El menor es: " << menor(f1, f2) << endl;

    return 0;
}
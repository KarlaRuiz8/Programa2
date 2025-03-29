#include <iostream>
using namespace std;

// Prototipo de función
int misterio(int n);

int main() {
    int n;
    cout << "Escriba dos enteros: ";
    cin >> n;

    if (n > 0) {
        cout << "El resultado es: " << misterio(n) << endl;
    } else {
        cout << "El número debe ser positivo." << endl;
    }

    return 0; // Fin de la función main
}

// Definición de la función misterio
int misterio(int n) {
    if (n == 1) { // Caso base
        return 1;
    }
    return n + misterio(n - 1); // Llamada recursiva
}
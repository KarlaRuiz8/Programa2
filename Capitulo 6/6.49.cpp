#include <iostream>
using namespace std;

// Función que triplica el valor pasando por valor
void triplicarPorValor(int numero) {
    numero *= 3; 
    cout << "Valor triplicado (por valor): " << numero << endl;
}

// Función que triplica el valor pasando por referencia
void triplicarPorReferencia(int &numero) {
    numero *= 3; 
}

int main() {
    int valor;

    // Solicitar al usuario que ingrese un número
    cout << "Ingrese un número: ";
    cin >> valor;

    // Llamada a la función que triplica por valor
    cout << "Valor original: " << valor << endl;
    triplicarPorValor(valor);
    cout << "Después de triplicar por valor: " << valor << endl; 

    // Llamada a la función que triplica por referencia
    triplicarPorReferencia(valor);
    cout << "Después de triplicar por referencia: " << valor << endl; 
    return 0;
}
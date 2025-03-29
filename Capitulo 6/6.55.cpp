#include <iostream>
using namespace std;

// Definición de la enumeración TipoCuenta
enum TipoCuenta {
    AHORROS,
    CORRIENTE,
    INVERSION
};

int main() {
    int eleccion;

    cout << "Seleccione un tipo de cuenta:\n";
    cout << "0: Ahorros\n";
    cout << "1: Corriente\n";
    cout << "2: Inversión\n";
    cout << "Ingrese su elección (0-2): ";
    cin >> eleccion;

    TipoCuenta cuenta;

    // Validar la elección del usuario
    if (eleccion >= 0 && eleccion <= 2) {
        cuenta = static_cast<TipoCuenta>(eleccion);
    } else {
        cout << "Elección no válida." << endl;
        return 1; // Salir con error
    }

    // Mostrar el tipo de cuenta seleccionado
    switch (cuenta) {
        case AHORROS:
            cout << "Tipo de cuenta: Ahorros." << endl;
            break;
        case CORRIENTE:
            cout << "Tipo de cuenta: Corriente." << endl;
            break;
        case INVERSION:
            cout << "Tipo de cuenta: Inversión." << endl;
            break;
        default:
            cout << "Tipo de cuenta no reconocido." << endl;
    }

    return 0;
}
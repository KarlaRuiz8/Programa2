#include <iostream>
#include <cstdlib>
using namespace std;

// Prototipos de funciones
float suma(int a, int b);
float resta(int a, int b);
float multiplicacion(int a, int b);
float division(int a, int b);
int residuo(int a, int b);

int main() {
    int operadorUno = 0, operadorDos = 0, opcionSeleccionada;
    char salidaMenu;

    do {
        system("cls");  // Limpia la consola
        cout << "=== Calculadora ===" << endl;
        cout << "1. Suma (+)" << endl;
        cout << "2. Resta (-)" << endl;
        cout << "3. Multiplicacion (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Residuo (%)" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionSeleccionada;

        if (opcionSeleccionada >= 1 && opcionSeleccionada <= 5) {
            cout << "Ingrese el primer numero: ";
            cin >> operadorUno;
            cout << "Ingrese el segundo numero: ";
            cin >> operadorDos;

            float resultado = 0;
            switch (opcionSeleccionada) {
                case 1:
                    resultado = suma(operadorUno, operadorDos);
                    break;
                case 2:
                    resultado = resta(operadorUno, operadorDos);
                    break;
                case 3:
                    resultado = multiplicacion(operadorUno, operadorDos);
                    break;
                case 4:
                    if (operadorDos != 0)
                        resultado = division(operadorUno, operadorDos);
                    else
                        cout << "Error: Division por cero no permitida." << endl;
                    break;
                case 5:
                    if (operadorDos != 0)
                        resultado = residuo(operadorUno, operadorDos);
                    else
                        cout << "Error: Division por cero no permitida." << endl;
                    break;
                default:
                    cout << "Opcion invalida." << endl;
            }

            if (opcionSeleccionada != 4 || operadorDos != 0)
                cout << "El resultado es: " << resultado << endl;
        } else {
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }

        cout << "¿Desea realizar otra operacion? (S/N): ";
        cin >> salidaMenu;
    } while (salidaMenu == 's' || salidaMenu == 'S');

    cout << "Gracias por usar la calculadora." << endl;
    return 0;
}

// Definicion de funciones
float suma(int a, int b) {
    return a + b;
}

float resta(int a, int b) {
    return a - b;
}

float multiplicacion(int a, int b) {
    return a * b;
}

float division(int a, int b) {
    return static_cast<float>(a) / b;
}

int residuo(int a, int b) {
    return a % b;
}

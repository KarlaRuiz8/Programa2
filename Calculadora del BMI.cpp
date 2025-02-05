#include <iostream>
using namespace std;

int main() {
    int opcionSeleccionada;
    double operadorUno, operadorDos, resultadoCalculadora;
    double peso, altura, BMI;
    char salidaMenu;

    do {
        system("cls"); 
        cout << "=== Calculadora ===" << endl;
        cout << "1. Suma (+)" << endl;
        cout << "2. Resta (-)" << endl;
        cout << "3. Multiplicacion (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Residuo (%)" << endl;
        cout << "6. Calcular Indice de Masa Corporal (BMI)" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcionSeleccionada;

        if (opcionSeleccionada >= 1 && opcionSeleccionada <= 5) {
            cout << "Ingrese el primer numero: ";
            cin >> operadorUno;
            cout << "Ingrese el segundo numero: ";
            cin >> operadorDos;

            switch (opcionSeleccionada) {
                case 1:
                    resultadoCalculadora = operadorUno + operadorDos;
                    break;
                case 2:
                    resultadoCalculadora = operadorUno - operadorDos;
                    break;
                case 3:
                    resultadoCalculadora = operadorUno * operadorDos;
                    break;
                case 4:
                    if (operadorDos != 0) {
                        resultadoCalculadora = operadorUno / operadorDos;
                    } else {
                        cout << "Error: Division por cero no permitida." << endl;
                        continue;
                    }
                    break;
                case 5:
                    if (operadorDos != 0) {
                        resultadoCalculadora = (int)operadorUno % (int)operadorDos;
                    } else {
                        cout << "Error: Division por cero no permitida." << endl;
                        continue;
                    }
                    break;
            }

            if (opcionSeleccionada != 4 || operadorDos != 0) {
                cout << "El resultado es: " << resultadoCalculadora << endl;
            }
        } else if (opcionSeleccionada == 6) {
            cout << "Ingrese su peso en kilogramos: ";
            cin >> peso;
            cout << "Ingrese su altura en metros: ";
            cin >> altura;

            if (altura > 0) {
                BMI = peso / (altura * altura);
                cout << "Su Indice de Masa Corporal (BMI) es: " << BMI << endl;

                if (BMI < 18.5) {
                    cout << "Clasificacion: Bajo peso" << endl;
                } else if (BMI >= 18.5 && BMI <= 24.9) {
                    cout << "Clasificacion: Peso normal" << endl;
                } else if (BMI >= 25 && BMI <= 29.9) {
                    cout << "Clasificacion: Sobrepeso" << endl;
                } else {
                    cout << "Clasificacion: Obeso" << endl;
                }
            } else {
                cout << "Error: La altura debe ser mayor que 0." << endl;
            }
        } else {
            cout << "Opcion invalida. Intente de nuevo." << endl;
        }

        cout << "¿Desea realizar otra operacion? (S/N): ";
        cin >> salidaMenu;

    } while (salidaMenu == 'S' || salidaMenu == 's');

    cout << "Gracias por usar la calculadora." << endl;
    return 0;
}

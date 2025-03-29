#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0)); // Inicializa la semilla
    int saldoBanco = 1000; // Saldo inicial
    int apuesta;

    while (true) {
        cout << "Introduzca su apuesta: ";
        cin >> apuesta;

        if (apuesta > saldoBanco || apuesta <= 0) {
            cout << "Apuesta inválida. Intente de nuevo." << endl;
            continue;
        }

        int dado1 = rand() % 6 + 1;
        int dado2 = rand() % 6 + 1;
        int sumaDados = dado1 + dado2;
        cout << "Usted lanzó: " << sumaDados << endl;

        if (sumaDados == 7 || sumaDados == 11) {
            saldoBanco += apuesta; // Gana
            cout << "Ganaste! Su nuevo saldo es: " << saldoBanco << endl;
        } else if (sumaDados == 2 || sumaDados == 3 || sumaDados == 12) {
            saldoBanco -= apuesta; // Pierde
            cout << "Perdiste! Su nuevo saldo es: " << saldoBanco << endl;
        } else {
            cout << "Oh, se esta yendo a la quiebra, verdad: " << saldoBanco << endl;
        }

        if (saldoBanco <= 0) {
            cout << "Lo siento. Se quedo sin fondos!" << endl;
            break;
        }
    }
    return 0;
}
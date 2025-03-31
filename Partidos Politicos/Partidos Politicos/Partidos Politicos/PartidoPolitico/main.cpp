#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void imprimirLinea();

int main() {
    srand(time(0));
    char opcion;
    do {
        int numCandidatos;

        cout << "Ingrese el número de candidatos: ";
        cin >> numCandidatos;

        string* candidatos = new string[numCandidatos];
        int votos[numCandidatos][5] = {0};
        int totalVotos[numCandidatos] = {0};

        cin.ignore(); // Limpiar el buffer de entrada
        for (int i = 0; i < numCandidatos; i++) {
            cout << "Ingrese el nombre del candidato " << i + 1 << ": ";
            getline(cin, candidatos[i]);
        }

        for (int j = 0; j < 5; j++) {
            int votosRestantes = 50;

            for (int i = 0; i < numCandidatos; i++) {
                if (i == numCandidatos - 1) {
                    // Asignar los votos restantes al último candidato
                    votos[i][j] = votosRestantes;
                } else {
                    // Generar un número aleatorio de votos para el candidato actual
                    votos[i][j] = rand() % (votosRestantes - (numCandidatos - i - 1)) + 1;
                    votosRestantes -= votos[i][j];
                }
                totalVotos[i] += votos[i][j];
            }
        }

        cout << "\nTabla de votos:" << endl;
        imprimirLinea();
        cout << "| " << setw(12) << "Candidato" << " | ";
        for (int j = 0; j < 5; j++) {
            cout << "Votos " << j + 1 << " | ";
        }
        cout << "Total  |" << endl;
        imprimirLinea();

        for (int i = 0; i < numCandidatos; i++) {
            cout << "| " << setw(12) << candidatos[i] << " | ";
            for (int j = 0; j < 5; j++) {
                cout << setw(7) << votos[i][j] << " | ";
            }
            cout << setw(6) << totalVotos[i] << " |" << endl;
            imprimirLinea();
        }

        int maxVotos = totalVotos[0], minVotos = totalVotos[0];
        int ganador = 0, perdedor = 0;

        for (int i = 1; i < numCandidatos; i++) {
            if (totalVotos[i] > maxVotos) {
                maxVotos = totalVotos[i];
                ganador = i;
            }
            if (totalVotos[i] < minVotos) {
                minVotos = totalVotos[i];
                perdedor = i;
            }
        }

        cout << "\nEl candidato ganador es: " << candidatos[ganador] << " con " << maxVotos << " votos." << endl;
        cout << "El candidato con menos votos es: " << candidatos[perdedor] << " con " << minVotos << " votos." << endl;

        cout << "¿Desea realizar otra elección? (S/N): ";
        cin >> opcion;
        delete[] candidatos; // Liberar la memoria asignada
    } while (opcion == 'S' || opcion == 's');
    return 0;
}

void imprimirLinea() {
    cout << "+--------------+---------+---------+---------+---------+---------+-------+" << endl;
}

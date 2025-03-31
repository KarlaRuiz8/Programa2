#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Candidato.h"

using namespace std;

void imprimirLinea();

int main() {
    srand(time(0));
    char opcion;

    do {
        int numCandidatos;
        cout << "Ingrese el número de candidatos: ";
        cin >> numCandidatos;

        vector<Candidato> candidatos;
        cin.ignore();

        for (int i = 0; i < numCandidatos; i++) {
            string nombre;
            cout << "Ingrese el nombre del candidato " << i + 1 << ": ";
            getline(cin, nombre);
            candidatos.push_back(Candidato(nombre));
        }

        for (int j = 0; j < 5; j++) {
            int votosRestantes = 50;

            for (int i = 0; i < numCandidatos; i++) {
                int votosAsignados;
                if (i == numCandidatos - 1) {
                    votosAsignados = votosRestantes;
                } else {
                    votosAsignados = rand() % (votosRestantes - (numCandidatos - i - 1)) + 1;
                    votosRestantes -= votosAsignados;
                }
                candidatos[i].asignarVoto(votosAsignados);
            }
        }

        cout << "\nTabla de votos:\n";
        imprimirLinea();
        cout << "| " << setw(12) << "Candidato" << " | ";
        for (int j = 0; j < 5; j++) {
            cout << "Votos " << j + 1 << " | ";
        }
        cout << "Total  |" << endl;
        imprimirLinea();

        int maxVotos = 0, minVotos = INT_MAX;
        string ganador, perdedor;

        for (auto& candidato : candidatos) {
            cout << "| " << setw(12) << candidato.getNombre() << " | ";
            cout << setw(7) << candidato.getTotalVotos() << " | ";
            cout << endl;
            imprimirLinea();

            if (candidato.getTotalVotos() > maxVotos) {
                maxVotos = candidato.getTotalVotos();
                ganador = candidato.getNombre();
            }
            if (candidato.getTotalVotos() < minVotos) {
                minVotos = candidato.getTotalVotos();
                perdedor = candidato.getNombre();
            }
        }

        cout << "\nEl candidato ganador es: " << ganador << " con " << maxVotos << " votos.\n";
        cout << "El candidato con menos votos es: " << perdedor << " con " << minVotos << " votos.\n";

        cout << "¿Desea realizar otra elección? (S/N): ";
        cin >> opcion;
    } while (opcion == 'S' || opcion == 's');

    return 0;
}

void imprimirLinea() {
    cout << "+--------------+---------+---------+---------+---------+---------+-------+\n";
}

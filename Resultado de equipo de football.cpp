#include <iostream>
#include <iomanip>
using namespace std;

const int NUM_EQUIPOS = 6;
const int NUM_PARTIDOS = NUM_EQUIPOS * (NUM_EQUIPOS - 1);

struct Equipo {
    string nombre;
    int jugados = 0, ganados = 0, empatados = 0, perdidos = 0, puntos = 0;
    double porcentaje = 0.0;
};

void ingresarResultados(Equipo equipos[]);
void calcularPorcentajes(Equipo equipos[]);
void mostrarTabla(const Equipo equipos[]);

int main() {
    Equipo equipos[NUM_EQUIPOS] = {
        {"Equipo 1"}, {"Equipo 2"}, {"Equipo 3"}, 
        {"Equipo 4"}, {"Equipo 5"}, {"Equipo 6"}
    };

    ingresarResultados(equipos);
    calcularPorcentajes(equipos);
    mostrarTabla(equipos);
    return 0;
}

void ingresarResultados(Equipo equipos[]) {
    cout << "Ingrese los resultados de los partidos (victorias 3pts, empate 1pt, derrota 0pts):\n";
    for (int i = 0; i < NUM_EQUIPOS; i++) {
        for (int j = 0; j < NUM_EQUIPOS; j++) {
            if (i != j) {
                int resultado;
                cout << equipos[i].nombre << " vs " << equipos[j].nombre << " (1=Gana, 2=Empate, 3=Pierde): ";
                cin >> resultado;
                equipos[i].jugados++;
                
                if (resultado == 1) {
                    equipos[i].ganados++;
                    equipos[i].puntos += 3;
                } else if (resultado == 2) {
                    equipos[i].empatados++;
                    equipos[i].puntos += 1;
                } else if (resultado == 3) {
                    equipos[i].perdidos++;
                }
            }
        }
    }
}

void calcularPorcentajes(Equipo equipos[]) {
    for (int i = 0; i < NUM_EQUIPOS; i++) {
        if (equipos[i].jugados > 0) {
            equipos[i].porcentaje = (equipos[i].puntos * 100.0) / (equipos[i].jugados * 3);
        }
    }
}

void mostrarTabla(const Equipo equipos[]) {
    cout << "\nTabla de Posiciones:\n";
    cout << left << setw(12) << "Equipo" << setw(8) << "J" << setw(8) << "G" << setw(8) << "E" << setw(8) << "P" << setw(10) << "Puntos" << "% Efect." << endl;
    cout << "-------------------------------------------------------------------" << endl;
    for (int i = 0; i < NUM_EQUIPOS; i++) {
        cout << left << setw(12) << equipos[i].nombre
             << setw(8) << equipos[i].jugados
             << setw(8) << equipos[i].ganados
             << setw(8) << equipos[i].empatados
             << setw(8) << equipos[i].perdidos
             << setw(10) << equipos[i].puntos
             << fixed << setprecision(2) << equipos[i].porcentaje << "%" << endl;
    }
}

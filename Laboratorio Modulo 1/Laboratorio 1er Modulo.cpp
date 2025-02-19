#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

#define NUM_CANDIDATOS 3
#define NUM_VOTANTES 50
#define NUM_RONDAS 5

void ingresarCandidatos(string candidatos[]);
void generarVotos(int votos[][NUM_RONDAS], int numCandidatos);
void mostrarResultados(string candidatos[], int votos[][NUM_RONDAS], int numCandidatos);
void determinarGanador(string candidatos[], int votos[][NUM_RONDAS], int numCandidatos);

int main() {
    srand(time(0)); // Inicializar generador de números aleatorios
    string candidatos[NUM_CANDIDATOS];
    int votos[NUM_CANDIDATOS][NUM_RONDAS] = {0};
    char opcion;
    
    do {
        system("cls");
        cout << "*** Control de Votaciones del Partido Politico ***\n\n";
        ingresarCandidatos(candidatos);
        generarVotos(votos, NUM_CANDIDATOS);
        mostrarResultados(candidatos, votos, NUM_CANDIDATOS);
        determinarGanador(candidatos, votos, NUM_CANDIDATOS);
        
        cout << "\n\nDesea realizar otra elección? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');
    
    return 0;
}

void ingresarCandidatos(string candidatos[]) {
    cout << "Ingrese los nombres de los " << NUM_CANDIDATOS << " candidatos:\n";
    for (int i = 0; i < NUM_CANDIDATOS; i++) {
        cout << "Candidato " << i + 1 << ": ";
        cin >> candidatos[i];
    }
}

void generarVotos(int votos[][NUM_RONDAS], int numCandidatos) {
    for (int i = 0; i < numCandidatos; i++) {
        for (int j = 0; j < NUM_RONDAS; j++) {
            votos[i][j] = rand() % (NUM_VOTANTES + 1);
        }
    }
}

void mostrarResultados(string candidatos[], int votos[][NUM_RONDAS], int numCandidatos) {
    cout << "\nResultados de la votación:\n";
    cout << setw(15) << "Candidato";
    for (int i = 0; i < NUM_RONDAS; i++) {
        cout << setw(10) << "Ronda " << i + 1;
    }
    cout << setw(10) << "Total" << endl;
    
    for (int i = 0; i < numCandidatos; i++) {
        cout << setw(15) << candidatos[i];
        int total = 0;
        for (int j = 0; j < NUM_RONDAS; j++) {
            cout << setw(10) << votos[i][j];
            total += votos[i][j];
        }
        cout << setw(10) << total << endl;
    }
}

void determinarGanador(string candidatos[], int votos[][NUM_RONDAS], int numCandidatos) {
    int maxVotos = 0, minVotos = NUM_VOTANTES * NUM_RONDAS;
    string ganador, perdedor;
    
    for (int i = 0; i < numCandidatos; i++) {
        int total = 0;
        for (int j = 0; j < NUM_RONDAS; j++) {
            total += votos[i][j];
        }
        if (total > maxVotos) {
            maxVotos = total;
            ganador = candidatos[i];
        }
        if (total < minVotos) {
            minVotos = total;
            perdedor = candidatos[i];
        }
    }
    
    cout << "\nEl candidato ganador es: " << ganador << " con " << maxVotos << " votos.";
    cout << "\nEl candidato con menos votos es: " << perdedor << " con " << minVotos << " votos.";
}

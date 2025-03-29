#include <iostream>
#include <cstdlib>  
#include <ctime>    

void jugar() {
    // Inicializar generador de números aleatorios
    srand(static_cast<unsigned int>(time(0)));
    
    int numeroSecreto = rand() % 1000 + 1; // Número entre 1 y 1000
    int intento;
    int intentos = 0;
    const int maxIntentos = 10;

    std::cout << "Tengo un número entre 1 y 1000." << std::endl;
    std::cout << "Puedes adivinar mi numero? Por favor escribe tu respuesta." << std::endl;

    while (intentos < maxIntentos) {
        std::cout << "Intento " << (intentos + 1) << ": ";
        std::cin >> intento;
        intentos++;

        if (intento < numeroSecreto) {
            std::cout << "Demasiado bajo. Intenta de nuevo." << std::endl;
        } else if (intento > numeroSecreto) {
            std::cout << "Demasiado alto. Intenta de nuevo." << std::endl;
        } else {
            std::cout << "Aja! Sabia usted el secreto" << intentos << " intentos." << std::endl;
            return; // Termina el juego si se adivina el número
        }

        if (intentos >= maxIntentos) {
            std::cout << "Deberia haberlo hecho mejor!" << numeroSecreto << "." << std::endl;
            std::cout << "¿Por qué no se deben requerir más de 10 intentos? Bueno, 'buen intento'." << std::endl;
        }
    }
}

int main() {
    jugar();
    return 0;
}
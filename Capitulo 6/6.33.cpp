#include <iostream>
#include <cstdlib>  
#include <ctime>    

int main() {
    // Inicializar generador de números aleatorios
    srand(static_cast<unsigned int>(time(0)));

    int caras = 0;
    int cruces = 0;
    const int lanzamientos = 100;

    // Simular el lanzamiento de la moneda
    for (int i = 0; i < lanzamientos; ++i) {
        // Generar un número aleatorio, 0 o 1
        int resultado = rand() % 2; // 0 para cara, 1 para cruz

        if (resultado == 0) {
            std::cout << "Lanzamiento " << (i + 1) << ": Cara" << std::endl;
            caras++;
        } else {
            std::cout << "Lanzamiento " << (i + 1) << ": Cruz" << std::endl;
            cruces++;
        }
    }

    // Mostrar resultados finales
    std::cout << "\nTotal de lanzamientos: " << lanzamientos << std::endl;
    std::cout << "Total de Caras: " << caras << std::endl;
    std::cout << "Total de Cruces: " << cruces << std::endl;

    return 0;
}
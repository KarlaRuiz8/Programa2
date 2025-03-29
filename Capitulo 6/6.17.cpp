#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    
    srand(time(NULL));

    // a) Imprimir un número aleatorio del conjunto {2, 4, 6, 8, 10}
    std::cout << "Número aleatorio de {2, 4, 6, 8, 10}: ";
    std::cout << (2 + (rand() % 5) * 2) << std::endl;

    // b) Imprimir un número aleatorio del conjunto {3, 5, 7, 9, 11}
    std::cout << "Número aleatorio de {3, 5, 7, 9, 11}: ";
    std::cout << (3 + (rand() % 5) * 2) << std::endl;

    // c) Imprimir un número aleatorio del conjunto {6, 10, 14, 18, 22}
    std::cout << "Número aleatorio de {6, 10, 14, 18, 22}: ";
    std::cout << (6 + (rand() % 5) * 4) << std::endl;

    return 0;
}
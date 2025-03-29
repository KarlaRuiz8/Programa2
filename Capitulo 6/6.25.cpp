#include <iostream>

// Función para convertir horas, minutos y segundos a total de segundos
int convertirASegundos(int horas, int minutos, int segundos) {
    return (horas * 3600) + (minutos * 60) + segundos;
}

// Función para calcular el número de segundos entre dos horas
int calcularSegundosEntre(int h1, int m1, int s1, int h2, int m2, int s2) {
    int totalSegundos1 = convertirASegundos(h1, m1, s1);
    int totalSegundos2 = convertirASegundos(h2, m2, s2);
    
    return totalSegundos2 - totalSegundos1; 
}

int main() {
    int horas1, minutos1, segundos1;
    int horas2, minutos2, segundos2;

    // Solicitar al usuario que ingrese la primera hora
    std::cout << "Ingresa la primera hora (horas minutos segundos): ";
    std::cin >> horas1 >> minutos1 >> segundos1;

    // Solicitar al usuario que ingrese la segunda hora
    std::cout << "Ingresa la segunda hora (horas minutos segundos): ";
    std::cin >> horas2 >> minutos2 >> segundos2;

    // Calcular y mostrar la diferencia en segundos
    int diferenciaSegundos = calcularSegundosEntre(horas1, minutos1, segundos1, horas2, minutos2, segundos2);
    std::cout << "La diferencia en segundos es: " << diferenciaSegundos << std::endl;

    return 0;
}
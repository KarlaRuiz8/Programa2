#include <iostream>
#include <cmath> // Para la función sqrt()

// Función que calcula la hipotenusa
double hipotenusa(double lado1, double lado2) {
    return sqrt(lado1 * lado1 + lado2 * lado2); // Teorema de Pitágoras
}

int main() {
    // Datos de los triángulos
    double lados[3][2] = {
        {3.0, 4.0},
        {5.0, 12.0},
        {8.0, 15.0}
    };

    // Calcular y mostrar la hipotenusa para cada triángulo
    for (int i = 0; i < 3; i++) {
        double lado1 = lados[i][0];
        double lado2 = lados[i][1];
        double resultado = hipotenusa(lado1, lado2);
        std::cout << "Triángulo " << (i + 1) << ": Lado 1 = " << lado1 
                  << ", Lado 2 = " << lado2 
                  << ", Hipotenusa = " << resultado << std::endl;
    }

    return 0;
}
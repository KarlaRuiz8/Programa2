#include <iostream>

// Función no recursiva para calcular el n-ésimo número de Fibonacci
int fibonacci(int n) {
    if (n <= 0) return 0; 
    if (n == 1) return 1; 

    int a = 0; 
    int b = 1; 
    int resultado;

    for (int i = 2; i <= n; ++i) {
        resultado = a + b; // Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
        a = b;             
        b = resultado;     
    }

    return resultado; // Devolver el n-ésimo número de Fibonacci
}

// Programa de prueba
int main() {
    int n;

    std::cout << "Ingrese un numero para calcular el n-esimo numero de Fibonacci: ";
    std::cin >> n;

    int resultado = fibonacci(n);
    std::cout << "El n-esimo número de Fibonacci es: " << resultado << std::endl;

    return 0;
}
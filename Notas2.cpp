// Declaración de Bibliotecas y librerías estándar de C++
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

// Declaración de Constantes
#define NUMERO_ALUMNOS 5
#define NUMERO_MATERIAS 5
#define NUMERO_NOTAS 4
#define MAX_CALIFICACION 100
#define MIN_CALIFICACION 0
#define MAXIMA_LONGITUD_CADENA 100

// Declaración de Prototipos de Función
void llamaCiclo();   // Función que controla el Ciclo comparativo de datos por todas las facultades
int busquedaAleatorios(int minimo, int maximo); // Función que permite obtener valores aleatorios en las notas de cada alumno
void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]); // Función que permite asignar a cada alumno las notas aleatorias
void imprimirMatrizLinea(); // Función que apoya el despliegue de títulos en el comparativo de facultades
float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA], string nombreFacultad);

// Función principal
int main()
{
    srand(getpid()); // Proceso preparativo para generación de valores aleatorios
    llamaCiclo();
    return 0;
}

void llamaCiclo()
{
    // Declaración de matrices por cada facultad
    float matriz_facultad_1[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_2[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_3[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];

    char opcion;  // Variable que controla el ciclo de repetición
    bool repetir = true;  // Variable booleana del ciclo de repetición

    // Declaración de variables flotantes para el cálculo de promedios
    float promedio_facultad_1;
    float promedio_facultad_2;
    float promedio_facultad_3;

    // Declaración de matriz que almacenará los nombres de los alumnos
    char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA] = {"Carlos", "Luis", "Maria", "Pedro", "Juan"};

    // Inicialización de contadores para las preguntas adicionales
    int numeroDeCalculos = 0;  // Cuántas veces se ha calculado
    int ganadasFacultad1 = 0, ganadasFacultad2 = 0, ganadasFacultad3 = 0; // Cuántas veces ha ganado cada facultad

    // Ciclo repetitivo del comparativo de facultades
    do
    {
        system("cls");
        // Inicializar los promedios por facultad
        promedio_facultad_1 = 0;
        promedio_facultad_2 = 0;
        promedio_facultad_3 = 0;

        cout << "*** Comparativo de Facultades ***" << endl << endl;
        llenarMatriz(matriz_facultad_1); // Calculo de las notas por facultad
        promedio_facultad_1 = imprimirMatriz(matriz_facultad_1, alumnos, "Facultad de Ingenieria"); // Despliegue de valores por facultad
        llenarMatriz(matriz_facultad_2);
        promedio_facultad_2 = imprimirMatriz(matriz_facultad_2, alumnos, "Facultad de Arquitectura");
        llenarMatriz(matriz_facultad_3);
        promedio_facultad_3 = imprimirMatriz(matriz_facultad_3, alumnos, "Facultad de Administracion");

        // Calculo del mejor promedio de las facultades
        if (promedio_facultad_1 > promedio_facultad_2 && promedio_facultad_1 > promedio_facultad_3)
        {
            // Facultad 1 es mayor
            cout << "La facultad con el mejor promedio es: " << "Facultad de Ingenieria" << " Promedio: " << promedio_facultad_1 << endl;
            ganadasFacultad1++;
        }
        else if (promedio_facultad_2 > promedio_facultad_1 && promedio_facultad_2 > promedio_facultad_3)
        {
            // Facultad 2 es mayor
            cout << "La facultad con el mejor promedio es: " << "Facultad de Arquitectura" << " Promedio: " << promedio_facultad_2 << endl;
            ganadasFacultad2++;
        }
        else if (promedio_facultad_3 > promedio_facultad_2 && promedio_facultad_3 > promedio_facultad_1)
        {
            // Facultad 3 es mayor
            cout << "La facultad con el mejor promedio es: " << "Facultad de Administracion" << " Promedio: " << promedio_facultad_3 << endl;
            ganadasFacultad3++;
        }
        else
        {
            // Varias facultades tienen el mismo promedio
            cout << "Algunas facultades tienen el mismo promedio." << endl << endl;
        }

        numeroDeCalculos++; // Incrementamos el número de cálculos realizados

        cout << "Desea otro cálculo (s/n)? ";
        cin >> opcion;
        if (opcion == 'n')
        {
            repetir = false;
        }

    } while (repetir);

    // Respuestas a las preguntas adicionales
    cout << "\n1. Número de cálculos realizados: " << numeroDeCalculos << endl;
    if (ganadasFacultad1 > ganadasFacultad2 && ganadasFacultad1 > ganadasFacultad3)
    {
        cout << "2. La facultad que más veces ha ganado: Facultad de Ingenieria" << endl;
    }
    else if (ganadasFacultad2 > ganadasFacultad1 && ganadasFacultad2 > ganadasFacultad3)
    {
        cout << "2. La facultad que más veces ha ganado: Facultad de Arquitectura" << endl;
    }
    else if (ganadasFacultad3 > ganadasFacultad1 && ganadasFacultad3 > ganadasFacultad2)
    {
        cout << "2. La facultad que más veces ha ganado: Facultad de Administracion" << endl;
    }
    else
    {
        cout << "2. Varias facultades han ganado el mismo número de veces." << endl;
    }

    cout << "3. Número de veces que cada facultad ha ganado:" << endl;
    cout << "Facultad de Ingenieria: " << ganadasFacultad1 << " veces." << endl;
    cout << "Facultad de Arquitectura: " << ganadasFacultad2 << " veces." << endl;
    cout << "Facultad de Administracion: " << ganadasFacultad3 << " veces." << endl;
}

int busquedaAleatorios(int minimo, int maximo)
{
    // Cálculo de valores aleatorios tomando como base la nota mínima y máxima del parcial
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1])
{
    // Función que permite llenar cada matriz con valores aleatorios
    int y, x;
    for (y = 0; y < NUMERO_ALUMNOS; y++)
    {
        float suma = 0;
        int calificacion = 0;
        for (x = 0; x < NUMERO_NOTAS; x++)
        {
            if (x == 0 || x == 3) // Cálculo del primer parcial o actividades
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 20);
            }
            else if (x == 1) // Cálculo del segundo parcial
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 25);
            }
            else if (x == 2) // Cálculo del examen final
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 35);
            }
            suma += (float)calificacion;
            matriz[y][x] = calificacion;
            calificacion = 0;
        }
        // Agregar promedio al final de la matriz
        matriz[y][NUMERO_NOTAS] = suma;
    }
}

void imprimirMatrizLinea()
{
    // Función que despliega título de cada nota calculada
    int x;
    cout << "+--------";
    for (x = 0; x < NUMERO_NOTAS + 1; x++)
    {
        cout << "+---------";
    }
    cout << "+\n";
}

float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], char alumnos[NUMERO_ALUMNOS][MAXIMA_LONGITUD_CADENA], string nombreFacultad)
{
    // Función que imprime la matriz en pantalla y realiza los cálculos necesarios del promedio
    int y, x;
    float promedioMayor = matriz[0][NUMERO_NOTAS];
    float promedioMenor = matriz[0][NUMERO_NOTAS];
    float totalGeneral = 0;
    float promedioGeneral = 0;
    char alumnoPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char alumnoPromedioMenor[MAXIMA_LONGITUD_CADENA];
    memcpy(alumnoPromedioMayor, alumnos[0], MAXIMA_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, alumnos[0], MAXIMA_LONGITUD_CADENA);

    cout << nombreFacultad << endl;
    cout << "(Nota1)=>Primer Parcial  (Nota2)=>Segundo Parcial (Nota3)=>Final (Nota4)=>Actividades" << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Alumno";
    for (x = 0; x < NUMERO_NOTAS; x++)
    {
        cout << setw(9) << "Nota" << x + 1;
    }
    cout << setw(8) << "Tot" << endl;
    imprimirMatrizLinea();

    for (y = 0; y < NUMERO_ALUMNOS; y++)
    {
        cout << "!" << setw(8) << alumnos[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_NOTAS; x++)
        {
            int calificacion = matriz[y][x];
            cout << setw(9) << calificacion << "!";
        }
        float promedio = matriz[y][NUMERO_NOTAS];
        totalGeneral += matriz[y][NUMERO_NOTAS];
        if (promedio > promedioMayor) // Se va guardando la nota mayor y el nombre del alumno
        {
            promedioMayor = promedio;
            memcpy(alumnoPromedioMayor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor) // Se va guardando la nota menor y el nombre del alumno
        {
            promedioMenor = promedio;
            memcpy(alumnoPromedioMenor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }

    // Cálculo del promedio general de cada facultad
    promedioGeneral = totalGeneral / NUMERO_ALUMNOS;
    cout << "Nota mayor: " << setw(10) << alumnoPromedioMayor << setw(10) << promedioMayor << endl;
    cout << "Nota menor: " << setw(10) << alumnoPromedioMenor << setw(10) << promedioMenor << endl;
    cout << "Nota prom : " << setw(10) << promedioGeneral << endl << endl;

    return promedioGeneral; // Retorno del promedio general por facultad
}

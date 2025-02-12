#include <iostream>
#include <iomanip> 
#include <cstdlib> 
#include <ctime>   

using namespace std;

// Declaración de Constantes
#define NUMEROALUMNOS 5
#define NUMERONOTAS 4
#define MAX_CALIFICACION 100
#define MIN_CALIFICACION 0
#define MAX_LONGITUD_CADENA 100

// Declaración de Prototipos de Función
void LlamarCiclo();
void InicializarMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS + 1]);
void LlenarMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS + 1]);
float imprimirMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS + 1], string alumnosFacultad[]);
int busquedaAleatoriaDeNotas(int minimo, int maximo);

int main()
{
    srand(time(NULL)); // Inicializar números aleatorios con las bibliotecas nuevas
    LlamarCiclo();
    return 0;
}

void LlamarCiclo()
{
    float matrizFacultad_1[NUMEROALUMNOS][NUMERONOTAS + 1];
    float matrizFacultad_2[NUMEROALUMNOS][NUMERONOTAS + 1];
    float matrizFacultad_3[NUMEROALUMNOS][NUMERONOTAS + 1];

    char opcion;
    bool repetir = true;

    float promedioFacultad_1;
    float promedioFacultad_2;
    float promedioFacultad_3;

    // Lista de nombres de los alumnos
    string alumnosFacultad[NUMEROALUMNOS] = {"Carlos", "Luis", "Maria", "Pedro", "Mario"};

    do
    {//se agrega system cls para limpiar pantalla
        system("CLS");
        promedioFacultad_1 = 0;
        promedioFacultad_2 = 0;
        promedioFacultad_3 = 0;
        cout << "\n*** Comparativo de Facultades ***\n\n";

        InicializarMatriz(matrizFacultad_1);
        InicializarMatriz(matrizFacultad_2);
        InicializarMatriz(matrizFacultad_3);

        LlenarMatriz(matrizFacultad_1);
        LlenarMatriz(matrizFacultad_2);
        LlenarMatriz(matrizFacultad_3);

        promedioFacultad_1 = imprimirMatriz(matrizFacultad_1, alumnosFacultad);
        promedioFacultad_2 = imprimirMatriz(matrizFacultad_2, alumnosFacultad);
        promedioFacultad_3 = imprimirMatriz(matrizFacultad_3, alumnosFacultad);

        // Preguntar al usuario si desea repetir
        cout << "\n¿Desea continuar? (s/n): ";
        cin >> opcion;

        if (opcion == 'n' || opcion == 'N')
        {
            repetir = false; // Salir del bucle
        }

    } while (repetir);
}

void InicializarMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS + 1])
{
    for (int i = 0; i < NUMEROALUMNOS; i++)
    {
        for (int j = 0; j <= NUMERONOTAS; j++)
        {
            matriz[i][j] = 0.0;
        }
    }
}

void LlenarMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS + 1])
{
    for (int i = 0; i < NUMEROALUMNOS; i++)
    {
        float suma = 0;
        int calificacionAlumno = 0;
        for (int j = 0; j < NUMERONOTAS; j++)
        {
            if (j == 0 || j == 3) // Primer parcial y actividades
            {
                calificacionAlumno = busquedaAleatoriaDeNotas(MIN_CALIFICACION, 20);
            }
            else if (j == 1) // Segundo parcial
            {
                calificacionAlumno = busquedaAleatoriaDeNotas(MIN_CALIFICACION, 25);
            }
            else if (j == 2) // Examen final
            {
                calificacionAlumno = busquedaAleatoriaDeNotas(MIN_CALIFICACION, 35);
            }
            suma+=(float)calificacionAlumno;
            matriz[i][j] = (float)calificacionAlumno;
            calificacionAlumno=0;
        }
        matriz[i][NUMERONOTAS] = suma; // Guardar la suma de las calificaciones
    }
}

float imprimirMatriz(float matriz[NUMEROALUMNOS][NUMERONOTAS + 1], string alumnosFacultad[])
{
    int x, y;
    float totalGeneral = 0;
    float promedioGeneral = 0;

    cout << "\n(nota1)=>Primer Parcial (Nota2)=>Segundo Parcial (Nota3)=>Final (Nota4)=>Actividades" << endl;
    cout << setw(12) << "Alumno";
    for (x = 1; x <= NUMERONOTAS; x++)
    {
        cout << setw(8) << "Nota" << x;
    }
    cout << setw(10) << "Total" << endl;

    for (x = 0; x < NUMEROALUMNOS; x++)
    {
        cout << setw(12) << alumnosFacultad[x]; // Imprime el nombre de los alumnos en pantalla
        for (y = 0; y <= NUMERONOTAS; y++)
        {
            cout << setw(8) << matriz[x][y];
        }
        cout << endl;
        totalGeneral += matriz[x][NUMERONOTAS];
    }
// Funcion para calcular el promedio
    promedioGeneral = totalGeneral / NUMEROALUMNOS;
    cout << "\nPromedio general: " << promedioGeneral << endl;
    return promedioGeneral;
}

int busquedaAleatoriaDeNotas(int minimo, int maximo)
{
    return minimo + rand() % (maximo - minimo + 1);
}


Algoritmo Calculadora_IMC
    Definir peso, altura, BMI Como Real
    Definir opcion Como Entero
    Definir salir Como Caracter
    
    Repetir
        LimpiarPantalla
        Escribir "Calculadora del Índice de Masa Corporal (BMI)"
        Escribir "Seleccione la unidad de medida:"
        Escribir "1. Peso en libras y altura en pulgadas"
        Escribir "2. Peso en kilogramos y altura en metros"
        Escribir "Opción: "
        Leer opcion
        
        Segun opcion Hacer
            Caso 1:
                Escribir "Ingrese su peso en libras: "
                Leer peso
                Escribir "Ingrese su altura en pulgadas: "
                Leer altura
                BMI <- (peso * 703) / (altura * altura)
            Caso 2:
                Escribir "Ingrese su peso en kilogramos: "
                Leer peso
                Escribir "Ingrese su altura en metros: "
                Leer altura
                BMI <- peso / (altura * altura)
            De otro modo:
                Escribir "Opción no válida. Intente de nuevo."
                
        FinSegun
        
        Escribir "Su índice de masa corporal (BMI) es: ", BMI
        
        Si BMI < 18.5 Entonces
            Escribir "Clasificación: Bajo peso"
        Sino
            Si BMI >= 18.5 y BMI <= 24.9 Entonces
                Escribir "Clasificación: Peso normal"
            Sino
                Si BMI >= 25 y BMI <= 29.9 Entonces
                    Escribir "Clasificación: Sobrepeso"
                Sino
                    Escribir "Clasificación: Obeso"
                FinSi
            FinSi
        FinSi
        
        Escribir "¿Desea calcular otro índice de masa corporal? (S/N): "
        Leer salir
    Hasta Que salir = "N" o salir = "n"
    
    Escribir "Gracias por usar la calculadora de BMI. ¡Hasta luego!"
    
FinAlgoritmo

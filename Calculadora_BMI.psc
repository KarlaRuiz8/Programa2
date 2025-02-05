Algoritmo Calculadora_IMC
    Definir peso, altura, BMI Como Real
    Definir opcion Como Entero
    Definir salir Como Caracter
    
    Repetir
        LimpiarPantalla
        Escribir "Calculadora del �ndice de Masa Corporal (BMI)"
        Escribir "Seleccione la unidad de medida:"
        Escribir "1. Peso en libras y altura en pulgadas"
        Escribir "2. Peso en kilogramos y altura en metros"
        Escribir "Opci�n: "
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
                Escribir "Opci�n no v�lida. Intente de nuevo."
                
        FinSegun
        
        Escribir "Su �ndice de masa corporal (BMI) es: ", BMI
        
        Si BMI < 18.5 Entonces
            Escribir "Clasificaci�n: Bajo peso"
        Sino
            Si BMI >= 18.5 y BMI <= 24.9 Entonces
                Escribir "Clasificaci�n: Peso normal"
            Sino
                Si BMI >= 25 y BMI <= 29.9 Entonces
                    Escribir "Clasificaci�n: Sobrepeso"
                Sino
                    Escribir "Clasificaci�n: Obeso"
                FinSi
            FinSi
        FinSi
        
        Escribir "�Desea calcular otro �ndice de masa corporal? (S/N): "
        Leer salir
    Hasta Que salir = "N" o salir = "n"
    
    Escribir "Gracias por usar la calculadora de BMI. �Hasta luego!"
    
FinAlgoritmo
